#include "Block.h"

class Segment
{
public:
	Block blockMassive[2];
	int segmentCount;
	int nextSegmentNumber;
	int busySegmentCount;
	int startBlockNumber;
	void clean();
	void write();
};