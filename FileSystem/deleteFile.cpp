#include "FileSystem.h"

int FileSystem::deleteFile()
{
	int resultCode=0;
	string fileName;
	cout<<"¬ведите им€ файла"<<endl;
	cin>>fileName;
	/*	
	if(fileName.length()>47)
		{
			resultCode=2222;
			return(resultCode);
		};
	*/
	if(getRecordNumber(fileName)==0)
		{
			resultCode=1;
			return(resultCode);
		};
	deleteRecord(fileName);
	resultCode=0;
	return(resultCode);
}


class Testdelete : public ::testing::Test {
public:
	void SetUp()	// инициализаци€ тестируемого класса
	{
		f1=new FileSystem;
		f1->createFile("testDelete");
		f1->openFile("testDelete");
		f1->format("23","tom","otherString","last");
		FileDescriptor d;
		FileDescriptor d1;
		
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="name";
		f1->writeRecord(d,5);
		d.fileName="ExistName";
		f1->writeRecord(d);
		
	}
	FileSystem *f1;
	
	
};

TEST_F(Testdelete, noDelete) //no file
{
	stringstream s;
	s<<"Test"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f1->deleteFile(),1);
};

TEST_F(Testdelete, correctDelete) //no file
{
	stringstream s;
	s<<"name"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f1->deleteFile(),0);
}
