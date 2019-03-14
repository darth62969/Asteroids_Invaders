/* 
 * Bullet Operations for Asteroids: RETURN OF METEOR
 * 
 * Made by:
 * Jonathan Oakes
 * Braeden Brettin
 * Ted Dorfeuille 
 * Chris Le
 * Emily Herron
 * 
 * For the class:
 * Intro to Computer Graphics (CSC315)
 * 
 * At:
 * Mercer Univercity  
 */


#include "bullet.h"
#include "globals.h"


bullet::bullet(std::vector<point> pnts, int dmg, double vel)
{
	layer lyr;
	lyr.pnts = pnts;
	tessellate(&lyr);
	lyr.fill = color{100,100,0,0};
	lyr.line = color{65,65,65,0};
	damage = dmg;
	location.w = vel; 
	lyrs.push_back(lyr);
}

bullet::bullet(const bullet& other, point loc) :
	damage(other.damage)
{
	for (layer l : other.lyrs)
	{
		lyrs.push_back(l);
	}
	location = other.location;
}
bullet::bullet()
{
	layer lyr;
	lyr.pnts.push_back(point { 3, -1, 0, 1});
	lyr.pnts.push_back(point { 3,  1, 0, 1});
	lyr.pnts.push_back(point { 1,  2, 0, 1});
	lyr.pnts.push_back(point {-3,  2, 0, 1});
	lyr.pnts.push_back(point {-3, -2, 0, 1});
	lyr.pnts.push_back(point { 1, -2, 0, 1});
	tessellate(&lyr);
	lyr.fill = color{100,100,0,0};
	lyr.line = color{65,65,65,0};
	damage=5;
	location.w = 2;
	lyrs.push_back(lyr);
}

bullet * bullet::fireBullet(double x, double y, double angle)
{
	//std::cout << angle << std::endl;
	point t_pnt =point{x, y, 0, location.w, angle};
	bullet * temp = new bullet();
	temp->setLocation(t_pnt);
	return temp;
}
std::shared_ptr<bullet> bullet::fireBullet2(double x, double y, double angle)
{
	//std::cout << angle << std::endl;
	point t_pnt =point{x, y, 0, location.w, angle};
	std::shared_ptr<bullet> temp = std::make_shared<bullet>(bullet(*this));
	temp->setLocation(t_pnt);
	return temp;
}

void bullet::doAction(mode * md)
{
	location.x+=location.w*cos(location.angle);
	location.y+=location.w*sin(location.angle);
}

void bullet::render(mode * md)
{

	for (layer lyr : lyrs)
	{
		md->r2->drawLayer(&lyr, location.x, location.y);
	}
}

std::vector<point> bullet::getBounds()
{
 	std::vector<point> temp = lyrs[0].pnts;
	for (int i =0; i < temp.size(); i++)
	{
			//scalePoint(temp[i], 5);

			point tempp;

			tempp.x= temp[i].x*cos(location.angle)-temp[i].y*sin(location.angle);
			tempp.y= temp[i].x*sin(location.angle)+temp[i].y*cos(location.angle);
			
			temp[i] = tempp;
			temp[i].x += location.x;
			temp[i].y += location.y;
	}

	return temp;		
}

int bullet::getDamage()
{
	return damage;
}

point bullet::getLocation()
{
	return location;
}


