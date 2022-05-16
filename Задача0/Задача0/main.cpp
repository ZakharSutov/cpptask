#include <iostream>
//#include "Box.h"
//#include "Container.h"
#include "BoxContainer.h"

using namespace std;
using namespace BoxContainer;

int main() {	
	Box box;
	Box box1(1, 1, 1, 100, 10);
	Box box2(2, 2, 2, 120, 20);
	Box box3(3, 3, 4, 200, 30);
	Box box4(4, 4, 4, 255, 40);
	Box box5(4, 4, 4, 255, 40);
	Box arr[4] = { box1, box2, box3, box4 };
	Container container(10, 10, 10, 1000);
	Container container1(1, 1, 1, 10);
	container.setBox(box1);
	container.setBox(box2);
	container.setBox(box3);
	container.setBox(box4);
	container.setBox(box5);
	cout << box.sumValue(arr, 4) << endl;
	cout << box.compareSum(arr, 50, 4) << endl;
	cout << box.maxWeight(arr, 8, 4) << endl;
	if (box.matryoshka(arr, 4)) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	if (box4 == box5) {
		cout << "true" << endl;
	}
	else {
		cout << "false" << endl;
	}
	cin >> box;
	cout << box << endl;


	cout << container << endl;
	container.deleteBox(4);
	cout << container << endl;
	cout << container.getSize() << endl;
	cout << container.sumWeight() << endl;
	cout << container.sumValue() << endl;
	cout << container.getBox(0) << endl;
	cin >> container1;
	cout << container1 << endl;
	Container arr1[] = { container, container1 };
	cout << arr1[1] << endl;
}