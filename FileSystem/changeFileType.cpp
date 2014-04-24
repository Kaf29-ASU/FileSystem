#include "FileSystem.h"

int FileSystem::changeFileType()
{
	int resultCode=0;
	string fileName;
	cout<<"¬ведите им€ файла"<<endl;
	cin>>fileName;
	if(getRecordNumber(fileName)==0)
		{
			resultCode=1;
			return(resultCode);
		};
	string fileType;
	cout<<"¬ведите тип файла не превышающий 32 сиволов"<<endl;
	cin>>fileType;
	if(fileType.length()>16)
	{
		resultCode=2;
		return(resultCode);
	};
	FileDescriptor current;
	current=getRecord(fileName);
	int pos=getRecordNumber(fileName);
	current.fileType=fileType;
	writeRecord(current, pos);
	return(resultCode);
}
