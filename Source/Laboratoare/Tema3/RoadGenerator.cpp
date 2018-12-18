//
// Created by oneze on 18/12/2018.
//

#include <iostream>
#include "RoadGenerator.h"

// To represent Disjoint Sets
struct DisjointSets {
	int *parent, *rnk;
	int n;

	// Constructor.
	DisjointSets(int n) {
		// Allocate memory
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];

		// Initially, all vertices are in
		// different sets and have rank 0.
		for (int i = 0; i <= n; i++) {
			rnk[i] = 0;

			//every element is parent of itself
			parent[i] = i;
		}
	}

	// Find the parent of a node 'u'
	// Path Compression
	int find(int u) {
		/* Make the parent of the nodes in the path
		   from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank
	void merge(int x, int y) {
		x = find(x), y = find(y);

		/* Make tree with smaller height
		   a subtree of the other tree  */
		if (rnk[x] > rnk[y])
			parent[y] = x;
		else // If rnk[x] <= rnk[y]
			parent[x] = y;

		if (rnk[x] == rnk[y])
			rnk[y]++;
	}
};

Graph::Graph(int V, int E) {
	this->V = V;
	this->E = E;
}

void Graph::addEdge(int u, int v, int w) {
	edges.push_back({ w, {u, v} });
}

std::vector<iPair> Graph::kruskalMST() {
	int mst_wt = 0; // Initialize result
	std::vector<iPair> mstEdges;
	// Sort edges in increasing order on basis of cost
	sort(edges.begin(), edges.end());

	// Create disjoint sets
	DisjointSets ds(V);

	// Iterate through all sorted edges
	std::vector<std::pair<int, iPair>>::iterator it;
	for (it = edges.begin(); it != edges.end(); it++) {
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		// Check if the selected edge is creating
		// a cycle or not (Cycle is created if u
		// and v belong to same set)
		if (set_u != set_v) {
			// Current edge will be in the MST
			// so print it
			mstEdges.emplace_back(u, v);

			// Update MST weight
			mst_wt += it->first;

			// Merge two sets
			ds.merge(set_u, set_v);
		}
	}

	return std::move(mstEdges);


}



void RoadGenerator::generateIntersecions() {
	int count = 0;
	while (count <= intr_no) {
		int x = (rand() % limits.first * 2) - limits.first;
		int z = (rand() % limits.second * 2) - limits.second;

		if (intersectionPos.empty()) {
			intersectionPos.emplace_back(glm::vec3(x, 0, z));
			continue;
		}

		bool validPlacement = true;

		for (auto pos : intersectionPos) {
			if (abs(pos[0] - x) < 5 &&
				abs(pos[2] - z) < 5) {
				validPlacement = false;
				break;
			}
		}

		if (validPlacement) {
			count++;
			intersectionPos.emplace_back(glm::vec3(x, 0, z));
		}

	}
}

void RoadGenerator::generate() {
	generateIntersecions();

	int V = intersectionPos.size();
	int E = V * (V - 1) / 2;
	Graph g(V, E);

	for (int i = 0; i < V; ++i) { combNumbers.push_back(i); }
	combinations(0, 2);

	for (int i = 0; i < combs.size(); i += 2) {
		g.addEdge(combs[i], combs[i + 1], glm::distance(intersectionPos[combs[i]], intersectionPos[combs[i + 1]]));
	}
	std::vector<iPair> edges = g.kruskalMST();

	generateRoads(&edges);

}

void RoadGenerator::combinations(int offset, int k) {
	if (k == 0) {
		for (int i = 0; i < tmpCombs.size(); ++i) {
			combs.push_back(tmpCombs[i]);
		}
		return;
	}
	for (int i = offset; i <= combNumbers.size() - k; ++i) {
		tmpCombs.push_back(combNumbers[i]);
		combinations(i + 1, k - 1);
		tmpCombs.pop_back();
	}
}

void RoadGenerator::generateRoads(const std::vector<iPair> *points) {
	Mesh* planeMesh = new Mesh("plane");

	for (auto p : *points) {
		glm::vec3 r = intersectionPos[p.first] - intersectionPos[p.second];
		glm::vec3 frd = glm::normalize(glm::cross(r, glm::vec3(0, 1, 0))) * 0.5f + intersectionPos[p.first];
		glm::vec3 frs = glm::normalize(glm::cross(r, glm::vec3(0, -1, 0))) * 0.5f + intersectionPos[p.first];
		glm::vec3 srs = glm::normalize(glm::cross(r, glm::vec3(0, 1, 0))) * 0.5f + intersectionPos[p.second];
		glm::vec3 srd = glm::normalize(glm::cross(r, glm::vec3(0, -1, 0))) * 0.5f + intersectionPos[p.second];

		float length = glm::length(r);

		std::vector<VertexFormat> vertices
		{
				VertexFormat(frs, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 0)),
				VertexFormat(frd, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 1)),
				VertexFormat(srd, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(length, 0)),
				VertexFormat(srs, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(length, 1))
		};
		std::vector<unsigned short> indices{ 0, 1, 2, 2, 1, 3 };

		planeMesh = new Mesh("plane");
		planeMesh->InitFromData(vertices, indices);
		roads.push_back(planeMesh);
	}

}

const std::vector<Mesh *> &RoadGenerator::getRoads() const {
	return roads;
}


