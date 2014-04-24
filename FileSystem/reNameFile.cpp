#include "FileSystem.h"

int FileSystem::reNameFile(string lastName, string newName)   //���� ������������ ���-1; ���� ��� ����� � �������� ������ ������ �����-2; ���� ���� � ����� ������ ��� ����������-3
{
	if ((lastName.length()>48)||(newName.length()>48)) return 1;
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
	ASSERT_EQ(f->reNameFile("name","notExistName"),0);
};

TEST_F(TestReNameFile, incorrectName)		//������������ ���
{
	ASSERT_EQ(f->reNameFile("name","ToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeNameToLargeName"),1);
}

TEST_F(TestReNameFile, notExistFile)		//�������������� ����
{
	ASSERT_EQ(f->reNameFile("notExistName","notExistName"),2);
};
TEST_F(TestReNameFile, nameBeenUsed)		//���������� ���� � ����� ������
{
	ASSERT_EQ(f->reNameFile("name","ExistName"),3);
};