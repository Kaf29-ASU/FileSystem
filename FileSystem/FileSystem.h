#include "Segment.h"
#include "FileDescriptor.h"
class FileSystem
{
private:
	fstream memory;
public:
	void createFile(string);
	void openFile(string);
	void format(string,string,string,string);

};