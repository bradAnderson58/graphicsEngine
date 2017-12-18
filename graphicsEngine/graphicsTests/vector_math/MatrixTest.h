#pragma once

#include <cxxtest/TestSuite.h>
#include "headers/vector_math/Matrix3.h"
#include "headers/vector_math/Vector3.h"

class MatrixTest : public CxxTest::TestSuite {
public:
    void testMatrix3Construction(void) {
        Vector3 tvec0 = Vector3(0.0f, 1.0f, 2.0f);
        Vector3 tvec1 = Vector3(4.0f, 5.0f, 6.0f);
        Vector3 tvec2 = Vector3();
        
        Matrix3 testmatrix = Matrix3(tvec0, tvec1, tvec2);
        Matrix3 defaultmatrix = Matrix3();
        
        TS_ASSERT_EQUALS(testmatrix.vec0, tvec0);
        TS_ASSERT_EQUALS(testmatrix.vec1, tvec1);
        TS_ASSERT_EQUALS(testmatrix.vec2, tvec2);
        
        TS_ASSERT_EQUALS(defaultmatrix.vec0, tvec2);
        TS_ASSERT_EQUALS(defaultmatrix.vec1, tvec2);
        TS_ASSERT_EQUALS(defaultmatrix.vec2, tvec2);
    }
};

