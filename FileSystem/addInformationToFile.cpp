#include "FileSystem.h"

int FileSystem::addInformationToFile()
{//Обозначаем переменные
	string FileName;
	int InformationCount;//Кол-во добавляемой информации, 
	int resultCode;
	resultCode = 1;
	int lenCritical =16;
	int CntCritical = 2 ^ 9;
	int BlockNf, SegmNf, BlockNs, SegmNs; //Номер блока , номер сегмента
	FileDescriptor AddFile;
	FileDescriptor NextFile;
	int freeSpace; //кол-во свободных блоков перед следующим файлом

	//Собствено функция
	cout << "Введите имя файла" << endl;
	cin >> FileName;
	if (FileName.length > lenCritical)//Проверка ввода имени
		return(1);

	cout << "Введите кол-во добавляемой информации" << endl;
	cin >> InformationCount;
	if (InformationCount > CntCritical)//Проверка ввода кол-ва информации 
		return(1);

	AddFile = getRecord(FileName);
	if ((AddFile.fileType) == "")
		return(1);
	NextFile = getRecord(FileName);//Тут нужно бы захуярить еще поиск следющего файла, так-то
	






	//AddFile.blockCount += InformationCount; //Увеличим кол-во инф. в файле
	return(resultCode);
}

//{
//	int resultCode=0;
//
//	return(resultCode);
//
//}
