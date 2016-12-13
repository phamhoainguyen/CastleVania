#include "Eclipse.h"

Eclipse::Eclipse(Eclipse* other)
{
	this->rA = other->rA;
	this->rB = other->rB;
}

char* Eclipse::className()
{
	return "Eclipse";
}

Figure* Eclipse::Clone()
{
	return new Eclipse(this);
}