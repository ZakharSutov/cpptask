#pragma once

#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <iostream>
#include <vector>
#include "Box.h"

using namespace std;

class Container
{
private:
	int length;
	int width;
	int height;
	double weight;
	vector<Box> boxs;
public:
	Container(int length, int width, int height, double weight);

	int setBox(Box box);

	void deleteBox(int i);

	int getSize();

	double sumWeight();

	int sumValue();

	Box getBox(int i);

	friend ostream& operator<<(ostream& os, const Container& x);

	friend istream& operator>>(istream& in, Container& x);

	const Box& operator[](int i) {
		int size = boxs.size();
		if (i < 0 || i > size) {
			throw invalid_argument("i > size");
		}
		return boxs.at(i); 
	}
};
#endif

