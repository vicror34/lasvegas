#include "tema3.h"

#include <vector>
#include <string>
#include <iostream>

#include <Core/Engine.h>

using namespace std;

tema3::tema3()
{
}

tema3::~tema3()
{
}

void tema3::GenerateIntersection() {
	int count = 0;
	while (count != (maxX + maxY) / 2) {
		int x = (rand() % maxX * 2) - maxX;
		int y = (rand() % maxY * 2) - maxY;

		if (IntersectionPos.size() == 0) {
			IntersectionPos.push_back(glm::vec3(x, 0, y));
			continue;
		}
		bool valid = true;

		for (auto pos : IntersectionPos) {
			if (abs(pos[0] - x) < 5 &&
				abs(pos[2] - y) < 5) {
				valid = false;
				break;
			}
		}

		if (valid) {
			count++;
			IntersectionPos.push_back(glm::vec3(x, 0, y));
		}

	}

}
int facti(int n) {
	int factorial = 1;
	for (int i = 1; i <= n; ++i)
	{
		factorial *= i;
	}

	return factorial;
}
// Creating shortcut for an integer pair 
typedef  pair<int, int> iPair;

// Structure to represent a graph 
struct Graphi
{
	int V, E;
	vector< pair<int, iPair> > edges;

	// Constructor 
	Graphi(int V, int E)
	{
		this->V = V;
		this->E = E;
	}

	// Utility function to add an edge 
	void addEdge(int u, int v, int w)
	{
		edges.push_back({ w, {u, v} });
	}

	// Function to find MST using Kruskal's 
	// MST algorithm 
	int kruskalMST(const vector<glm::vec3> &iPos, vector<Mesh*> *roads, tema3 context);
};

// To represent Disjoint Sets 
struct DisjointSets
{
	int *parent, *rnk;
	int n;

	// Constructor. 
	DisjointSets(int n)
	{
		// Allocate memory 
		this->n = n;
		parent = new int[n + 1];
		rnk = new int[n + 1];

		// Initially, all vertices are in 
		// different sets and have rank 0. 
		for (int i = 0; i <= n; i++)
		{
			rnk[i] = 0;

			//every element is parent of itself 
			parent[i] = i;
		}
	}

	// Find the parent of a node 'u' 
	// Path Compression 
	int find(int u)
	{
		/* Make the parent of the nodes in the path
		   from u--> parent[u] point to parent[u] */
		if (u != parent[u])
			parent[u] = find(parent[u]);
		return parent[u];
	}

	// Union by rank 
	void merge(int x, int y)
	{
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

/* Functions returns weight of the MST*/

int Graphi::kruskalMST(const vector<glm::vec3> &iPos, vector<Mesh*> *roads, tema3 context)
{
	int mst_wt = 0; // Initialize result 

	// Sort edges in increasing order on basis of cost 
	sort(edges.begin(), edges.end());

	// Create disjoint sets 
	DisjointSets ds(V);

	// Iterate through all sorted edges 
	vector< pair<int, iPair> >::iterator it;
	for (it = edges.begin(); it != edges.end(); it++)
	{
		int u = it->second.first;
		int v = it->second.second;

		int set_u = ds.find(u);
		int set_v = ds.find(v);

		// Check if the selected edge is creating 
		// a cycle or not (Cycle is created if u 
		// and v belong to same set) 
		if (set_u != set_v)
		{
			// Current edge will be in the MST 
			// so print it 
			cout << u << " " << v << endl;
			glm::vec3 r = iPos[u] - iPos[v];
			glm::vec3 frd = glm::normalize(glm::cross(r, glm::vec3(0, 1, 0))) * 0.5f + iPos[u];
			glm::vec3 frs = glm::normalize(glm::cross(r, glm::vec3(0, -1, 0))) * 0.5f + iPos[u];
			glm::vec3 srs = glm::normalize(glm::cross(r, glm::vec3(0, 1, 0))) * 0.5f + iPos[v];
			glm::vec3 srd = glm::normalize(glm::cross(r, glm::vec3(0, -1, 0))) * 0.5f + iPos[v];

			float length = glm::length(r);

			vector<VertexFormat> vertices
			{
				VertexFormat(frs, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 0)),
				VertexFormat(frd, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 1)),
				VertexFormat(srd, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(length, 0)),
				VertexFormat(srs, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(length, 1))
			};
			vector<unsigned short> indices
			{
				0, 1, 2, 2, 1, 3,
			};
			roads->push_back(context.CreateMesh("road", vertices, indices));

			// Update MST weight 
			mst_wt += it->first;

			// Merge two sets 
			ds.merge(set_u, set_v);
		}
	}

	return mst_wt;


}

void tema3::go(int offset, int k) {
	if (k == 0) {
		for (int i = 0; i < combination.size(); ++i) { 
			cout << combination[i] << " "; 
			combroads.push_back(combination[i]);
		}
		return;
	}
	for (int i = offset; i <= people.size() - k; ++i) {
		combination.push_back(people[i]);
		go(i + 1, k - 1);
		combination.pop_back();
	}
}

