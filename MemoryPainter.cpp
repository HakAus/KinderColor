#include "MemoryPainter.h"

MemoryPainter::MemoryPainter() {
	currentIndex = 0;
}

void MemoryPainter::paint()
{
	cout << colorQueue.size()<<endl;
	while (!colorQueue.empty() && currentIndex < GOING_TO_PAINT) {
		pair<string, Country*> tempPair = colorQueue.front();
		tempPair.second->setColor(tempPair.first);
		cout << tempPair.second->getId();
		colorQueue.pop();
		currentIndex++;
	}
	currentIndex = 0;
}

void MemoryPainter::push_back(pair<string, Country*> pPair)
{
	colorQueue.push(pPair);
}
