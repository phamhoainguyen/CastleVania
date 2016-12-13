#include "Figure.h"

class Eclipse :public Figure{
protected:
	float rA;
	float rB;
public:
	Eclipse();
	Eclipse(Eclipse*);
	~Eclipse();
	virtual char* className();
	virtual Figure* Clone(); 
};