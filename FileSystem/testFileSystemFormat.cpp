#include "FileSystem.h"
#include <gtest\gtest.h>



class TestFileSystem : public ::testing::Test {
public:
	void SetUp()
	{
		f=new FileSystem;
		f->createFile("3");
		f->openFile("3");
	}
	FileSystem *f;
};

TEST_F(TestFileSystem, correctFormat) 
{
	ASSERT_EQ(f->format("23","tom","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatVersion) 
{
	ASSERT_EQ(f->format("235","tom","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatTomName) 
{
	ASSERT_EQ(f->format("23","123456789123456789","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatUserName) 
{
	ASSERT_EQ(f->format("23","12345678","123456789123456789","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatSystemName) 
{
	ASSERT_EQ(f->format("23","1234567","otherString","12345678901234567"),0);
}


int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}