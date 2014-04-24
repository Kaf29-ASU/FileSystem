#include "FileSystem.h"

int FileSystem::changeFileType()
{
	int resultCode=0;
	string fileName;
	cout<<"������� ��� �����"<<endl;
	cin>>fileName;
	if(getRecordNumber(fileName)==0)
		{
			resultCode=1;
			return(resultCode);
		};
	string fileType;
	cout<<"������� ��� ����� �� ����������� 32 �������"<<endl;
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
