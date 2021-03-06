#pragma once
#include "TextureCache.h"
#include "GLTexture.h"

#include <string>

namespace Bengine {

class ResourceManager
{
public:
	static GLTexture getTexture(std::string texturePath);

private:
	static TextureCache _textureCache;
};

}