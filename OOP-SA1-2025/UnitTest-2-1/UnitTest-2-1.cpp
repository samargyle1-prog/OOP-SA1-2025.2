#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA1-2021/statistics.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest21
{
	TEST_CLASS(UnitTest21)
	{
	private:
		Statistics s;

		std::vector<double> vectData{ 2.6,5555.9999, 12.0, 90.0, 90.0, 40, 11, 453.879, 12, 12, 90, 8 };
		std::vector<long double> longVectData{ 2.6,5555.9999, 12.0, 90.0, 90.0, 40, 11, 453.879, 12, 12, 90, 8 };
	
	public:
		
		TEST_METHOD(SubTotals)
		{
			std::map<double, long double> sMap;
			sMap = s.subTotals(vectData);
			std::map<double, long double> testMap{
				{ 2.6000000000000001,	2.6000000000000001},
				{ 8.0000000000000000,	8.0000000000000000 },
				{ 11.000000000000000,	11.000000000000000 },
				{ 12.000000000000000,	36.000000000000000 },
				{ 40.000000000000000,	40.000000000000000 },
				{ 90.000000000000000,	270.00000000000000 },
				{ 453.87900000000002,	453.87900000000002 },
				{ 5555.9998999999998,	5555.9998999999998 } };

			bool result = (sMap == testMap);
			Assert::AreEqual(true, result, L"Sub totalling method did not give a unique list of values with correct totals.");

		}

		TEST_METHOD(Frequency)
		{
			std::map<double, long> fMap;
			fMap = s.frequency(vectData);
			std::map<double, long> testMap{
				{ 2.6000000000000001,	1 },
				{ 8.0000000000000000,	1 },
				{ 11.000000000000000,	1 },
				{ 12.000000000000000,	3 },
				{ 40.000000000000000,	1 },
				{ 90.000000000000000,	3 },
				{ 453.87900000000002,	1 },
				{ 5555.9998999999998,	1 } };

			bool result = (fMap == testMap);
			Assert::AreEqual(true, result, L"Frequency method did not give a unique list of values with correct totals.");
		}

		TEST_METHOD(Mode)
		{
			std::vector<double> modeValues;
			std::vector<double> testData{ 12.0, 90.0 };

			modeValues = s.mode(vectData);

			bool result = (testData == modeValues);

			Assert::AreEqual(true, result, L"Unique method did not give a unique list of values.");
		}

		TEST_METHOD(Median)
		{
			double result = this->s.median(this->vectData);
			Assert::AreEqual(26.0, result, 0.001, L"Median method did not fnd the median value correctly.");
		}

		TEST_METHOD(LongSum)
		{
			long double result = this->s.sum(this->longVectData);
			Assert::AreEqual(6377.48, result, 0.002, L"Long Sum method did not total the values correctly.");
		}

		TEST_METHOD(LongMean)
		{
			long double result = this->s.mean(this->longVectData);
			Assert::AreEqual(531.457, result, 0.001, L"Long Mean method did not average the values correctly.");
		}

		TEST_METHOD(LongMin)
		{
			long double result = this->s.min(this->longVectData);
			Assert::AreEqual(2.6, result, 0.001, L"Long Min method did not fnd the lowest value.");
		}

		TEST_METHOD(LongMax)
		{
			long double result = this->s.max(this->longVectData);
			Assert::AreEqual(5556, result, 0.001, L"Long Max method did not fnd the highest value correctly.");
		}
	};
}
