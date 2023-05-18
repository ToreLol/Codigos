#include <iostream>

using namespace std;

int main()
{
    int n;  //En n se almacenara el grado del polinomio

    cout << "Cual es el grado del polinomio: "; //Se pide al ususario que introduzca el grado del polinomio
    cin >> n;

    float* P;   //Declaramos el arreglo que contendra los coefientes del polinomio como puntero.
    P = new float[n+1];   //Se redimensiona el arreglo al tamaño requerido

    for (int i = 0; i <= n; i++)
    {
        cout << "Dame el coeficiente " << i << ": ";
        cin >> P[i];
    }//Ciclo para introducir los coeficientees del polinomio

    cout << "El polinomio es: " << endl;
    for(int i = 0; i<=n; i++)
    {//multiplico i por p[i] y le resto 1 a la variable i
        cout << " + " << P[i]xi << "*x^" << i-1;
    }//Cliclo para imprimir el polinomio

    return 0;
