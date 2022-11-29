#pragma once
#include "RingBuffer.h"

class Iterator {
	int index;
	RingBuffer* queue;
public:
	friend class RingBuffer;
	Iterator(RingBuffer*& que);
	void start();
	void next();
	bool finish();
	double getValue();
};