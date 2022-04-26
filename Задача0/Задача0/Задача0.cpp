#include <iostream>

using namespace std;

class Box
{
private:
	int length, width, height, value;
	double weight;

public:
	Box(int _length, int _width, int _height, int _value, double _weight) {
		length = _length;
		width = _width;
		height = _height;
		value = _value;
		weight = _weight;
	}

	Box() {
		length = 0;
		width = 0;
		height = 0;
		value = 0;
		weight = 0;
	}

	int sumValue(Box* arrBox, int size) {
		int sum = 0;
		for (int i = 0; i < size; i++) {
			sum += arrBox[i].value;
		}
		return sum;
	}

	bool compareSum(Box* arrBox, int x, int size) {
		int sumLWH = 0;
		for (int i = 0; i < size; i++) {
			sumLWH += arrBox[i].length + arrBox[i].width + arrBox[i].height;
		}
		return sumLWH <= x;
	}

	double maxWeight(Box* arrBox, int maxV, int size) {
		double maxW = 0;
		int V;
		for (int i = 0; i < size; i++) {
			V = arrBox[i].length * arrBox[i].width * arrBox[i].height;
			if (V <= maxV && maxW < arrBox[i].weight) {
				maxW = arrBox[i].weight;
			}
		}
		return maxW;
	}


	bool matryoshka(Box* arrBox, int size) {
		int k = 0;
		int t = 0;
		int i = 0;
		Box max;
		bool flag = true;
		while (flag == true && i < size)
		{
			for (int j = 0; j < size - i; j++)
			{
				if (max.length < arrBox[j].length && max.width < arrBox[j].width && max.height < arrBox[j].height) {
					max = arrBox[j];
					k = j;
				}
			}
			for (int j = k; j < size - 1 - i; j++)
			{
				arrBox[j] = arrBox[j + 1];
			}
			while (t < size - 1 - i && flag == true) {
				if (max.length <= arrBox[t].length || max.width <= arrBox[t].width || max.height <= arrBox[t].height) {
					flag = false;
				}
				t++;
			}
			max = Box();
			t = 0;
			i++;
		}
		return flag;
	}


	friend bool operator==(Box b1, Box b2) {
		return (b1.length == b2.length && b1.width == b2.width &&
			b1.height == b2.height && b1.weight == b2.weight && b1.value == b2.value);
	}

	friend ostream& operator<<(ostream& os, const Box& x) {
		return os << x.length << " " << x.width << " " << x.height << " " << x.value << " " << x.weight << endl;
	}

	friend istream& operator>>(istream& in, Box& x) {
		in >> x.length >> x.width >> x.height >> x.value >> x.weight;
		return in;
	}
};