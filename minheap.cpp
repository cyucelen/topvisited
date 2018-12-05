#include "minheap.h"
#include <iostream>
#include <string>

MinHeap::MinHeap(const int& capacity):
	capacity(capacity),
	size(0)
{
	arr = new Entry[capacity];
	sorted = new Entry[capacity];
}

int MinHeap::parent(const int &i) const{
	return (i - 1) / 2;
}

int MinHeap::left(const int &i) const{
	return (2 * i + 1);
}

int MinHeap::right(const int &i) const{
	return (2 * i + 2);
}

void MinHeap::swap(Entry &x, Entry &y) {
	Entry temp = x;
	x = y;
	y = temp;
}

void MinHeap::insert(const Entry& e) {
	size++;
	int i = size - 1;
	arr[i] = e;
	while (i != 0 && arr[parent(i)].getValue() > arr[i].getValue()) {
		MinHeap::swap(arr[parent(i)], arr[i]);
		i = parent(i);
	}
}

void MinHeap::heapify() {
	int index = 0;
	for (int i = 1; i < size; i *= 2) {
		int indexVal = arr[index].getValue();
		bool rightExist = right(index) < size;
		bool leftExist = left(index) < size;
		int rightVal;
		int leftVal;
		if (rightExist) rightVal = arr[right(index)].getValue();
		if (leftExist) leftVal = arr[left(index)].getValue();

		if (rightExist || leftExist) {
			if (rightExist && indexVal > rightVal && leftExist && indexVal > leftVal) {
				if (leftVal < rightVal) {
					swap(arr[index], arr[left(index)]);
					index = left(index);
				}
				else {
					swap(arr[index], arr[right(index)]);
					index = right(index);
				}
			}
			else if (leftExist && indexVal > leftVal) {
				swap(arr[index], arr[left(index)]);
				index = left(index);
			}
			else if (rightExist && indexVal > rightVal) {
				swap(arr[index], arr[right(index)]);
				index = right(index);
			}
		}
	}
}

void MinHeap::insertAsMin(const Entry& e) {
	if (e.getValue() > arr[0].getValue()) {
		arr[0] = e;
		heapify();
	}
}

void MinHeap::sort() {
	int s = size;
	
	for (int i = 0; i < s; i++) {
		sorted[i] = arr[0];
		swap(arr[0], arr[size-1]);
		size--;
		heapify();
	}
	size = s;
}


void MinHeap::printSorted() {
	sort();
	for (int i = 1; i <= size; i++) {
		std::cout << "Key : " << sorted[size - i].getKey() << " | Value : " << sorted[size - i].getValue() << std::endl;
	}
}

MinHeap::~MinHeap(){}