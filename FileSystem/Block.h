
#include "Word.h"
#include <sstream>

class Block
{
public:
	char byteMassive[512];
	void Clean();
	void InsertString(int,string);
	int getInt(int,int);
	string getString(int,int);
};