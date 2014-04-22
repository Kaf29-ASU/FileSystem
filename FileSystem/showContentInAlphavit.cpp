#include "FileSystem.h"

int FileSystem::showContentInAlphavit()
{
	int resultCode=0;
	string s[218];
	
	for (int i=0;i<218; i++)
		{
		FileDescriptor fileDescriptor=getRecord(i);
		if(fileDescriptor.descriptorType!="0000000000000000")
			{
			int number=fileDescriptor.fileName.find("|");
			s[i]=fileDescriptor.fileName.substr(0,number);
			number=fileDescriptor.fileType.find("|");
			s[i]+="."+fileDescriptor.filetype.substr(0,number);
                	}
		}
	for (int n=0;n<218; n++)
		for (int i=0;i<217; i++)
		{
			string buf="";
			if (s[i]>s[i+1])
			{
				buf=s[i];
				s[i]=s[i+1];
				s[i+1]=buf;
			}
		}

	for (int i=0;i<218; i++)
		cout<<s[i]<<endl;
	return(resultCode);
}

