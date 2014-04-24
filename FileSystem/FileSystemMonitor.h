#include "FileSystem.h"
#include <iomanip>
#include <ctime>

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
	void writeVolumeLabelAndOwner(string VolumeLabel, string Owner);
	void showTableInAlphavit();
	void formatFileSystem();

	void startWorking();
	string showMenu();
	void workCycle();
	void showHelp();
};