#pragma once
#include "Country.h"
#include "Includes.h"
#include <utility>
#include <queue>

class MemoryPainter {
	queue<pair<string, Country*>> colorQueue;
	const int GOING_TO_PAINT = 10;
	int currentIndex;
public:
	MemoryPainter();
	void paint();
	void push_back(pair<string, Country*>pPair);
};