
#include "Vector3.h"

bool Vector3::operator==(const Vector3 &other)  const {
	return (other.x == this->x && other.y == this->y && other.z == this->z);
}

Vector3 Vector3::piecewise(Vector3 vec1, Vector3 vec2) {
	Vector3 retval = Vector3();
	retval.x = vec1.x * vec2.x;
	retval.y = vec1.y * vec2.y;
	retval.z = vec1.z * vec2.z;
	return retval;
}

Vector3 Vector3::standardX() {
	return Vector3(1, 0, 0);
}
Vector3 Vector3::standardY() {
	return Vector3(0, 1, 0);
}
Vector3 Vector3::standardZ() {
	return Vector3(0, 0, 1);
}

