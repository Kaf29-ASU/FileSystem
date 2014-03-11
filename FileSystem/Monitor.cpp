#include "FileSystemMonitor.h"



int main()
{
	setlocale(LC_ALL, "Russian"); 
	//FileSystemMonitor f1;
	FileSystem f;
	//f1.workCycle();
	
	Block r;
	r.Clean();
	string p=r.getString(0,4);
	//f.createFile("test");
	f.openFile("test");
	f.format("23","tom","otherString","last");

	f.writeBlock(r,6);
	int y;
	y=f.findRecord("5");

	f.writeBlock(r,6);


};
