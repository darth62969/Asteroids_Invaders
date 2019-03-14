#include <algorithm>
#include "invaders.h"
#include "bullet.h"
#include "render.h"
#include "fighter.h"

int gamestate =1;

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
void invaders::init()
{
	return;
}

int invaders::step()
{/*
	stp++;
	int numInvaders=0;
	for (int i = 0; i<onScreen2->size(); i++)
	{
		onScreen2->at(i)->doAction(this);
		if(!std::dynamic_pointer_cast<bullet>(onScreen2->at(i)))
			numInvaders++;
	}
	switch(numInvaders)
	{
		case 0:
			level++;
			std::vector<std::shared_ptr<object>> * temp = onScreen2;
			onScreen2 = offScreen;
			offScreen = temp;
			offScreen->clear();
			generateLevel();
			
		default:
			switch(level)
			{
				case 1:
					
			}
			break;
		
	}*/
	return 1;
}

void invaders::generateLevel()
{
	onScreen2->push_back(std::make_shared<fighter>(fighter()));
	onScreen2->back()->setLocation(0,0);
}

void invaders::drawAll()
{
	drawObjects();
}
void invaders::drawLevel()
{
	return;
}
void invaders::drawScore()
{
	return;
}

void invaders::drawObjects()
{
	for(std::weak_ptr<object> o : *onScreen2)
	{
		char a[10];
		//sprintf(a, "%d", i);
		if(auto opt = o.lock())
		{
			opt->render(this);
		}
	}
}
void invaders::keyboardFunc(char key, int x, int y)
{
	return;
}
void invaders::mouseFunc(int button, int state, int x, int y)
{
	return;
}
void invaders::passiveMouseFunc(int x, int y)
{
	return;
}




extern "C" mode * create()
{
	return new invaders();
}
extern "C" mode * destroy(mode * m)
{
	delete (m);
}