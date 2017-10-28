
#include "headers/vector_math/Vector4.h"

bool Vector4::operator==(const Vector4 &other)  const {
	return (other.x == this->x && other.y == this->y && other.z == this->z && other.w == this->w);
}

Vector4 Vector4::piecewise(Vector4 vec1, Vector4 vec2) {
	Vector4 retval = Vector4();
	retval.x = vec1.x * vec2.x;
	retval.y = vec1.y * vec2.y;
	retval.z = vec1.z * vec2.z;
	retval.w = vec1.w * vec2.w;
	return retval;
}