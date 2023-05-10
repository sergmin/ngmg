#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Black\Git\ngmg\Sources\ngmg\ngmgDynamicLibrary\ngmgDynamicLibrary.h"
#include "C:\Black\Git\ngmg\Sources\ngmg\ngmg\pch.h"
#include "C:\Black\Git\ngmg\Sources\ngmg\ngmgDynamicLibrary\ngmgDynamicLibrary.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

int main()
{
	return 0;
}

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
