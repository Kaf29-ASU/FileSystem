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
	if ((AddFile.fileType) == "")
		return(1);
	NextFile = getNextRecord(FileName);
	//LastFile=getLastFile();
	AddFile.blockCount=toString((toInt(AddFile.blockCount)+InformationCount),CountLength); //�������� ���-�� ���. � �����
	if ((toInt(AddFile.firstBlockNumber) + toInt(AddFile.blockCount) + InformationCount / 512) > (toInt(NextFile.firstBlockNumber)))
	{//AddFile.firstBlockNumber=FindLastFi
	}	
	return(resultCode);
}

//{
//	int resultCode=0;
//
//	return(resultCode);
//
//}
