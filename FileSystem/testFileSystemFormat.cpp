#include "FileSystem.h"
//#include <gtest\gtest.h>
#include <gtest\gtest.h>
//#include 



class TestFileSystem : public ::testing::Test {
public:
	void SetUp()	// ������������� ������������ ������
	{
		f=new FileSystem;
		f->createFile("3");
		f->openFile("3");
	}
	FileSystem *f;
};

TEST_F(TestFileSystem, correctFormat)	//�������� ��������� ��������������
{
	ASSERT_EQ(f->format("23","tom","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatVersion)		// �������� ������ ���� ������ ��� ������������ ������ �������
{
	ASSERT_EQ(f->format("235","tom","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatTomName)		//������� ���� ������ ��� ������������ ����� ����
{
	ASSERT_EQ(f->format("23","123456789123456789","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatUserName)		//�������� ���� ������ ��� �������� ����� ������������
{
	ASSERT_EQ(f->format("23","12345678","123456789123456789","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatSystemName)		//�������� ���� ������ ��� ������������ ����� �������
{
	ASSERT_EQ(f->format("23","1234567","otherString","12345678901234567"),0);
}


int main(int argc, char **argv)
{
	if(argc > 1)
	{
		for (int i=1;i<argc;i++)
		{
			string tmp(argv[i]);
			if (tmp.compare("runtest")==0)		
			{
				::testing::InitGoogleTest(&argc, argv);
				RUN_ALL_TESTS();
				getch();
			}
		}
	}
	return 0;
}