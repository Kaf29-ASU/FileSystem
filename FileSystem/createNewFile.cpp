#include "FileSystem.h"

int FileSystem::createNewFile()
{
	int resultCode=100;
	string fileName;
	cout<<"Введите имя файла не превышающее 48 символа"<<endl;
	cin>>fileName;
		if(fileName.length()>48)
		{
			resultCode=2222;
			return(resultCode);
		};
	
	if(getRecordNumber(fileName)!=0)
		{
			resultCode=222;
			return(resultCode);
		};
	string fileType;
	cout<<"Введите тип файла не превышающий 32 сиволов"<<endl;
	cin>>fileType;
	if(fileType.length()>16)
	{
		resultCode=2222;
		return(resultCode);
	};
	int fileSize;
	cout<<"Введите размер файла в байтах"<<endl;
	cin>>fileSize;
	/*
	string fileSizeString=toString(fileSize, 16);
	cin>>fileType;
	if(fileSizeString.length()>16)
	{
		resultCode=2222;
		return(resultCode);
	};
	*/
	char creationDate[16];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(creationDate, 16, format, timeinfo);
	cout<<endl<<"Дата создания файла: "<<creationDate<<endl;


FileDescriptor current;
FileDescriptor nextDescr;
int number=0;
	for(int i=1;i<218;++i)
	{
	
		current=getRecord(i);
		nextDescr=getRecord(i+1);
		if(((toInt(nextDescr.firstBlockNumber)-toInt(current.firstBlockNumber))>=fileSize)&&(current.descriptorType=="0000000000000000"))
		{
			FileDescriptor fileDescriptor;
			fileDescriptor.descriptorType="00000000002000";
			fileDescriptor.fileName=fileName+"|";
			fileDescriptor.fileType=fileType+"|";
			fileDescriptor.blockCount=fileSize;
			fileDescriptor.creationDate=creationDate;
			fileDescriptor.firstBlockNumber=current.firstBlockNumber;
			writeRecord(fileDescriptor ,i);
			resultCode=0;
			return(resultCode);
		}
		if(i==217)
		{
			FileDescriptor fileDescriptor;
			fileDescriptor.descriptorType="00000000002000";
			fileDescriptor.fileName=fileName+"|";
			fileDescriptor.fileType=fileType+"|";
			fileDescriptor.blockCount=fileSize;
			fileDescriptor.creationDate=creationDate;
			writeRecord(fileDescriptor);
			resultCode=0;
			return(resultCode);
		}
	}

if(resultCode==100)
{
	resultCode=22;
	return(resultCode);
}		
	

	
	
return(resultCode);
}