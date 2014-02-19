#include "FileSystem.h"


void FileSystem:: createFile(string address)
{
	memory.open(address+".txt",ios::out);
	memory.close();
}

void FileSystem::openFile(string fileName)
{
	memory.open(fileName+".txt");
}

void FileSystem::format(string version, string tomName, string userName, string systemName)
{
	memory.clear();
	Block firstBlock;		//загрузочный блок
	firstBlock.Clean();
	memory.write((char*)firstBlock.byteMassive, sizeof(firstBlock.byteMassive));

	Block systemBlock;
	systemBlock.Clean();		//системный блок
	systemBlock.InsertString(470,version);
	systemBlock.InsertString(472,tomName);
	systemBlock.InsertString(484,userName);
	systemBlock.InsertString(496,systemName);
	memory.write((char*)systemBlock.byteMassive, sizeof(firstBlock.byteMassive));

	for (int i=0;i<4;i++)
	{
		Block emptyBlock;		//4 пустых блока
		emptyBlock.Clean();
		memory.write((char*)emptyBlock.byteMassive, sizeof(emptyBlock.byteMassive));
	}

	Segment catalog[31];
	for (int i=0;i<31;i++)
	{
		catalog[i].clean();
	}

	memory.close();
}