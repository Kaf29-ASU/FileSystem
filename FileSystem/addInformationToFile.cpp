#include "FileSystem.h"

int FileSystem::addInformationToFile()
<<<<<<< HEAD
{//���������� ����������
	string FileName;
=======
{
	//���������� ����������
	string fileName;
>>>>>>> e881486cc22b5f2da5945db442d4a3d6e0080c98
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
<<<<<<< HEAD
	NextFile = getRecord(FileName);//��� ����� �� ��������� ��� ����� ��������� �����, ���-��
	






	//AddFile.blockCount += InformationCount; //�������� ���-�� ���. � �����
	return(resultCode);
=======
	NextFile = getRecord(fileName);//��� ����� �� ��������� ��� ����� ��������� �����, ���-��

return(resultCode);

>>>>>>> e881486cc22b5f2da5945db442d4a3d6e0080c98
}

//{
//	int resultCode=0;
//
//	return(resultCode);
//
//}
