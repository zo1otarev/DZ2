#include "header.h"
#include <iostream>

int main(int argc, const char *argv[]) {
    if (argc != 3) {
        cerr << "Error: Use three parameters\n";
        return 5;
    }
    string a;
    const string mode(argv[1]); // Режим работы// Имя файла
    if (mode == "encryption") encryption(argv[2]);
// Режим шифрование
    else if (mode == "decryption") decryption(argv[2]);
// Режим расшифрования
    return 0;
}