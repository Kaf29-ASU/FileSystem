#include <conio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;


struct FileDescriptor
{
public:
	string descriptorType;
	string fileName;
	string fileType;
	string blockCount;
	string creationDate;
	string firstBlockNumber;

};