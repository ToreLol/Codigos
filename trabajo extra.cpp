#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

// Define la función fibonacci fuera de la función main
vector<int> fibonacci(int n) {
    vector<int> fib(n);
    fib[0] = 0;
    if (n > 1) {
        fib[1] = 1;
        for (int i = 2; i < n; ++i) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }
    }
    return fib;
}

int main()
{
    int respuesta;

    cout<<"\nTarea extra\n";
    do{

    cout<<"\nCual actividad quiere ver? \n1)salir \n2)ciclos anidados \n3)serie fibonacci \n4)numero mayor \n5)numero mayor con repeticion \n6)numero que termina en 4 \n7)numero con mas digitos \n8)factoriales\n";
    cin>>respuesta;

    // Variables para el caso 2
    int prim;

    // Variables para el caso 3
    vector<int> fibonacci_series;

    // Variables para el caso 4
    vector<int> numerosmayores;

    // Variables para el caso 5
    const int numnumeros = 8;
    vector<int> numeros(numnumeros);
    int mayor = numeros[0];
    int repeticiones = 1;

    // Variables para el caso 6
    const int numentradas = 10;
    vector<int> numerosen4(numentradas);

    // Variables para el caso 7
    const int numerodigital = 7;
    vector<long long int> numerosdigitales(numerodigital);
    vector<int> tamaniosdigitales(numerodigital);
    int posicionMayor = 0;

    // Variables para el caso 8
    const int factoriales = 10;
    vector<int> numerosfactorial(factoriales);
    vector<int> factorialesCalculados(factoriales, 1);

    // Variable para el caso 4 y 5
    auto numerote = numerosmayores.begin();

    switch(respuesta){
        case 2:
            prim = 1;
            for (int i = 1; i <= 3; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    cout << prim << "     " << i << "     " << j << '\n';
                    ++prim;
                }
            }
            break;

        case 3:
            fibonacci_series = fibonacci(10);
            cout << "Los primeros 10 elementos de la serie de fibonacci son:" << endl;
            for (int num : fibonacci_series) {
                cout << num << " , ";
            }
            cout << endl;
            break;

        case 4:
            numerosmayores = {734, 6792, 1234, 345, 567, 1, 6785, 6789, 456, 1287, 234789, 234, 5678};
            numerote = max_element(numerosmayores.begin(), numerosmayores.end());
            cout << "El mayor elemento es: " << *numerote << endl;
            break;

        case 5:
            cout << "Escribe 8 numeros:" << endl;
            for (int i = 0; i < numnumeros; i++) {
                cin >> numeros[i];
            }
            mayor = numeros[0];
            repeticiones = 1;
            for (int i = 1; i < numnumeros; i++) {
                if (numeros[i] > mayor) {
                    mayor = numeros[i];
                    repeticiones = 1;
                } else if (numeros[i] == mayor) {
                    repeticiones++;
                }
            }
            cout << "El numero mas alto es " << mayor << endl;
            cout << "Y se repite " << repeticiones << " veces" << endl;
            break;

        case 6:
            cout << "\nescribe 10 numeros\n" << endl;
            for (int i = 0; i < numentradas; i++) {
                cin >> numerosen4[i];
            }
            cout << "\nLos numeros que terminan en 4 estan en las posiciones: ";
            for (int i = 0; i < numentradas; i++) {
                if (numerosen4[i] % 10 == 4) {
                    cout << i+1 << ", ";
                }
            }
            cout << endl;
            break;

        case 7:
            cout << "\nEscribe 7 numeros enteros para contar:" << endl;
            for (int i = 0; i < numerodigital; i++) {
                cin >> numerosdigitales[i];
            }
            mayor = 0;
            posicionMayor = 0;
            for (int i = 0; i < numerodigital; i++) {
                tamaniosdigitales[i] = to_string(numerosdigitales[i]).size();
                if (tamaniosdigitales[i] > mayor) {
                    mayor = tamaniosdigitales[i];
                    posicionMayor = i;
                }
            }
            cout << "El numero con mayor digitos es: " << numerosdigitales[posicionMayor] << endl;
            cout << "Tiene " << mayor << " digitos" << endl;
            break;

        case 8:
            cout << "Escribe 10 numeros enteros para factorizar:" << endl;
            for (int i = 0; i < factoriales; i++) {
                cin >> numerosfactorial[i];
            }
            for (int i = 0; i < factoriales; i++) {
                for (int j = 1; j <= numerosfactorial[i]; j++) {
                    factorialesCalculados[i] *= j;
                }
            }
            cout << "Los factoriales de los numeros son:" << endl;
            for (int i = 0; i < factoriales; i++) {
                cout << factorialesCalculados[i] << " ";
            }
            cout << endl;
            break;

    }
        
    }while(respuesta!=1);
    return 0;
}