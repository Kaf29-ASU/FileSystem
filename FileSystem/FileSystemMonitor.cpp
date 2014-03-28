#include "FileSystemMonitor.h"


void FileSystemMonitor::startWorking()
{
	cout<<"������� ������� �����! ��� ������������ ������ �������� ������� �� ��������� �������. "<<endl;
		cout<<"��� ����������� ������ � ���������� ������� ����� ������� �� ��������������� ����"<<endl<<endl;
		
}


string FileSystemMonitor::showMenu()
{
	cout<<endl;
	cout<<"1(showContent) - ������� ���������� ��� ����"<<endl;
	cout<<"2(showInAlphavit) - ������� ���������� �� ��������"<<endl;
	cout<<"3(showInformation) - ������� ���������� � ������ ����� �� ����� � ��� ���������������"<<endl;
	cout<<"4(createNewFile) - ������� ����"<<endl;
	cout<<"5(deleteFile) - ������� ����"<<endl;
	cout<<"6(reNameFile) - ������������� ����"<<endl;
	cout<<"7(addInformation) - �������� ���������� � ������������ ����"<<endl;
	cout<<"8(compression) - ������ �������� �������"<<endl;
	cout<<"9(changeFileType) - ��������� ���� �����"<<endl;
	cout<<"10(writeFileSystemInformation) - �������� ����� ���� � ���������"<<endl;
	cout<<"11(showHelp) - �������� ������� �� �������� �������� �������"<<endl;
	cout<<"0 - ���������� ������ � ����������"<<endl;
	cout<<"������� ����� �������"<<endl;
	string comand;
	cin>>comand;
	cout<<endl;
	return(comand);
}

void FileSystemMonitor::showHelp()
{
	cout<<"������� � �������� �������� �������"<<endl;
	cout<<"1 - ������� ������� ���������� ��� ����������"<<endl;
	cout<<"2 - ������� ������� ���������� ��������������� �� ��������"<<endl;
	cout<<"3 - ������� ������� ���������� � ������ ����� �� �����"<<endl;
	cout<<"4 - ������� ������ ����� ���� � ��������� ����������������"<<endl;
	cout<<"5 - ������� ������� ���� �������� ������"<<endl;
	cout<<"6 - ������� �������� ��� ������������� ����� �� �����"<<endl;
	cout<<"7 - ������� ��������� ���������� � ��� ������������ ����"<<endl;
	cout<<"8 - ������� ������������ �������������� �����"<<endl;
	cout<<"9 - ������� �������� ��� ������������� �����"<<endl;
	cout<<"10 - � ������� ������ ������� ���������� ����� ���� � �������� �������� �������"<<endl;
	cout<<"11 - ��������� ������ ������ ������� �� ������ ����"<<endl<<endl<<endl;
}

void FileSystemMonitor::showTableOfContents()
{
	cout<<"��������� ����������"<<endl;
}

void FileSystemMonitor::showTableInAlphavit()
{
	cout<<"��������� ���������� �� ��������"<<endl;
}

void FileSystemMonitor::createNewFile()
{
	string fileName;
	cout<<"������� ��� ����� �� ����������� 32 �������"<<endl;
	cin>>fileName;
	string fileType;
	cout<<"������� ��� ����� �� ����������� 16 �������"<<endl;
	cin>>fileType;
	string fileSize;
	cout<<"������� ������ ����� � ������"<<endl;
	cin>>fileSize;
	char creationDate[16];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(creationDate, 16, format, timeinfo);
	cout<<endl<<"���� �������� �����: "<<creationDate<<endl;
	
	cout<<"������ ����"<<endl;
}

void FileSystemMonitor::showInformation()
{
	cout<<"��������� ���������� � ������ ����� �� �����"<<endl;
}

void FileSystemMonitor::deleteFile()
{
	cout<<"������� ��� ������� �����"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"������ ����"<<endl;
}

