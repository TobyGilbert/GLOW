// GLOW.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include <stb_image_write.h>

#include <glm/glm.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/norm.hpp>

#include <random>
#include <algorithm>

#include "Camera.h"
#include "Sphere.h"

const int xres = 256;
const int yres = 128;

glm::vec3 traceScene(const Ray &_ray)
{
	Sphere s = Sphere(glm::vec3(0.0f, 0.0f, -1.0f), 0.5f);
	Sphere floor = Sphere(glm::vec3(0.0, -100.5f, -1.0f), 100.0f);

	glm::vec3 lightPos = glm::vec3(-4.0f, 3.0f, 1.0f);
	glm::vec3 lightDirection = normalize(lightPos);
		
	float t = std::min(s.intersect(_ray, 0.001f, 10000.0f), floor.intersect(_ray, 0.001f, 10000.0f));

	if (t < std::numeric_limits<float>::max()) // hit the sphere
	{
		glm::vec3 normal = glm::normalize(_ray.pointAtParameter(t) - glm::vec3(0.0f, 0.0f, -1.0f));
		return 0.5f * glm::vec3(normal.x + 1.0f, normal.y + 1.0f, normal.z + 1.0f);
	}

	t = 0.5f * (_ray.getDirection().y + 1.0f);

	return (1.0f - t) * glm::vec3(1.0f) + t * glm::vec3(0.5f, 0.7f, 1.0f);
}

void trace()
{
	int numSamples = 100;

	char* data = new char[xres * yres * 3];

	float aspect = (float)xres / (float)yres;
	
	Camera camera(aspect);

	int pixelIndex = 0;
	for (int y = yres-1; y >= 0; y--)
	{
		for (int x = 0; x < xres; x++)
		{
			glm::vec3 col(0.0f);
			for (int i = 0; i < numSamples; i++)
			{
				float u = float(x + ((double)rand() / (RAND_MAX))) / float(xres);
				float v = float(y + ((double)rand() / (RAND_MAX))) / float(yres);
				Ray ray = camera.getRay(u, v);

				col += traceScene(ray);
			}

			col /= float(numSamples);

			// Gamma correct
			col = glm::vec3(sqrt(col.r), sqrt(col.g), sqrt(col.b));
			int ir = int(255.99 * col.r);
			int ig = int(255.99 * col.g);
			int ib = int(255.99 * col.b);

			data[pixelIndex++] = ir;
			data[pixelIndex++] = ig;
			data[pixelIndex++] = ib;
		}
	}

	stbi_write_bmp("antialiased.bmp", xres, yres, 3, data);

	delete[] data;
}

int main()
{
	std::cout << "Trace!\n";

	trace();
}
