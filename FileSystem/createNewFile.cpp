#include "FileSystem.h"

int FileSystem::createNewFile()
{
	int resultCode=0;
	string fileName;
	cout<<"������� ��� ����� �� ����������� 48 �������"<<endl;
	cin>>fileName;
	string fileType;
	cout<<"������� ��� ����� �� ����������� 32 �������"<<endl;
	cin>>fileType;
	int fileSize;
	cout<<"������� ������ ����� � ������"<<endl;
	cin>>fileSize;
	string fileSizeString=toString(fileSize, 16);
	char creationDate[16];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(creationDate, 16, format, timeinfo);
	cout<<endl<<"���� �������� �����: "<<creationDate<<endl;
	FileDescriptor fileDescriptor;
	fileDescriptor.fileName=fileName;
	fileDescriptor.fileType=fileType;
	fileDescriptor.blockCount=fileSize;
	fileDescriptor.creationDate=creationDate;
	

	return(resultCode);
}