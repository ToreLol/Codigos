//Critter
#include <iostream>
#include <vector>
#include <locale.h>

using namespace std;

void Pointers();
void Calculate(vector<int>* listNumbers);
void CritterGame();

class Critter
{
public:
    Critter(int hunger = 0, int boredom = 0, int thirst = 0);
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Drink(int drink = 4);
   

private:
    int m_Hunger;
    int m_Boredom;
    int m_Thirst;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int thirst) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Thirst(thirst)
{}


void Critter::PassTime(int time)
{
    m_Hunger += time;
    m_Boredom += time;
    m_Thirst += time;
}

void Critter::Talk()
{
    cout << "\nNecesidades\n";
    cout << "Hambre - " << m_Hunger << endl;
    cout << "Aburrimiento - " << m_Boredom << endl;
    cout << "Sed - " << m_Thirst << endl;

    if (m_Hunger >= 0 && m_Hunger < 3 || m_Boredom >= 0 && m_Boredom < 3 || m_Thirst >= 0 && m_Thirst < 3)
    {
        cout << "HAPPY, LUCKY, SMILE, YAY!!\n";
    }

    if (m_Hunger >= 3 && m_Hunger < 5)
    {
        cout << "Tengo hambre!   Nivel de hambre - " << m_Hunger << endl;
    }
    if (m_Boredom >= 3 && m_Boredom < 5)
    {
        cout << "Estoy aburrido!   Nivel de aburrimiento - " << m_Boredom << endl;
    }
    if (m_Thirst >= 3 && m_Thirst < 5)
    {
        cout << "Tengo sed!   Nivel de sed - " << m_Thirst << endl;
    }

    if (m_Hunger >= 5 && m_Hunger < 8)
    {
        cout << "Me dio hambre! Que hay de botana?!!   Nivel de hambre - " << m_Hunger << endl;
    }
    if (m_Boredom >= 5 && m_Boredom < 8)
    {
        cout << "Estoy aburrido... Jugemos algo!!   Nivel de aburrimiento - " << m_Boredom << endl;
    }
    if (m_Thirst >= 5 && m_Thirst < 8)
    {
        cout << "Me dio sed! Tienes agua?   Nivel de sed - " << m_Thirst << endl;
    }

    if (m_Hunger >= 8 && m_Hunger < 10)
    {
        cout << "HAMBREEE, COMIDA!!! ALIMENTAME   Nivel de hambre - " << m_Hunger << endl;
    }
    if (m_Boredom >= 8 && m_Boredom < 10)
    {
        cout << "QUE ABURRIDOOO!!!   Nivel de aburrimiento - " << m_Boredom << endl;
    }
    if (m_Thirst >= 8 && m_Thirst < 10)
    {
        cout << "ESTOY SEDIENTOO!!!   Nivel de sed - " << m_Thirst << endl;
    }

    if (m_Hunger >= 10 || m_Boredom >= 10 || m_Thirst >= 10)
    {
        cout << "Me mataste 💀";
        exit(0);
    }

    PassTime();
}

void Critter::Eat(int food)
{
    cout << "\nÑan ñam Ñam ÑAN . \n";
    m_Hunger -= food;
    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWIIIII\n";
    m_Boredom -= fun;
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    PassTime();
}

void Critter::Drink(int drink)
{
    cout << "\nGlu Glu Glu!\n";
    m_Thirst -= drink;
    if (m_Thirst < 0)
    {
        m_Thirst = 0;
    }
    PassTime();
}

int main()
{
    int choice;
    cout << "Eliga una opcion?\n1 - Punteros          2 - Objetos\n";
    cin >> choice;
    switch (choice)
    {
    case 1:
        Pointers();
        break;
    case 2:
        CritterGame();
    default:
        break;
    }
}
int CountEvenDigits(int number)
{
    int count = 0;
    while (number != 0)
    {
        int digit = number % 10;
        if (digit % 2 == 0)
            count++;
        number /= 10;
    }
    return count;
}

void FindNumberWithMostEvenDigits(vector<int>* listNumbers)
{
    int maxDigits = 0;
    int* maxNumPtr = nullptr;

    for (int i = 0; i < listNumbers->size(); ++i)
    {
        int digits = CountEvenDigits(listNumbers->at(i));
        if (digits > maxDigits)
        {
            maxDigits = digits;
            maxNumPtr = &listNumbers->at(i);
        }
    }

    cout << "El número con más dígitos pares es: " << *maxNumPtr << endl;
    cout << "Dirección de memoria: " << maxNumPtr << endl;
    cout << "Posición en el vector: " << (maxNumPtr - &listNumbers->at(0)) << endl;
}
void Pointers()
{
     vector<int> listNumbers;
    cout << "Ingrese 8 series de números: ";
    for (int i = 0; i < 8; ++i)
    {
        int num;
        cin >> num;
        listNumbers.push_back(num);
    }

    FindNumberWithMostEvenDigits(&listNumbers);
}

void CritterGame()
{
    Critter crit;
    crit.Talk();
    int choice;
    setlocale(LC_ALL, "spanish");
    do
    {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 - Salir.\n";
        cout << "1 - Escucha a tu mascota.\n";
        cout << "2 - Alimentar.\n";
        cout << "3 - Jugar con tu mascota.\n";
        cout << "4 - Hidratar\n";
        cout << "Elige una opción: ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.Drink();
            break;
        default:
            cout << "\n Opcion inválida. \n";
        }
    } while (choice != 0);
}