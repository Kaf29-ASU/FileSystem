#include "FileSystem.h"
#include "string"
int FileSystem::addInformationToFile()
{//���������� ����������
	string FileName;
	int InformationCount;//���-�� ����������� ����������, 
	int resultCode;
	resultCode = 1;
	int lenCritical = 48;
	int CntCritical = 2 ^ 9;
	int BlockNf, SegmNf, BlockNs, SegmNs; //����� ����� , ����� ��������
	FileDescriptor AddFile;
	FileDescriptor NextFile;
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
	/*
	if (((AddFile.firstBlockNumber) + (AddFile.blockCount) + InformationCount / 512) >= (NextFile.firstBlockNumber))
		
	else

	AddFile.blockCount += InformationCount; //�������� ���-�� ���. � �����
	*/
	return(resultCode);
}

//{
//	int resultCode=0;
//
//	return(resultCode);
//
//}
