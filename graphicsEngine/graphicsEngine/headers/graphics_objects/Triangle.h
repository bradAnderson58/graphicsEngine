#pragma once

#include "headers/vector_math/Vector3.h"

// TODO: Useful?

class Triangle {
public:
    Triangle::Triangle(Vector3 p0, Vector3 p1, Vector3 p2) :
    point0(p0), point1(p1), point2(p2) {}
    
    Triangle::Triangle(Vector3 points[3]) :
    point0(points[0]), point1(points[1]), point2(points[2]) {}
    
    Triangle::Triangle() :
    point0(Vector3()), point1(Vector3()), point2(Vector3()) {}
    
private:
    Vector3 point0;
    Vector3 point1;
    Vector3 point2;
};
