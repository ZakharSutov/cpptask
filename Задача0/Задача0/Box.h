#pragma once

#ifndef __BOX_H__
#define __BOX_H__
#include <iostream>

using namespace std;

class Box
{
private:
	int length, width, height, value;
	double weight;
public:
	Box(int _length, int _width, int _height, int _value, double _weight);
	Box();
	int getLength();
	int getWidth();
	int getHeight();
	int getValue();
	double getWeight();
	void setLength(int length);
	void setWidth(int width);
	void setHeight(int height);
	void setValue(int value);
	void setWeight(double weight);
	int sumValue(Box* arrBox, int size);
	bool compareSum(Box* arrBox, int x, int size);
	double maxWeight(Box* arrBox, int maxV, int size);
	bool matryoshka(Box* arrBox, int size);
	friend bool operator==(Box b1, Box b2);
	friend ostream& operator<<(ostream& os, const Box& x);
	friend istream& operator>>(istream& in, Box& x);
};
#endif