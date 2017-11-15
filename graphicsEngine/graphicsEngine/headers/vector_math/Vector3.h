#pragma once

class Vector3 {
public:
    Vector3(float px, float py, float pz) : x(px), y(py), z(pz) {};
    Vector3() : x(0), y(0), z(0) {};
    
    bool operator==(const Vector3 &other) const;
    
    // piecewise vector multiplication
    // piecewise(u, v) returns ((u0*v0), (u1*v1), (u2*v2))
    static Vector3 piecewise(Vector3 vec1, Vector3 vec2);
    static Vector3 standardX();
    static Vector3 standardY();
    static Vector3 standardZ();
    
    float x;
    float y;
    float z;
};
