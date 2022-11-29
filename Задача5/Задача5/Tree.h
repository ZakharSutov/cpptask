#pragma once
#include "vector"
#include <iostream>

struct VectorException {};

struct TreeElem {
	int data;
	TreeElem* left;
	TreeElem* right;
	TreeElem(int data, TreeElem* left, TreeElem* rigth);
};

class Tree
{
private:
	TreeElem* root;
	int size;
	void writeTree(std::ostream& os, TreeElem* root, int step);
	int countEven(TreeElem* root);
	bool positiveElem(TreeElem* root);
	double middle(TreeElem* root);
	bool findElem(int x, TreeElem* root, std::vector<int>& vect);
	void print(TreeElem* p, int step);
public:
	Tree();
	void pasteElem(int elem, std::vector<int> vector);
	int countEven();
	bool positiveElem();
	double middle();
	std::vector<int> findElem(int x);
	friend std::ostream& operator<<(std::ostream& stream, Tree& tree);
	void print();
};
