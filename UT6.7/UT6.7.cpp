#include "pch.h"
#include "CppUnitTest.h"
#include "../PKR6.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UT67
{
	TEST_CLASS(UT67)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL,
				* last = NULL;

			for (int i = 0; i < 2; i++)
			{
				enqueue(first, last, 2);
			}

			Assert::AreEqual(first->info, 2);
		}
	};
}