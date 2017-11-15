#pragma once

#include "Vector3.h"

class Matrix3 {
public:
	Matrix3(Vector3 v0, Vector3 v1, Vector3 v2) :
		vec0(v0), vec1(v1), vec2(v2) {};
	Matrix3() : vec0(Vector3()), vec1(Vector3()), vec2(Vector3()) {};

	Vector3 vec0, vec1, vec2;
};