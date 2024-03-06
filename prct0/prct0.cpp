// prct0.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<iomanip>
#include<string>
using namespace std;
struct Date
{
    unsigned int day, month, year;
};
std::ostream& operator <<(std::ostream& os, struct Date& date)
{
    char sdate[40] = "";
    unsigned int bd = date.day, bm= date.month, by = date.year;
    for (int i = 1; i > -1; i--)
    {
        sdate[i] += (bd % 10) + '0';
        bd /= 10;
    }
    sdate[2] = '.';
    for (int i = 4; i > 2; i--)
    {
        sdate[i] += (bm % 10) + '0';
        bm /= 10;
    }
    sdate[5] = '.';
    for (int i = 9; i > 5; i--)
    {
        sdate[i] += (by % 10) + '0';
        by /= 10;
    }
    os << sdate;
    return os;
}
struct  Record
{
    char firm[30],nwpr[4];
    unsigned long long income;
    double dolya;
    Date founded;
};
void myCentre(Date s, int wLine) {
    int w = 10;
    int delta = (wLine - w) / 2;
    cout << left;
    cout.width(delta); cout << " ";
    cout << s;
    cout.width(delta + 1); cout << " ";
}
void Draw(struct Record* records) {
    int width = 78 + 16;
    cout << endl; cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(width); cout << left << "|Фирмы - производители СКБД"; cout << " | " << endl;
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');
    cout << left; cout.width(12);cout  << "| Фирма ";
    cout << left; cout.width(20); cout <<  "| Количество продуктов ";
    cout << left; cout.width(20); cout << "| Объем продажи ($) ";
    cout << left; cout.width(20); cout << "| Часть рынка (%) ";
    cout << left; cout.width(20); cout << "| Дата основания";cout << "|" << endl;
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' ');
    for (int i = 0; i < 3; i++) {
        cout << left << "|"; cout << left; cout.width(11); cout << records[i].firm;
        cout << left << "|"; cout << left; cout.width(22); cout << records[i].nwpr;
        cout << left << "|"; cout << left; cout.width(18);cout << records[i].income;
        cout << left << " ";
        cout << left << "|"; cout.width(19); cout << left << fixed << setprecision(1) << records[i].dolya;
        cout << left << "|"; 
        cout << left;  cout.width(18); myCentre(records[i].founded,18); cout.fill(' '); cout << "|" << endl;
    }
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
    cout.fill(' '); cout.width(width); cout << left << "|Примечание: по данным GartnerGroup за 1999г"; cout << " | " << endl;
    cout.width(width + 1); cout.fill('-'); cout << "-" << endl;
}
int main()
{
    setlocale(LC_ALL, "ru");
    Record rdcs[3];
    rdcs[0] = { "Oracle","+ 1", 2488000000, 31.1 , {01,02,2010}};
    rdcs[1] = { "IBM", "+ 3",2392000000,29.9,{02,03,2020}};
    rdcs[2] = { "Microsoft","+ 2", 1048000000,13.1, {12,12,2012} };
    Draw(rdcs);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
