#include "Segment.h"
#include "FileDescriptor.h"
class FileSystem
{
private:
	
public:
	fstream memory;
	void createFile(string);
	void openFile(string);
	int format(string,string,string,string);
	Block readBlock(int);
	void writeBlock(Block,int);

	FileDescriptor getRecord(string);   
	int writeRecord(FileDescriptor);    
	int deleteRecord(string);			

	void closeFileSystem();
	
};