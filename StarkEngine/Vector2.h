#pragma once

class Vector2 {
public:
	Vector2(float px, float py) : x(px), y(py) {};
	Vector2() : x(0), y(0) {};

	bool operator==(const Vector2 &other) const;

	// piecewise vector multiplication
	// piecewise(u, v) returns ((u0*v0), (u1*v1), (u2*v2))
	static Vector2 piecewise(Vector2 vec1, Vector2 vec2);
	static Vector2 perpendicular(Vector2 vec);

	float x;
	float y;
};