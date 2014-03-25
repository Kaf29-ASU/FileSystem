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




FileDescriptor FileSystem::getRecord(string name)
{
	Block b;
	FileDescriptor result;
	for (int i=0;i<62;i++)
	{
		b=readBlock(i+6);
		if ((b.getString(16,name.length())==name)&&!(i%2==0))
			{
				result.descriptorType=b.getString(0,16);
				result.fileName=b.getString(16,48);
				result.fileType=b.getString(64,32);
				result.blockCount=b.getString(96,16);
				result.creationDate=b.getString(112,16);
				return result;
			}
		for (int m=1;m<=3;m++)
		{
		if (b.getString(16+m*128,name.length())==name)
			{
				result.descriptorType=b.getString(m*128,16);
				result.fileName=b.getString(16+m*128,48);
				result.fileType=b.getString(64+m*128,32);
				result.blockCount=b.getString(96+m*128,16);
				result.creationDate=b.getString(112+m*128,16);
				return result;
			}
		}
	}

				result.descriptorType.erase();  //если не найден, то тип описателя пустой
				return result;
		
}

	

int FileSystem::deleteRecord(string name)
{
	Block b;
	for (int i=0;i<62;i++)
	{
		b=readBlock(i+6);
		if ((b.getString(16,name.length())==name)&&!(i%2==0))
			{
				b.InsertString(0,"0010000000000000");
				for(int n=0;n<48;n++)   b.InsertString(16+n,"0");
				writeBlock(b,i+6);
				return 0;
			}
		for (int m=1;m<=3;m++)
		if (b.getString(16+m*128,name.length())==name)
			{
				b.InsertString(m*128,"0010000000000000");
				for(int n=0;n<48;n++)   b.InsertString(16+m*128+n,"0");
				writeBlock(b,i+6);
				return 0;
			}
		
	}
	return 1; //код ошибки при отсутствии
}


int FileSystem::writeRecord(FileDescriptor input)
{

	Block b;
	for (int i=0;i<62;i++)
	{
		b=readBlock(i+6);
		if (((b.getString(0,16)=="0010000000000000")||(b.getString(0,16)=="0000000000000000"))&&!(i%2==0))
			{
				b.InsertString(0,input.descriptorType);
				b.InsertString(16,input.fileName);
				b.InsertString(64,input.fileType);
				b.InsertString(96,input.blockCount);
				b.InsertString(112,input.creationDate);
				writeBlock(b,i+6);
				return 0;
			}
		for (int m=1;m<=3;m++)
		if ((b.getString(m*128,16)=="0010000000000000")||(b.getString(m*128,16)=="0000000000000000"))
			{
				b.InsertString(m*128,input.descriptorType);
				b.InsertString(m*128+16,input.fileName);
				b.InsertString(m*128+64,input.fileType);
				b.InsertString(m*128+96,input.blockCount);
				b.InsertString(m*128+112,input.creationDate);
				writeBlock(b,i+6);
				return 0;
			}
		
	}
	return 1;     //нет свободного места-ошибка 1
}


void FileSystem::closeFileSystem()
{
	memory.close();

}
