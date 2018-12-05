#include "hashtable.h"
#include <iostream>
#include <string>
#include <fstream>

std::ofstream myfile;

HashTable::HashTable(const int &size):
	size(size),
	length(0)
{
	indexes = new int[size];
	table = new Entry*[size];
	for (int i = 0; i < size; i++) {
		table[i] = NULL;
	}
}

unsigned long HashTable::hash(const std::string &str) const{
	unsigned long h = 5381;
	unsigned c;
	for (c = 0; c < str.size(); c++) {
		h = (h << 5) + h + (int)str[c];
	}
	return h;
}

void HashTable::pushToTable(const std::string &key) {
	unsigned long h = hash(key);
	int index = h % size;

	indexes[length] = index;

	if (table[index] == NULL) {
		table[index] = new Entry(key, 1);
		length++;
	}else {
		Entry *iter = table[index];
		while (iter->getKey() != key && iter->getLink() != NULL) {
			iter = iter->getLink();
		}
		if (iter->getKey() != key) {
			Entry *item = new Entry(key, 1);
			iter->setLink(item);
		}else {
			iter->incrementValue();
		}
	}
}

void HashTable::print() const {
	myfile.open("ex.txt");
	for (int i = 0; i < size; i++) {
		if (table[i] != NULL) {
			Entry *iter = table[i];
			while (iter != NULL) {
				myfile << "Key : " << iter->getKey() << " | Value : " << iter->getValue() << std::endl;
				iter = iter->getLink();
			}
		}	
	}
}

void HashTable::printTopTen() const {
	MinHeap mh(10);

	int pushCount = 0;
	for (int i = 0; i < length; i++) {
		Entry *iter = table[indexes[i]];
		while (iter != NULL) {
			if (pushCount < 10) {
				mh.insert(*iter);
				pushCount++;
			}else {
				mh.insertAsMin(*iter);
			}
			iter = iter->getLink();
		}
	}
	mh.printSorted();
}

int HashTable::getLength() const {
	return length;
}

HashTable::~HashTable(){}
