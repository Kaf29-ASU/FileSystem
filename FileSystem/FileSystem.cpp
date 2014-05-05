#include "FileSystem.h"

string& FileSystem::nameTrim(string& input)
{
	int n;
	n=input.find_first_of("|");
	input=input.substr(0,n);
	return input;
}


string FileSystem::toString(int n, int length)
{
			string tmp;
			stringstream buf;
			buf<<n;
			buf>>tmp;
			while(tmp.length()!=length)
			{
				tmp="0"+tmp;
			}
			return tmp;
}

int FileSystem::toInt(string s)
{
	stringstream buf;
	buf<<s;
	int out;
	buf>>out;
	return out;
}


void FileSystem::createFile(string address)
{
	memory.open(address+".txt",ios::out);
	memory.close();
	openFile(address);
}

void FileSystem::openFile(string fileName)
{
	memory.open(fileName+".txt");
}

int FileSystem::format(string version, string tomName, string userName, string systemName)
{
	
	
	if(version.length()>2||tomName.length()>12||userName.length()>12||systemName.length()>12) return 1;
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

		return 0;
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
	
}

FileDescriptor FileSystem::getRecord(int number)
{

	Block b;
	FileDescriptor result;
	if (number>217) {result.descriptorType.erase(); return result;}
				

	int k;
		if (number%7==0) k=number/7; else k=1+(number/7);   //номер сегмента куда идет запись

		int n;
		n=number%7;
		if (n==0) n=7;    //номер записи в сегменте
		
		int i;
		if (n<=3) i=k*2-2; else i=k*2-1;		//номер считываемого блока относительно начала каталога

		b=readBlock(i+6);
		if (i%2==0)
			{
				result.descriptorType=b.getString((n)*128,16);
				result.fileName=b.getString((n)*128+16,48);
				result.fileType=b.getString((n)*128+64,16);
				result.firstBlockNumber=b.getString(80+n*128,16);
				result.blockCount=b.getInt((n)*128+96,16);
				result.creationDate=b.getString((n)*128+112,16);
				result.fileName=nameTrim(result.fileName);
				result.fileType=nameTrim(result.fileType);
				return result;
			}else{
				result.descriptorType=b.getString((n-1-3)*128,16);
				result.fileName=b.getString(16+(n-1-3)*128,48);
				result.fileType=b.getString(64+(n-1-3)*128,16);
				result.firstBlockNumber=b.getString(80+(n-1-3)*128,16);
				result.blockCount=b.getInt(96+(n-1-3)*128,16);
				result.creationDate=b.getString(112+(n-1-3)*128,16);
				result.fileName=nameTrim(result.fileName);
				result.fileType=nameTrim(result.fileType);
				return result;
			}
		

				result.descriptorType.erase();  //если не найден, то тип описателя пустой
				result.fileName=nameTrim(result.fileName);
				result.fileType=nameTrim(result.fileType);
				return result;
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
				result.fileType=b.getString(64,16);
				result.firstBlockNumber=b.getString(80,16);
				result.blockCount=b.getInt(96,16);
				result.creationDate=b.getString(112,16);
				result.fileName=nameTrim(result.fileName);
				result.fileType=nameTrim(result.fileType);
				return result;
			}
		for (int m=1;m<=3;m++)
		{
		if (b.getString(16+m*128,name.length())==name)
			{
				result.descriptorType=b.getString(m*128,16);
				result.fileName=b.getString(16+m*128,48);
				result.fileType=b.getString(64+m*128,16);
				result.firstBlockNumber=b.getString(m*128+80,16);
				result.blockCount=b.getInt(96+m*128,16);
				result.creationDate=b.getString(112+m*128,16);
				result.fileName=nameTrim(result.fileName);
				result.fileType=nameTrim(result.fileType);
				return result;
			}
		}
	}

				result.descriptorType.erase();  //если не найден, то тип описателя пустой
				result.fileName=nameTrim(result.fileName);
				result.fileType=nameTrim(result.fileType);
				return result;
		
}


