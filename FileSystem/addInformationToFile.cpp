#include "FileSystem.h"

int FileSystem::addInformationToFile()
{//���������� ����������
	string fileName;
	int InformationCount;//���-�� ����������� ����������, 
	int resultCode;
	resultCode = 1;
	int rez = 16; //����������� ������� ����� �����
	int BlockNf, SegmNf,BlockNs,SegmNs; //����� ����� , ����� ��������
	FileDescriptor AddFile;
	FileDescriptor NextFile;
	int freeSpace; //���-�� ��������� ������ ����� ��������� ������

	//��������� �������
	cout << "������� ��� �����" << endl;
	cin >> fileName;
	cout << "������� ���-�� ����������� ����������" << endl;
	cin >> InformationCount;

	if (InformationCount > rez)//�������� �����
		return(1);
	AddFile = getRecord(fileName);
	if ((AddFile.fileType) == "")
		return(1);
	NextFile = getRecord(fileName);//��� ����� �� ��������� ��� ����� ��������� �����, ���-��






	

		return(resultCode);

{
	int resultCode=0;

	return(resultCode);

}