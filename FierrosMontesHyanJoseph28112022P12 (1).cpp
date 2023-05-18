#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y) {
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void Textcolor() {
    for (int i = 1; i < 243; i++)
    {
        gotoxy(10, 1);
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(hConsole, i);
        cout << "Pasto loco" << endl;
        _getch();
    }
}

int main() {
    goto pum2;
    pum1:
    cout << "Caca pedo pis" << endl;
    pum2:
    Textcolor();
}