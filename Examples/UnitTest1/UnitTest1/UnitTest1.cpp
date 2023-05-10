#include "pch.h"
#include "CppUnitTest.h"
#include "ngmgDynamicLibrary.h"
#include "ngmgDynamicLibrary.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			int a = 5;
			int b = 3;
			int sum = a + b;
			
			Assert::AreEqual(Sum(a,b), sum);
		}

		TEST_METHOD(TestMethod2)
		{
			int a = 5;
			int b = 3;
			int sum = a + a;

			Assert::AreEqual(Sum(a, b), sum);
		}
	};
}
