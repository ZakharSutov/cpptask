#include "Tree.h"
#include <iostream>

void Tree::writeTree(std::ostream& os, TreeElem* root, int step) {
	if (!root) { return; }
	for (int i = 0; i < step; i++) {
		os << "\t";
	}
	os << root->data << "\n";
	writeTree(os, root->left, step + 1);
	writeTree(os, root->right, step + 1);
}

int Tree::countEven(TreeElem* root) {

	if (!root) { return 0; }
	if (root->data % 2 == 0) { return 1 + countEven(root->left) + countEven(root->right); }
	return countEven(root->left) + countEven(root->right);
}

bool Tree::positiveElem(TreeElem* root) {
	if (!root) { return true; }
	if (root->data >= 0) { return positiveElem(root->left) && positiveElem(root->right); }
	return false;
}

double Tree::middle(TreeElem* root) {
	if (!root) { return 0; }
	return root->data + middle(root->left) + middle(root->right);
}

bool Tree::findElem(int x, TreeElem* root, std::vector<int>& vect) {
	if (!root) { return false; }
	if (root->data == x) { return true; }
	vect.push_back(0);
	if (findElem(x, root->left, vect)) {
		return true;
	}
	vect.pop_back();
	vect.push_back(1);
	if (findElem(x, root->right, vect)) {
		return true;
	}
	vect.pop_back();
	return false;
}

Tree::Tree() {
	root = nullptr;
	size = 0;
}

void Tree::pasteElem(int elem, std::vector<int> vector) {
	TreeElem* node;
	if (vector.size() == 0) {
		if (root) {
			root->data = elem;
		}
		else {
			root = new TreeElem(elem, nullptr, nullptr);
			size++;
		}
	}
	else {
		node = root;
		for (int i = 0; i < vector.size() - 1; i++) {
			if (!node) { throw VectorException(); }
			if (vector[i] == 0) {
				node = node->left;
			}
			if (vector[i] == 1) {
				node = node->right;
			}
		}
		if (vector.back() == 0) {
			if (node->left) {
				node->left->data = elem;
			}
			else {
				node->left = new TreeElem(elem, nullptr, nullptr);
				size++;
			}
		}
		else {
			if (node->right) {
				node->right->data = elem;
			}
			else {
				node->right = new TreeElem(elem, nullptr, nullptr);
				size++;
			}
		}
	}

}

int Tree::countEven() {
	return countEven(root);
}

bool Tree::positiveElem() {
	return positiveElem(root);

}

double Tree::middle() {
	return middle(root) / size;

}

std::vector<int> Tree::findElem(int x) {
	std::vector<int> res = {};

	if (findElem(x, root, res)) {
		return res;
	}
}


TreeElem::TreeElem(int data, TreeElem* left, TreeElem* rigth) {
	this->data = data;
	this->left = left;
	this->right = rigth;
}

std::ostream& operator<<(std::ostream& stream, Tree& tree) {
	tree.writeTree(stream, tree.root, 0);
	return stream;
}

void Tree::print(TreeElem* p, int step) {
	if (p) {
		print(p->left, step + 1);
		for (int i = 0; i < step; i++) {
			std::cout << " ";
		}
		std::cout << p->data << std::endl;
		print(p->right, step + 1);
	}
}

void Tree::print() {
	return print(root, 0);
}
