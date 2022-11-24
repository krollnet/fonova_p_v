#pragma once
#include <string>
#include <fstream>
#include <ctime>

const int RANDOM_FROM = 0;
const int RANDOM_TO = 200'000;


void generateTest(size_t size, std::string filename) {
	std::ofstream file(filename);
	srand((unsigned)time(NULL));
	int x;

	file << size;
	file << '\n';
	while (size--) {
		x = rand() % (RANDOM_TO - RANDOM_FROM + 1) + RANDOM_FROM;
		file << x;
		if (size) {
			file << ' ';
		}
 	}
	file << '\n';

	file.close();
}