#include "file.hpp"


int main() {
    setlocale(LC_ALL, "ru");
    fs::path path;
    cout << "¬ведите путь до директории:" << endl;
    wcin >> path;
    Files files(path);
    files.moveFiles();
}

// K:/Projects/яѕ/јудиторные/3/test