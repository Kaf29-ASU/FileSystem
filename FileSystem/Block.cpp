#include "Block.h"

void Block::Clean()
{
	for(int i=0;i<512;i++)
		byteMassive[i]='0';
}

void Block::InsertString(int position, string inform)
{
	int g=inform.length();
	for(int i=0; i<g; i++)
	{
		byteMassive[i+position]=inform[i];
	}
}
