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
	systemBlock.InsertString(469,"6");
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
	for (int i=0;i<30;i++)
	{
		catalog[i].clean();
		catalog[i].segmentCount=31;
		catalog[i].nextSegmentNumber=(i+2);
		catalog[i].busySegmentCount=0;
		catalog[i].write();
		memory.write((char*)catalog[i].blockMassive[0].byteMassive, sizeof(catalog[i].blockMassive[0].byteMassive));
		memory.write((char*)catalog[i].blockMassive[1].byteMassive, sizeof(catalog[i].blockMassive[1].byteMassive));

	}
	catalog[30].clean();
		catalog[30].segmentCount=31;
		catalog[30].nextSegmentNumber=(0);
		catalog[30].busySegmentCount=0;
		catalog[30].write();
		memory.write((char*)catalog[30].blockMassive[0].byteMassive, sizeof(catalog[30].blockMassive[0].byteMassive));
		memory.write((char*)catalog[30].blockMassive[1].byteMassive, sizeof(catalog[30].blockMassive[1].byteMassive));


	memory.close();
}

Block FileSystem::readBlock(int number)
{
	openFile("test");
	Block result;
	char tmp[513];
	for (int i=0;i<number;i++)
	{
		memory.get(tmp,513);
	}
	memory.close();
	for (int i=0;i<512;i++)
		result.byteMassive[i]=tmp[i];

	return result;
}