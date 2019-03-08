#include "structs.h"
#include "object.h"
#include <vector>


struct path
{
	std::vector<point> p;
	bool smoothed;
};

class pather
{
	public:
		pather(object * o1, std::vector<point> p1, bool sm);
		step();
		
		
	protected:
		path p;
		object * o;
		int x;


};