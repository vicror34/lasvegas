#include "BaseForm.h"


BaseForm::BaseForm(Mesh *mesh, Texture2D tex, glm::vec3 pos) {
	this->tex = tex;
	this->mesh = mesh;
	this->pos = pos;
}