#include "FileSystem.h"

int FileSystem::reNameFile()   //если некорректное им€-1; если нет файла с заданным старым именем файла-2; если файл с новым именем уже существует-3
{
	string lastName;
	cout<<"¬ведите им€ файла"<<endl;
	cin>>lastName;
	string newName;
	cout<<"¬ведите новое им€ файла"<<endl;
	cin>>newName;
	if ((lastName.length()>47)||(newName.length()>47)) return 1;
	if (getRecordNumber(newName)!=0) return 3;
	int fileNumber;
	fileNumber=getRecordNumber(lastName);
	if (fileNumber==0) return 2;
	FileDescriptor file;
	file=getRecord(lastName);
	file.fileName=newName;
	writeRecord(file,fileNumber);
	return 0;
}


class TestReNameFile : public ::testing::Test {
public:
	void SetUp()	// инициализаци€ тестируемого класса
	{
		f=new FileSystem;
		f->createFile("3");
		f->openFile("3");
		f->format("23","tom","otherString","last");

		FileDescriptor d;
		FileDescriptor d1;
		d.firstBlockNumber=f->toString(20,16);
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="name";
		f->writeRecord(d,5);
		d.fileName="ExistName";
		f->writeRecord(d);
	}
	FileSystem *f;
};


TEST_F(TestReNameFile, correctRename)		//успешное переимнование
{
	stringstream s;
	s<<"name"<<endl;
	s<<"notExistName"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->reNameFile(),0);
};

TEST_F(TestReNameFile, incorrectName)		//некооректное им€
{
	stringstream s;
	s<<"name"<<endl;
	s<<"ToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeName"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->reNameFile(),1);
}

TEST_F(TestReNameFile, notExistFile)		//несуществующий файл
{
	stringstream s;
	s<<"notExistName"<<endl;
	s<<"notExistName"<<endl;
	ASSERT_EQ(f->reNameFile(),2);
};
TEST_F(TestReNameFile, nameBeenUsed)		//существует файл с новым именем
{
	stringstream s;
	s<<"name"<<endl;
	s<<"ExistName"<<endl;
	ASSERT_EQ(f->reNameFile(),3);
};
