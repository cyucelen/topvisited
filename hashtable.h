#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "entry.h"
#include "minheap.h"

class HashTable{
private:
	int size;
	Entry **table;
	int *indexes;
	int length;
public:
	explicit HashTable(const int &size = 100);
	int getLength() const;
	void pushToTable(const std::string&);
	unsigned long hash(const std::string&) const;
	void print() const;
	void printTopTen() const;
	~HashTable();
};

#endif