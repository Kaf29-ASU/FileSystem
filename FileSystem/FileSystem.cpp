#include "FileSystem.h"


void FileSystem:: createFile(string address)
{
	memory.open(address+".txt",ios::out);
	//memory.close();
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
		catalog[i].nextSegmentNumber=(i+1);
		catalog[i].busySegmentCount=0;
		catalog[i].write();
		catalog[i].blockMassive[1].byteMassive[128]='1';
		catalog[i].blockMassive[1].byteMassive[16+128]='5';
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


	//memory.close();
}

Block FileSystem::readBlock(int number)
{
	Block result;
	char tmp[513];
	memory.seekg(number*512);
	for (int i=0;i<512;i++)
		result.byteMassive[i]=memory.get();
	memory.seekg(0);
	return result;
}

void FileSystem::writeBlock(Block input, int place)
{

	memory.seekp((place)*512);
	memory.write((char*)input.byteMassive, sizeof(input.byteMassive));

	//memory.close();
	
}




int FileSystem::findRecord(string name)
{
	Block b;
	string s;
	for (int i=0;i<31;i++)
	{
		
		b=readBlock(i+6);
		s=b.getString(16,name.length());
		if ((readBlock(i+6).getString(16,name.length())==name)&&!(i%2==0))
			return (6+i)*512;
		if (readBlock(i+6).getString(16+128,name.length())==name)
			return (6+i)*512+128;
		if (readBlock(i+6).getString(16+256,name.length())==name)
			return (6+i)*512+256;
		if (readBlock(i+6).getString(16+384,name.length())==name)
			return (6+i)*512+384;
	}

	return 0;
}

	


void FileSystem::closeFileSystem()
{
	memory.close();

}

FileDescriptor FileSystem::getDescriptor(){}