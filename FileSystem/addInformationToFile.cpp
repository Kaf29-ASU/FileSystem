#include "FileSystem.h"

int FileSystem::addInformationToFile()
{//���������� ����������
	string FileName;
	int InformationCount;//���-�� ����������� ����������, 
	int resultCode;
	resultCode = 1;
	int lenCritical =16;
	int CntCritical = 2 ^ 9;
	int BlockNf, SegmNf, BlockNs, SegmNs; //����� ����� , ����� ��������
	FileDescriptor AddFile;
	FileDescriptor NextFile;
	int freeSpace; //���-�� ��������� ������ ����� ��������� ������

	//��������� �������
	cout << "������� ��� �����" << endl;
	cin >> FileName;
	if (FileName.length > lenCritical)//�������� ����� �����
		return(1);

	cout << "������� ���-�� ����������� ����������" << endl;
	cin >> InformationCount;
	if (InformationCount > CntCritical)//�������� ����� ���-�� ���������� 
		return(1);

	AddFile = getRecord(FileName);
	if ((AddFile.fileType) == "")
		return(1);
	NextFile = getRecord(FileName);//��� ����� �� ��������� ��� ����� ��������� �����, ���-��
	






	//AddFile.blockCount += InformationCount; //�������� ���-�� ���. � �����
	return(resultCode);
}

//{
//	int resultCode=0;
//
//	return(resultCode);
//
//}
