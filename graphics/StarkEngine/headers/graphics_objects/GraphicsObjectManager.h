#pragma once

#include "GraphicsObject.h"
#include "headers/vector_math/Vector3.h"

#include <vector>

class GraphicsObjectManager {

public:
	GraphicsObjectManager() {}

	GraphicsObject* createNewGraphicsObject(std::vector<Vector3> vertices, std::vector<int> indices);
	void initializeObjects();
	void redrawObjects();
	void deallocateObjects();

private:
	std::vector<GraphicsObject*> objects;
};