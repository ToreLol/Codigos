#include <iostream>
#include <algorithm>
using namespace std;
 
 int main(){
     int numeros[10]={0,5,8,1,9,7,3,2,6,4};
     int tempo = 0;

 cout<<endl<<"Arreglo sin acomodar:"<<endl;
        for(int x= 0; x<10; x++){
        cout<<numeros[x];
        }


             for(int x = 0; x<10; x++)
        {
            int c = x;
        for(c; c<9; c++)
        {
        if(numeros[x]>numeros[c+1])
        {
        tempo= numeros[x];
        numeros[x] = numeros[c+1];
        numeros[c+1] = tempo;
        }
        }
        }

        cout<<endl<<"Acomodo con Seleccion"<<endl;
        for(int x= 0; x<10; x++){
        cout<<numeros[x];
        }
 }