#include "Point.h"

Point::Point()
{
	z = new int;
}

Point::Point(int _x, int _y, int _z)
{
	this->x = _x;
	this->y = _y;
	z = new int;
	*z = _z;
}


Point::Point(const Point& _point)
{
	x = _point.x;
	y = _point.y;
	z = new int;
	*z = *(_point.z);
}

Point::~Point()
{
	if (z != nullptr)
		delete z;
}

int Point::getX() const
{
	return x;
}


int Point::getY() const
{
	return y;
}

int Point::getZ() const
{
	return *z;
}

void Point::setX(int _x)
{
	x = _x;
}

void Point::setY(int _y)
{
	y = _y;
}

void Point::setZ(int _z)
{
	*z = _z;
}