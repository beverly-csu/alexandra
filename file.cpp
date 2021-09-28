#include "file.hpp"

void MyFile::setPath(fs::path p) {
	path = p;
	path = path.native();
}

MyFile::MyFile(fs::path p) {
	setPath(p);
	setSize();
}

void MyFile::setSize() {
	error_code ec;
	
	size = fs::file_size(path, ec);
	if (ec) {
		cout << ec.message() << " " << path << endl;
	}
	size = getRoundSize();
}

uintmax_t MyFile::getRoundSize() {
	if (size % 1024)
		return size / 1024 + 1;
	else return size /= 1024;
}

void Files::setPath(fs::path p) {
	path = p;
	path = path.native();
}

void Files::getFiles() {
	for (auto& p : fs::directory_iterator(path)) {
		if (!fs::is_directory(p)) {
			MyFile file(p);
			files.push_back(file);
		}
	}
}

Files::Files(fs::path p) {
	dirIterator = 1;
	setPath(p);
	getFiles();
}

void Files::createDir() {
	fs::path p = path.string() + "/Директория " + to_string(dirIterator);
	fs::create_directory(p);
	++dirIterator;
}

void Files::moveFile(fs::path oldPath, fs::path newPath) {
	fs::rename(oldPath, newPath);
}

void Files::moveFiles() {	
	for (int i = 0; i < files.size(); ++i) {
		fs::path pathDir = path.string() + "/Директория " + to_string(dirIterator) + "/";
		fs::path dopPath = pathDir.string() + files[i].path.filename().string();
		if (files[i].size >= 100) {
			createDir();
			moveFile(files[i].path, dopPath);

		}
		else {
			uintmax_t dopSize = 0;
			createDir();
			while ((dopSize + files[i].size <= 100) && (i < files.size())) {
				fs::path dopPath = pathDir.string() + files[i].path.filename().string();
				moveFile(files[i].path, dopPath);
				dopSize += files[i].size;
				++i;
			}
			if (dopSize + files[i].size > 100) --i;
		}
	}
}