#include "FileSystemMonitor.h"


int main()
{
	FileSystem f;
	f.createFile("test");
	f.openFile("test");
	f.format("23","tom","otherString","last");
}
