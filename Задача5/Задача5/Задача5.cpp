#include "Tree.h"
using namespace std;
int main()
{
	Tree* treeOne = new Tree();
	treeOne->pasteElem(1, {});
	treeOne->pasteElem(2, { 0 });
	treeOne->pasteElem(3, { 1 });
	treeOne->pasteElem(4, { 0,1 });
	treeOne->pasteElem(8, { 0, 0 });
	treeOne->pasteElem(5, { 1,0 });
	cout << *treeOne << endl;
	cout << "Count even: " << treeOne->countEven() << endl;
	cout << "Positive elem: " << treeOne->positiveElem() << endl;
	cout << "Middle arifmetic: " << treeOne->middle() << endl;
	vector<int> vec = treeOne->findElem(5);
	cout << "Vector way: ";
	for (unsigned int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}

	treeOne->print();
}