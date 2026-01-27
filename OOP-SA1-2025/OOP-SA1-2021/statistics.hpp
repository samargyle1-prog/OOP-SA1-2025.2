#pragma once

#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include "math.h"
#include <numeric>

class Statistics
{

public:
	/*
		Currently the signatures here are returning a value to allow the tests for the 3rd to run (and fail),
		you will need to replace the { return 0.0;} with a ; and implement the methods correctly below the
		class definition to allow the code to pass.

		To run test right click on the the test in the test explorer. Go to the test menu and select test explorer if it
		isn't visible.

		the 2.2 tests and the 2.1 tests will not compile until you write at least the signatures with an appropriate return
		value.
	*/

	/* 3rd */
	// implement the method to return the sum of the values
	long double sum(std::vector<double> const& v);

	// implement the method to return the mean of the values
	long double mean(std::vector<double> const& v);

	// implement the method to return the min of the values
	double min(std::vector<double> const& v);

	// implement the method to return the max of the values
	double max(std::vector<double> const& v);

	//2.2


	// 2.1
	// implement the method to return the subtotals map
	std::map<double, long double> subTotals(const std::vector<double>& data);

	// implement the method to return the frequency map
	std::map<double, long double> frequency(const std::vector<double>& data);

	// implement the method to return the mode map
	std::map<double, long double> mode(const std::vector<double>& data);

	// implement the method to return the median value
	std::map<double, long double> median(const std::vector<double>& data);

	//1st 


	/*
			Test data used is as follows { 2.6, 5555.9999, 12.0, 90.0, 90.0, 40, 11, 453.879, 12, 12, 90, 8 }

			Expected results from this data:

			Sum			6377.48
			Mean		531.457
			Min			2.6
			Max			5556
			Std. Dev.	1519.6576
			Unique Vals { 2.6, 8.0, 11.0, 12.0, 40.0, 90.0, 453.879, 5555.9999 }
			Outliers	1
			Mode		{ 12.0, 90.0 }
			Median		26.0
			Frequency	{ 2.6,			1 }
						{ 8.0,			1 }
						{ 11.0,			1 }
						{ 12.0,			3 }
						{ 40.0,			1 }
						{ 90.0,			3 }
						{ 453.879,		1 }
						{ 5555.9999,	1 }
			Subtotals	{ 2.6,			2.6 }
						{ 8.0,			8.0 }
						{ 11.0,			11.0 }
						{ 12.0,			36.0 }
						{ 40.0,			40.0 }
						{ 90.0,			270.0 }
						{ 453.879,		453.879 }
						{ 5555.9999,	5555.9999 }

		*/
		/* write your method implementations here!*/
		//3rd
		// implement the method to return the sum of the values
	long double sum(const std::vector<long double>& data) {
		long double total = 0;
		for (auto v : data) total += v;
		return total;
	}

	// implement the method to return the mean of the values
	long double mean(const std::vector<long double>& data) {
		if (data.empty()) return 0;
		return sum(data) / data.size();
	}
	// implement the method to return the min of the values
	double min(const std::vector<long double>& data) {
		if (data.empty()) return 0;
		return *std::min_element(data.begin(), data.end());
	}
	// implement the method to return the max of the values
	double max(const std::vector<long double>& data) {
		if (data.empty()) return 0;
		return *std::max_element(data.begin(), data.end());
	}

	//2.1
	// implement the method to return the subtotals map
	std::map<double, long double> Statistics::subTotals(const std::vector<double>& data) {
		std::map<double, long double> result;
		for (const auto& value : data) {
			result[value] += value;
		}
		return result;
	}
	// implement the method to return the frequency map
	std::map<double, long double> Statistics::frequency(const std::vector<double>& data) {
		std::map<double, long double> freqMap;
		for (const auto& value : data) {
			++freqMap[value];
		}
		return freqMap;
	}
};
}