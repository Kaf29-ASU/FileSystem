#include "FileSystem.h"

int FileSystem::createNewFile()
{
	int resultCode=0;
	string fileName;
	cout<<"Введите имя файла не превышающее 48 символа"<<endl;
	cin>>fileName;
	string fileType;
	cout<<"Введите тип файла не превышающий 32 сиволов"<<endl;
	cin>>fileType;
	string fileSize;
	cout<<"Введите размер файла в байтах"<<endl;
	cin>>fileSize;
	char creationDate[16];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(creationDate, 16, format, timeinfo);
	cout<<endl<<"Дата создания файла: "<<creationDate<<endl;
	

	return(resultCode);
}