#pragma once

#ifndef __RENDER_H__
#define __RENDER_H__



#include <GL/glut.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include "structs.h"
#include "windowProperties.h"



class render
{
	public:
		void drawString(GLuint x, GLuint y, const char* string); 
		void drawLayer(layer * lyr, point loc);

		
		void setFont(void * font);
		


		void *currentfont;				// Bit map font pointer.
		std::vector<layer> gameConstruct;
		std::vector<point> octogon;
		std::vector<point> playArea;
		
};



#endif