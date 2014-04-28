#include "FileSystem.h"


int FileSystem::createNewFile()
{
	int resultCode=100;
	string fileName;
	cout<<"Введите имя файла не превышающее 48 символа"<<endl;
	cin>>fileName;
		if(fileName.length()>47)
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
	if(fileType.length()>15)
	{
		resultCode=2222;
		return(resultCode);
	};
	int fileSize;
	cout<<"Введите размер файла в байтах"<<endl;
	cin>>fileSize;
	int blockCount=(fileSize/512)+1;
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

for(int i=1;i<=218;++i)
{
	
		current=getRecord(i);
		nextDescr=getRecord(i+1);
		if(((toInt(nextDescr.firstBlockNumber)-toInt(current.firstBlockNumber))>=blockCount)&&((current.descriptorType=="001000")||(current.descriptorType=="000000")))
		{
			FileDescriptor fileDescriptor;
			fileDescriptor.descriptorType="0020000000000000";
			fileDescriptor.fileName=fileName;
			fileDescriptor.fileType=fileType;
			fileDescriptor.blockCount=blockCount;
			fileDescriptor.creationDate=creationDate;
			fileDescriptor.firstBlockNumber=current.firstBlockNumber;
			writeRecord(fileDescriptor ,i);
			resultCode=0;
			return(resultCode);
		}
		
		if(current.descriptorType=="0010000000000000")
		{
			if(nextDescr.descriptorType=="0000000000000000")
			{
			FileDescriptor fileDescriptor;
			fileDescriptor.descriptorType="0020000000000000";
			fileDescriptor.fileName=fileName;
			fileDescriptor.fileType=fileType;
			fileDescriptor.blockCount=blockCount;
			fileDescriptor.creationDate=creationDate;
			fileDescriptor.firstBlockNumber=current.firstBlockNumber;
			writeRecord(fileDescriptor ,i);
			resultCode=0;
			return(resultCode);
			};
		}
		else
		{
			if(current.descriptorType=="0000000000000000")
			{
				FileDescriptor fileDescriptor;
			fileDescriptor.descriptorType="0020000000000000";
			fileDescriptor.fileName=fileName;
			fileDescriptor.fileType=fileType;
			fileDescriptor.blockCount=blockCount;
			fileDescriptor.creationDate=creationDate;
			fileDescriptor.firstBlockNumber=current.firstBlockNumber;
			writeRecord(fileDescriptor ,i);
			resultCode=0;
			return(resultCode);
			}
		};
	
		
		if((i==218)&&(getRecord(217).descriptorType=="0000000000000000"))
		{
			FileDescriptor fileDescriptor;
			fileDescriptor.descriptorType="002000";
			fileDescriptor.fileName=fileName;
			fileDescriptor.fileType=fileType;
			fileDescriptor.blockCount=blockCount;
			fileDescriptor.creationDate=creationDate;
			writeRecord(fileDescriptor,i-1);
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



class TestCreateFile : public ::testing::Test {
public:
	void SetUp()	// инициализация тестируемого класса
	{
		f=new FileSystem;
		f->createFile("testCreate");
		f->openFile("testCreate");
		f->format("23","tom","otherString","last");

		FileDescriptor d;
		FileDescriptor d1;
		d.firstBlockNumber=f->toString(20,16);
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="name";
		f->writeRecord(d,5);
		d.fileName="ExistName";
		f->writeRecord(d);
	}
	FileSystem *f;
};


TEST_F(TestCreateFile, nameUsed)		//такой файл существует создание
{
	stringstream s;
	s<<"name"<<endl;
	s<<"notExistName"<<endl;
	s<<1000<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->createNewFile(),222);
};

TEST_F(TestCreateFile, correctCreate)		//корректные входные
{
	stringstream s;
	s<<"New"<<endl;
	s<<"type"<<endl;
	s<<1000<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->createNewFile(),0);
}


TEST_F(TestCreateFile, inCorrect)		//некорректные входные
{
	stringstream s;
	s<<"notExistNamenotExistNamenotExistNamenotExistNamenotExistNamenotExistNamenotExistName"<<endl;
	s<<"notExistNamenotExistNamenotExistNameммnotExistName"<<endl;
	s<<1000<<endl;
	ASSERT_EQ(f->createNewFile(),2222);
};

class TestCreateFile2 : public ::testing::Test {
public:
	void SetUp()	// инициализация тестируемого класса
	{
		f=new FileSystem;
		//f->createFile("testCreate2");
		f->openFile("testCreate2");
		//f->format("23","tom","otherString","last");

		FileDescriptor d;
		
		
	}
	FileSystem *f;
};


TEST_F(TestCreateFile2, notEnoughPlace)	
{
	/*
	for(int i=1;i<218;++i)
		{
		FileDescriptor d;
		//d.firstBlockNumber=f->toString(20,16);
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="0000";
		//f->writeRecord(d,5);
		//d.fileName="ExistName";
		f->writeRecord(d);
		};
		*/
	stringstream s;
	s<<"1111"<<endl;
	s<<"111"<<endl;
	s<<"111"<<endl;
	ASSERT_EQ(f->createNewFile(),22);
};
