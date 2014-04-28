//#include "FileSystem.h"
#include "FileSystemMonitor.h"
//#include <gtest\gtest.h>
#include <gtest\gtest.h>
#include <iomanip>



class TestFileSystem : public ::testing::Test {
public:
	void SetUp()	// инициализация тестируемого класса
	{
		f=new FileSystem;
		f->createFile("3");
		f->openFile("3");
	}
	FileSystem *f;
};

TEST_F(TestFileSystem, correctFormat)	//проверка успешного форматирования
{
	ASSERT_EQ(f->format("23","tom","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatVersion)		// проверка вывода кода ошибки при некорректной версии системы
{
	ASSERT_EQ(f->format("235","tom","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatTomName)		//провека кода ошибки при неправильном имени тома
{
	ASSERT_EQ(f->format("23","123456789123456789","otherString","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatUserName)		//проверка кода ошибки при неверном имени пользователя
{
	ASSERT_EQ(f->format("23","12345678","123456789123456789","last"),0);
}

TEST_F(TestFileSystem, incorrectFormatSystemName)		//проверка кода ошибки при некорректном имени системы
{
	ASSERT_EQ(f->format("23","1234567","otherString","12345678901234567"),0);
}


int main(int argc, char **argv)
{

	//argv[1]="runtest";
	//argc=2;
	
	setlocale(LC_ALL, "Russian"); 

		for (int i=1;i<argc;i++)
		{
			string tmp(argv[i]);
			if (tmp.compare("runtest")==0)		
			{
				::testing::InitGoogleTest(&argc, argv);
				RUN_ALL_TESTS();
				getch();
				return 0;
			};

		}


	string s("123");
	
	//FileSystemMonitor f1;
	//FileSystemMonitor f1;
	FileSystem f;
	FileSystem ff; 
	s=f.nameTrim(s);
	//f1.workCycle();
	//f.createFile("testCreate2");
	//f.openFile("testCreate2");
	//f.format("23","tom","otherString","last");
	/*
	for(int i=1;i<218;++i)
		{
		FileDescriptor d;
		//d.firstBlockNumber=f->toString(20,16);
		d.blockCount=9;
		d.descriptorType="002000";
		d.fileName="0000";
		//f->writeRecord(d,5);
		//d.fileName="ExistName";
		f.writeRecord(d);
		};
			
*/
	
	//Block r;
	//r.Clean();
	//int y;
	//string p=r.getString(0,4);
	f.createFile("4-1");
	//f.toInt("00010");
	f.openFile("4-1");
	f.format("23","tom","otherString","last");
	FileDescriptor d;
	FileDescriptor d1;
	d.firstBlockNumber=f.toString(20,16);
	d.blockCount=15;
	d.descriptorType="002000";
	for (int i=0;i<9;i++)
		{d.fileName="file"+(f.toString(i+1,1));
	f.writeRecord(d);}
	d=f.getRecord(1);
	d.descriptorType="001000";
	f.writeRecord(d,1);
	f.compressionOfFileSystem();
	d=f.getRecord(6);
	d.blockCount=10;
	f.writeRecord(d,6);
	d=f.getRecord("file7");
	int e;
	e=f.addInformationToFile();
	getch();
  //  f.reNameFile();

	//d.blockCount=123;
	//d.descriptorType="abccvc";
	//d.fileName="ascaxcx";
	//int a=f.addInformationToFile();
	//cout<<a;
	//f.writeRecord(d,7);
	//d1=f.getRecord(f.getRecordNumber("232323"));
	//y=f.getRecordNumber("232323");
	//f.deleteRecord("232323");
	//f.writeBlock(r,6);

//	y=f.findRecord('5');
	//char c;
	//f.memory.seekg(y);
	//c=f.memory.get();
//	f.writeBlock(r,6);
//	r=f.readBlock(6);

		
	//system("pause");
	}
