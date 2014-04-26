#include "FileSystem.h"

int FileSystem::compressionOfFileSystem()
{

	FileDescriptor *last=NULL;
	FileDescriptor *current=NULL;
	FileDescriptor *next=NULL;
	for (int i=1;i<=216;i++)
	{
		current=new FileDescriptor(getRecord(i));
		next=new FileDescriptor(getRecord(i+1));
		if (current->descriptorType=="0010000000000000")
		{
			for (int m=i;m<=216;m++)
			{
				if (last==NULL){
					last=new FileDescriptor;
					*last=*current;
					*current=*next;
					if(current->descriptorType!="0000000000000000")
						current->firstBlockNumber=toString(toInt(last->firstBlockNumber)+last->blockCount,16);
					writeRecord(*current,m);
					if (m!=216) *next=getRecord(m+2);
				}else{
					*last=*current;
					*current=*next;
					if(current->descriptorType!="0000000000000000")
						current->firstBlockNumber=toString(toInt(last->firstBlockNumber)+last->blockCount,16);
					writeRecord(*current,m);
					*next=getRecord(m+2);}
			}
			next->fileName="000000000000000000000000000000000000000000000000";
			next->fileType="0000000000000000";
			next->blockCount=0;
			next->creationDate="0000000000000000";
			next->descriptorType="0000000000000000";
			next->firstBlockNumber="0000000000000000";
			writeRecord(*next,217);
		}
	}

	*current=getRecord(217);
	if (current->descriptorType=="0010000000000000")
	{
		current->fileName="000000000000000000000000000000000000000000000000";
		current->fileType="0000000000000000";
		current->blockCount=0;
		current->creationDate="0000000000000000";			
		current->descriptorType="0000000000000000";
		current->firstBlockNumber="0000000000000000";
		writeRecord(*current,217);
	}

	return 0;
}