
#include "FileSystem.h"
#include <vector>
#include <iterator>

int FileSystem::showContentInAlphavit()
{
	int resultCode=0;
	vector <string> s(0);
	
	for (int i=0;i<218; i++)
		{
		FileDescriptor fileDescriptor=getRecord(i);
		if(fileDescriptor.descriptorType!="0000000000000000")
			{
				if (s.size()==0)
					{
						int number=fileDescriptor.fileName.find("|");
						s.insert(s.begin(),fileDescriptor.fileName.substr(0,number));
						number=fileDescriptor.fileType.find("|");
						s[0]+="."+fileDescriptor.fileType.substr(0,number);
					}


				if (s.size()>0)
				{int low=0, high=s.size()-1;
				 int number=fileDescriptor.fileName.find("|");
					
					if(s[high]<=fileDescriptor.fileName.substr(0,number))
					{s.insert(s.end(),fileDescriptor.fileName.substr(0,number));
					number=fileDescriptor.fileType.find("|");
					s[s.size()-1]+="."+fileDescriptor.fileType.substr(0,number);}
				
			else
				{int bord=high;
					while(low<high)
					{
						int middle=(low+high)/2;
						if (s[middle]>=fileDescriptor.fileName.substr(0,number))
							high=middle;
						else
							low=middle+1;
					}
					s.insert(s.begin()+low,fileDescriptor.fileName.substr(0,number));
					number=fileDescriptor.fileType.find("|");
					s[low]+="."+fileDescriptor.fileType.substr(0,number);
					}}

			
            }
		}
	
	copy( s.begin(), s.end(),ostream_iterator<string>(cout," ") );
	return(resultCode);

}
