#pragma once
#include <vector>
#include <include/glm.h>
#include <Core/GPU/Mesh.h>


typedef std::pair<int, int> iPair;

class RoadGenerator {
public:
	RoadGenerator(int intersection_no, iPair limits) : intr_no(intersection_no), limits(limits) {};
    void generate();
private:
    int intr_no;
    iPair limits;
    std::vector<glm::vec3> intersectionPos;

    void generateIntersecions();
    void combinations(int offset, int k);
    void generateRoads(const std::vector<iPair> *points);
    std::vector<int> combNumbers;
    std::vector<int> tmpCombs;
    std::vector<int> combs;

    std::vector<Mesh*> roads;
public:
    const std::vector<Mesh *> &getRoads() const;

};



class Graph{
private:
    int V, E;
    std::vector< std::pair<int, iPair> > edges;
public:
    // Constructor
    Graph(int V, int E);
    void addEdge(int u, int v, int w);
    std::vector<iPair> kruskalMST();

};


