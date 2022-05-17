#pragma once
#include <iostream>

using namespace std;

class DynamicArrayOfIntegers
{
private:
	int size;
	int* data;
public:
	DynamicArrayOfIntegers();
	DynamicArrayOfIntegers(int _size);
	DynamicArrayOfIntegers(int _size, int n);
	DynamicArrayOfIntegers(const DynamicArrayOfIntegers& x);
	DynamicArrayOfIntegers(DynamicArrayOfIntegers&& x);
	~DynamicArrayOfIntegers();
	int getSize();
	const int operator[](int i);
	void resize(int newSize);
	DynamicArrayOfIntegers& operator=(const DynamicArrayOfIntegers& x);
	DynamicArrayOfIntegers& operator=(DynamicArrayOfIntegers&& x);
	friend bool operator==(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y);
	friend bool operator!=(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y);
	friend bool operator<(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y);
	friend bool operator>(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y);
	friend bool operator<=(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y);
	friend bool operator>=(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y);
	friend DynamicArrayOfIntegers operator+(DynamicArrayOfIntegers x, DynamicArrayOfIntegers y);
	friend ostream& operator<<(ostream& os, const DynamicArrayOfIntegers& x);
	friend istream& operator>>(istream& in, DynamicArrayOfIntegers& x);
};

