#include "file.hpp"


int main() {
    setlocale(LC_ALL, "ru");
    fs::path path;
    cout << "������� ���� �� ����������:" << endl;
    wcin >> path;
    Files files(path);
    files.moveFiles();
}

// K:/Projects/��/����������/3/test