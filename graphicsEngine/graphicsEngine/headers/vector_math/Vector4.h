#pragma once

class Vector4 {
public:
    Vector4(float px, float py, float pz, float pw) : x(px), y(py), z(pz), w(pw) {};
    Vector4() : x(0), y(0), z(0), w(0) {};
    
    bool operator==(const Vector4 &other) const;
    
    static Vector4 piecewise(Vector4 vec1, Vector4 vec2);
    
    float x, y, z, w;
};
