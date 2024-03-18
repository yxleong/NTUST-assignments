#include "object.h"

object::object()
{
}
void object::initialize()
{
	//shaderManager = new ShaderManager();

	//VAO
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//VBO
	glGenBuffers(1, &pVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, pVBOs);

	glGenBuffers(1, &pcVBOs);
	glBindBuffer(GL_ARRAY_BUFFER, pcVBOs);
}
void object::setShader(char* vert, char* frag)
{
	ShaderInfo shaders[] =
	{
		{ GL_VERTEX_SHADER,		vert },
		{ GL_FRAGMENT_SHADER,	frag },
		{ GL_NONE, NULL }
	};
	shaderProgram = LoadShaders(shaders);
}

void object::setPoint(vec3 point)
{
	Points.push_back(point);
}
void object::setColor(vec3 color)
{
	PColors.push_back(color);
}

mat4 object::setTranslate(float x, float y, float z)
{
	vec4 t = vec4(x, y, z, 1);
	vec4 c1 = vec4(1, 0, 0, 0);
	vec4 c2 = vec4(0, 1, 0, 0);
	vec4 c3 = vec4(0, 0, 1, 0);
	return mat4(c1, c2, c3, t);
}

mat4 object::setRotate(float angle, float x, float y, float z)
{
	float r = angle*3.1415 / 180;
	vec4 c1 = vec4(cos(r) + (1 - cos(r))*x*x, (1 - cos(r))*y*x + sin(r)*z, (1 - cos(r))*z*x - sin(r)*y, 0);
	vec4 c2 = vec4((1 - cos(r))*y*x - sin(r)*z, cos(r) + (1 - cos(r))*y*y, (1 - cos(r))*z*y + sin(r)*x, 0);
	vec4 c3 = vec4((1 - cos(r))*z*x + sin(r)*y, (1 - cos(r))*z*y - sin(r)*x, cos(r) + (1 - cos(r))*z*z, 0);
	vec4 c4 = vec4(0, 0, 0, 1);
	return mat4(c1, c2, c3, c4);
}

mat4 object::setScale(float x, float y, float z)
{
	vec4 c1 = vec4(x, 0, 0, 0);
	vec4 c2 = vec4(0, y, 0, 0);
	vec4 c3 = vec4(0, 0, z, 0);
	vec4 c4 = vec4(0, 0, 0, 1);
	return mat4(c1, c2, c3, c4);
}

void object::render(GLenum type,mat4 projectionMatrix, mat4 viewMatrix, mat4 modelMatrix)
{
	glUseProgram(shaderProgram);
	glBindVertexArray(VAO);

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ModelMatrix"), 1, GL_FALSE, &modelMatrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ViewMatrix"), 1, GL_FALSE, &viewMatrix[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "ProjectionMatrix"), 1, GL_FALSE, &projectionMatrix[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, pVBOs);
	glBufferData(GL_ARRAY_BUFFER, Points.size() * sizeof(glm::vec3), &Points[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer
	(0, //shader對應位置
	3, //對應結構
	GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, pcVBOs);
	glBufferData(GL_ARRAY_BUFFER, PColors.size() * sizeof(glm::vec3), &PColors[0], GL_DYNAMIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(1);

	glDrawArrays(type, 0, Points.size());

	glEnable(GL_DEPTH_TEST);

}