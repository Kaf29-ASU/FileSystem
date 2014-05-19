#include "FileSystem.h"

int FileSystem::showInformation()
{
	int num=1;
	int sumBlocks=0;
	Block b;
	cout<<"    "<<"������ ����"<<"   "<<"����� ������"<<endl;
	for (int i=0;i<62;i++)
	{
		b=readBlock(i+6);

		if ((b.getString(0,16)=="0010000000000000")&&!(i%2==0))
			{
				cout<<num<<")       "<<toInt(b.getString(80,16))<<"            "<<toInt(b.getString(96,16))<<endl;
				sumBlocks+=toInt(b.getString(96,16));
				num++;
			}
		for (int m=1;m<=3;m++)
		if (b.getString(m*128,16)=="0010000000000000")
			{
				cout<<num<<")       "<<toInt(b.getString(m*128+80,16))<<"            "<<toInt(b.getString(m*128+96,16))<<endl;
				sumBlocks+=toInt(b.getString(m*128+96,16));
				num++;
			}
		
	}
	if (sumBlocks==0) {cout<<"������������ �����������"<<endl ;}

	else {cout<<"����� ��������� ������: "<<sumBlocks<<endl;}
	FileDescriptor d;
	int m=0;
	for (int i=1;i<=217;i++)
	{
		d=getRecord(i);

		if ((d.descriptorType=="0000000000000000")||(d.descriptorType=="0010000000000000"))
			m++;
	}
	cout<<"����� ������: "<<(217-m)<<endl;
	return 0;
}




class TestShowInformation : public ::testing::Test {
public:
	void SetUp()	// ������������� ������������ ������
	{
		f=new FileSystem;
		f->createFile("3");
		f->openFile("3");
		f->format("23","tom","otherString","last");
		FileDescriptor d;
		d.firstBlockNumber=f->toString(20,16);
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="name";
		for(int i=0;i<10;i++)
			f->writeRecord(d);
		//d.descriptorType="001000";
		//f->writeRecord(d);
	}
	FileSystem *f;
};

TEST_F(TestShowInformation, correctShowInformation)		//���������� ����� ����������
{
		FileDescriptor d;
		d.blockCount=3;
		d.firstBlockNumber=f->toString(20,16);
		d.descriptorType="001000000";
		f->writeRecord(d,4);
		f->showInformation();
	ASSERT_EQ(f->showInformation(),0);
};


TEST_F(TestShowInformation, incorrectShowInformation)		//���� ��� ���������� �����
{
	ASSERT_EQ(f->showInformation(),1);
};



