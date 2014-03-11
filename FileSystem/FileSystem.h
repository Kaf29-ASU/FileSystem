#include "Segment.h"
#include "FileDescriptor.h"
class FileSystem
{
private:
	
public:
	fstream memory;
	void createFile(string);
	void openFile(string);
	void format(string,string,string,string);
	Block readBlock(int);
	void writeBlock(Block,int);
	int findRecord(string);
	void closeFileSystem();
	FileDescriptor getDescriptor();
	
};