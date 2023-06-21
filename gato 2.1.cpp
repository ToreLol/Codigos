#include <iostream>
#include <limits>
using namespace std;

const int row = 3;
const int column = 3;
bool turn = true;
 char pregunteishon;
void cout_board(char board[row][column]) {
    cout << "   |   |   \n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
    cout << "   |   |   \n";
}

bool check_full_board(char board[row][column]) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (board[i][j] == '1'||board[i][j] == '2'||board[i][j] == '3'||
            board[i][j] == '4'||board[i][j] == '5'||board[i][j] == '6'||
            board[i][j] == '7'||board[i][j] == '8'||board[i][j] == '9') {
                return false; // El tablero aun no esta lleno
            }
        }
    }
    return true; // El tablero esta lleno
}

bool win(char board[row][column]){
    //verifico filas
    for (int i = 0; i < column; i++) {
    if((board[i][0] == 'X' || board[i][0] == 'O') && (board[i][1] == board[i][0]) && (board[i][2] == board[i][0])){
    return true;
    }}
    // Verifico columnas
    for (int j = 0; j < column; j++) {
    if ((board[0][j] == 'X' || board[0][j] == 'O') && (board[1][j] == board[0][j]) && (board[2][j] == board[0][j])) {
    return true;
    }}
    // Verifico diagonales
    if((board[0][0] == 'X' || board[0][0] == 'O')&&(board[1][1] == board[0][0]) && (board[2][2] == board[0][0])){
        return true;
    }
    if((board[0][2] == 'X' || board[0][2] == 'O')&&(board[1][1] == board[0][2]) && (board[2][0] == board[0][2])){
        return true;
    }
    return false;//si no se cumple nada de esto nadie ah ganado
}

int main() {
    char board[row][column] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };
   do{
       //es solo para reiniciar el juego nuevo
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {
                board[i][j] = '1' + i * column + j;
            }
        }
        //presentacion
    cout << "GATO ヾ(•ω•`)つ ⁿʸᵃ~\n";
    cout << "\n";
    cout << "   |   |   \n";
    cout << "(1)|(2)|(3)\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << "(4)|(5)|(6)\n";
    cout << "___|___|___\n";
    cout << "   |   |   \n";
    cout << "(7)|(8)|(9)\n";
    cout << "   |   |   \n";

    int ansnum;
    do {
        if (turn) {
            cout << "\nTurno de Jugador 1 (X) (escribe el numero segun la posicion que quieras): \n";
        } else {
            cout << "\nTurno de Jugador 2 (O) (escribe el numero segun la posicion que quieras): \n";
        }

        cin >> ansnum;
        
        //alch le pedi a chat gpt una forma de evitar que escriba letras (es lo unico que pedi)
        if (cin.fail()) {
        cout<<"\n~~~~~~~\n";
        cout << "OPCION INVALIDA. INGRESA un NUMERO.\n";
        cout<<"~~~~~~~\n";
        cout_board(board);
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        continue;
        }
    
        // Verifico si el numero de posicion es valido
        int row_index, column_index;
        switch(ansnum){
        case 1:
        row_index = 0;
        column_index = 0;
        break;

        case 2:
        row_index = 0;
        column_index = 1;
        break;

        case 3:
        row_index = 0;
        column_index = 2;
        break;

        case 4:
        row_index = 1;
        column_index = 0;
        break;

        case 5:
        row_index = 1;
        column_index = 1;
        break;

        case 6:
        row_index = 1;
        column_index = 2;
        break;

        case 7:
        row_index = 2;
        column_index = 0;
        break;

        case 8:
        row_index = 2;
        column_index = 1;
        break;

        case 9:
        row_index = 2;
        column_index = 2;
        break;

    }

            // Verifico si la posicion esta vacia
            if (board[row_index][column_index] != 'X' && board[row_index][column_index] != 'O') {
                if (turn) {
                    board[row_index][column_index] = 'X';
                } else {
                    board[row_index][column_index] = 'O';
                }

                cout_board(board);
                
            //antes del cambio de turno verifico la condicion de ganar 
            if (win(board)) {
             break;
            }
                // Cambio de turno
                turn = !turn;
            } else {
                cout<<"\n~~~~~~~\n";
                cout << "La posicion seleccionada YA esta OCUPADA. Elige otra posicion.\n";
                cout<<"~~~~~~~\n";
                cout_board(board);
            }
        if (ansnum < 1 || ansnum > 9) {
             cout<<"\n~~~~~~~\n";
             cout << "\nNumero de POSICION INVALIDA. Elige un numero del 1 al 9.\n";
             cout<<"~~~~~~~\n";
             cout_board(board);
        }
        
    } while (!check_full_board(board)&&!win(board));
    
    if(win(board)){
    cout<<"\n~~~~~~~\n";
    cout << "\nJugador " << (turn ? "1 (X)" : "2 (O)") << " ha ganado!\n";
    cout<<"\n~~~~~~~\n";
    }else if (check_full_board(board)){
    cout << "Empate! El tablero está lleno.\n";
    }
       cout<<"\nQuieres jugar otra vez? (y/n)\n";
      
       cin>>pregunteishon;
       
   }while(pregunteishon=='Y'||pregunteishon=='y');
    return 0;
}