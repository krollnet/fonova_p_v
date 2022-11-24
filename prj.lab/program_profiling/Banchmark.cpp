#include "solution1.h"
#include "solution2.h"

#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <vector>
#include <limits>
#include <algorithm>

#include "generator.h"

#define ll long long

struct TStatistica {
	ll minimal = std::numeric_limits<ll>::min();
	ll maximal = std::numeric_limits<ll>::max();
	ll mean = 0;
	ll std = std::numeric_limits<ll>::max();
	size_t size = 0;
	
	TStatistica(std::vector<ll> vec) {
		this->size = vec.size();
		if (vec.empty()) {
			return;
		}
		ll summa = 0;
		this->minimal = std::numeric_limits<ll>::max();
		this->maximal = std::numeric_limits<ll>::min();
		for (auto val : vec) {
			this->minimal = std::min(this->minimal, val);
			this->maximal = std::max(this->maximal, val);
			summa += val;
		}
		this->mean = summa / this->size;
		if (this->size > 1) {
			ll summaSq = 0;
			for (auto val : vec) {
				summaSq += (val - this->mean) * (val - this->mean);
			}
			this->std = summaSq / (this->size - 1);
		}
	}

	void print() {
		std::cout << "Среднее: " << this->mean << '±' << this->std << " мс";
		std::cout << " \tМинимум: " << this->minimal << " мс";
		std::cout << " \tМаксимум: " << this->maximal << " мс" << std::endl;
	}
};

const int test_sizes[] = {1, 10, 100, 1000, 10000, 100000, 200000};

void testSolution(size_t size, size_t count=7) {
	std::string filename_in = "input.txt";
	std::string filename_out = "output.txt";
	std::vector<ll> inputTimes, calcTimes, totalTimes;

	std::cout << "##########################################" << std::endl;
	std::cout << "ТЕСТ РЕШЕНИЯ solution1 С РАЗМЕРОМ " << size << std::endl;
	for (size_t i = 1; i <= count; ++i) {
		generateTest(size, filename_in);
		std::ifstream fin(filename_in);
		std::streambuf* cinbuf = std::cin.rdbuf();
		std::cin.rdbuf(fin.rdbuf());
		std::ofstream fout(filename_out);
		std::streambuf* coutbuf = std::cout.rdbuf();
		std::cout.rdbuf(fout.rdbuf());

		std::pair<ll, ll> times = runSolution1();
		ll totalTime = times.first + times.second;
		inputTimes.push_back(times.first);
		calcTimes.push_back(times.second);
		totalTimes.push_back(totalTime);

		std::cin.rdbuf(cinbuf);
		std::cout.rdbuf(coutbuf);
		std::cout << '\t' << i << ")\t";
		std::cout << "Считывание: \t" << times.first << " мс   ";
		std::cout << "Алгоритм: \t" << times.second << " мс   ";
		std::cout << "Всего: \t" << totalTime << " мс   " << std::endl;
	}
	TStatistica inputStats(inputTimes), calcStats(calcTimes), totalStats(totalTimes);
	std::cout << "СЧИТЫВАНИЕ ДАННЫХ     ";
	inputStats.print();
	std::cout << "АЛГОРИТМИЧЕСКАЯ ЧАСТЬ ";
	calcStats.print();
	std::cout << "ИТОГОВОЕ ВРЕМЯ        ";
	totalStats.print();
	std::cout << "##########################################" << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	testSolution(100);
	
}
