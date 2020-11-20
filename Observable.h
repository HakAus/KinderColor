#pragma once
#include "Observer.h"

class Observable {
protected:
	Observer* observer;
	void notify();
};