void tema3::Init()
{
	GenerateIntersection();

	int V = IntersectionPos.size();
	long int E = V * (V - 1) / 2;
	Graphi g(V, E);
	
	//g.addEdge(i, i, V - i);
	for (int i = 0; i < V; ++i) { people.push_back(i + 1); }
	go(0, 2);
	for (int i = 0; i < combroads.size(); i += 2) {
		//cout << combroads[i] << " " << combroads[i + 1] << endl;
		g.addEdge(combroads[i]-1, combroads[i + 1] -1, glm::distance(IntersectionPos[combroads[i] -1], IntersectionPos[combroads[i + 1] -1]));
	}
	g.kruskalMST(IntersectionPos, &roads, *this);
	//for (auto frp : IntersectionPos) {
	//	for (auto srp : IntersectionPos) {
	//		if (srp != frp) {

	//			glm::vec3 r = srp - frp;
	//			glm::vec3 frd = glm::normalize(glm::cross(r, glm::vec3(0, 1, 0))) * 0.5f + frp;
	//			glm::vec3 frs = glm::normalize(glm::cross(r, glm::vec3(0, -1, 0))) * 0.5f + frp;
	//			glm::vec3 srs = glm::normalize(glm::cross(r, glm::vec3(0, 1, 0))) * 0.5f + srp;
	//			glm::vec3 srd = glm::normalize(glm::cross(r, glm::vec3(0, -1, 0))) * 0.5f + srp;

	//			float length = glm::length(r);

	//			vector<VertexFormat> vertices
	//			{
	//				VertexFormat(frs, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 0)),
	//				VertexFormat(frd, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 1)),
	//				VertexFormat(srd, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(length, 0)),
	//				VertexFormat(srs, glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(length, 1))
	//			};
	//			vector<unsigned short> indices
	//			{
	//				0, 1, 2, 2, 1, 3,
	//			};
	//			roads.push_back(CreateMesh("road", vertices, indices));
	//			//meshes["plane"] = CreateMesh("plane", vertices, indices);

	//		}
	//	}
	//}

	const string textureLoc = "Source/Laboratoare/Tema2/Textures/";
	const string textureLoc2 = "Source/Laboratoare/Laborator9/Textures/";

	{
		Texture2D* texture = new Texture2D();
		texture->Load2D((textureLoc2 + "crate.jpg").c_str(), GL_REPEAT);
		mapTextures["crate"] = texture;
	}

	{
		Shader *shader = new Shader("ShaderLab6");
		shader->AddShader("Source/Laboratoare/tema3/Shaders/VertexShader.glsl", GL_VERTEX_SHADER);
		shader->AddShader("Source/Laboratoare/tema3/Shaders/FragmentShader.glsl", GL_FRAGMENT_SHADER);
		shader->CreateAndLink();
		shaders[shader->GetName()] = shader;
	}

	{
		Mesh* mesh = new Mesh("box");
		mesh->LoadMesh(RESOURCE_PATH::MODELS + "Primitives", "box.obj");
		meshes[mesh->GetMeshID()] = mesh;
	}

	//	{
	//		Texture2D* texture = new Texture2D();
	//		texture->Load2D((textureLoc + "crate.jpg").c_str(), GL_REPEAT);
	//		mapTextures["crate"] = texture;
	//	}

	vector<VertexFormat> vertices
	{
		VertexFormat(glm::vec3(0, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 0)),
		VertexFormat(glm::vec3(1, 0, 0), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(0, 1)),
		VertexFormat(glm::vec3(0, 0, 1), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(1, 0)),
		VertexFormat(glm::vec3(1, 0, 1), glm::vec3(1, 1, 1), glm::vec3(0, 1, 0), glm::vec2(1, 1))
	};
	vector<unsigned short> indices
	{
		0, 1, 2, 2, 1, 3,
	};
	meshes["plane"] = CreateMesh("plane", vertices, indices);



}

Mesh* tema3::CreateMesh(const char *name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices)
{
	unsigned int VAO = 0;
	// TODO: Create the VAO and bind it
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	// TODO: Create the VBO and bind it
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// TODO: Send vertices data into the VBO buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0]) * vertices.size(), &vertices[0], GL_STATIC_DRAW);

	// TODO: Crete the IBO and bind it
	unsigned int IBO;
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	// TODO: Send indices data into the IBO buffer
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0]) * indices.size(), &indices[0], GL_STATIC_DRAW);

	// ========================================================================
	// This section describes how the GPU Shader Vertex Shader program receives data

	// set vertex position attribute
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), 0);

	// set vertex normal attribute
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(sizeof(glm::vec3)));

	// set texture coordinate attribute
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3)));

	// set vertex color attribute
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(VertexFormat), (void*)(2 * sizeof(glm::vec3) + sizeof(glm::vec2)));
	// ========================================================================

	// Unbind the VAO
	glBindVertexArray(0);

	// Check for OpenGL errors
	CheckOpenGLError();

	// Mesh information is saved into a Mesh object
	meshes[name] = new Mesh(name);
	meshes[name]->InitFromBuffer(VAO, static_cast<unsigned short>(indices.size()));
	meshes[name]->vertices = vertices;
	meshes[name]->indices = indices;
	return meshes[name];
}


