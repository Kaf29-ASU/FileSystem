#include "FileSystemMonitor.h"



int main()
{
	setlocale(LC_ALL, "Russian"); 
	FileSystemMonitor f1;
	FileSystem f;
	f1.workCycle();
	
	Block r;
	r.Clean();
	string p=r.getString(0,4);
	//f.createFile("test");
	f.openFile("test");
	f.format("23","tom","otherString","last");

	f.writeBlock(r,6);
	int y;
	y=f.findRecord("000");
<<<<<<< HEAD
=======
	f.writeBlock(r,6);*/
=======

	f.writeBlock(r,6);


>>>>>>> b0d4cfdc9d14ae7d6a18465f3d39fe52b47f8219
};
