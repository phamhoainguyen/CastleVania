#ifndef  __POINT_H__
#define  __POINT_H__

class Point
{
public:
	Point();				// Defaut Constructor
	Point(const Point&);   // Constructor copy
	Point(int, int, int );	   //Constructor with 2 parameter
	~Point();				// Destructor
	int getX() const;		//Get x
	int getY() const;		//Get y
	void setX(int );		//Set x
	void setY(int );       // Set y
	int getZ() const;		//Get z
	void setZ(int);			//Set z
private:
	int x, y;
	int *z;

};


#endif  //__POINT_H__