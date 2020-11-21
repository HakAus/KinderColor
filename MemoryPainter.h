#pragma once
#include "Country.h"
#include "Includes.h"
#include <utility>
#include <queue>

class MemoryPainter {
	queue<pair<string, Country*>> colorQueue;
	const int GOING_TO_PAINT = 10;
	int currentIndex;
	bool finished;
public:
	MemoryPainter();
	bool hasFinished();
	void finish();
	void paint();
	void push_back(pair<string, Country*>pPair);
};