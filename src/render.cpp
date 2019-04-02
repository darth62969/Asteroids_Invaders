#define _USE_MATH_DEFINES

#include "render.h"
#include "prototypes.h"

#include <cmath>

void *currentfont;
std::vector<point> octogon;

void render::drawString(GLuint x, GLuint y, const char* string)
{
	
	// create a pointer to the character
	const char *c;

	//position the drawing pointer
	glRasterPos2i(x, y);
	//glColor3f(1.0, 0.0, 0.0);

	// Print each letter using the font pointer and the character pointer.
	for(c=string; *c!='\0'; c++)
	{
		glutBitmapCharacter(currentfont, *c);	
	}
}

void render::drawLayer(layer * lyr, point loc)
{
	//std::cout << "rendering layer\n";
	//std::cout << "fill(r=" << lyr->fill.red << " g=" << lyr->fill.green << " b=" << lyr->fill.blue << ")\n";
	glColor3i(lyr->fill.red, lyr->fill.green, lyr->fill.blue);
	glColor3d(((double)lyr->fill.red/255.0), ((double)lyr->fill.green/255.0), ((double)lyr->fill.blue/255.0));

	
	//if(lyr->tris.empty()) std::cout << "empty layer\n";
	for(triangle l : lyr->tris)
	{
		triangle l2 = l;
		rotatePoint(l2.a, loc.angle);
		rotatePoint(l2.b, loc.angle);
		rotatePoint(l2.c, loc.angle);
		glColor3d(((double)lyr->fill.red/255.0), ((double)lyr->fill.green/255.0), ((double)lyr->fill.blue/255.0));
		glBegin(GL_TRIANGLES);
			glVertex2d((l2.a.x)+(loc.x), (l2.a.y)+(loc.y));
			glVertex2d((l2.b.x)+(loc.x), (l2.b.y)+(loc.y));
			glVertex2d((l2.c.x)+(loc.x), (l2.c.y)+(loc.y));
		glEnd();

		/*glColor3d(.5, 1, .5);
		glBegin(GL_LINES);
			glVertex2d((l.a.x)+(x), (l.a.y)+(y));
			glVertex2d((l.b.x)+(x), (l.b.y)+(y));
			glVertex2d((l.b.x)+(x), (l.b.y)+(y));
			glVertex2d((l.c.x)+(x), (l.c.y)+(y));
			glVertex2d((l.c.x)+(x), (l.c.y)+(y));
			glVertex2d((l.a.x)+(x), (l.a.y)+(y));
		glEnd();
		*/
	}
	glColor3i(lyr->line.red, lyr->line.green, lyr->line.blue);
	glColor3d(((double)lyr->line.red/255.0), ((double)lyr->line.green/255.0), ((double)lyr->line.blue/255.0));
	std::vector<point> temp_p = lyr->pnts;
	for (int i = 0; i<temp_p.size(); i++)
	{
		rotatePoint(temp_p[i], loc.angle);
	}
	for(int i = 0; i<temp_p.size(); i++)
	{
		glBegin(GL_LINES);
			glVertex2d((temp_p[i].x)+(loc.x), (temp_p[i].y)+(loc.y));
			glVertex2d((temp_p[(i+1)%temp_p.size()].x)+(loc.x), (temp_p[(i+1)%temp_p.size()].y)+(loc.y));
		glEnd();
	}
}


void render::setFont(void * font)
{
	currentfont=font;
}