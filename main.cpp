#include <iostream>
#include <fstream>
#include <cstdio>
#include <sys/types.h>
#include <sys/stat.h>
using namespace std;

#define _WIN64

bool isPathExist(const char *path) {

    struct stat info;

    if (stat(path, &info) != 0) return false;
    else if (info.st_mode & S_IFDIR) return true;
    else return false;

}

void winrar_crack() {

    // This is where the fun begins.

    const char key[] = R"""(RAR registration data
User
Single PC usage license
UID=71386fe49139860c9b39
64122122509b39d7a07c92e95d0cc3def23770cb5f9a5f9a6bd1f6
0e434177e80bbcda24286035c6ab9048e2c5c62f0238f183d28519
aa87488bf38f5b634cf28190bdf438ac593b1857cdb55a7fcb0eb0
c3e4c2736090b3dfa45384e08e9de05c5860653bd6229e3cb62cef
9a6b32bf153ae4ded0c32f815bf5fabc83b8e6f80da0b7b4524674
44e01c14f62da85708f329fa419956dcb1e1afe3e65a589060b1e4
184e1f1eb471c0f6c10c89542ad16ce02e0c577916160863188952)""";

    ofstream RARREG_KEY("rarreg.key");
    RARREG_KEY << key;
    RARREG_KEY.close();

    const char *path = "C:\\Program Files\\WinRAR";

    if (isPathExist(path)) {
        system("MOVE rarreg.key \"C:\\Program Files\\WinRAR");
        ifstream key_check;
        key_check.open("C:\\Program Files\\WinRAR\\rarreg.key");
        if (key_check) {
            system("cls");
            system("timeout /t 5 /nobreak");
            system("cls");

            cout << "WinRAR is activated.\nMade my Blue.\n" << endl;
            system("PAUSE");
        } else {
            system("cls");
            cout << "Access is denied. Please run this program with Administrator.\n" << endl;
            remove("./rarreg.key");
        }
    } else {
        system("cls");
        cout << "Path not found.\n" << endl;
    }

}

int main(int argc, char **argv) {

    char option = 'y';

    cout << "WinRAR activator by Blue.\n\nPlease be aware that only 64bit version is supported. Do you want to continue? (y/n) ";
    cin >> option;

    switch (option) {
        case 'y':
            winrar_crack();
            break;
        case 'n':
            system("PAUSE");
            break;
        default:
            cout << "Invalid input." << endl;
            break;
    }

    return 0;
}
