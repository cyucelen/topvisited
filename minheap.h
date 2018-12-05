#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include "entry.h"

class MinHeap{
private:
	Entry *arr;
	Entry *sorted;
	int capacity;
	int size;

	void swap(Entry&, Entry&);
	void sort();
	void heapify();
public:
	explicit MinHeap(const int &capacity = 100);
	int parent(const int&) const;
	int left(const int&) const;
	int right(const int&) const;
	void insert(const Entry&);
	void insertAsMin(const Entry&);
	void printSorted();
	~MinHeap();
};

#endif