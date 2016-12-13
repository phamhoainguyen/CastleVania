#ifndef __CREATE_OBJECT_USING_CHAIN_H__
#define __CREATE_OBJECT_USING_CHAIN_H__

#include <stdio.h>
#include <vector>
using namespace std;

class Figure{
	static vector<Figure*> sampleObject;
protected:
	static void addSample(Figure* pFig);
public:
	static Figure* createObject(char* clsName);
	virtual char* className() = 0;
	virtual Figure* Clone() = 0;
};

#endif //__CREATE_OBJECT_USING_CHAIN_H__

