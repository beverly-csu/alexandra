#pragma once
#include <iostream>
#include <vector>
#include <filesystem>
#include <clocale>
#include <string>

namespace fs = std::filesystem;
using namespace std; 

class MyFile
{
public:
	uintmax_t size;
	fs::path path;
	MyFile(fs::path);
	void setPath(fs::path);
private:
	uintmax_t getRoundSize();
	void setSize();
};

class Files
{
public:
	vector<MyFile> files;
	fs::path path;
	Files(fs::path);
	void getFiles();
	void setPath(fs::path);
	void createDir();
	void moveFile(fs::path, fs::path);
	void moveFiles();
private:
	int dirIterator;

};
