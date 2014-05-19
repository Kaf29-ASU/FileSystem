#include "FileSystemMonitor.h"



void FileSystemMonitor::startWorking()
{
	cout<<"������� ������� �����! ��� ������������ ������ �������� ������� �� ��������� �������. "<<endl;
		cout<<"��� ����������� ������ � ���������� ������� ����� ������� �� ��������������� ����"<<endl<<endl;
		
}


string FileSystemMonitor::showMenu()
{
	cout<<endl;
	cout<<"1 - content"<<endl;
	cout<<"2 - contenta"<<endl;
	cout<<"3 - dinfo"<<endl;
	cout<<"4 - createf"<<endl;
	cout<<"5 - delf"<<endl;
	cout<<"6 - renamef"<<endl;
	cout<<"7 - addinfo"<<endl;
	cout<<"8 - compress"<<endl;
	cout<<"9 - chft"<<endl;
	cout<<"10 - fsparam"<<endl;
	cout<<"11 - help"<<endl;
	cout<<"12 - createfs"<<endl;
	cout<<"0 - exit"<<endl;
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
	cout<<"11 - ��������� ������ ������ ������� �� ������ ����"<<endl;
	cout<<"12 - ������� ��������� ��������������� �������� �������"<<endl<<endl<<endl;
}

void FileSystemMonitor::showTableOfContents()
{
	int resultCode;
	resultCode=fileSystem.showTableOfContent();
	cout<<"�������� ����������"<<endl;
}

void FileSystemMonitor::showTableInAlphavit()
{
	int resultCode;
	resultCode=fileSystem.showContentInAlphavit();
	cout<<"�������� ����������"<<endl;
}

void FileSystemMonitor::createNewFile()
{
	int resultCode;
	resultCode=fileSystem.createNewFile();
	switch(resultCode)
	{
	case(0):
			cout<<"������ ����"<<endl;

			break;
	case(2):
			cout<<"������������ ����� � �������"<<endl;
			break;
	case(22):
			cout<<"��� ���������� ����� ��� ������ � ��������"<<endl;
			break;
	case(222):
			cout<<"���� � ����� ������ ��� ����������"<<endl;
	case(2222):
			cout<<"������ ����� ������"<<endl;
			break;
	

	};
}

void FileSystemMonitor::showInformation()
{
	int resultCode;
	resultCode=fileSystem.showInformation();
	cout<<"�������� ����������"<<endl;
}

void FileSystemMonitor::deleteFile()
{
	int resultCode;
	resultCode=fileSystem.deleteFile();
	switch(resultCode)
	{
	case(0):
			cout<<"�������� ����������"<<endl;

			break;
	case(1):
			cout<<"���������� �������� �����"<<endl;
			break;
	}
}

void FileSystemMonitor::reNameFile()
{
	int resultCode;
	resultCode=fileSystem.reNameFile();
	switch(resultCode)
	{
	case(0):
			cout<<"�������� ����������"<<endl;
			break;
	case(1):
			cout<<"���������� �������� �����"<<endl;
			break;
	case(2):
			cout<<"���� � ����� ������ ��� ����������"<<endl;
			break;
	case(3):
			cout<<"������������ ����� ����� �����"<<endl;
			break;
	}

}

void FileSystemMonitor::addInformationToFile()
{
	int resultCode;
	resultCode=fileSystem.addInformationToFile();
	switch(resultCode)
	{
	case(0):
			cout<<"�������� ����������"<<endl;
			break;
	case(1):
			cout<<"���������� �������� �����"<<endl;
			break;
	case(2):
			cout<<"���� ����� ������� ������� ������"<<endl;
			break;
	
	}
}

void FileSystemMonitor::compressionOfFileSystem()
{
	int resultCode;
	resultCode=fileSystem.compressionOfFileSystem();
	switch(resultCode)
	{
	case(0):
			cout<<"�������� ����������"<<endl;
			break;
	
	}
}

