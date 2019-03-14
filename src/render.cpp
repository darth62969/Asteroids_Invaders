#define _USE_MATH_DEFINES

#include "render.h"

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

void render::drawLayer(layer * lyr, double x, double y)
{
	std::cout << "rendering layer\n";
	std::cout << "fill(r=" << lyr->fill.red << " g=" << lyr->fill.green << " b=" << lyr->fill.blue << ")\n";
	glColor3i(lyr->fill.red, lyr->fill.green, lyr->fill.blue);

	
	if(lyr->tris.empty()) std::cout << "empty layer\n";
	for(triangle l : lyr->tris)
	{
		glBegin(GL_TRIANGLES);
			std::cout<< 
			glVertex2d((l.a.x)+(x), (l.a.y)+(y));
			glVertex2d((l.b.x)+(x), (l.b.y)+(y));
			glVertex2d((l.c.x)+(x), (l.c.y)+(y));
		glEnd();
	}
	std::cout << "line(r=" << lyr->line.red << " g=" << lyr->line.green << " b=" << lyr->line.blue << ")\n";
	glColor3i(lyr->line.red, lyr->line.green, lyr->line.blue);
	
	for(int i = 0; i<lyr->pnts.size(); i++)
	{
		glBegin(GL_LINES);
			glVertex2d((lyr->pnts[i].x)+(x), (lyr->pnts[i].y)+(y));
			glVertex2d((lyr->pnts[(i+1)%lyr->pnts.size()].x)+(x), (lyr->pnts[(i+1)%lyr->pnts.size()].y)+(y));
		glEnd();
	}
}

void render::setFont(void * font)
{
	currentfont=font;
}