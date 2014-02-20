#include "Segment.h"

void Segment::clean()
{
	blockMassive[1].Clean();
	blockMassive[2].Clean();
}

void Segment::write()
{
	string tempString;
	for (int i=0;i<16-segmentCount.length();i++)
		tempString+='0';
	segmentCount=tempString+segmentCount;
	blockMassive[1].InsertString(0,segmentCount);
}