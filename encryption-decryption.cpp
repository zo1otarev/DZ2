//
// Created by daniil on 07.11.2020.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

void encryption(string t) {
    setlocale(LC_ALL, "Russian");

    string a;
    int b, c, d = 0;
    cout << "Your text" << endl;
    getline(cin, a);
    cout << "Password" << endl;
    cin >> b; //Пароль, семя ГСПЧ
    srand(b);
    for (int i = 0; i < a.size(); i += 4) {
        for (int m = 0; m < 4; m++) {  // d - 32 битное число, состоящее из 4 кодов символов, записанных упорядоченно
            d <<= 8; // Освобождаем место для байта кода символа (4 раза)
            d |= static_cast<int8_t>(a[i + m]); // Записываем на свободное место байт кода символа
        }
        c = rand(); // ГСПЧ, у меня сразу выдается значение 4 байта, насколько я понял из sizeof(rand())
        c ^= d; // Исключающее ИЛИ (encryption)
        c = (c >> 30) | (c << 2); // Мой сдвиг на 2 бита
        for (int k = 0; k < 4; k++) a[i + k] = static_cast<char>((c >> ((3 - k) * 8)) & 255); // Меняем 4 символа на новые
    }                                                                //Если точнее, то сдвигаем байт нужного кода символа на первое место и накладываем маску байта
    ofstream myfile; //Вывод в файл
    myfile.open(t);
    myfile << a;
    myfile.close();
}

void decryption(string t) {   //То же самое в обратном порядке

    string a;
    int b, c = 0, d;
    cout << "Password" << endl;
    cin >> b;
    srand(b);
    ifstream myfile;
    myfile.open(t);
    getline(myfile, a);
    myfile.close();
    for (int i = 0; i < a.size(); i += 4) {
        for (int m = 0; m < 4; m++) {
            c <<= 8;
            c |= static_cast<int8_t>(a[i + m]);
        }
        c = (c >> 2) | (c << 30);
        d = rand();
        c ^= d;
        for (int k = 0; k < 4; k++) a[i + k] = static_cast<char>((c >> ((3 - k) * 8)) & 255);
    }
    cout << a << endl;
}