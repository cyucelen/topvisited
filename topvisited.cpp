#include <iostream>
#include <chrono>
#include <fstream>
#include <string>
#include"hashtable.h"

#define SIZE 100000

int main(){
	auto start = std::chrono::system_clock::now();
	HashTable ht(SIZE);
	std::string line;
	std::ifstream stream("access_log");

	while (std::getline(stream, line)) {
		unsigned first = line.find("GET ");
		unsigned last = line.find(" ", first + 4);
		std::string strNew = line.substr(first + 4, last - first - 4);
		ht.pushToTable(strNew);
	}

	stream.close();
	ht.printTopTen();
	auto end = std::chrono::system_clock::now();

	std::chrono::duration<double> elapsedTime = end - start;
	std::cout << std::fixed << elapsedTime.count() << "s" << std::endl;
	std::getchar();
	return 0;
}