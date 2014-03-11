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
	Block readBlock(int);
	void writeBlock(Block,int);

	int findRecord(string);

<<<<<<< HEAD

	void closeFileSystem();

=======
	void closeFileSystem();
>>>>>>> b0d4cfdc9d14ae7d6a18465f3d39fe52b47f8219
};