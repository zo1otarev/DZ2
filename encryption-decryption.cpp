//
// Created by daniil on 07.11.2020.
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

void encryption(string t) {
    setlocale(LC_ALL, "Russian")

    string a;
    int b, c, d = 0;
    cout << "Your text" << endl;
    getline(cin, a);
    cout << "Password" << endl;
    cin >> b; //?????? ?????? - ???? ????
    srand(b);
    for (int i = 0; i < a.size(); i += 4) {
        for (int m = 0; m < 4; m++) {  // d - 32 ?????? ?????, ???? ????????????? 4 ???? ????????
            d <<= 8; // ??????????? ????
            d |= static_cast<int8_t>(a[i + m]); // ?????????? ?? ????????? ????? ???? ????
        }
        c = rand(); // ????, ? ???? ????? 4 ?????, ????????? ? ????? ?? sizeof(rand())
        c ^= d; // ????????? ??????????? ???
        c = (c >> 30) | (c << 2); // ??? ????? 2 ???? ?????
        for (int k = 0; k < 4; k++) a[i + k] = static_cast<char>((c >> ((3 - k) * 8)) & 255); // ?????? 4 ???????? ?? ?????
    }                                                                       // ???? ??????, ?? ???????? ???, ????? ???? ???? ??????? ?????? ? ????????? ??????, ? ??????????? ???????? ?????
    ofstream myfile; //????? ? ????
    myfile.open(t);
    myfile << a;
    myfile.close();
}

void decryption(string t) {   //???? ????? ? ???????? ???????

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