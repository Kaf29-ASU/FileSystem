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
	string fileSize;
	cout<<"������� ������ ����� � ������"<<endl;
	cin>>fileSize;
	char creationDate[16];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(creationDate, 16, format, timeinfo);
	cout<<endl<<"���� �������� �����: "<<creationDate<<endl;
	

	return(resultCode);
}