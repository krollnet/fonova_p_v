#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <chrono>

#define ms std::chrono::milliseconds
#define clock std::chrono::high_resolution_clock
#define ll long long

std::pair<ll, ll> runSolution1() {
	clock::time_point startTime = clock::now();

	int n = 0;
	std::cin >> n;
	std::vector<int> as(200001, -1);
	for (int i = 0; i < n; i += 1) {
		int idx = 0;
		std::cin >> idx;
		as[idx] = n - i - 1;
	}

	clock::time_point readyTime = clock::now();

	std::cout << std::distance(
		as.begin(),
		std::max_element(as.begin(), as.end())
	);

	clock::time_point endTime = clock::now();

	ll inputDuration = std::chrono::duration_cast<ms>(readyTime - startTime).count();
	ll calcDuration = std::chrono::duration_cast<ms>(endTime - readyTime).count();
	return std::make_pair(inputDuration, calcDuration);
}