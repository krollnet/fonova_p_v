#pragma once
#include <iostream>
#include <vector>
#include <unordered_set>
#include <chrono>

#define ms std::chrono::milliseconds
#define clock std::chrono::high_resolution_clock
#define ll long long

std::pair<ll, ll> runSolution2() {
	clock::time_point startTime = clock::now();

	int n = 0;
	std::cin >> n;
	std::vector<int> data(n, 0);
	for (int i = 0; i < n; i += 1) {
		std::cin >> data[i];
	}

	clock::time_point readyTime = clock::now();

	std::unordered_set<int> unique;
	unique.reserve(200000);
	int idx_unique = n;
	for (int i = n - 1; 0 <= i; i -= 1) {
		if (!unique.contains(data[i])) {
			idx_unique = data[i];
			unique.insert(idx_unique);
		}
	}
	std::cout << idx_unique;

	clock::time_point endTime = clock::now();

	ll inputDuration = std::chrono::duration_cast<ms>(readyTime - startTime).count();
	ll calcDuration = std::chrono::duration_cast<ms>(endTime - readyTime).count();
	return std::make_pair(inputDuration, calcDuration);
}