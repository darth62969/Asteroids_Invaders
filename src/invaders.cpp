#include <algorithm>
#include "invaders.h"
#include "bullet.h"
#include "render.h"
#include "fighter.h"


invaders::invaders()
{
	std::cout << "Loading invaders...\n";
	maxLevel=1;
	std::cout << "Initiating Octogon...\n";
	r2 = new render();
	//r2->initOctogon();
	std::cout << "Generating Level...\n";
	onScreen2 = new std::vector<std::shared_ptr<object>>;
	generateLevel();
	std::cout << "Establishing the Enterprise...\n";
	//player = new enterprise();
	std::cout << "Setting Name to invaders...\n";
	name = "invaders";

	std::cout << "Seeding RNG...\n";
	std::chrono::high_resolution_clock::time_point s = 
		std::chrono::high_resolution_clock::now();
	std::chrono::high_resolution_clock::duration d = 
		std::chrono::high_resolution_clock::now()-s;
	unsigned s2 = d.count();
	generator.seed(s2);

	std::cout << "Loaded invaders\n";
}

invaders::step()
{
	stp++;
	int numInvaders=0;
	for (int i = 0; i<onScreen2->size(); i++)
	{
		onScreen2->at(i)->doAction(this);
		if(std::dynamic_pointer_cast<asteroid>(onScreen2->at(i)))
			numAsteroids++;
	}
}




extern "C" mode * create()
{
	return new normal();
}
extern "C" mode * destroy(mode * m)
{
	delete (m);
}