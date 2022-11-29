#include "Iterator.h"

Iterator::Iterator(RingBuffer*& que) {
	this->index = que->firstPointer - 1;
	this->queue = que;
}

void Iterator::start() {
	index = queue->firstPointer - 1;
}

void Iterator::next() {
	index++;
	index = index % queue->size;
}

bool Iterator::finish() {
	if (queue->lastPointer != index && !queue->checkEmpty()) {
		return false;
	} return true;
}

double Iterator::getValue() {
	return queue->arr[index];
}