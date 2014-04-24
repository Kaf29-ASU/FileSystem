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
	void createFile(string);			//�������� ������������� ����������� ����� ��� �������� ������
	void openFile(string);		
	int format(string version, string tomName, string userName, string systemName); //�������������� �������� �������
	Block readBlock(int);			//���������� �����, ��������� �������
	void writeBlock(Block,int);		//������ ����� � �������� ������� �����
	FileDescriptor getRecord(string);  //���������� ��������� ����� �� �����
	int writeRecord(FileDescriptor);    //���������� ������ � ����� � ����� 
	int deleteRecord(string);		//�������� ������ � �����	
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


