#include "Segment.h"
#include "FileDescriptor.h"
#include <ctime>

class FileSystem
{
private:
	
public:
	fstream memory;
	void createFile(string);			//открытие существующего физического файла или создание нового
	void openFile(string);
	int format(string,string,string,string); //форматирование файловой системы
	Block readBlock(int);			//считывание блока, заданного номером
	void writeBlock(Block,int);		//запись блока в заданную позицию файла
	FileDescriptor getRecord(string);  //извлечение описателя файла по имени
	FileDescriptor getNextRecord(string);
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
};