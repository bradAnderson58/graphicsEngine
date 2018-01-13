#pragma once

#include <cxxtest/TestSuite.h>
#include "headers/vector_math/Vector2.h"
#include "headers/vector_math/Vector3.h"
#include "headers/vector_math/Vector4.h"

class VectorTest : public CxxTest::TestSuite {
public:
    void testSanity(void) {
        TS_ASSERT(1 + 1 > 1);
        TS_ASSERT_EQUALS(1 + 1, 2);
    }
    
    // CONSTRUCTORS
    void testVector2Construction(void) {
        Vector2 testVector = Vector2(1.0f, 2.0f);
        Vector2 defaultVector = Vector2();
        
        TS_ASSERT_EQUALS(testVector.x, 1.0f);
        TS_ASSERT_EQUALS(testVector.y, 2.0f);
        
        TS_ASSERT_EQUALS(defaultVector.x, 0.0f);
        TS_ASSERT_EQUALS(defaultVector.y, 0.0f);
    }
    void testVector3Construction(void) {
        Vector3 testvector = Vector3(1.0f, 2.0f, 3.0f);
        Vector3 defaultvector = Vector3();
        
        TS_ASSERT_EQUALS(testvector.x, 1.0f);
        TS_ASSERT_EQUALS(testvector.y, 2.0f);
        TS_ASSERT_EQUALS(testvector.z, 3.0f);
        
        TS_ASSERT_EQUALS(defaultvector.x, 0.0f);
        TS_ASSERT_EQUALS(defaultvector.y, 0.0f);
        TS_ASSERT_EQUALS(defaultvector.z, 0.0f);
    }
    
    void testVector4Construction(void) {
        Vector4 testVector = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
        Vector4 defaultVector = Vector4();
        
        TS_ASSERT_EQUALS(testVector.x, 1.0f);
        TS_ASSERT_EQUALS(testVector.y, 2.0f);
        TS_ASSERT_EQUALS(testVector.z, 3.0f);
        TS_ASSERT_EQUALS(testVector.w, 4.0f);
        
        TS_ASSERT_EQUALS(defaultVector.x, 0.0f);
        TS_ASSERT_EQUALS(defaultVector.y, 0.0f);
        TS_ASSERT_EQUALS(defaultVector.z, 0.0f);
        TS_ASSERT_EQUALS(defaultVector.w, 0.0f);
    }
    
    void testStandardVector3(void) {
        Vector3 x = Vector3::standardX();
        Vector3 y = Vector3::standardY();
        Vector3 z = Vector3::standardZ();
        
        TS_ASSERT_EQUALS(x, Vector3(1,0,0));
        TS_ASSERT_EQUALS(y, Vector3(0,1,0));
        TS_ASSERT_EQUALS(z, Vector3(0,0,1));
    }
    
    // OPERATORS
    void testEqualityOperator2(void) {
        Vector2 vec = Vector2(9.0f, 9.0f);
        Vector2 sameVec = Vector2(9.0f, 9.0f);
        Vector2 differentVec = Vector2(5.0f, 5.0f);
        
        TS_ASSERT(vec == sameVec);
        TS_ASSERT(!(vec == differentVec));
    }
    
    void testEqualityOperator3(void) {
        Vector3 vec = Vector3(9.0f, 9.0f, 9.0f);
        Vector3 sameVec = Vector3(9.0f, 9.0f, 9.0f);
        Vector3 differentVec = Vector3(5.0f, 5.0f, 5.0f);
        
        TS_ASSERT(vec == sameVec);
        TS_ASSERT(!(vec == differentVec));
    }
    
    void testEqualityOperator4(void) {
        Vector4 vec = Vector4(9.0f, 9.0f, 9.0f, 9.0f);
        Vector4 sameVec = Vector4(9.0f, 9.0f, 9.0f, 9.0f);
        Vector4 differentVec = Vector4(5.0f, 5.0f, 5.0f, 5.0f);
        
        TS_ASSERT(vec == sameVec);
        TS_ASSERT(!(vec == differentVec));
    }
    
    // STATIC METHODS
    void testPieceWiseVector2(void) {
        Vector2 vec1 = Vector2(3.0f, 4.0f);
        Vector2 vec2 = Vector2(1.0f, 2.0f);
        Vector2 answer = Vector2::piecewise(vec1, vec2);
        
        TS_ASSERT_EQUALS(answer, Vector2(3.0f, 8.0f));
    }
    
    void testPiecewiseVector3(void) {
        Vector3 vec1 = Vector3(3.0f, 4.0f, 5.0f);
        Vector3 vec2 = Vector3(1.0f, 2.0f, 3.0f);
        Vector3 answer = Vector3::piecewise(vec1, vec2);
        
        TS_ASSERT_EQUALS(answer, Vector3(3.0f, 8.0f, 15.0f));
    }
    
    void testPiecewiseVector4(void) {
        Vector4 vec1 = Vector4(3.0f, 4.0f, 5.0f, 6.0f);
        Vector4 vec2 = Vector4(1.0f, 2.0f, 3.0f, 4.0f);
        Vector4 answer = Vector4::piecewise(vec1, vec2);
        
        TS_ASSERT_EQUALS(answer, Vector4(3.0f, 8.0f, 15.0f, 24.0f));
    }
    
    void testPerpendicular(void) {
        Vector2 vec = Vector2(1.0f, 5.0f);
        Vector2 answer = Vector2::perpendicular(vec);
        
        TS_ASSERT_EQUALS(answer, Vector2(-5.0f, 1.0f));
    }
};

