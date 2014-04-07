#include "Segment.h"
#include "FileDescriptor.h"
#include <ctime>

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

	FileDescriptor getNextRecord(string);
	int writeRecord(FileDescriptor);    
	int deleteRecord(string);			

	void closeFileSystem();

	int showTableOfContent();
	int showContentInAlphavit();
	int createNewFile();
	int showInformation();
	int deleteFile();
	int reNameFile();
	int addInformationToFile();
	int changeFileType();
	int compressionOfFileSystem();
	int writeVolumeLabelAndOwner();

	
};