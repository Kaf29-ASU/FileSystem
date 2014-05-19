#include "FileSystem.h"

int FileSystem::showTableOfContent()
{
	int resultCode=0;
	for(int i=1;i<218;++i)
	{
		FileDescriptor fileDescriptor=getRecord(i);
		if(fileDescriptor.descriptorType!="0000000000000000")	
		{
			int number=fileDescriptor.fileName.find("|");
			cout<<fileDescriptor.fileName.substr(0,number)<<".";
			number=fileDescriptor.fileType.find("|");
			cout<<fileDescriptor.fileType.substr(0,number)<<endl;
			cout<<fileDescriptor.blockCount<<endl;
			//number=fileDescriptor.creationDate.find("|");
			cout<<fileDescriptor.creationDate.substr(0,15)<<endl<<endl;
		}
	}	
			
	
	return(resultCode);
}
