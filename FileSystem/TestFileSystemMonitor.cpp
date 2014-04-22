//#include "FileSystem.h"
#include "FileSystemMonitor.h"
//#include <gtest\gtest.h>
#include <gtest\gtest.h>
#include <iomanip>
#include <sstream>
#include <iostream>




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

TEST_F(TestFileSystemMonitor, correctWork)
{
	stringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	//std::cout<<"test";
	//return;
	//std::stringstream s;
	 //#define cout s;
	f1->deleteFile();
	string ss;
	ss = oss.str();
	string s1="";
	EXPECT_EQ(ss,s1);
}