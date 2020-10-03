#include <iostream>
using namespace std;

int main() {

    setlocale(LC_ALL, "Russian");

    int x, y, z;
    cout << "Введите x, y, z" << endl;
    cin >> x >> y >> z;

    if (x % 2 == 0 and y % 2 == 0) cout << "True" << endl;
    else cout << "False" << endl;

    if (x < 20 ^ y < 20) cout << "True" << endl;
    else cout << "False" << endl;

    if (x == 0 || y == 0) cout << "Либо x, либо y = 0" << endl;
    else cout << "False" << endl;

    if (x < 0 and y < 0 and z < 0) cout << "x, y и z < 0" << endl;
    else cout << "False" << endl;

    if (x % 5 == 0 and y % 5 != 0 and z % 5 != 0) cout << "True" << endl;
    else
    {
        if (x % 5 != 0 and (y % 5 == 0 ^ z % 5 == 0)) cout << "True" << endl;
        else cout << "False";
    }

    if (x > 100 || y > 100 || z > 100) cout << "True" << endl;
    else cout << "False" << endl;

    using byte = unsigned char;
    pair <byte, byte> positionA;
    pair <byte, byte> positionB;

    cout << "Введите позицию для A" << endl;
    cin >> positionA.first >> positionA.second;
    cout << "Введите позицию для B" << endl;
    cin >> positionB.first >> positionB.second;

    if (positionA.first == positionB.first || positionA.second == positionB.second)
        cout << "Ладья А угрожает B" << endl;
    else cout << "Ладья A не угрожает B" << endl;

    if ((positionA.first - positionB.first) == (positionA.second - positionB.second))
        cout << "Слон А угрожает B" << endl;
    else cout << "Слон A не угрожает B" << endl;

    if (abs(positionA.first - positionB.first) <= 1 and (positionA.second - positionB.second) <= 1)
        cout << "Король А попадает на B" << endl;
    else cout << "Король A не попадает на B" << endl;

    if ((positionA.first == positionB.first) || (positionA.second == positionB.second) || ((positionA.first - positionB.first) == (positionA.second - positionB.second)))
        cout << "Ферзь А угрожает B" << endl;
    else cout << "Ферзь A не угрожает B" << endl;

    if ((positionA.second - positionB.second) == -1 and (positionA.first == positionB.first))
        cout << "Пешка А попадает на B" << endl;
    else cout << "Пешка A не попадает на B" << endl;

    if (abs(positionA.first - positionB.first) == 1 and (positionA.second - positionB.second) == -1)
        cout << "Пешка А бьет фигуру на B" << endl;
    else cout << "Пешка A не не бьет фигуру на B" << endl;

    for (int i=1; i <= 10; i++) cout << i << " * 7 = " << i*7 << endl;

    int l;
    cout << "Введите n" << endl;
    cin >> l;
    for (int i=1; i <= 10 ; i++)
        cout << i << " * " << l << " = "  << i*l << endl;

    long n = 8, i = 8;
    while (n < 15)
    {
        n++;
        i *= n;
    }
    cout << "15!/7! = " << i << endl;

    long a , b ;
    cout << "Введите a" << endl;
    cin >> a;
    b = a;
    while (a < 20)
    {
        a++;
        b *= a;
    }
    cout << "20!/(a-1)! = " << b << endl;

    long c = 1, t, f=1;
    cout << "Введите b" << endl;
    cin >> t;
    while (c <= t)
    {
        f *= c;
        c++;
    }
    cout << "b! = " << f << endl;

    long q, w, e;
    cout << "Введите a и b" << endl;
    cin >> q >> w;
    e = 1;
    while (q <= w)
    {
        e *= q;
        q++;
    }
    cout << e << endl;

    return 0;
}
