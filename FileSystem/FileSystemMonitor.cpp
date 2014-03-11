#include "FileSystemMonitor.h"


void FileSystemMonitor::startWorking()
{
	cout<<"Доброго времени суток! Вас приветствует модель файловой системы ос реального времени. "<<endl;
		cout<<"Для продолжения работы с программой введите номер команды из представленного меню"<<endl<<endl;
		
}


int FileSystemMonitor::showMenu()
{
	cout<<endl;
	cout<<"1 - Вывести оглавление как есть"<<endl;
	cout<<"2 - Вывести оглавление по алфавиту"<<endl;
	cout<<"3 - Вывести информацию о пустом месте на диске и его характеристиках"<<endl;
	cout<<"4 - создать файл"<<endl;
	cout<<"5 - Удалить файл"<<endl;
	cout<<"6 - Перемеиновать файл"<<endl;
	cout<<"7 - Добавить информацию в существующий файл"<<endl;
	cout<<"8 - Сжатие файловой системы"<<endl;
	cout<<"9 - Изменение типа файла"<<endl;
	cout<<"10 - Записать метку тома и владельца"<<endl;
	cout<<"11 - Показать справку по командам файловой системы"<<endl;
	cout<<"0 - Завершение работы с программой"<<endl;
	cout<<"Введите номер команды"<<endl;
	int comandNumber;
	cin>>comandNumber;
	cout<<endl;
	return(comandNumber);
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
	cout<<"Введите имя файла"<<endl;
	cin>>fileName;
	string fileType;
	cout<<"Введите тип файла"<<endl;
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
	cout<<"Введите новое файла"<<endl;
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
	cout<<"Введите новый тип файла"<<endl;
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
		int comandNumber=showMenu();
		int resultCode=0;
		if(comandNumber==0) break;
		if(comandNumber==1){ showTableOfContents(); resultCode=1;};
		if(comandNumber==2){ showTableInAlphavit(); resultCode=1;};
		if(comandNumber==3){ showInformation(); resultCode=1;};
		if(comandNumber==4){ createNewFile(); resultCode=1;};
		if(comandNumber==5){ deleteFile(); resultCode=1;};
		if(comandNumber==6){ reNameFile(); resultCode=1;};
		if(comandNumber==7){ addInformationToFile(); resultCode=1;};
		if(comandNumber==8){ compressionOfFileSystem(); resultCode=1;};
		if(comandNumber==9){ changeFileType(); resultCode=1;};
		if(comandNumber==10){ writeVolumeLabelAndOwner(); resultCode=1;};
		if(comandNumber==11){ showHelp(); resultCode=1; this->fileSystem.closeFileSystem(); };
		if(!resultCode) cout<<"Некорректное входное значение. Повторите ввод"<<endl;
	}
}


