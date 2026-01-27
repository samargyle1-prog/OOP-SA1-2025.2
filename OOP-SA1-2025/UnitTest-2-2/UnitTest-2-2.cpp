#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA1-2021/statistics.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest22
{
	TEST_CLASS(UnitTest22)
	{
	private:
		Statistics s;

		std::vector<double> vectData{ 2.6,5555.9999, 12.0, 90.0, 90.0, 40, 11, 453.879, 12, 12, 90, 8 };

	public:
		
		TEST_METHOD(SDeviation)
		{
			long double result = this->s.standardDeviation(this->vectData);
			Assert::AreEqual(1519.6576, result, 0.0001, L"Standard Deviation method did not fnd the SD correctly.");
		}

		TEST_METHOD(Outliers)
		{
			std::vector<double> outlierData(vectData);
			std::size_t result = s.stripOutliers(outlierData, 1);
			Assert::AreEqual((std::size_t)1, result, L"Strip outlier method did not find the correct number of outliers.");
		}

		TEST_METHOD(UniqueValues)
		{
			std::vector<double> testData{ 2.6000000000000001,
											8.0000000000000000,
											11.000000000000000,
											12.000000000000000,
											40.000000000000000,
											90.000000000000000,
											453.87900000000002,
											5555.9998999999998 };
			std::vector<double> uniqueData(vectData);

			s.uniqueValues(uniqueData);
			bool result = (testData == uniqueData);

			Assert::AreEqual(true, result, L"Unique method did not give a unique list of values.");
		}

		TEST_METHOD(ExceptionSum)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Statistics localStatistics;
				long double result = localStatistics.sum(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Sum failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionMin)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Statistics localStatistics;
				long double result = localStatistics.min(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Min failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionMean)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Statistics localStatistics;
				long double result = localStatistics.mean(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Mean failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionMax)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Statistics localStatistics;
				long double result = localStatistics.max(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Max failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionSD)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Statistics localStatistics;
				long double result = localStatistics.standardDeviation(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"Standard Deviation failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionUniqueValues)
		{
			auto func = [] {
				std::vector<double> emptyVector;

				Statistics localStatistics;
				localStatistics.uniqueValues(emptyVector);
			};

			Assert::ExpectException<std::invalid_argument>(func, L"UniqueValues failed to to throw and exception when passed an empty vector.");
		}

		TEST_METHOD(ExceptionOutliersAboveThree)
		{
			auto func = [] {
				
				std::vector<double> fullVector{ 2.6,5555.9999, 12.0, 90.0, 90.0, 40, 11, 453.879, 12, 12, 90, 8 };

				Statistics localStatistics;
				std::size_t result = localStatistics.stripOutliers(fullVector, 4);
			};

			Assert::ExpectException<std::range_error>(func, L"Strip Outliers failed to to throw and exception when passed a outlier count of 4 or more.");
		}

		TEST_METHOD(ExceptionOutliersNegative)
		{
			auto func = [] {

				std::vector<double> fullVector{ 2.6,5555.9999, 12.0, 90.0, 90.0, 40, 11, 453.879, 12, 12, 90, 8 };

				Statistics localStatistics;
				std::size_t result = localStatistics.stripOutliers(fullVector, -1);
			};

			Assert::ExpectException<std::range_error>(func, L"Strip Outliers failed to to throw and exception when passed a negative outlier count.");
		}

	};
}
