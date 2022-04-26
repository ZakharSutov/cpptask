#pragma once
#include <iostream>
#include <vector>
#include "Box.h"
#include "Container.h"

//using namespace std;

namespace BoxContainer 
{
	namespace box 
	{
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
		};
		bool operator==(Box b1, Box b2);
		ostream& operator<<(ostream& os, const Box& x);
		istream& operator>>(istream& in, Box& x);
	}

	namespace container
	{
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
			const Box& operator[](int i);
		};
		ostream& operator<<(ostream& os, const Container& x);
		istream& operator>>(istream& in, Container& x);
		
	}
}