void tema3::FrameStart()
{
	// clears the color buffer (using the previously set color) and depth buffer
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glm::ivec2 resolution = window->GetResolution();
	// sets the screen area where to draw
	glViewport(0, 0, resolution.x, resolution.y);
	DrawCoordinatSystem();
}

void tema3::Update(float deltaTimeSeconds)
{

	for (auto rp : roads) {
		glm::mat4 modelMatrix = glm::mat4(1);
	
		RenderSimpleMesh(rp, shaders["ShaderLab6"], modelMatrix, mapTextures["crate"]);
	}


	//modelMatrix = glm::translate(modelMatrix, srd);
	/*for (auto rp = IntersectionPos.cbegin(); rp != --IntersectionPos.cend(); ++rp) {
		glm::vec3 r = *(rp + 1) - *rp;
		glm::mat4 modelMatrix = glm::mat4(1);
		modelMatrix = glm::translate(modelMatrix, *rp);
		RenderSimpleMesh(meshes["box"], shaders["ShaderLab6"], modelMatrix, mapTextures["crate"]);
	}*/
	
}

void tema3::FrameEnd()
{
}

void tema3::RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 & modelMatrix, Texture2D* texture1, Texture2D* texture2)
{
	if (!mesh || !shader || !shader->GetProgramID())
		return;

	// render an object using the specified shader and the specified position
	glUseProgram(shader->program);

	// Bind model matrix
	GLint loc_model_matrix = glGetUniformLocation(shader->program, "Model");
	glUniformMatrix4fv(loc_model_matrix, 1, GL_FALSE, glm::value_ptr(modelMatrix));

	// Bind view matrix
	glm::mat4 viewMatrix = GetSceneCamera()->GetViewMatrix();
	int loc_view_matrix = glGetUniformLocation(shader->program, "View");
	glUniformMatrix4fv(loc_view_matrix, 1, GL_FALSE, glm::value_ptr(viewMatrix));

	// Bind projection matrix
	glm::mat4 projectionMatrix = GetSceneCamera()->GetProjectionMatrix();
	int loc_projection_matrix = glGetUniformLocation(shader->program, "Projection");
	glUniformMatrix4fv(loc_projection_matrix, 1, GL_FALSE, glm::value_ptr(projectionMatrix));

	// rotirea sferei
	int loc_time = glGetUniformLocation(shader->program, "time");

	// mix doua texturi
	int loc_mix = glGetUniformLocation(shader->program, "mixer");
	glUniform1i(loc_mix, textureMix);

	if (mesh == meshes["sphere"])
		glUniform1f(loc_time, (float)Engine::GetElapsedTime());
	else
		glUniform1f(loc_time, -1.0f);

	if (texture1)
	{
		//TODO : activate texture location 0
		//TODO : Bind the texture1 ID
		//TODO : Send texture uniform value
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1->GetTextureID());
		glUniform1i(glGetUniformLocation(shader->GetProgramID(), "texture_1"), 0);
	}

	if (texture2)
	{
		//TODO : activate texture location 1
		//TODO : Bind the texture2 ID
		//TODO : Send texture uniform value
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2->GetTextureID());
		glUniform1i(glGetUniformLocation(shader->GetProgramID(), "texture_2"), 1);
	}

	// Draw the object
	glBindVertexArray(mesh->GetBuffers()->VAO);
	glDrawElements(mesh->GetDrawMode(), static_cast<int>(mesh->indices.size()), GL_UNSIGNED_SHORT, 0);
}

// Documentation for the input functions can be found in: "/Source/Core/Window/InputController.h" or
// https://github.com/UPB-Graphics/Framework-EGC/blob/master/Source/Core/Window/InputController.h

void tema3::OnInputUpdate(float deltaTime, int mods)
{
	float speed = 2;

	if (!window->MouseHold(GLFW_MOUSE_BUTTON_RIGHT))
	{
		glm::vec3 up = glm::vec3(0, 1, 0);
		glm::vec3 right = GetSceneCamera()->transform->GetLocalOXVector();
		glm::vec3 forward = GetSceneCamera()->transform->GetLocalOZVector();
		forward = glm::normalize(glm::vec3(forward.x, 0, forward.z));
	}
}

void tema3::OnKeyPress(int key, int mods)
{
}

void tema3::OnKeyRelease(int key, int mods)
{
	// add key release event
}

void tema3::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
}

void tema3::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
	// add mouse button press event
}

void tema3::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{
}

void tema3::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}

void tema3::OnWindowResize(int width, int height)
{
}