#include "FileSystem.h"

int FileSystem::writeVolumeLabelAndOwner(string VolName, string Owner)
{
	if (VolName.length()>12) return 1;
	if (Owner.length()>12) return 2; 
	int resultCode=0;
	Block temp_Block;
	temp_Block.InsertString(472,VolName);
	temp_Block.InsertString(484,Owner);
	memory.write((char*)temp_Block.byteMassive, 512);
	return 0;
}