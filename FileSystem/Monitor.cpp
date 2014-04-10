#include "FileSystemMonitor.h"



int main()
{
	setlocale(LC_ALL, "Russian"); 
	FileSystemMonitor f1;
	FileSystem f;
	f1.workCycle();
	
	Block r;
	r.Clean();
	//string p=r.getString(0,4);
	//f.createFile("4");
	f.toInt("00010");
	f.openFile("4");
	f.format("23","tom","otherString","last");
	FileDescriptor d;
	d.blockCount="4";
	d.descriptorType="1111";
	d.fileName="ngdfghdfgjdgjd";
	for(int i=0;i<250;i++)
	f.writeRecord(d);
	//f.writeBlock(r,6);
	int y;

//	y=f.findRecord('5');
	char c;
	//f.memory.seekg(y);
	//c=f.memory.get();
//	f.writeBlock(r,6);
//	r=f.readBlock(6);
	

};
