
#include "GraphicsObjectManager.h"

#include <algorithm>
#include <vector>

using namespace std;

GraphicsObject* GraphicsObjectManager::createNewGraphicsObject(vector<Vector3> vertices) {
	GraphicsObject *object = new GraphicsObject(vertices);
	objects.push_back(object);
	return object;
}

void GraphicsObjectManager::initializeObjects() {
	std::for_each(objects.begin(), objects.end(), [](GraphicsObject* object) {
		object->init();
	});
}

void GraphicsObjectManager::redrawObjects() {
	std::for_each(objects.begin(), objects.end(), [](GraphicsObject* object) {
		object->redraw();
	});
}

void GraphicsObjectManager::deallocateObjects() {
	std::for_each(objects.begin(), objects.end(), [](GraphicsObject* object) {
		object->deallocate();
	});
}