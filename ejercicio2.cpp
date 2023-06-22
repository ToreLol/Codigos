/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    const int matriz [3][4]={{2, 1, 4, 6}
                            ,{5, 8, 3, 9}
                            ,{7, 8, 5, 6}};
    int sum,resta,answer;
    
    cout<<"la matriz es: \n";
    for(int i=0;i<=2;i++){
        for(int j=0;j<=3;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    
    for(int i=0; i<=2;i++){
        for(int j=0;j<=3;j++){
            if((matriz[i][j]%2)==0){
             cout << "el numero " << matriz[i][j] << " es par \n";
             sum += matriz[i][j];
             cout<<"el indice es "<<i<<j<<"\n";
             resta += ((i*10)+j);
            }
        }
    }
    cout<<"la suma de los pares es ="<<sum<<"\n";
    cout<<"la suma de los pares es ="<<resta<<"\n";
    answer=sum-resta;
    cout<<"la suma de los pares es ="<<sum<<"\n";
    return 0;
}
