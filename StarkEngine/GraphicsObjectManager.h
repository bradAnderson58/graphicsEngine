#pragma once

#include "GraphicsObject.h"
#include "Vector3.h"

#include <vector>

class GraphicsObjectManager {

public:
	GraphicsObjectManager() {}

	GraphicsObject* createNewGraphicsObject(std::vector<Vector3> vertices);
	void initializeObjects();
	void redrawObjects();
	void deallocateObjects();

private:
	std::vector<GraphicsObject*> objects;
};