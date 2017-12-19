/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#include <fstream>
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/XUnitPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    std::ofstream ofstr("TestResults.xml");
    CxxTest::XUnitPrinter tmp(ofstr);
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main<CxxTest::XUnitPrinter>( tmp, argc, argv );
    return status;
}
bool suite_MyTestSuite_init = false;
#include "MyTest.h"

static MyTestSuite suite_MyTestSuite;

static CxxTest::List Tests_MyTestSuite = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MyTestSuite( "/Users/bradanderson/projects/books/Real_Time_Rendering/graphicsEngine/graphicsEngine/graphicsTests/MyTest.h", 4, "MyTestSuite", suite_MyTestSuite, Tests_MyTestSuite );

static class TestDescription_suite_MyTestSuite_testAddition : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testAddition() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 6, "testAddition" ) {}
 void runTest() { suite_MyTestSuite.testAddition(); }
} testDescription_suite_MyTestSuite_testAddition;

static class TestDescription_suite_MyTestSuite_testTwo : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MyTestSuite_testTwo() : CxxTest::RealTestDescription( Tests_MyTestSuite, suiteDescription_MyTestSuite, 11, "testTwo" ) {}
 void runTest() { suite_MyTestSuite.testTwo(); }
} testDescription_suite_MyTestSuite_testTwo;

#include "vector_math/MathFunctionsTest.h"

static MathFunctionsTest suite_MathFunctionsTest;

static CxxTest::List Tests_MathFunctionsTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MathFunctionsTest( "/Users/bradanderson/projects/books/Real_Time_Rendering/graphicsEngine/graphicsEngine/graphicsTests/vector_math/MathFunctionsTest.h", 6, "MathFunctionsTest", suite_MathFunctionsTest, Tests_MathFunctionsTest );

static class TestDescription_suite_MathFunctionsTest_testFactorialFunction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MathFunctionsTest_testFactorialFunction() : CxxTest::RealTestDescription( Tests_MathFunctionsTest, suiteDescription_MathFunctionsTest, 8, "testFactorialFunction" ) {}
 void runTest() { suite_MathFunctionsTest.testFactorialFunction(); }
} testDescription_suite_MathFunctionsTest_testFactorialFunction;

static class TestDescription_suite_MathFunctionsTest_testBinomialFactorialFunction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MathFunctionsTest_testBinomialFactorialFunction() : CxxTest::RealTestDescription( Tests_MathFunctionsTest, suiteDescription_MathFunctionsTest, 20, "testBinomialFactorialFunction" ) {}
 void runTest() { suite_MathFunctionsTest.testBinomialFactorialFunction(); }
} testDescription_suite_MathFunctionsTest_testBinomialFactorialFunction;

static class TestDescription_suite_MathFunctionsTest_testClampedCosine : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MathFunctionsTest_testClampedCosine() : CxxTest::RealTestDescription( Tests_MathFunctionsTest, suiteDescription_MathFunctionsTest, 34, "testClampedCosine" ) {}
 void runTest() { suite_MathFunctionsTest.testClampedCosine(); }
} testDescription_suite_MathFunctionsTest_testClampedCosine;

#include "vector_math/MatrixTest.h"

static MatrixTest suite_MatrixTest;

static CxxTest::List Tests_MatrixTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_MatrixTest( "/Users/bradanderson/projects/books/Real_Time_Rendering/graphicsEngine/graphicsEngine/graphicsTests/vector_math/MatrixTest.h", 7, "MatrixTest", suite_MatrixTest, Tests_MatrixTest );

static class TestDescription_suite_MatrixTest_testMatrix3Construction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_MatrixTest_testMatrix3Construction() : CxxTest::RealTestDescription( Tests_MatrixTest, suiteDescription_MatrixTest, 9, "testMatrix3Construction" ) {}
 void runTest() { suite_MatrixTest.testMatrix3Construction(); }
} testDescription_suite_MatrixTest_testMatrix3Construction;

#include "vector_math/VectorTest.h"

static VectorTest suite_VectorTest;

static CxxTest::List Tests_VectorTest = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_VectorTest( "/Users/bradanderson/projects/books/Real_Time_Rendering/graphicsEngine/graphicsEngine/graphicsTests/vector_math/VectorTest.h", 8, "VectorTest", suite_VectorTest, Tests_VectorTest );

static class TestDescription_suite_VectorTest_testSanity : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testSanity() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 10, "testSanity" ) {}
 void runTest() { suite_VectorTest.testSanity(); }
} testDescription_suite_VectorTest_testSanity;

static class TestDescription_suite_VectorTest_testVector2Construction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testVector2Construction() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 16, "testVector2Construction" ) {}
 void runTest() { suite_VectorTest.testVector2Construction(); }
} testDescription_suite_VectorTest_testVector2Construction;

static class TestDescription_suite_VectorTest_testVector3Construction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testVector3Construction() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 26, "testVector3Construction" ) {}
 void runTest() { suite_VectorTest.testVector3Construction(); }
} testDescription_suite_VectorTest_testVector3Construction;

static class TestDescription_suite_VectorTest_testVector4Construction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testVector4Construction() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 39, "testVector4Construction" ) {}
 void runTest() { suite_VectorTest.testVector4Construction(); }
} testDescription_suite_VectorTest_testVector4Construction;

static class TestDescription_suite_VectorTest_testStandardVector3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testStandardVector3() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 54, "testStandardVector3" ) {}
 void runTest() { suite_VectorTest.testStandardVector3(); }
} testDescription_suite_VectorTest_testStandardVector3;

static class TestDescription_suite_VectorTest_testEqualityOperator2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testEqualityOperator2() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 65, "testEqualityOperator2" ) {}
 void runTest() { suite_VectorTest.testEqualityOperator2(); }
} testDescription_suite_VectorTest_testEqualityOperator2;

static class TestDescription_suite_VectorTest_testEqualityOperator3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testEqualityOperator3() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 74, "testEqualityOperator3" ) {}
 void runTest() { suite_VectorTest.testEqualityOperator3(); }
} testDescription_suite_VectorTest_testEqualityOperator3;

static class TestDescription_suite_VectorTest_testEqualityOperator4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testEqualityOperator4() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 83, "testEqualityOperator4" ) {}
 void runTest() { suite_VectorTest.testEqualityOperator4(); }
} testDescription_suite_VectorTest_testEqualityOperator4;

static class TestDescription_suite_VectorTest_testPieceWiseVector2 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testPieceWiseVector2() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 93, "testPieceWiseVector2" ) {}
 void runTest() { suite_VectorTest.testPieceWiseVector2(); }
} testDescription_suite_VectorTest_testPieceWiseVector2;

static class TestDescription_suite_VectorTest_testPiecewiseVector3 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testPiecewiseVector3() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 101, "testPiecewiseVector3" ) {}
 void runTest() { suite_VectorTest.testPiecewiseVector3(); }
} testDescription_suite_VectorTest_testPiecewiseVector3;

static class TestDescription_suite_VectorTest_testPiecewiseVector4 : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testPiecewiseVector4() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 109, "testPiecewiseVector4" ) {}
 void runTest() { suite_VectorTest.testPiecewiseVector4(); }
} testDescription_suite_VectorTest_testPiecewiseVector4;

static class TestDescription_suite_VectorTest_testPerpendicular : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_VectorTest_testPerpendicular() : CxxTest::RealTestDescription( Tests_VectorTest, suiteDescription_VectorTest, 117, "testPerpendicular" ) {}
 void runTest() { suite_VectorTest.testPerpendicular(); }
} testDescription_suite_VectorTest_testPerpendicular;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
