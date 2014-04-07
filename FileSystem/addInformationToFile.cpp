#include "FileSystem.h"

<<<<<<< HEAD
int FileSystem::addInformationToFile(){return 0;}/*
{//Обозначаем переменные
=======
int FileSystem::addInformationToFile()
{
	//Обозначаем переменные
>>>>>>> origin/master
	string fileName;
	int InformationCount;//Кол-во добавляемой информации, 
	int resultCode;
	resultCode = 1;
	int rez = 16; //Ограничение размера имени файла
	int BlockNf, SegmNf,BlockNs,SegmNs; //Номер блока , номер сегмента
	FileDescriptor AddFile;
	FileDescriptor NextFile;
	int freeSpace; //кол-во свободных блоков перед следующим файлом

	//Собствено функция
	cout << "Введите имя файла" << endl;
	cin >> fileName;
	cout << "Введите кол-во добавляемой информации" << endl;
	cin >> InformationCount;

	if (InformationCount > rez)//Проверка ввода
		return(1);
	AddFile = getRecord(fileName);
	if ((AddFile.fileType) == "")
		return(1);
	NextFile = getRecord(fileName);//Тут нужно бы захуярить еще поиск следющего файла, так-то

return(resultCode);

}
*/
