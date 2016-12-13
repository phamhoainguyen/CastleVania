#include "Point.h"
#include <stdio.h>


int main()
{
	//printf("%d", Point(1, 2).getX());
	Point* p = new Point();
	p->setX(5);
	p->setY(5);
	p->setZ(5);
	Point p1(*p);

	Point* p2 = new Point(1, 2, 3);

	Point p3(*p2);

	p3.setX(999);

	p1.setX(7);
	p1.setZ(7);


	printf("p	%d		%d		%d\n", p->getX(), p->getY(), p->getZ());

	printf("p1	%d		%d		%d\n", p1.getX(), p1.getY(), p1.getZ());

	printf("p2	%d		%d		%d\n", p2->getX(), p2->getY(), p2->getZ());

	printf("p3	%d		%d		%d\n", p3.getX(), p3.getY(), p3.getZ());

	//printf("p2	%d		%d", p2.getX());
	//printf("p2	%d		%d", p2.getX());

	for (;;);
	return 0;
}
