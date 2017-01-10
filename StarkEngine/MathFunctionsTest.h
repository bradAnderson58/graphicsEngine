#pragma once

#include <cxxtest/TestSuite.h>
#include "MathFunctions.h"

class MathFunctionsTest : public CxxTest::TestSuite {
public:
	void testFactorialFunction(void) {

		// some simple tet cases
		int f5 = MathFunctions::factorial(5);
		int f6 = MathFunctions::factorial(6);
		int f11 = MathFunctions::factorial(11);

		TS_ASSERT_EQUALS(f5, 120);
		TS_ASSERT_EQUALS(f6, 720);
		TS_ASSERT_EQUALS(f11, 39916800);
	}

	void testBinomialFactorialFunction(void) {

		// some test cases
		int _10Choose2 = MathFunctions::binomialFactorial(10, 2);
		int _6Choose4 = MathFunctions::binomialFactorial(6, 4);
		int _5Choose5 = MathFunctions::binomialFactorial(5, 5);
		int _4Choose6 = MathFunctions::binomialFactorial(4, 6);

		TS_ASSERT_EQUALS(_10Choose2, 45);
		TS_ASSERT_EQUALS(_6Choose4, 15);
		TS_ASSERT_EQUALS(_5Choose5, 1);
		TS_ASSERT_EQUALS(_4Choose6, 0);
	}

	void testClampedCosine(void) {
		float cos5 = MathFunctions::clampedCos(5.0f);
		float cos10 = MathFunctions::clampedCos(10.0f);

		double diff = fabs(cos5 - cos(5));
		TS_ASSERT(diff < FLT_EPSILON);
		TS_ASSERT_EQUALS(cos10, 0);
	}
};