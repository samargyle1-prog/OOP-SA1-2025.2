#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA1-2021/statistics.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3rd
{
	TEST_CLASS(UnitTest3rd)
	{

	private:
		
		Statistics s;

		std::vector<double> vectData{ 2.6,5555.9999, 12.0, 90.0, 90.0, 40, 11, 453.879, 12, 12, 90, 8 };

	public:
		
		TEST_METHOD(Sum)
		{			
			long double result = this->s.sum(this->vectData);
			Assert::AreEqual(6377.48, result, 0.002, L"Sum method did not total the values correctly.");
		}

		TEST_METHOD(Mean)
		{
			long double result = this->s.mean(this->vectData);
			Assert::AreEqual(531.457, result, 0.001, L"Mean method did not average the values correctly.");
		}

		TEST_METHOD(Min)
		{
			double result = this->s.min(this->vectData);
			Assert::AreEqual(2.6, result, 0.001, L"Min method did not fnd the lowest value.");
		}

		TEST_METHOD(Max)
		{
			double result = this->s.max(this->vectData);
			Assert::AreEqual(5556, result, 0.001, L"Max method did not fnd the highest value correctly.");
		}

	};
}
