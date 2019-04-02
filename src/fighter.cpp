#include "fighter.h"
#include "globals.h"
 int scale =2;
 int count;
 int stage;
 int stagelck = 0;
fighter::fighter()
{
	layer lyr;

	std::vector<point> temp;

	lyr.fill = color{100, 100, 100};
	lyr.line = color{ 60,  60,  60};

	lyr.pnts.push_back(point{   0*scale,  18*scale, 0 ,1});
	lyr.pnts.push_back(point{  -1*scale,  18*scale, 0 ,1});
	lyr.pnts.push_back(point{  -3*scale,  16*scale, 0 ,1});
	lyr.pnts.push_back(point{  -5*scale,  12*scale, 0 ,1});
	lyr.pnts.push_back(point{  -5*scale,   2*scale, 0 ,1});
	lyr.pnts.push_back(point{  -7*scale,  -2*scale, 0 ,1});
	lyr.pnts.push_back(point{  -9*scale,  -5*scale, 0 ,1});
	lyr.pnts.push_back(point{ -11*scale,  -8*scale, 0 ,1});
	lyr.pnts.push_back(point{ -11*scale, -16*scale, 0 ,1});
	lyr.pnts.push_back(point{  -9*scale, -18*scale, 0 ,1});
	lyr.pnts.push_back(point{   9*scale, -18*scale, 0 ,1});
	lyr.pnts.push_back(point{  11*scale, -16*scale, 0 ,1});
	lyr.pnts.push_back(point{  11*scale,  -8*scale, 0 ,1});
	lyr.pnts.push_back(point{   9*scale,  -4*scale, 0 ,1});
	lyr.pnts.push_back(point{   7*scale,  -2*scale, 0 ,1});
	lyr.pnts.push_back(point{   5*scale,   2*scale, 0 ,1});
	lyr.pnts.push_back(point{   5*scale,  12*scale, 0 ,1});
	lyr.pnts.push_back(point{   3*scale,  16*scale, 0 ,1});
	lyr.pnts.push_back(point{   1*scale,  18*scale, 0 ,1});
	
	
	tessellate(&lyr);
	
	lyrs.push_back(lyr);

	layer lyr2;
	
	lyr2.fill = color{50, 50, 50};
	lyr2.line = color{ 60, 100,  60};
	
	lyr2.pnts.push_back(point{ 9*scale,  -6*scale, 0 ,1});
	lyr2.pnts.push_back(point{ 5*scale,  -6*scale, 0 ,1});
	lyr2.pnts.push_back(point{ 5*scale, -16*scale, 0 ,1});
	lyr2.pnts.push_back(point{ 9*scale, -16*scale, 0 ,1});
	
	
	tessellate(&lyr2);
	
	lyrs.push_back(lyr2);

	layer lyr3;
	
	lyr3.fill = color{50, 50, 50};
	lyr3.line = color{ 60, 100,  60};
	
	lyr3.pnts.push_back(point{ -9*scale,  -6*scale, 0 ,1});
	lyr3.pnts.push_back(point{ -5*scale,  -6*scale, 0 ,1});
	lyr3.pnts.push_back(point{ -5*scale, -16*scale, 0 ,1});
	lyr3.pnts.push_back(point{ -9*scale, -16*scale, 0 ,1});

	tessellate(&lyr3);
	
	lyrs.push_back(lyr3);



	atkpnts.push_back(point{ 3,  0, 0, 1});

	temp.push_back(point { 3, -1, 0, 1});
	temp.push_back(point { 3,  1, 0, 1});
	temp.push_back(point { 1,  2, 0, 1});
	temp.push_back(point {-3,  2, 0, 1});
	temp.push_back(point {-3, -2, 0, 1});
	temp.push_back(point { 1, -2, 0, 1});

	blt = bullet(temp, 10, 2);

	//actionSet = 2;
	health = 20;
	cycle = 25;

	stage=1;
}

void fighter::fire(mode * md)
{
	//std::cout << "getting attack point" << std::endl;
	std::vector<point> temp=getAtkPnts();
	for (int i = 0; i < temp.size(); i++)
	{
		std::shared_ptr<bullet> shot = blt.fireBullet2(temp[i].x, temp[i].y, location.angle);
		md->addToOnScreen(shot);
	}
}

void fighter::doAction(mode * md)
{
	std::cout<< stage << " : " << count << std::endl;
	switch (stage)
	{
		case 1:
			count++;
			switch (count)
			{
				case 1:
					fire(md);
					break;
				case 10:
					count=0;
			}
			if(count>10)
			 	count=0;
			break;
		case 2:
			count++;
			switch(count)
			{
				case 1:
					fire(md);
					break;
				case 5:
					fire(md);
					count=0;
					break;
			}
	}
	if (health==10)
	{
		stage++;
	}
}

void fighter::render(mode * md)
{
	for (layer lyr : lyrs)
	{
		md->r2->drawLayer(&lyr, location);
	}
}