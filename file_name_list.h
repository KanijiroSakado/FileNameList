#ifdef FILE_NAME_LIST_H
#else
#define FILE_NAME_LIST_H

#include <filesystem>
#include<vector>
#include<string>

using namespace std;

namespace sakado {

	class FileNameList {

	public:
		vector<string> FileNames;
		vector<string> DirNames;
		vector<string> FilePath;
		vector<string> DirPath;
		vector<FileNameList> Dirs;
		string Path;

		FileNameList() {
			FileNameList_Private(".");
		}

		FileNameList(string targetPath) {
			FileNameList_Private(targetPath);
		}

	private:

		void FileNameList_Private(string targetPath) {
			Path = targetPath;
			//ディレクトリ直下に含まれる全ファイル
			for (const filesystem::directory_entry& x : filesystem::directory_iterator(targetPath)) {
				if (x.is_directory()) {
					DirNames.push_back(x.path().filename().string());
					DirPath.push_back(Path + "/" + x.path().filename().string());
				}
				else {
					FileNames.push_back(x.path().filename().string());
					FilePath.push_back(Path + "/" + x.path().filename().string());
				}
			}
			for (string str : DirNames) {
				Dirs.push_back(*(new FileNameList(targetPath + "/" + str)));
			}
		}

	};

}
#endif
