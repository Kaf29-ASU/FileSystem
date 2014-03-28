#include "FileSystemMonitor.h"


void FileSystemMonitor::startWorking()
{
	cout<<"Доброго времени суток! Вас приветствует модель файловой системы ос реального времени. "<<endl;
		cout<<"Для продолжения работы с программой введите номер команды из представленного меню"<<endl<<endl;
		
}


string FileSystemMonitor::showMenu()
{
	cout<<endl;
	cout<<"1(showContent) - Вывести оглавление как есть"<<endl;
	cout<<"2(showInAlphavit) - Вывести оглавление по алфавиту"<<endl;
	cout<<"3(showInformation) - Вывести информацию о пустом месте на диске и его характеристиках"<<endl;
	cout<<"4(createNewFile) - создать файл"<<endl;
	cout<<"5(deleteFile) - Удалить файл"<<endl;
	cout<<"6(reNameFile) - Перемеиновать файл"<<endl;
	cout<<"7(addInformation) - Добавить информацию в существующий файл"<<endl;
	cout<<"8(compression) - Сжатие файловой системы"<<endl;
	cout<<"9(changeFileType) - Изменение типа файла"<<endl;
	cout<<"10(writeFileSystemInformation) - Записать метку тома и владельца"<<endl;
	cout<<"11(showHelp) - Показать справку по командам файловой системы"<<endl;
	cout<<"0 - Завершение работы с программой"<<endl;
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
	cout<<"11 - Результат работы данной функции вы видите выше"<<endl<<endl<<endl;
}

void FileSystemMonitor::showTableOfContents()
{
	cout<<"показываю оглавление"<<endl;
}

void FileSystemMonitor::showTableInAlphavit()
{
	cout<<"показываю оглавление по алфавиту"<<endl;
}

void FileSystemMonitor::createNewFile()
{
	string fileName;
	cout<<"Введите имя файла не превышающее 32 символа"<<endl;
	cin>>fileName;
	string fileType;
	cout<<"Введите тип файла не превышающий 16 сиволов"<<endl;
	cin>>fileType;
	string fileSize;
	cout<<"Введите размер файла в байтах"<<endl;
	cin>>fileSize;
	char creationDate[16];
	time_t seconds = time(NULL);
	tm* timeinfo = localtime(&seconds);
	char* format = "%B %d, %Y";
	strftime(creationDate, 16, format, timeinfo);
	cout<<endl<<"Дата создания файла: "<<creationDate<<endl;
	
	cout<<"создаю файл"<<endl;
}

void FileSystemMonitor::showInformation()
{
	cout<<"показываю информацию о пустом месте на диске"<<endl;
}

void FileSystemMonitor::deleteFile()
{
	cout<<"Введите имя нужного файла"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"удаляю файл"<<endl;
}

void FileSystemMonitor::reNameFile()
{
	cout<<"Введите имя нужного файла"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"Введите новое имя файла не превышающее 32 символа"<<endl;
	string newFileName;
	cin>>newFileName;
	cout<<"переименовываю файл"<<endl;
}

void FileSystemMonitor::addInformationToFile()
{
	cout<<"Введите имя нужного файла"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"добавляю информацию в файл"<<endl;
}

void FileSystemMonitor::compressionOfFileSystem()
{
	cout<<"сжимаю файловую систему"<<endl;
}

void FileSystemMonitor::changeFileType()
{
	cout<<"Введите имя нужного файла"<<endl;
	string fileName;
	cin>>fileName;
	cout<<"Введите новый тип файла не превышающий 16 символов"<<endl;
	string fileType;
	cin>>fileType;
	cout<<"меняю тип файла"<<endl;
}

void FileSystemMonitor::writeVolumeLabelAndOwner()
{
	cout<<"меняю метку тома и владельца"<<endl;
}

void FileSystemMonitor::workCycle()
{
	startWorking();
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
		cout<<"Введите имя файла для сохранения файловой системы"<<endl;
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
		cout<<"Введите имя существующего файла "<<endl;
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

		if(!resultCode) cout<<"Некорректное входное значение. Повторите ввод"<<endl;
	}
}


