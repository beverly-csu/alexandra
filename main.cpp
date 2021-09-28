#include "file.hpp"


int main() {
    setlocale(LC_ALL, "ru");
    fs::path path;
    cout << "Введите путь к директории:" << endl;
    wcin >> path;
    Files files(path);
    files.moveFiles();
}
