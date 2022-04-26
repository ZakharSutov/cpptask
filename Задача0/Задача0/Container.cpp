#include "Container.h"
#include <iostream>

using namespace std;

Container::Container(int _length, int _width, int _height, double _weight) {
	length = _length;
	width = _width;
	height = _height;
	weight = _weight;
}

int Container::setBox(Box box) {
	if (sumWeight() + box.getWeight() > weight) {
		throw "does not fit";
	}
	boxs.push_back(box);
	return boxs.size() - 1;
}

void Container::deleteBox(int i) {
	boxs.erase(boxs.begin() + i);
}

int Container::getSize() {
	return boxs.size();
}

double Container::sumWeight() {
	double sum = 0;
	for (auto& b : boxs) {
		sum += b.getWeight();
	}
	return sum;
}

int Container::sumValue() {
	int sum = 0;
	for (auto& b : boxs) {
		sum += b.getValue();
	}
	return sum;
}

Box Container::getBox(int i) {
	return boxs.at(i);
}

ostream& operator<<(ostream& os, const Container& x) {
	os << x.length << " " << x.width << " " << x.height << " " << x.weight << endl;
	for (auto b : x.boxs) {
		os << b.getLength() << " " << b.getWidth() << " " << b.getHeight() << " " << b.getWeight() << endl;
	}
	return os;
}

istream& operator>>(istream& in, Container& x) {
	in >> x.length >> x.width >> x.height >> x.weight;
	return in;
}



