#include "FileSystem.h"

int FileSystem::showTableOfContent()
{
	int resultCode=0;
	for(int i=1;i<218;++i)
	{
		FileDescriptor fileDescriptor=getRecord(i);
		if((fileDescriptor.descriptorType!="0000000000000000")&&((fileDescriptor.descriptorType!="0010000000000000")))
		{
			int number=fileDescriptor.fileName.find("|");
			cout<<fileDescriptor.fileName.substr(0,number)<<".";
			number=fileDescriptor.fileType.find("|");
			cout<<fileDescriptor.fileType.substr(0,number)<<endl;
			cout<<fileDescriptor.blockCount<<endl;
			cout<<fileDescriptor.creationDate<<endl<<endl;
		}
	}	
			
	
	return(resultCode);
}
