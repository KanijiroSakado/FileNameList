#include "file_name_list.h"

using namespace std;

int main() {

	sakado::FileNameList fnl("./test");

	cout <<"Target Directory : "<< fnl.Path<<"\n";
	cout << "\nFiles :\n";
	for (string str : fnl.FileNames)cout << str << "\n";
	cout << "\nDirectories :\n";
	for (string str : fnl.DirNames)cout << str << "\n";
	cout << "\nFile paths :\n";
	for (string str : fnl.FilePath)cout << str << "\n";
	cout << "\nDirectory paths :\n";
	for (string str : fnl.DirPath)cout << str << "\n";
	
	int dummy;
	cin >> dummy;
	
	return 0;
}
