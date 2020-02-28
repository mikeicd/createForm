#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <errno.h>

using namespace std;

string replaceThis(string str, const string &from, const string &to) {
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
    return str;
}

int main(int argc, char *argv[]) {
    string linha, argumentos[argc -2], keyWord[argc -2], subWord[argc -2];

    size_t startPos=0;
    for (int i = 0; i < argc -2; ++i) {
        argumentos[i] = argv[i+2];
        startPos = argumentos[i].find("=", startPos);
        keyWord[i] = "$" + argumentos[i].substr(0, startPos);
        subWord[i] = argumentos[i].substr(startPos+1, argumentos[i].length()-1);
        startPos=0;
    }

    std::string filePath(argv[1]);
    ifstream arq(filePath);

    if (!arq.is_open()) {
        perror("Ao abrir arquivo");
        return errno;
    }

    while (getline(arq, linha)) {

        for (int i = 0; i < argc-2; ++i) {
            linha = replaceThis(linha, keyWord[i], subWord[i]);
        }
        cout << linha << endl;
    }
    return 0;
}
