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
		//f1->fileSystem.createFile("");
		f1->fileSystem.openFile("testContent");
		
	}
	FileSystemMonitor *f1;
	
	
};

/*TEST_F(TestFileSystemMonitor, showContent)
{
	setlocale(LC_ALL, "Russian"); 
	stringstream oss;
	oss.clear();
	std::cout.rdbuf(oss.rdbuf());
	//std::cout<<"test";
	//return;
	//std::stringstream s;
	 //#define cout s;
	f1->fileSystem.showTableOfContent();
	string ss;
	ss = oss.str();
	string s1="testtest.ttt\n";
	s1=s1+ "1000000\n" +"Апрель 18, 20140\n\n"+"ttttt.ttt\n"+"100000000\n"+"Апрель 18, 20140\n\n";
	
	EXPECT_EQ(ss,s1);
}*/