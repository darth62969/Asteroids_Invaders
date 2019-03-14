#include <algorithm>
#include "mode.h"
#include "render.h"


std::vector<object*> mode::getOnScreen()
{
	return onScreen;
}

std::vector<std::shared_ptr<object>> mode::getOnScreen2()
{
	return *onScreen2;
}

void mode::addToOnScreen(object * obj)
{
	onScreen.push_back(obj);
}
void mode::addToOnScreen(std::shared_ptr<object> obj)
{
	onScreen2->push_back(obj);
}

std::string mode::getName()
{
	return name;
}


