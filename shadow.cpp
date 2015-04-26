///////////////////////////////////////////////////////////////////////////////////////
// w tym pliku ma nast¹piæ generacja tekstury cieni za pomoc¹ rzutowania vertexów    //
// na p³aszczyznê za pomoc¹ ray-traycingu, a nastêpnie textura ta ma trafiæ do       //
// shadera, który zmiesza texturê diffuse i shadow a nastêpnie narysuje j¹ na ekranie//
///////////////////////////////////////////////////////////////////////////////////////


#include "shadow.h"
#include <iostream>

Shadow::Shadow()
{
	
	this->dephProgramID = shader.initial_program_shader("./res/shadow/depth");
	this->dephMatrixID = glGetUniformLocation(dephProgramID, "dephMVP");
	this->FramebufferName = 0;
	glGenFramebuffers(1, &FramebufferName);
	glBindBuffer(GL_FRAMEBUFFER, FramebufferName);
	this->depthTexture = 0;
	glGenTextures(1, &depthTexture);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT16, 1024, 1024, 0, GL_DEPTH_COMPONENT, GL_FLOAT, 0);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC, GL_LEQUAL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE, GL_COMPARE_R_TO_TEXTURE);
	glFramebufferTexture(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, depthTexture, 0);

	glDrawBuffer(GL_NONE);

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
		std::cerr << "FrameBuffer don't compile!" << std::endl;

	this->programID = shader.initial_program_shader("./res/shadow/shadow");
	this->textureID = glGetUniformLocation(programID, "myTextureSampler");
	this->MatrixID = glGetUniformLocation(programID, "MVP");
	this->DepthBiasID = glGetUniformLocation(programID, "DepthBiasMVP");
	this->ShadowMapID = glGetUniformLocation(programID, "shadowMap");
}

void Shadow::Bind_deph()
{
	glBindFramebuffer(GL_FRAMEBUFFER, FramebufferName);
	glUseProgram(dephProgramID);
}

void Shadow::compue_light()
{
	lightInvDir = glm::vec3(0.5f, 2, 2);
	depthProjectionMatrix = glm::ortho<float>(-20, 40, -10, 30, -10, 90);
	depthViewMatrix = glm::lookAt(lightInvDir, glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	depthModelMatrix = glm::mat4(1.0);
}


void Shadow::update_deph(const Transform& transform, const Camera& camera)
{
	depthMVP = depthProjectionMatrix * depthViewMatrix * depthModelMatrix;
	glUniformMatrix4fv(dephMatrixID, 1, GL_FALSE, &depthMVP[0][0]);
}

void Shadow::bind_shadow()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glUseProgram(programID);
}

void Shadow::update_shadow(const Transform& transform, const Camera& camera)
{
	glm::mat4 biasMatrix(
		0.5, 0.0, 0.0, 0.0,
		0.0, 0.5, 0.0, 0.0,
		0.0, 0.0, 0.5, 0.0,
		0.5, 0.5, 0.5, 1.0
		);
	glm::mat4 depthBiasMVP = biasMatrix*depthMVP;
	glm::mat4 MVP = camera.GetViewProjection() * transform.GetModel();
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	glUniformMatrix4fv(DepthBiasID, 1, GL_FALSE, &depthBiasMVP[0][0]);
	// Bind our texture in Texture Unit 0
	
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, depthTexture);
	glUniform1i(ShadowMapID, 1);
}

Shadow::~Shadow()
{
	glDeleteProgram(programID);
	glDeleteProgram(dephProgramID);
	glDeleteFramebuffers(1, &FramebufferName);
	glDeleteTextures(1, &depthTexture);
}
