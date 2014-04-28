#include "FileSystem.h"
#include "string"
int FileSystem::addInformationToFile()
{//Обозначаем переменные
	string FileName;
	int InformationCount;//Кол-во добавляемой информации, 
	int CountLength=8;
	int resultCode = 1;
	int lenCritical = 48;
	int CntCritical = 2 ^ 16;
	//int BlockNf, SegmNf, BlockNs, SegmNs; //Номер блока , номер сегмента
	FileDescriptor AddFile;
	FileDescriptor NextFile;
	//FileDescriptor LastFile;
	int ResultCount;
	int freeSpace; //кол-во свободных блоков перед следующим файлом
	int RecordNumber,NextRecordNumber; //Номер изменяемой записи, номер следующей записи
	int i; //Счетчик

	//Собствено функция
	cout << "Введите имя файла" << endl;
	cin >> FileName;
	if (getRecordNumber(FileName)==0)//Проверка ввода имени
		return(1);

	cout << "Введите кол-во добавляемой информации" << endl;
	cin >> InformationCount;
	if (InformationCount > CntCritical)//Проверка ввода кол-ва информации 
		return(2);

	AddFile = getRecord(FileName);
	if ((AddFile.descriptorType) == "0010000000000000")					//!!!!!!!в дескрипторе число блоков сделал интом!!!!!!
		return(1);
	RecordNumber=getRecordNumber(FileName);
	NextRecordNumber=RecordNumber+1;
	NextFile=getRecord(NextRecordNumber);
	
	
	if ((toInt(AddFile.firstBlockNumber) + AddFile.blockCount + InformationCount) > (toInt(NextFile.firstBlockNumber)))
	{
		//LastFile=AddFile;
		//LastFile.blockCount+=InformationCount;
		AddFile.blockCount+=InformationCount;
		for(i=217;((getRecord(i).fileType)=="");i--)
		//LastFile.firstBlockNumber=toString((toInt(getRecord(i).firstBlockNumber)+getRecord(i).blockCount+1),8);
		AddFile.firstBlockNumber=toString((toInt(getRecord(i).firstBlockNumber)+getRecord(i).blockCount+1),8);
		deleteRecord(FileName);
		//writeRecord(LastFile);
		writeRecord(AddFile);
		resultCode=0;
	}
	else 
	{
		AddFile.blockCount=(AddFile.blockCount+InformationCount);
		deleteRecord(FileName);
		writeRecord(AddFile,RecordNumber);
		resultCode=0;
	}
	return(resultCode);
};

class TestAdd : public ::testing::Test {
public:
	void SetUp()	// инициализация тестируемого класса
	{
		f1=new FileSystem;
		f1->createFile("testAdd");
		f1->openFile("testAdd");
		f1->format("23","tom","otherString","last");
		FileDescriptor d;
		d.blockCount=15;
		d.descriptorType="002000";
		for (int i=0;i<20;i++)
			{d.fileName="file"+(f1->toString(i+1,4));
			f1->writeRecord(d);}
		f1->compressionOfFileSystem();
		d=f1->getRecord(7);
		d.blockCount=10;
		f1->writeRecord(d,7);
	}
	FileSystem *f1;
	
	
};


TEST_F(TestAdd, correctAdd)
{
	stringstream s;
	s<<"file"<<endl;
	s<<"4"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f1->addInformationToFile(),0);
}


TEST_F(TestAdd, noFile)
{
	stringstream s;
	s<<"notExist"<<endl;
	s<<"4"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f1->addInformationToFile(),1);
}


class TestAdd2 : public ::testing::Test {
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

TEST_F(TestAdd2, noPlace)
{
	stringstream s;
	s<<"test0001"<<endl;
	s<<"10000"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_FALSE(f->addInformationToFile()==2);
}