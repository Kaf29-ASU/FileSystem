//#include "FileSystem.h"
#include "FileSystemMonitor.h"
//#include <gtest\gtest.h>
#include <gtest\gtest.h>
#include <iomanip>



class TestFileSystemMonitor : public ::testing::Test {
public:
	void SetUp()	// инициализация тестируемого класса
	{
		f1=new FileSystemMonitor;
		f1->fileSystem.createFile("testMonitor");
		f1->fileSystem.openFile("testMonitor");
	}
	FileSystemMonitor *f1;
};

