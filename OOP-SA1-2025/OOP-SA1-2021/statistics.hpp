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
	long double sum(std::vector<double> const& v) {
		long double totalValue = std::accumulate(v.begin(), v.end(), 0.0L);
		return totalValue;
	}
	long double mean(std::vector<double> const& v) { return 0.0; }
	double min(std::vector<double> const& v) { return 0.0; }
	double max(std::vector<double> const& v) { return 0.0; }

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
		

};
/* write your method implementations here!
// implement the method to return the sum of the values
long double sum(std::vector<double> const& v) {
	long double totalValue = std::accumulate(v.begin(), v.end(), 0.0L);
	return totalValue;
}
// implement the method to return the mean of the values
long double mean(std::vector<double> const& v) {
	long double totalValue = std::accumulate(v.begin(), v.end(), 0.0L);
	long double meanValue = totalValue / v.size();
    return meanValue;
}

// implement the method to return the min of the values
double min(std::vector<double> const& v) {
	double minValue = std::min_element(v.begin(), v.end());
	return minValue;
}
// implement the method to return the max of the values
double max(std::vector<double> const& v) {
	double maxValue = std::max_element(v.begin(), v.end());
	return maxValue;
}

//2.2
// implement the method to return the standard deviation of the values
long double SDeviation(std::vector<double> const& v) {
	long double totalValue = std::accumulate(v.begin(), v.end(), 0.0L);
	long double meanValue = totalValue / v.size();
	long double std.Dev = 0.0;
	return std.Dev;
}
// implement the method to return the unique values from the vector
void UniqueValues(std::vector<double> const& v) {
	std::sort(v.begin(), v.end());
	auto last = std::unique(v.begin(), v.end());
	v.erase(last, v.end());
}
// implement the method to return the number of outliers from the vector
void Outliers(std::vector<double> const& v) {
	double outlierCount = 0;
	return outlierCount;
}
//2.1
// implement the method to return the mode values from the vector
std::vector<double> Mode(std::vector<double> const& v) {
	std::vector<double> modeValues;
	return modeValues;
}
// implement the method to return the frequency map from the vector
std::map<double, long> Frequency(std::vector<double> const& v) {
	std::map<double, long> freqMap;
	return freqMap;
}
// implement the method to return the median value from the vector
double Median(std::vector<double> const& v) {
	double medianValue = 0.0;
	return medianValue;
}
*/
