#include "textures.h"
#include "stb_image.h"
#include <iostream>
#include <cassert>

//domyœlny konstruktor pomocny przy ³adowaniu textury
Texture::Texture()
{
}

//konstruktor posiadaj¹cy ju¿ funkcje ³adowania tekstury
Texture::Texture(const std::string& fileName)
{
	LoadImage(fileName);
}

Texture::~Texture()
{
	glDeleteTextures(1, &m_texture);
}


//aktywuje i binduje odpowiedni¹ teksturê
void Texture::Bind(unsigned int unit)
{
	assert(unit >= 0 && unit <= 31);
	glActiveTexture(GL_TEXTURE0 + unit);
	glBindTexture(GL_TEXTURE_2D, m_texture);
}

//fucnkcja ³aduj¹ca texturê
void Texture::LoadImage(const std::string& fileName)
{
	int width, height, numComponents;
	unsigned char* data = stbi_load((fileName).c_str(), &width, &height, &numComponents, STBI_rgb_alpha);

	if (data == NULL)
		std::cerr << "Unable to load texture: " << fileName << std::endl;
	//generujemy i bindujemy texturê
	glGenTextures(1, &m_texture);
	glBindTexture(GL_TEXTURE_2D, m_texture);

	//pszypisujemy jej parametry lustrzanego odbicia, aby nie by³o widaæ kafelkowania
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	
	stbi_image_free(data);
}