void FileSystemMonitor::reNameFile()
{
	cout<<"������� ��� ������� �����"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"������� ����� ��� ����� �� ����������� 32 �������"<<endl;
	string newFileName;
	cin>>newFileName;
	cout<<"�������������� ����"<<endl;
}

void FileSystemMonitor::addInformationToFile()
{
	cout<<"������� ��� ������� �����"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"�������� ���������� � ����"<<endl;
}

void FileSystemMonitor::compressionOfFileSystem()
{
	cout<<"������ �������� �������"<<endl;
}

void FileSystemMonitor::changeFileType()
{
	cout<<"������� ��� ������� �����"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"������� ����� ��� ����� �� ����������� 16 ��������"<<endl;
	string fileType;
	cin>>fileType;
	cout<<"����� ��� �����"<<endl;
}

void FileSystemMonitor::writeVolumeLabelAndOwner()
{
	cout<<"����� ����� ���� � ���������"<<endl;
}

void FileSystemMonitor::workCycle()
{
	startWorking();
	cout<<"���� �� ������ �������� � ��� ������������ ������ ������ 1"<<endl;
	cout<<"���� �� ������ ������� ����� ���� ������� 2"<<endl;
	int startType;
	cin>>startType;
	while((startType!=1)&&(startType!=2))
	{
		cout<<"������������ ����. ������� 1 ��� 2"<<endl;
		cin>>startType;
	};
	if(startType==2)
	{
		cout<<"������� ��� ����� ��� ���������� �������� �������"<<endl;
		string fileSystemName;
		cin>>fileSystemName;
		fileSystem.createFile(fileSystemName);
		string version;
		cout<<"print version"<<endl;
		cin>>version;
		string tomName;
		cout<<"print tomName"<<endl;
		cin>>tomName;
		string userName;
		cout<<"print userName"<<endl;
		cin>>userName;
		string systemName;
		cout<<"print systemName"<<endl;
		cin>>systemName;
		this->fileSystem.format(version, tomName, userName, systemName);
	};
	if(startType==1)
	{
		cout<<"������� ��� ������������� ����� "<<endl;
		string fileSystemName;
		cin>>fileSystemName;
		fileSystem.openFile(fileSystemName);
	};
	for(;;)
	{
		cout<<endl;
		string comand=showMenu();
		int resultCode=0;
		if((comand.compare("0")==0)||(comand.compare("exit")==0))
			{ break;};

		if((comand.compare("1")==0)||(comand.compare("showContent")==0))
			{ showTableOfContents(); resultCode=1;};

		if((comand.compare("2")==0)||(comand.compare("showInAlphavit")==0))
			{ showTableInAlphavit(); resultCode=1;};

		if((comand.compare("3")==0)||(comand.compare("showInformation")==0))
			{ showInformation(); resultCode=1;};

		if((comand.compare("4")==0)||(comand.compare("createNewFile")==0))
			{ createNewFile(); resultCode=1;};

		if((comand.compare("5")==0)||(comand.compare("deleteFile")==0))
			{ deleteFile(); resultCode=1;};

		if((comand.compare("6")==0)||(comand.compare("reNameFile")==0))
			{ reNameFile(); resultCode=1;};

		if((comand.compare("7")==0)||(comand.compare("addInformation")==0))
			{ addInformationToFile(); resultCode=1;};

		if((comand.compare("8")==0)||(comand.compare("compression")==0))
			{ compressionOfFileSystem(); resultCode=1;};

		if((comand.compare("9")==0)||(comand.compare("changeFileType")==0))
			{ changeFileType(); resultCode=1;};

		if((comand.compare("10")==0)||(comand.compare("writeFileSystemInformation")==0))
			{ writeVolumeLabelAndOwner(); resultCode=1;};

		if((comand.compare("11")==0)||(comand.compare("showHelp")==0))
			{ showHelp(); resultCode=1; this->fileSystem.closeFileSystem(); };

		if(!resultCode) cout<<"������������ ������� ��������. ��������� ����"<<endl;
	}
}


