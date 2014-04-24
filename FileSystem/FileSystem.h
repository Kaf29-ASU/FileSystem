#include "Segment.h"
#include "FileDescriptor.h"
#include <ctime>
#include <gtest\gtest.h>
#include <iomanip>

class FileSystem
{
private:
	
public:
	fstream memory;
	void createFile(string);			//�������� ������������� ����������� ����� ��� �������� ������
	void openFile(string);		
	int format(string version, string tomName, string userName, string systemName); //�������������� �������� �������
	Block readBlock(int);			//���������� �����, ��������� �������
	void writeBlock(Block,int);		//������ ����� � �������� ������� �����
	FileDescriptor getRecord(string);  //���������� ��������� ����� �� �����
	FileDescriptor getNextRecord(string);
	int writeRecord(FileDescriptor);    //���������� ������ � ����� � ����� 
	int deleteRecord(string);		//�������� ������ � �����	
	void closeFileSystem();			
	int showTableOfContent();
	int showContentInAlphavit();
	int createNewFile();
	int showInformation();
	int deleteFile();
	int reNameFile(string lastName, string newName);
	int addInformationToFile();
	int changeFileType();
	int compressionOfFileSystem();
	int writeVolumeLabelAndOwner(string,string);
	string toString(int,int);
	int toInt(string);
	int writeRecord(FileDescriptor,int);
	FileDescriptor getRecord(int);
	int getRecordNumber(string);
};


