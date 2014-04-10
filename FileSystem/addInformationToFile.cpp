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
	int BlockNf, SegmNf, BlockNs, SegmNs; //Номер блока , номер сегмента
	FileDescriptor AddFile;
	FileDescriptor NextFile;
	FileDescriptor LastFile;
	int ResultCount;
	int freeSpace; //кол-во свободных блоков перед следующим файлом

	//Собствено функция
	cout << "Введите имя файла" << endl;
	cin >> FileName;
	if (FileName.length() > lenCritical)//Проверка ввода имени
		return(1);

	cout << "Введите кол-во добавляемой информации" << endl;
	cin >> InformationCount;
	if (InformationCount > CntCritical)//Проверка ввода кол-ва информации 
		return(1);

	AddFile = getRecord(FileName);
	if ((AddFile.fileType) == "")
		return(1);
	NextFile = getNextRecord(FileName);
	//LastFile=getLastFile();
	AddFile.blockCount=toString((toInt(AddFile.blockCount)+InformationCount),CountLength); //Увеличим кол-во инф. в файле
	if ((toInt(AddFile.firstBlockNumber) + toInt(AddFile.blockCount) + InformationCount / 512) > (toInt(NextFile.firstBlockNumber)))
	{//AddFile.firstBlockNumber=FindLastFi
	}	
	return(resultCode);
}

//{
//	int resultCode=0;
//
//	return(resultCode);
//
//}
