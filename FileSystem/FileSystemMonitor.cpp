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
	cout<<"1 - Вывести оглавление как есть <здесь будет справка>"<<endl;
	cout<<"2 - Вывести оглавление по алфавиту <здесь будет справка>"<<endl;
	cout<<"3 - Вывести информацию о пустом месте на диске и его характеристиках <здесь будет справка>"<<endl;
	cout<<"4 - создать файл <здесь будет справка>"<<endl;
	cout<<"5 - Удалить файл <здесь будет справка>"<<endl;
	cout<<"6 - Перемеиновать файл <здесь будет справка>"<<endl;
	cout<<"7 - Добавить информацию в существующий файл <здесь будет справка>"<<endl;
	cout<<"8 - Сжатие файловой системы <здесь будет справка>"<<endl;
	cout<<"9 - Изменение типа файла <здесь будет справка>"<<endl;
	cout<<"10 - Записать метку тома и владельца <здесь будет справка>"<<endl;
	cout<<"11 - Показать справку по командам файловой системы <здесь будет справка>"<<endl<<endl<<endl;
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
	cout<<"создаю файл"<<endl;
}

void FileSystemMonitor::showInformation()
{
	cout<<"показываю информацию о пустом месте на диске"<<endl;
}

void FileSystemMonitor::deleteFile()
{
	cout<<"удаляю файл"<<endl;
}

void FileSystemMonitor::reNameFile()
{
	cout<<"переименовываю файл"<<endl;
}

void FileSystemMonitor::addInformationToFile()
{
	cout<<"добавляю информацию в файл"<<endl;
}

void FileSystemMonitor::compressionOfFileSystem()
{
	cout<<"сжимаю файловую систему"<<endl;
}

void FileSystemMonitor::changeFileType()
{
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
		fileSystem.format(version, tomName, userName, systemName);
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
		if(comandNumber==11){ showHelp(); resultCode=1;};
		if(!resultCode) cout<<"Некорректное входное значение. Повторите ввод"<<endl;
	}
}


