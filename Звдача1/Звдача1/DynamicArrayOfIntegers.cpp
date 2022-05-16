#include "DynamicArrayOfIntegers.h"
#include <iostream>

using namespace std;

DynamicArrayOfIntegers::DynamicArrayOfIntegers() {
	size = 0;
	data = new int[0];
}
DynamicArrayOfIntegers::DynamicArrayOfIntegers(int _size) {
	size = _size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = 0;
	}
}
DynamicArrayOfIntegers::DynamicArrayOfIntegers(int _size, int n) {
	size = _size;
	data = new int[size];
	for (int i = 0; i < size; i++) {
		data[i] = n;
	}
}
DynamicArrayOfIntegers::DynamicArrayOfIntegers(const DynamicArrayOfIntegers& x) : size(x.size), data(new int[x.size]) {
	copy(x.data, x.data + size, data);
}
DynamicArrayOfIntegers::DynamicArrayOfIntegers(DynamicArrayOfIntegers&& x) : size(0), data(nullptr) {
	size = x.size;
	data = x.data;
	x.size = 0;
	x.data = nullptr;
}
DynamicArrayOfIntegers::~DynamicArrayOfIntegers() {
	delete[] data;
}
int DynamicArrayOfIntegers::getSize() {
	return size;
}
const int DynamicArrayOfIntegers::operator[](int i) {
	if (i < 0 || i > size) {
		throw invalid_argument("i > size");
	}
	return data[i];
}
void DynamicArrayOfIntegers::resize(int newSize) {
	int* newData;
	if (newSize > size) {
		newData = new int[newSize];
		for (int i = 0; i < size; i++) {
			newData[i] = data[i];
		}
		for (int i = size; i < newSize; i++) {
			newData[i] = 0;
		}
	}
	else {
		newData = new int[newSize];
		for (int i = 0; i < newSize; i++) {
			newData[i] = data[i];
		}
	}
	size = newSize;
	delete[] data;
	data = newData;
}
DynamicArrayOfIntegers& DynamicArrayOfIntegers::operator=(const DynamicArrayOfIntegers&& x) {
	if (this != &x) {
		delete[] data;
		size = x.size;
		data = new int[size];
		copy(x.data, x.data + size, data);
	}
	return *this;
}
DynamicArrayOfIntegers& DynamicArrayOfIntegers::operator=(DynamicArrayOfIntegers&& x) {
	if (this != &x) {
		delete[] data;
		data = x.data;
		size = x.size;
		x.data = nullptr;
		x.size = 0;
	}
	return *this;
}
bool operator==(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y) {
	if (x.size != y.size) {
		throw "different sizes";
	}
	for (int i = 0; i < x.size; ++i)
	{
		if (x.data[i] != y.data[i]) {
			return false;
		}
	}
	return true;
}
bool operator!=(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y) {
	if (x.size != y.size) {
		throw "different sizes";
	}
	for (int i = 0; i < x.size; ++i)
	{
		if (x.data[i] == y.data[i]) {
			return false;
		}
	}
	return true;
}
bool operator<(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y) {
	int size;
	if (x.size <= y.size) {
		size = x.size;
	}
	else {
		size = y.size;
	}
	for (int i = 0; i < size; i++) {
		if (x.data[i] < y.data[i]) {
			return true;
		}
	}
	if (x.size < y.size) {
		return true;
	}
	return false;
}
bool operator>(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y) {
	int size;
	if (x.size <= y.size) {
		size = x.size;
	}
	else {
		size = y.size;
	}
	for (int i = 0; i < size; i++) {
		if (x.data[i] > y.data[i]) {
			return true;
		}
	}
	if (x.size > y.size) {
		return true;
	}
	return false;
}
bool operator<=(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y) {
	int size;
	if (x.size <= y.size) {
		size = x.size;
	}
	else {
		size = y.size;
	}
	for (int i = 0; i < size; i++) {
		if (x.data < y.data) {
			return true;
		}
	}
	if (x.size <= y.size) {
		return true;
	}
	return false;
}
bool operator>=(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y) {
	int size;
	if (x.size <= y.size) {
		size = x.size;
	}
	else {
		size = y.size;
	}
	for (int i = 0; i < size; i++) {
		if (x.data > y.data) {
			return true;
		}
	}
	if (x.size >= y.size) {
		return true;
	}
	return false;
}
DynamicArrayOfIntegers operator+(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y) {
	int size;
	size = x.size + y.size;
	DynamicArrayOfIntegers res = DynamicArrayOfIntegers(size);
	for (int i = 0; i < x.size; i++) {
		res.data[i] = x.data[i];
	}
	for (int i = 0; i < y.size; i++) {
		res.data[x.size + i] = y.data[i];
	}
	return res;
}
ostream& operator<<(ostream& os, const DynamicArrayOfIntegers& x) {
	os << x.size << endl;
	for (int i = 0; i < x.size; i++) {
		os << x.data[i] << " ";
	}
	return os;
}
istream& operator>>(istream& in, DynamicArrayOfIntegers& x) {
	in >> x.size;
	for (int i = 0; i < x.size; i++) {
		in >> x.data[i];
	}
	return in;
}
