#ifndef SHADOW_H
#define SHADOW_H

#include "shader.h"

class Shadow
{
public:
	Shadow();
	~Shadow();
	void Bind_deph();
	void compue_light();
	void update_deph();
	void bind_shadow();
	void update_deph(const Transform& transform, const Camera& camera);
	void update_shadow(const Transform& transform, const Camera& camera);
protected:

private:
	glm::mat4 depthMVP;
	GLuint dephProgramID;
	GLuint dephMatrixID;
	GLuint FramebufferName;
	GLuint depthTexture;
	GLuint programID;
	GLuint textureID;
	GLuint MatrixID;
	GLuint DepthBiasID;
	GLuint ShadowMapID;
	Shader shader;
	glm::vec3 lightInvDir;
	glm::mat4 depthProjectionMatrix;
	glm::mat4 depthViewMatrix;
	glm::mat4 depthModelMatrix;
};

#endif