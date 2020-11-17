#include "header.h"

int main(int argc, const char *argv[]) {
    setlocale(LC_ALL, "Russian");
    std::string mode;
    if (argc != 3) {
        std::cerr << "Error: Используйте 3 параметра.\n";
        std::cerr << "1) Название программы (путь к программе). \n";
        std::cerr << "2) Режим работы программы (encryption / decryption). \n";
        std::cerr
                << "3) Файл (путь к файлу). В нем храниться сообщение при дешифровке либо сохраняется в него при шифровании.\n";
        return 5;
    }
    mode = argv[1];
    if (mode == "encryption") encryption(argv[2]); // Режим шифрование
    else {
        if (mode == "decryption") decryption(argv[2]); // Режим расшифрования
        else std::cerr << "Введите правильно режим работы";
    }
    return 0;
}