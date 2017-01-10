
#include "Vector2.h"

bool Vector2::operator==(const Vector2 &other)  const {
	return (other.x == this->x && other.y == this->y);
}

Vector2 Vector2::piecewise(Vector2 vec1, Vector2 vec2) {
	Vector2 retval = Vector2();
	retval.x = vec1.x * vec2.x;
	retval.y = vec1.y * vec2.y;
	return retval;
}

Vector2 Vector2::perpendicular(Vector2 vec) {
	return Vector2(-vec.y, vec.x);
}