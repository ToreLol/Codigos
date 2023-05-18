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




    for (int c=0; c<9; c++){
        int x = c;
        while(numeros[x]>numeros[x+1])
        {
            tempo = numeros[x];
            numeros[x] = numeros[x+1];
            numeros[x+1] = tempo ;
            x--;

        }

        }



        cout<<endl<<"Acomodo con Insersion"<<endl;
        for(int x= 0; x<10; x++){
        cout<<numeros[x];
        }
 }