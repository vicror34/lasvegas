#pragma once
#include <Core/GPU/Mesh.h>
#include <Component/SimpleScene.h>
#include <Component/Transform/Transform.h>
#include <Component/Camera/Camera.h>
#include <Laboratoare/Tema3/LabCamera.h>
#include "BaseForm.h"
#include <Laboratoare\Tema3\RoadGenerator.h>

class tema3 : public SimpleScene
{
public:

	tema3();
	~tema3();

	void Init() override;

	Mesh * CreateMesh(const char * name, const std::vector<VertexFormat> &vertices, const std::vector<unsigned short> &indices);
	const int MAX_X = 30, MAX_Y = 30;
	RoadGenerator roadGen;


	glm::mat4 projectionMatrix = glm::perspective(RADIANS(60), window->props.aspectRatio, 0.01f, 200.0f);
	std::vector<glm::vec3> IntersectionPos;
	std::unordered_map<std::string, Texture2D*> mapTextures;
	std::vector<Mesh*> roads;
	int textureMix = 0;

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
};
