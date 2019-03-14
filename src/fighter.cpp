#include "fighter.h"
#include "globals.h"
 int scale =5;
fighter::fighter()
{
	layer lyr;

	std::vector<point> temp;

	lyr.fill = color{100, 100, 100};
	lyr.line = color{ 60,  60,  60};
	lyr.pnts.push_back(point{   0*scale,  18*scale, 0 ,1});
	lyr.pnts.push_back(point{   1*scale,  18*scale, 0 ,1});
	lyr.pnts.push_back(point{   3*scale,  16*scale, 0 ,1});
	lyr.pnts.push_back(point{   5*scale,  12*scale, 0 ,1});
	lyr.pnts.push_back(point{   5*scale,   2*scale, 0 ,1});
	lyr.pnts.push_back(point{   7*scale,  -2*scale, 0 ,1});
	lyr.pnts.push_back(point{   9*scale,  -4*scale, 0 ,1});
	lyr.pnts.push_back(point{  11*scale,  -8*scale, 0 ,1});
	lyr.pnts.push_back(point{  11*scale, -16*scale, 0 ,1});
	lyr.pnts.push_back(point{   9*scale, -18*scale, 0 ,1});
	lyr.pnts.push_back(point{  -9*scale, -18*scale, 0 ,1});
	lyr.pnts.push_back(point{ -11*scale, -16*scale, 0 ,1});
	lyr.pnts.push_back(point{ -11*scale,  -8*scale, 0 ,1});
	lyr.pnts.push_back(point{  -9*scale,  -5*scale, 0 ,1});
	lyr.pnts.push_back(point{  -7*scale,  -2*scale, 0 ,1});
	lyr.pnts.push_back(point{  -5*scale,   2*scale, 0 ,1});
	lyr.pnts.push_back(point{  -5*scale,  12*scale, 0 ,1});
	lyr.pnts.push_back(point{  -2*scale,  16*scale, 0 ,1});
	lyr.pnts.push_back(point{  -1*scale,  18*scale, 0 ,1});
	
	tessellate(&lyr);
	
	lyrs.push_back(lyr);

	layer lyr2;
	
	lyr2.fill = color{100, 100, 100};
	lyr2.line = color{ 60, 100,  60};
	
	lyr2.pnts.push_back(point{ 9,  -6, 0 ,1});
	lyr2.pnts.push_back(point{ 9, -16, 0 ,1});
	lyr2.pnts.push_back(point{ 5, -16, 0 ,1});
	lyr2.pnts.push_back(point{ 5,  -6, 0 ,1});
	
	tessellate(&lyr2);
	
	lyrs.push_back(lyr2);

	layer lyr3;
	
	lyr3.fill = color{100, 100, 100};
	lyr3.line = color{ 60, 100,  60};
	
	lyr3.pnts.push_back(point{ -9,  -6, 0 ,1});
	lyr3.pnts.push_back(point{ -9, -16, 0 ,1});
	lyr3.pnts.push_back(point{ -5, -16, 0 ,1});
	lyr3.pnts.push_back(point{ -5,  -6, 0 ,1});
	
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
}

void fighter::fire(mode * md)
{
	std::vector<point> temp=getAtkPnts();
	for (int i = 0; i < temp.size(); i++)
	{	
		temp[i].x+=sin(location.angle);
		temp[i].y+=cos(location.angle);
		bullet * shot = blt.fireBullet(temp[i].x, temp[i].y, location.angle);
		md->addToOnScreen(shot);
	}
}

void fighter::doAction(mode * md)
{/*
	cycle++;

	point pnt = player.getAtkPnts()[0];
	double bearing =(atan2f(pnt.y-this->getAtkPnts()[0].y, pnt.x-this->getAtkPnts()[0].x));
	this->setRotation(bearing);

	switch(cycle/50)
	{
		case 0:
			location.x++;
			break;
		case 1:
			location.x--;
			break;
	}
	switch(cycle%50)
	{
		case 0:
			location.y-=10;
			break;

	}
	if (cycle >= 100)
	{
		cycle = 0;
	}
	switch(rand()%70)
	{
		case 0: 
		fire(md);
		break;
	}*/
}

void fighter::render(mode * md)
{
	for (layer lyr : lyrs)
	{
		md->r2->drawLayer(&lyr, location.x, location.y);
	}
}