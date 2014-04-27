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


/*
TEST_F(TestFileSystemMonitor, correctRename)
{
	stringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	//std::cout<<"test";
	//return;
	//std::stringstream s;
	 //#define cout s;
	f1->reNameFile();
	string ss;
	ss = oss.str();
	string s1="";
	EXPECT_EQ(ss,s1);
}


TEST_F(TestFileSystemMonitor, correctCreateF)
{
	stringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	//std::cout<<"test";
	//return;
	//std::stringstream s;
	 //#define cout s;
	f1->createNewFile();
	string ss;
	ss = oss.str();
	string s1="";
	EXPECT_EQ(ss,s1);
}

TEST_F(TestFileSystemMonitor, correctChangeT)
{
	stringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	//std::cout<<"test";
	//return;
	//std::stringstream s;
	 //#define cout s;
	f1->changeFileType();
	string ss;
	ss = oss.str();
	string s1="";
	EXPECT_EQ(ss,s1);
}

TEST_F(TestFileSystemMonitor, correctWorkCycle)
{
	stringstream oss;
	std::cout.rdbuf(oss.rdbuf());

	f1->workCycle();
	string ss;
	ss = oss.str();
	string s1="";
	EXPECT_EQ(ss,s1);
}
*/


