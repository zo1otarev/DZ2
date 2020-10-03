#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
    setlocale(LC_ALL, "Russian");

    cout << "Hello, World!" << std::endl;

    cout << "1 13 49" << endl;

    char k;
    cout << "Введите символ" << endl;
    cin >> k;
    cout << "1" << k << "13" << k << "49" << endl;

    int k1, k2, k3;
    cout << "Введите 3 числа" << endl;
    cin >> k1 >> k2 >> k3;
    cout << k1 << " " << k2 << " " << k3 << endl;

    double y, x, a;
    cout << "Введите a" << endl;
    cin >> a;
    x = 12 * pow(a,2) + 7 * a - 12;
    cout << x << endl;

    cout << "Введите x" << endl;
    cin >> x;
    y = pow(x,3) * 3 + pow(x,2) * 4 - 11 * x + 1;
    cout << y << endl;

    double V, m, p;
    cout << "Введите обьем и массу" << endl;
    cin >> V >> m;
    p=m/V;
    cout << p << endl;

    double x1, a1, b;
    cout << "Введите a, а затем b" << endl;
    cin >> a1 >> b;
    x1 = -b / a1;
    cout << x1 << endl;

    double x2, y2, x3, y3, l;
    cout << "Введите координаты первой, а затем второй точки" << endl;
    cin >> x2 >> y2 >> x3 >> y3;
    l = sqrt(pow((x2+x3),2) + pow((y2+y3),2));
    cout << l << endl;

    double o1, o2, h, P;
    cout << "Введите длины оснований, а затем высоту" << endl;
    cin >> o1 >> o2 >> h;
    P = 2 * sqrt(pow(((o1 - 02)/2), 2) + pow(h,2)) + o1 + o2;
    cout << P << endl;

    const double PI = acos(-1.0);
    double r1, r2, S;
    cout << "Введите длины радиусов окружностей" << endl;
    cin >> r1 >> r2;
    S = PI * abs(r2 - r1);
    cout << S << endl;

    double c;
    cout << "Введите длину стороны куба" << endl;
    cin >> c;
    cout << pow(c, 3) << 6 * pow(c, 2) << endl;

    double c1;
    cout << "Введите длину стороны квадрата" << endl;
    cin >> c1;
    cout << 4*c1 << endl;

    double r3;
    cout << "Введите длину радиуса" << endl;
    cin >> r3;
    cout << 2*r3 << endl;

    string name;
    cout << "Введите имя" << endl;
    cin >> name;
    cout << "Hello, " << name << "! My name is  C++." << endl;

    string word;
    cout << "Введите слово из 7 букв" << endl;
    cin >> word;
    cout << ((word[0] == word[6] and word[1] == word[5] and word[2] == word[4]) ? "This is polindrom!" : "Sorry, this is not polindrom!") << endl;

    system ("pause");
    return 0;
}
