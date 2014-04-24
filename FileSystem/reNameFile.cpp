#include "FileSystem.h"

int FileSystem::reNameFile()   //���� ������������ ���-1; ���� ��� ����� � �������� ������ ������ �����-2; ���� ���� � ����� ������ ��� ����������-3
{
	string lastName;
	cout<<"������� ��� �����"<<endl;
	cin>>lastName;
	string newName;
	cout<<"������� ����� ��� �����"<<endl;
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
	void SetUp()	// ������������� ������������ ������
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


TEST_F(TestReNameFile, correctRename)		//�������� �������������
{
	stringstream s;
	s<<"name"<<endl;
	s<<"notExistName"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->reNameFile(),0);
};

TEST_F(TestReNameFile, incorrectName)		//������������ ���
{
	stringstream s;
	s<<"name"<<endl;
	s<<"ToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeName"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->reNameFile(),1);
}

TEST_F(TestReNameFile, notExistFile)		//�������������� ����
{
	stringstream s;
	s<<"notExistName"<<endl;
	s<<"notExistName"<<endl;
	ASSERT_EQ(f->reNameFile(),2);
};
TEST_F(TestReNameFile, nameBeenUsed)		//���������� ���� � ����� ������
{
	stringstream s;
	s<<"name"<<endl;
	s<<"ExistName"<<endl;
	ASSERT_EQ(f->reNameFile(),3);
};
