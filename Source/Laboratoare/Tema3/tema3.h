#pragma once
#include <Core/GPU/Mesh.h>
#include <Component/SimpleScene.h>
#include <Component/Transform/Transform.h>
#include <Component/Camera/Camera.h>
#include <Laboratoare/Tema3/LabCamera.h>
#include "BaseForm.h"
#include "kruskal.cpp"


struct Player {
	int color;
	bool ball8;
	int score;
};

class tema3 : public SimpleScene
{
public:
	tema3();
	~tema3();

	void Init() override;

	Mesh * CreateMesh(const char * name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices);
private:
	void FrameStart() override;
	void Update(float deltaTimeSeconds) override;
	void FrameEnd() override;

	void RenderSimpleMesh(Mesh *mesh, Shader *shader, const glm::mat4 &modelMatrix, Texture2D* texture1 = NULL, Texture2D* texture2 = NULL);

	void OnInputUpdate(float deltaTime, int mods) override;
	void OnKeyPress(int key, int mods) override;
	void OnKeyRelease(int key, int mods) override;
	void OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY) override;
	void OnMouseBtnPress(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods) override;
	void OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY) override;
	void OnWindowResize(int width, int height) override;
	void GenerateIntersection();
	void go(int offset, int k);
	

public:
	//LabCamera::Camera2 * Camera;
	glm::mat4 projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
	std::vector<glm::vec3> IntersectionPos;
	std::unordered_map<std::string, Texture2D*> mapTextures;
	std::vector<Mesh*> roads;
	int textureMix = 0;

	vector<int> people;
	vector<int> combination;
	vector<int> combroads;

	int maxX = 30;
	int maxY = 30;
};
