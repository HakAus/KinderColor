#include "MemoryPainter.h"

MemoryPainter::MemoryPainter() {
	currentIndex = 0;
	finished = false;
}

void MemoryPainter::paint()
{
	while (!colorQueue.empty() && currentIndex < GOING_TO_PAINT) {
		pair<string, Country*> tempPair = colorQueue.front();
		tempPair.second->setColor(tempPair.first);
		// cout << tempPair.second->getId();
		colorQueue.pop();
		currentIndex++;
	}
	currentIndex = 0;
}

bool MemoryPainter::hasFinished()
{
	return colorQueue.empty() && finished;
}

void MemoryPainter::finish()
{
	finished = true;
}

void MemoryPainter::push_back(pair<string, Country*> pPair)
{
	colorQueue.push(pPair);
}
