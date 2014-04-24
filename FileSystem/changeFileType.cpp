#include "FileSystem.h"
#include <gtest/gtest.h>

int FileSystem::changeFileType()
{
	int resultCode=0;
	string fileName;
	cout<<"¬ведите им€ файла"<<endl;
	cin>>fileName;
	if(getRecordNumber(fileName)==0)
		{
			resultCode=1;
			return(resultCode);
		};
	string fileType;
	cout<<"¬ведите тип файла не превышающий 32 сиволов"<<endl;
	cin>>fileType;
	if(fileType.length()>16)
	{
		resultCode=2;
		return(resultCode);
	};
	FileDescriptor current;
	current=getRecord(fileName);
	int pos=getRecordNumber(fileName);
	current.fileType=fileType;
	writeRecord(current, pos);
	return(resultCode);
};


class TestChangeFileType : public ::testing::Test {
public:
	void SetUp()	// инициализаци€ тестируемого класса
	{
		f=new FileSystem;
		f->createFile("cft");
		f->openFile("cft");
		f->format("23","tom","otherString","last");

		FileDescriptor d;
		FileDescriptor d1;
		d.firstBlockNumber=f->toString(20,16);
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="name";
		d.fileType="type";
		f->writeRecord(d,5);
		d.fileName="ExistName";
		f->writeRecord(d);
	}
	FileSystem *f;
};



TEST_F(TestChangeFileType, correctChange)		//успешна€ смена типа
{
	stringstream s;
	s<<"name"<<endl;
	s<<"notExistType"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->changeFileType(),0);
};

TEST_F(TestChangeFileType, incorrectType)		//некооректный тип
{
	stringstream s;
	s<<"name"<<endl;
	s<<"ToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeName"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->changeFileType(),2);
};

TEST_F(TestChangeFileType, notExistFile)		//несуществующий файл
{
	stringstream s;
	s<<"notExistName"<<endl;
	s<<"notExistName"<<endl;
	ASSERT_EQ(f->changeFileType(),1);
};
