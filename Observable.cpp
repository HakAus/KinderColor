#include "Observable.h"
#include "Includes.h"

void Observable::notify()
{
	std::cout << "Notifying"<<endl;
	observer->update();
}
