#include <iostream>

using namespace std;

int main()
{
int limite = 0, k = 0, n = 0;
char f='0';
do
{
    cout << "\nHasta que numero va a sumar?\n";
    cin >> n;
    for(n; n >= limite; n--)
   {
    k = n + k;
   }
    cout << "\nLa suma es =" << k << endl ;

    limite = 0, k = 0, n = 0;
    cout<<"\nDesea salir? y/n\n";
    cin>>f;

} while (f!='y');

return 0;
}