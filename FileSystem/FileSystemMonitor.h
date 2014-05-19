#include "FileSystem.h"
#include <iomanip>
#include <ctime>
#include <string>
//using namespace System;


class FileSystemMonitor
{
public:
	FileSystem fileSystem;
	void createNewFileSystem();
	void showTableOfContents();
	void showInformation();
	void createNewFile();
	void deleteFile();
	void reNameFile();
	void addInformationToFile();
	void compressionOfFileSystem();
	void changeFileType();
	void writeVolumeLabelAndOwner();
	void showTableInAlphavit();
	void formatFileSystem();

	inline void startWorking();
	inline string showMenu();
	void workCycle();
	inline void showHelp();
};