#include "FileSystem.h"
#include "string"
int FileSystem::addInformationToFile()
{//���������� ����������
	string FileName;
	int InformationCount;//���-�� ����������� ����������, 
	int CountLength=8;
	int resultCode = 1;
	int lenCritical = 48;
	int CntCritical = 2 ^ 9;
	int BlockNf, SegmNf, BlockNs, SegmNs; //����� ����� , ����� ��������
	FileDescriptor AddFile;
	FileDescriptor NextFile;
	FileDescriptor LastFile;
	int ResultCount;
	int freeSpace; //���-�� ��������� ������ ����� ��������� ������
	int RecordNumber,NextRecordNumber; //����� ���������� ������, ����� ��������� ������
	int i; //�������

	//��������� �������
	cout << "������� ��� �����" << endl;
	cin >> FileName;
	if (FileName.length() > lenCritical)//�������� ����� �����
		return(1);

	cout << "������� ���-�� ����������� ����������" << endl;
	cin >> InformationCount;
	if (InformationCount > CntCritical)//�������� ����� ���-�� ���������� 
		return(1);

	AddFile = getRecord(FileName);
	if ((AddFile.fileType) == "")					//!!!!!!!� ����������� ����� ������ ������ �����!!!!!!
		return(1);
	RecordNumber=getRecordNumber(FileName);
	NextRecordNumber=RecordNumber+1;
	NextFile=getRecord(NextRecordNumber);
	
	//AddFile.blockCount=(AddFile.blockCount+InformationCount); //�������� ���-�� ���. � �����
	if ((toInt(AddFile.firstBlockNumber) + AddFile.blockCount + InformationCount / 512) > (toInt(NextFile.firstBlockNumber)))
	{
		LastFile=AddFile;
		LastFile.blockCount+=InformationCount;
		for(i=217;((getRecord(i).fileType)=="");i--)
		LastFile.firstBlockNumber=toString((toInt(getRecord(i).firstBlockNumber)+getRecord(i).blockCount+1),8);
		deleteRecord(FileName);
		writeRecord(LastFile);
		resultCode=0;
	}
	else 
	{
		//getRecord(FileName).blockCount+=InformationCount;
		AddFile.blockCount=(AddFile.blockCount+InformationCount);

		resultCode=0;
	}
	return(resultCode);
}

