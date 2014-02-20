#include "FileSystem.h"


int main()
{
	FileSystem f;
	f.createFile("test");
	f.openFile("test");
	f.format("tomname","nextstring","otherString","last");
}