int FileSystem::getRecordNumber(string name)
{
	Block b;
	int result;
	for (int i=0;i<62;i++)
	{
		b=readBlock(i+6);
		if (i%2==0)
			{
				for(int m=1;m<=3;m++)
				{
					if (b.getString(16+m*128,name.length())==name){
						result=m+4*((i+1)/2)+3*(((i+1)%2)+((i+1)/2))-3;
						return result;}
				}	
		}else{
			for(int m=1;m<=4;m++)
				{
					if (b.getString(16+(m-1)*128,name.length())==name){
						result=m+4*((i+1)/2)+3*(((i+1)%2)+((i+1)/2))-4;
						return result;}
			}}
	}
				return 0;
		
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


int FileSystem::writeRecord(FileDescriptor input,int place)
{
	Block b;
	input.fileName=input.fileName+"|";
	input.fileType=input.fileType+"|";
	b.Clean();
		int k;
		if (place%7==0) k=place/7; else k=1+(place/7);   //номер сегмента куда идет запись

		int n;
		n=place%7;
		if (n==0) n=7;    //номер записи в сегменте
		
		int i;
		if (n<=3) i=k*2-1; else i=k*2;		//номер считываемого блока относительно начала каталога

		b=readBlock(i+5);
		
		if (i%2!=0)
			{
				for (int k=0;k<128;k++)
					b.InsertString((n)*128+k,"0");
				b.InsertString((n)*128,input.descriptorType);
				b.InsertString((n)*128+16,input.fileName);
				b.InsertString((n)*128+64,input.fileType);
				b.InsertString((n)*128+80,input.firstBlockNumber);
				b.InsertString((n)*128+96,toString(input.blockCount,16));
				b.InsertString((n)*128+112,input.creationDate);
				writeBlock(b,i+5);
				return 0;
			}else{
				for (int k=0;k<128;k++)
					b.InsertString((n-1-3)*128+k,"0");
				b.InsertString((n-1-3)*128,input.descriptorType);
				b.InsertString((n-1-3)*128+16,input.fileName);
				b.InsertString((n-1-3)*128+64,input.fileType);
				b.InsertString((n-1-3)*128+80,input.firstBlockNumber);
				b.InsertString((n-1-3)*128+96,toString(input.blockCount,16));
				b.InsertString((n-1-3)*128+112,input.creationDate);
				writeBlock(b,i+5);
				return 0;}
		
}


int FileSystem::writeRecord(FileDescriptor input)
{
	input.fileName=input.fileName+"|";
	input.fileType=input.fileType+"|";
	Block b;
	for (int i=0;i<62;i++)
	{
		b=readBlock(i+6);

		if ((i%2==0)&&(b.getInt(16,16)<=i+2))
		{
			string tmp;
			tmp=toString(i/2+1,16);
			for (int k=0;k<62;k=k+2)
			{
				Block t=readBlock(k+6);
				t.InsertString(32,tmp);
				writeBlock(t,k+6);
			}
			b.InsertString(32,tmp);
			if(i!=0){
			string tmp;
			tmp=toString(234,16);
			Block a=readBlock(5+i);
			b.InsertString(64,tmp);}
			else b.InsertString(64,"0000000000000070");

		}

		if ((((b.getInt(96,16)>input.blockCount)&&(b.getString(0,16)=="0010000000000000"))||(b.getString(0,16)=="0000000000000000"))&&!(i%2==0))
			{
				b.InsertString(0,input.descriptorType);
				b.InsertString(16,input.fileName);
				b.InsertString(64,input.fileType);
				b.InsertString(80,input.firstBlockNumber);
				b.InsertString(96,toString(input.blockCount,16));
				b.InsertString(112,input.creationDate);
				writeBlock(b,i+6);
				input.fileName=nameTrim(input.fileName);
				input.fileType=nameTrim(input.fileType);
				int pos=getRecordNumber(input.fileName);
				FileDescriptor prev=getRecord(pos-1);
				input.firstBlockNumber=toString(prev.blockCount+toInt(prev.firstBlockNumber),16);
				writeRecord(input,pos);
				return 0;
			}
		for (int m=1;m<=3;m++)
		if (((b.getInt(m*128+96,16)>input.blockCount)&&(b.getString(m*128,16)=="0010000000000000"))||(b.getString(m*128,16)=="0000000000000000"))
			{
				b.InsertString(m*128,input.descriptorType);
				b.InsertString(m*128+16,input.fileName);
				b.InsertString(m*128+64,input.fileType);
				b.InsertString(m*128+80,input.firstBlockNumber);
				b.InsertString(m*128+96,toString(input.blockCount,16));
				b.InsertString(m*128+112,input.creationDate);
				writeBlock(b,i+6);
				input.fileName=nameTrim(input.fileName);
				input.fileType=nameTrim(input.fileType);
				int pos=getRecordNumber(input.fileName);
				FileDescriptor prev=getRecord(pos-1);
				input.firstBlockNumber=toString(prev.blockCount+toInt(prev.firstBlockNumber),16);
				writeRecord(input,pos);
				return 0;
			}
		
	}
	return 1;     //нет свободного места-ошибка 1
}


void FileSystem::closeFileSystem()
{
	memory.close();

}
