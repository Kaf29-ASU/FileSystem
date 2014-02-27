#include "Segment.h"

void Segment::clean()
{
	blockMassive[0].Clean();
	blockMassive[1].Clean();
}

void Segment::write()
{
	stringstream ss;
	ss << segmentCount;
	string tmp = ss.str();
	int len=tmp.length();
	for (int i=0;i<16-len;i++)
		tmp="0"+tmp;
	blockMassive[0].InsertString(0,tmp);
	ss.str("");

	ss<<nextSegmentNumber;
	tmp=ss.str();
	len=tmp.length();
	for (int i=0;i<16-len;i++)
		tmp="0"+tmp;
	blockMassive[0].InsertString(16,tmp);
	ss.str("");


}