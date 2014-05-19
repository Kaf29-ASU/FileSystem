#include "FileSystemMonitor.h"



void FileSystemMonitor::startWorking()
{
	cout<<"Доброго времени суток! Вас приветствует модель файловой системы ос реального времени. "<<endl;
		cout<<"Для продолжения работы с программой введите номер команды из представленного меню"<<endl<<endl;
		
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
	cout<<"Введите номер команды"<<endl;
	string comand;
	cin>>comand;
	cout<<endl;
	return(comand);
}

void FileSystemMonitor::showHelp()
{
	cout<<"Справка к командам файловой системы"<<endl;
	cout<<"1 - Функция выводит оглавление без сортировки"<<endl;
	cout<<"2 - Функция выводит оглавление отсортированное по алфавиту"<<endl;
	cout<<"3 - Функция выводит информацию о пустом месте на диске"<<endl;
	cout<<"4 - Функция создаёт новый файл с заданными характеристиками"<<endl;
	cout<<"5 - Функция удаляет файл заданный именем"<<endl;
	cout<<"6 - Функция изменяет имя существующего файла на диске"<<endl;
	cout<<"7 - Функция добавляет информацию в уже существующий файл"<<endl;
	cout<<"8 - Функция осуществляет дефрагментацию диска"<<endl;
	cout<<"9 - Функция изменяет тип существующего файла"<<endl;
	cout<<"10 - С помощью данной функции изменяются метка тома и владелец файловой системы"<<endl;
	cout<<"11 - Результат работы данной функции вы видите выше"<<endl;
	cout<<"12 - Функция позволяет отформатировать файловую систему"<<endl<<endl<<endl;
}

void FileSystemMonitor::showTableOfContents()
{
	int resultCode;
	resultCode=fileSystem.showTableOfContent();
	cout<<"успешное завершение"<<endl;
}

void FileSystemMonitor::showTableInAlphavit()
{
	int resultCode;
	resultCode=fileSystem.showContentInAlphavit();
	cout<<"успешное завершение"<<endl;
}

void FileSystemMonitor::createNewFile()
{
	int resultCode;
	resultCode=fileSystem.createNewFile();
	switch(resultCode)
	{
	case(0):
			cout<<"создаю файл"<<endl;

			break;
	case(2):
			cout<<"недостаточно места в системе"<<endl;
			break;
	case(22):
			cout<<"нет доступного места для записи в каталоге"<<endl;
			break;
	case(222):
			cout<<"файл с таким именем уже существует"<<endl;
	case(2222):
			cout<<"ошибка ввода данных"<<endl;
			break;
	

	};
}

void FileSystemMonitor::showInformation()
{
	int resultCode;
	resultCode=fileSystem.showInformation();
	cout<<"успешное завершение"<<endl;
}

void FileSystemMonitor::deleteFile()
{
	int resultCode;
	resultCode=fileSystem.deleteFile();
	switch(resultCode)
	{
	case(0):
			cout<<"успешное завершение"<<endl;

			break;
	case(1):
			cout<<"отсутствие искомого файла"<<endl;
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
			cout<<"успешное завершение"<<endl;
			break;
	case(1):
			cout<<"отсутствие искомого файла"<<endl;
			break;
	case(2):
			cout<<"файл с таким именем уже существует"<<endl;
			break;
	case(3):
			cout<<"недопустимая длина имени файла"<<endl;
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
			cout<<"успешное завершение"<<endl;
			break;
	case(1):
			cout<<"отсутствие искомого файла"<<endl;
			break;
	case(2):
			cout<<"файл имеет слишком большой размер"<<endl;
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
			cout<<"успешное завершение"<<endl;
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
			cout<<"успешное завершение"<<endl;
			break;
	case(1):
			cout<<"отсутствие искомого файла"<<endl;
			break;
	case(2):
			cout<<"недопустимый тип файла"<<endl;
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
			cout<<"успешное завершение"<<endl;
			break;
	case(1):
			cout<<"недопустимое имя владельца"<<endl;
			break;
	case(2):
			cout<<"недопустимая метка тома"<<endl;
			break;
	}
}

void FileSystemMonitor::createNewFileSystem()
{
	cout<<"Введите имя файла для сохранения файловой системы"<<endl;
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
		if (fileSystem.format(version, tomName, userName, systemName)==0) cout<<"форматирование успешно"<<endl;
		else {
			cout<<"некорректные входные данные, повторите ввод"<<endl;
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
		if (fileSystem.format(version, tomName, userName, systemName)==0) cout<<"форматирование успешно"<<endl;
		else {
			cout<<"некорректные входные данные, повторите ввод"<<endl;
			 formatFileSystem();
		}
		
};


void FileSystemMonitor::workCycle()
{
	this->startWorking();
	cout<<"Если вы хотите работать с уже существующим файлом ведите 1"<<endl;
	cout<<"Если вы хотите создать новый файл введите 2"<<endl;
	int startType;
	cin>>startType;
	
	while((startType!=1)&&(startType!=2))
	{
		cout<<"Некорректный ввод. Введите 1 или 2"<<endl;
		cin>>startType;
	};
	if(startType==2)
	{
		createNewFileSystem();
	
	};
	if(startType==1)
	{
		cout<<"Введите имя существующего файла "<<endl;
		string fileSystemName;
		cin>>fileSystemName;
		fileSystem.openFile(fileSystemName);
		while(!fileSystem.memory.is_open())
		{
			cout<<"Введите имя существующего файла "<<endl;
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

		if(!resultCode) cout<<"Некорректное входное значение. Повторите ввод"<<endl;

	};
}



