#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <errno.h>


using namespace std;

string replaceThis(string str, const string& from, const string& to) {
    size_t startPos = 0;
    while ((startPos = str.find(from, startPos)) != std::string::npos) {
        str.replace(startPos, from.length(), to);
        startPos += to.length();
    }
    return str;
}

int main(int argc, char *argv[]) {

    std::string s(argv[1]);

    ifstream arq("../" + s);

    if (!arq.is_open()) {
        perror("Ao abrir arquivo");
        return errno;
    }
    string linha;
    while (getline(arq, linha)) {
        linha =  replaceThis(linha, "$cidade", argv[2]);
        linha =  replaceThis(linha, "$data", argv[3]);
        linha =  replaceThis(linha, "$aluno", argv[4]);
        linha =  replaceThis(linha, "$disciplina", argv[5]);

        cout << linha << endl;
    }

    return 0;
}
