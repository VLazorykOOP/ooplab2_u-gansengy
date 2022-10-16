#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Examples of problems using bitwise operations \n";
    cout << "    6.  Exit \n";
}
void task1() {
    // Обчислення виразів з використанням побітових операцій
    // Calculation of expressions using bitwise operations 
    cout << " Calculation of expressions using bitwise operations  \n";

    int a, b, c, d, x, y;
    
    cin >> a >> b >> c >> d;
    auto st = cin.rdstate();
    if (st != cin.goodbit) { cin.clear(); cout << " error \n"; cin.get(); cin.get(); return; }
    x = (a << 5) + (a << 1) + ( ( ((a << 4) - ((a << 1) - a)) + ((c << 4) - (c << 2)) ) >> 6 ) - ((b << 11) + (b << 9)) + ((d << 7) - d ) - ((c << 4) + (c << 1));
    y = a * 34 + (a * 13 + c * 12) / 64 - b * 2560 + d*127 - c * 18;
    
    cout << " Result using bitwise operstions :  " << x << "\n Using standart operations : " << y << 
        "\na = " << a << " b = " << b << " c = " << c << " d = " << d << endl;
    
    cin.get();
    cin.get();
    return;
}

void task2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";

    char data[70] = "This's text that\nYou can hardcode\nWhenever you    \nWant :)))         ";
    // prepared text for using myencryption

    unsigned short OutCoding[64];

    
        unsigned char c;
        unsigned short r, t, i, b, num, numByk;
        short j;
        for (i = 0; i < 64; i++)            //
        {
            int k = 64, counter = 1;
            while (k - 16 > 0) { k - 16; counter++; }

            r = 0;                        // 0000 0000 0000 0000
            c = data[i];                     // s - 0x73 = 0111 0011
            t = c;
            num = counter;
            numByk = k;
            r |= num << 2; // nomer ryadky 0-1
            r |= numByk << 3; // nomer bykvi 2-5
            r |= t << 5;                  // ASCI 6-13

            b = 0;
            for (j = 0; j < 2; j++)         // обчислення біта парності
            {
                if (r & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }
            r |= b << 14;

            b = 0;
            for (j = 0; j < 16; j++)         // обчислення біта парності
            {
                if (r & t) {
                    if (b == 0) b = 1; else b = 0;
                }
                t <<= 1;
            }
            r |= b << 15;                    // 0011 0000 0101 0111 if i=5 0000 0000 0000 0101

            OutCoding[i] = r;

        }
}

void task3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";

    struct TextCode {
        unsigned short num : 2;
        unsigned short numSymb : 3;
        unsigned short ASCII : 5;
        unsigned short bitStr : 14;
        unsigned short bitSymb : 15;
    };

    

    char data[70] = "This's text that\nYou can hardcode\nWhenever you    \nWant :)))         ";
    // prepared text for using myencryption

    unsigned short OutCoding[64];


    unsigned char c;
    unsigned short r, t, i, b, num, numByk;
    short j;
    for (i = 0; i < 64; i++)            //
    {
        TextCode l{};
        int k = 64, counter = 1;
        while (k - 16 > 0) { k - 16; counter++; }

        r = 0;                        // 0000 0000 0000 0000
        c = data[i];                     // s - 0x73 = 0111 0011
        t = c;
        num = counter;
        numByk = k;
        r |= num << l.num; // nomer ryadky 0-1
        r |= numByk << l.numSymb; // nomer bykvi 2-5
        r |= t << l.ASCII;                  // ASCI 6-13

        b = 0;
        for (j = 0; j < 2; j++)         // обчислення біта парності
        {
            if (r & t) {
                if (b == 0) b = 1; else b = 0;
            }
            t <<= 1;
        }
        r |= b << l.bitStr;

        b = 0;
        for (j = 0; j < 16; j++)         // обчислення біта парності
        {
            if (r & t) {
                if (b == 0) b = 1; else b = 0;
            }
            t <<= l.bitSymb;
        }
        r |= b << 15;                    // 0011 0000 0101 0111 if i=5 0000 0000 0000 0101

        OutCoding[i] = r;
    }
}

void task4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

    int a, b;

    cin >> a;
    cin >> b;

    if (a == 0 || b == 0) {
        cout << "YOU CAN'T MULTIPLY ON 0" << endl;
        return;
    }

    cout << "RESULT OF A * B : " << a * b << endl;

    if (a == b) {
        cout << "SAME RESULT OF A * B BUT USING BITWISE SHIFT & BITWISE AND : " << (a << 2) << endl;
        return;
    }
    else if (a == 1 || b == 1) {
        int answer = a == 1 ? b : a;
        cout << "SAME RESULT OF A * B BUT USING BITWISE SHIFT & BITWISE AND : " << (answer << 0) << endl;
        return;
    }

    if (a < b) {
        int temp = a;
        a = b;
        b = temp;
    }

    b = abs(b | -1);

    cout << "SAME RESULT OF A * B BUT USING BITWISE SHIFT & BITWISE AND : " << (a << b) << endl;

    return;
}


