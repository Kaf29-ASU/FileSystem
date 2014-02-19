#include "Block.h"

class Segment
{
public:
	Block blockMassive[2];
	string segmentCount;
	string nextSegmentNumber;
	string busySegmentCount;
	string startBlockNumber;
	void clean();
};