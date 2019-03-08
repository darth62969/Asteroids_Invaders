#ifndef STRUCTS
#define STRUCTS

struct point
{
    float x, y, z, w, angle ;
};

struct triangle
{
    point a, b, c;
};

struct value
{
	int type;
	char* name;
	int _int;
	double _double;
	short fail;
};
struct condition
{
	int condition;
	value a;
	value b;
	
	
};

struct color
{
	int red;
	int green;
	int blue;
	int alpha;
};

struct layer
{
	std::vector<point>    pnts;
	std::vector<triangle> tris;
	color fill;
	color line;
};

#endif
