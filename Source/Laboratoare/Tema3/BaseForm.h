#include <Core/Engine.h>
class BaseForm {
private:
	Texture2D tex;
	glm::vec3 pos;
	Mesh *mesh;
public:
	BaseForm(Mesh *mesh, Texture2D tex, glm::vec3 pos);
};