#include "Figure.h"

vector<Figure*> Figure::sampleObject;

void Figure::addSample(Figure* pFig)
{
	if (pFig == NULL)
		return;
	int pos = sampleObject.size();
	while (--pos >= 0)
	{
		Figure* Obj = sampleObject[pos];
		if (strcmp(pFig->className(), Obj->className()) == 0)
			break;
	}

	if (pos < 0)
		sampleObject.push_back(pFig);
}