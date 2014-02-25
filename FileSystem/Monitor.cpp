#include "FileSystem.h"



int main()
{
	FileSystem f;
	Block r;
	//f.createFile("test");
	//f.openFile("test");
	//f.format("23","tom","otherString","last");
	r=f.readBlock(1);
	cout<<r.byteMassive<<endl;
	getch();
};
