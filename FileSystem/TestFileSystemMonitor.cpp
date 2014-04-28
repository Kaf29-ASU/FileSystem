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
		//f1=new FileSystemMonitor;
		f1.fileSystem.createFile("testMonitor");
		f1.fileSystem.openFile("testMonitor");
		f1.fileSystem.format("23","tom","otherString","last");
	}
	FileSystemMonitor f1;
	
	
};



TEST_F(TestFileSystemMonitor, correctWorkCycle)
{
	stringstream oss;
	streambuf *buff;
	//cout.rdbuf(oss.rdbuf());
	f1.workCycle();
	buff=oss.rdbuf();

	oss<<"1"<<endl;
	oss<<"testMonitor"<<endl;

	oss<<"1"<<endl;
	string ss;
	ss=oss.str();
	oss<<"0";
	cin.rdbuf(buff);
	oss.clear();
	//cout.rdbuf(buff);
	cout.rdbuf(oss.rdbuf());
	string s1=("успешное завершение");
	
	
	EXPECT_EQ(ss,s1);
}



