#include "FileSystem.h"

class FileSystemMonitor
{
public:
	FileSystem* filesystem;
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


};