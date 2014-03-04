#include "FileSystemMonitor.h"


void FileSystemMonitor::startWorking()
{
	cout<<"Доброго времени суток! Вас приветствует модель файловой системы ос реального времени. "<<endl;
		cout<<"Для продолжения работы с программой введите номер команды из представленного"<<endl;
		
}


int FileSystemMonitor::showMenu()
{
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
	cout<<"Для получения информации о входных параметрах и работе коианды введите номер команды со знаком <?>"<<endl;
	cout<<"Введите номер команды"<<endl;
	int comandNumber;
	cin>>comandNumber;
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

}

void FileSystemMonitor::showTableInAlphavit()
{

}

void FileSystemMonitor::createNewFile()
{

}

void FileSystemMonitor::showInformation()
{

}

void FileSystemMonitor::deleteFile()
{

}

void FileSystemMonitor::reNameFile()
{

}

void FileSystemMonitor::addInformationToFile()
{

}

void FileSystemMonitor::compressionOfFileSystem()
{

}

void FileSystemMonitor::changeFileType()
{

}

void FileSystemMonitor::writeVolumeLabelAndOwner()
{

}

void FileSystemMonitor::workCycle()
{
	startWorking();
	for(;;)
	{
		int comandNumber=showMenu();
		if(comandNumber==0) break;
		if(comandNumber==1) showTableOfContents();
		if(comandNumber==2) showTableInAlphavit();
		if(comandNumber==3) showInformation();
		if(comandNumber==4) createNewFile();
		if(comandNumber==5) deleteFile();
		if(comandNumber==6) reNameFile();
		if(comandNumber==7) addInformationToFile();
		if(comandNumber==8) compressionOfFileSystem();
		if(comandNumber==9) changeFileType();
		if(comandNumber==10) writeVolumeLabelAndOwner();
		if(comandNumber==11) showHelp();
	}
}