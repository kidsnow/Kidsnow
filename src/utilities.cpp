#include "utilities.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

namespace kidsnow {

unsigned char* loadImageFile(const char* fileName, int& width, int& height)
{
	int temp;
	return stbi_load(fileName, &width, &height, &temp, 0);
}

void freeImageBuffer(unsigned char* data)
{
	stbi_image_free(data);
}

}