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
	cout<<"Для получения информации о входных параметрах и работе коианды введите номер команды со знаком <?>"<<endl;
	cout<<""<<endl;
	return(getch());
}


void FileSystemMonitor::workCycle()
{
	startWorking();
	for(;;)
	{
		int comandNumber=showMenu();
		if(comandNumber=='0') break;
	}
}