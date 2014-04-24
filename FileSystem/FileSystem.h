#include "Segment.h"
#include "FileDescriptor.h"
#include <ctime>
#include <gtest\gtest.h>
#include <iomanip>
#include <sstream>

class FileSystem
{
private:
	
public:
	fstream memory;
	void createFile(string);			//открытие существующего физического файла или создание нового
	void openFile(string);		
	int format(string version, string tomName, string userName, string systemName); //форматирование файловой системы
	Block readBlock(int);			//считывание блока, заданного номером
	void writeBlock(Block,int);		//запись блока в заданную позицию файла
	FileDescriptor getRecord(string);  //извлечение описателя файла по имени
	int writeRecord(FileDescriptor);    //сохранение записи о файле в конец 
	int deleteRecord(string);		//удаление записи о файле	
	void closeFileSystem();			
	int showTableOfContent();
	int showContentInAlphavit();
	int createNewFile();
	int showInformation();
	int deleteFile();
	int reNameFile();
	int addInformationToFile();
	int changeFileType();
	int compressionOfFileSystem();
	int writeVolumeLabelAndOwner();
	string toString(int,int);
	int toInt(string);
	int writeRecord(FileDescriptor,int);
	FileDescriptor getRecord(int);
	int getRecordNumber(string);
	string& nameTrim(string& input);
};


