//
// Created by zo1otarev
//
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>

//  Режим шифрования
void encryption(std::string t) {
    setlocale(LC_ALL, "Russian");

    std::vector<int> crmessage; //Вектор, в который будут сохраняться шифрованные коды символов сообщения
    std::cout << "Введите текст, который вы хотите зашифровать" << std::endl;
    std::string message;
    getline(std::cin, message); //Записываем в переменную сообщение
    std::cout << "Пароль шифрования" << std::endl;
    int seem; //Семя ГПСЧ (Пароль)
    std::cin >> seem;
    srand(seem); // Настраиваем ГПСЧ с помощью пароля
    //Добавляем незначимые пробелы для того, чтобы кол-во символов в сообщение было кратно 4 (Так удобней делить на блоки)
    for (int i = 0; i < message.size() % 4; i++) message += ' ';
    for (int i = 0; i < message.size(); i += 4) { //Делим на блоки по 4 символа (4 байта)
        int block = 0;
        for (int m = 0; m < 4; m++) {                     //
            block <<= 8;                                  //Записываем в блок подряд коды 4 символов
            block |= static_cast<int8_t>(message[i + m]); //
        }
        int crypt = rand(); //Псевдослучайное число для шифрования
        block ^= crypt;     //Шифруем блок
        int block_bias =
                (block >> 30) | (block << 2); //Смещаем блок циклически на 2 бита влево, получаем смещенный блок
        for (int m = 0; m < 4; m++) {
            int o = block_bias >> ((3 - m) * 8);  //Делим смещенный блок на байты и записываем в вектор
            crmessage.push_back(o & 255);         //
        }
    }
    std::ofstream file(t, std::ios::app);                                   //
    for (int i = 0; i < crmessage.size(); i++) file << crmessage[i] << ' '; //Выводим вектор в файл
    file.close();                                                           //
}

//Режим дешифровки
//Почти тоже самое в обратном направлении, я обошел здесь два непонятных бага, поэтому есть различия
//Если будет нужно, то я могу пояснить какие именно
void decryption(std::string t) { //Почти тоже самое в обратном направлении
    std::vector<int> cryptv; // Вектор соотнесенных байтовых паролей для каждого кода зашифрованног символа
    std::vector<int> crmessage; //Вектор, который будет содержать зашифрованные смещенные коды символов сообщения
    std::cout << "Введите пароль дешифрования" << std::endl;
    int seem; //Пароль (семя ГПСЧ)
    std::cin >> seem;
    srand(seem);
    std::string strcrmessage;
    std::ifstream myfile;
    myfile.open(t);
    getline(myfile, strcrmessage); //Записываем в строку коды зашифрованных символов
    myfile.close();
    strcrmessage += ' '; //Добавляем, чтобы было проще считывать в вектор коды
    for (unsigned int i = 0; i < strcrmessage.size(); i++) {
        int n = strcrmessage.find(' ', i);
        int crp = atoi(strcrmessage.substr(i, n - i).c_str());  //Считываем в вектор зашифрованные коды
        crmessage.push_back(crp);
        i = n;
    }
    for (int i = 0; i < crmessage.size(); i += 4) {
        int f = (crmessage[i + 3] << 6) & 255;            //Делаем обратный сдвиг на 2 бита влево поблочно
        for (int m = 3; m > 0; m--) {
            crmessage[i + m] = (crmessage[i + m] >> 2) | ((crmessage[i + m - 1] << 6) & 255);
        }
        crmessage[i] = (crmessage[i] >> 2) | f;
        int crypt = rand();                     // Блочный дешифровщик на 4 байта из ГПСЧ
        //Разбиваем его на байтовые для соотнесенности и записываем в вектор
        for (int m = 0; m < 4; m++) cryptv.push_back((crypt >> ((3 - m) * 8)) & 255);
    }
    for (int i = 0; i < crmessage.size() - 1; i++)
        std::cout << static_cast<char>(crmessage[i] ^ cryptv[i]); //Побайтово дешифруем и выводим
    std::cout << std::endl;
}