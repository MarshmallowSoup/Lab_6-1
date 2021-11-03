#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6-1/Lab_6-1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:	
		TEST_METHOD(TestMethod1)
		{
			const int n = 4;
			int c[n] = {1,2,3,4};
			int k = Sum(c, n);
			Assert::AreEqual(10, k);

		}
		TEST_METHOD(TestMethod2)
		{
			const int n = 4;
			int c[n] = { 4,2,1,7 };
			QuickSort(c, 0,3);
			Assert::AreEqual(4, c[2]);

		}
	};
}
