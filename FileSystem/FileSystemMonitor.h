#include "FileSystem.h"
#include <iomanip>
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

	void startWorking();
	int showMenu();
	void workCycle();
	void showHelp();
};