void FileSystemMonitor::changeFileType()
{
	int resultCode;
	resultCode=fileSystem.changeFileType();
	switch(resultCode)
	{
	case(0):
			cout<<"�������� ����������"<<endl;
			break;
	case(1):
			cout<<"���������� �������� �����"<<endl;
			break;
	case(2):
			cout<<"������������ ��� �����"<<endl;
			break;
	
	}
}

void FileSystemMonitor::writeVolumeLabelAndOwner()
{
	int resultCode;
	resultCode=fileSystem.writeVolumeLabelAndOwner();
	switch(resultCode)
	{
	case(0):
			cout<<"�������� ����������"<<endl;
			break;
	case(1):
			cout<<"������������ ��� ���������"<<endl;
			break;
	case(2):
			cout<<"������������ ����� ����"<<endl;
			break;
	}
}

void FileSystemMonitor::createNewFileSystem()
{
	cout<<"������� ��� ����� ��� ���������� �������� �������"<<endl;
		string fileSystemName;
		cin>>fileSystemName;
		//fileSystem.createFile(fileSystemName);
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
		fileSystem.createFile(fileSystemName);
		fileSystem.openFile(fileSystemName);
		if (fileSystem.format(version, tomName, userName, systemName)==0) cout<<"�������������� �������"<<endl;
		else {
			cout<<"������������ ������� ������, ��������� ����"<<endl;
			 formatFileSystem();
		}
}

void FileSystemMonitor::formatFileSystem()
{
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
		if (fileSystem.format(version, tomName, userName, systemName)==0) cout<<"�������������� �������"<<endl;
		else {
			cout<<"������������ ������� ������, ��������� ����"<<endl;
			 formatFileSystem();
		}
		
};


void FileSystemMonitor::workCycle()
{
	this->startWorking();
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
		createNewFileSystem();
	
	};
	if(startType==1)
	{
		cout<<"������� ��� ������������� ����� "<<endl;
		string fileSystemName;
		cin>>fileSystemName;
		fileSystem.openFile(fileSystemName);
		while(!fileSystem.memory.is_open())
		{
			cout<<"������� ��� ������������� ����� "<<endl;
			string fileSystemName;
			cin>>fileSystemName;
			fileSystem.openFile(fileSystemName);
		}
	};
	for(;;)
	{
		cout<<endl;
		string comand=this->showMenu();
		int resultCode=0;
		if((comand.compare("0")==0)||(comand.compare("exit")==0))
			{fileSystem.closeFileSystem(); break;};

		if((comand.compare("1")==0)||(comand.compare("content")==0))
			{ showTableOfContents(); resultCode=1;};

		if((comand.compare("2")==0)||(comand.compare("contenta")==0))
			{ showTableInAlphavit(); resultCode=1;};
		if((comand.compare("3")==0)||(comand.compare("showinfo")==0))
			{ showInformation(); resultCode=1;};

		if((comand.compare("4")==0)||(comand.compare("createf")==0))
			{ createNewFile(); resultCode=1;};

		if((comand.compare("5")==0)||(comand.compare("delf")==0))
			{ deleteFile(); resultCode=1;};

		if((comand.compare("6")==0)||(comand.compare("renamef")==0))
			{ reNameFile(); resultCode=1;};

		if((comand.compare("7")==0)||(comand.compare("addinfo")==0))
			{ addInformationToFile(); resultCode=1;};

		if((comand.compare("8")==0)||(comand.compare("compress")==0))
			{ compressionOfFileSystem(); resultCode=1;};

		if((comand.compare("9")==0)||(comand.compare("chft")==0))
			{ changeFileType(); resultCode=1;};

		if((comand.compare("10")==0)||(comand.compare("fsparam")==0))
			{ 
				resultCode=1;
				writeVolumeLabelAndOwner();
			};

		if((comand.compare("11")==0)||(comand.compare("help")==0))
			{ showHelp(); resultCode=1; };

		if((comand.compare("12")==0)||(comand.compare("createfs")==0))
		{ formatFileSystem(); resultCode=1;};

		if(!resultCode) cout<<"������������ ������� ��������. ��������� ����"<<endl;

	};
}



