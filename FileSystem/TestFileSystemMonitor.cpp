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
		//f1->fileSystem.createFile("testMonitor");
		//f1->fileSystem.openFile("testMonitor");
		//f1->fileSystem.format("23","tom","otherString","last");
	}
	FileSystemMonitor *f1;
	
	
};



TEST_F(TestFileSystemMonitor, correctWorkCycle)
{
	stringstream oss;
	//streambuf *buff;
	//cout.rdbuf(oss.rdbuf());
	
	cin.rdbuf(oss.rdbuf());
	
	stringstream scout;
	//cout.rdbuf(scout.rdbuf());

	oss<<"1"<<endl;
	oss<<"testMonitor"<<endl;
	oss<<"1"<<endl;
	oss<<"0"<<endl;
	cout.rdbuf(scout.rdbuf());
	f1->workCycle();

	
	string ss;
	ss=scout.str();
	oss<<"0";
	//cout.rdbuf(buff);
	
	string s1=("успешное завершение");
	
	
	ASSERT_TRUE(ss.find("успешное завершение")!=0);
}



