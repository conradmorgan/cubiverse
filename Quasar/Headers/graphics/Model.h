#pragma once

#include "graphics/Graphics.h"
#include "graphics/Texture.h"

#include "math/Math.h"
#include "graphics/IRender.h"
#include "graphics/Shader.h"

class ModelFactory;

class Model : public IRender {
public:
	Model();

	bool Init(const ModelFactory& mf, int buffExtra = 0);
	void Shutdown();

	virtual void Render();

	bool Update(const ModelFactory& mf);

	void EnableOrtho(bool ortho = true);

	void Bind();
	void Unbind();

	byte* Map(GLenum access);
	void Unmap();

	bool orthographic;

	glm::mat4 world;

	Shader* shader;
	Texture* texture;

	int vertexCount;
	int indexCount;

	int vertexBufferSize;

	GLenum topology;
	GLuint vertexBuffer;
	GLuint indexBuffer;
	GLuint vertexArrayObject;
};