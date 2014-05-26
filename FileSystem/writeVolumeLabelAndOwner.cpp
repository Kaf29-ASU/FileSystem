#include "FileSystem.h"

int FileSystem::writeVolumeLabelAndOwner()
{
	cout<<"������� ����� ����"<<endl;
	string VolName;
	cin>>VolName;
	if (VolName.length()>12) return 2;
	cout<<"������� ��� ���������"<<endl;
	string Owner;
	cin>>Owner;
	if (Owner.length()>12) return 1; 
	Block temp_Block;
	temp_Block.Clean();
	temp_Block.InsertString(472,VolName);
	temp_Block.InsertString(484,Owner);
	this->writeBlock(temp_Block,2);
	return 0;
}

class TestVolumeLabelAndOwner : public ::testing::Test {
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

TEST_F(TestVolumeLabelAndOwner, correctVolumeLabelAndOwner)		//�������� ������� ����� ���� � ����� ���������
{
	stringstream s;
	s<<"LocalDriveD"<<endl;
	s<<"Anonymous"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->writeVolumeLabelAndOwner(),0);
};

TEST_F(TestVolumeLabelAndOwner, longVolumeLabel)		//������� ����� ���� � ���������� ��� ���������
{
	stringstream s;
	s<<"LocalDriveD_Doubled"<<endl;
	s<<"Anonymous"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->writeVolumeLabelAndOwner(),1);
};

TEST_F(TestVolumeLabelAndOwner, correctVolumeLabelAndLongOwner)		//�������� ������� ����� ���� � ������� ��� ���������
{
	stringstream s;
	s<<"LocalDriveD"<<endl;
	s<<"AnonymousDoubled"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->writeVolumeLabelAndOwner(),2);
};

TEST_F(TestVolumeLabelAndOwner, LongVolumeLabelAndLongOwner)		//������� ����� ���� � ��� ���������
{
	stringstream s;
	s<<"LocalDriveDDoubled"<<endl;
	s<<"AnonymousDoubled"<<endl;
	//cout.rdbuf(s.rdbuf());
	cin.rdbuf(s.rdbuf());
	ASSERT_EQ(f->writeVolumeLabelAndOwner(),1);
};