#include "FileSystemMonitor.h"



int main()
{
	setlocale(LC_ALL, "Russian"); 
	FileSystemMonitor f1;
	//FileSystem f;
	f1.workCycle();
	
	//Block r;
	//r.Clean();
	int y;
	//string p=r.getString(0,4);
	//f.createFile("4");
	//f.toInt("00010");
	//f.openFile("4");
	//f.format("23","tom","otherString","last");
	FileDescriptor d;
	FileDescriptor d1;
	d.blockCount=7;
	d.descriptorType="222";
	d.fileName="232323";
	//for(int i=0;i<10;i++)
	//f.writeRecord(d);
	d.blockCount=123;
	d.descriptorType="abccvc";
	d.fileName="ascaxcx";
	//f.writeRecord(d,7);
	//d1=f.getRecord(f.getRecordNumber("232323"));
	//y=f.getRecordNumber("232323");
	//f.deleteRecord("232323");
	//f.writeBlock(r,6);

//	y=f.findRecord('5');
	char c;
	//f.memory.seekg(y);
	//c=f.memory.get();
//	f.writeBlock(r,6);
//	r=f.readBlock(6);
	
	
};
