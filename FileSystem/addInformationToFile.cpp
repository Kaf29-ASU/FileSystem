#include "FileSystem.h"
#include "string"
int FileSystem::addInformationToFile()
{//Обозначаем переменные
	string FileName;
	int InformationCount;//Кол-во добавляемой информации, 
	int CountLength=8;
	int resultCode = 1;
	int lenCritical = 48;
	int CntCritical = 2 ^ 9;
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
	if (FileName.length() > lenCritical)//Проверка ввода имени
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
	
	
	if (((toInt(AddFile.firstBlockNumber) + AddFile.blockCount + InformationCount) / 512) > (toInt(NextFile.firstBlockNumber)))
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
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="name";
		f1->writeRecord(d,5);
		d.fileName="ExistName";
		f1->writeRecord(d);
		
	}
	FileSystem *f1;
	
	
};