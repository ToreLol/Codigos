#include <iostream>
#include <vector>
#include<cstdlib>


using namespace std;

void Instruccions();
char PlayerSymbol();
char Oponent(char Player);
void Board(const vector<char> board);
char WinConditions(const vector<char> board);
void PlayMode(char Player, char computer, vector<char>& board);
void Winner(vector<char> board,char Player);
int askNumber(int Max, int Min);
void IA(char computer, char Player ,vector<char>& board);
bool IAFIll(char Search, char fill, vector<char>& board);
bool IALOgicSistem(vector<char>& board, char fill, char search, int n1, int n2, int n3);

const int	NUM_SQUARES = 9;
const char	EMPTY = ' ';
const char X = 'X';
const char O = 'O';
const bool NO_ONE = false;
const char EMP = 'E';
const int TOTAL_ROWS = 8;

int main()
{
    char Player, Computer, Turn = X;
    vector<char> board(NUM_SQUARES, EMPTY);
    
    Player = PlayerSymbol();
    Computer = Oponent(Player);
    cout << "jugaras como: " << Player << "\n Tu oponente sera: " << Computer << "\n";
    Instruccions();
    system("pause");
    system("cls");
    while (WinConditions(board) == NO_ONE)
    {
        //jeha X
        if (WinConditions(board) == NO_ONE)
        {
            if (Player == X)
            {
                PlayMode(Player, Computer, board);
            }
            else
            {
                Board(board);
                cout << "Turno de la ia";
                IA(Computer, Player ,board);
            }
        }
        //juega O
        if (WinConditions(board) == NO_ONE)
        {
            if (Player == O)
            {
                PlayMode(Player, Computer, board);
            }
            else
            {
                Board(board);
              
                IA(Computer, Player, board);
            }
        }
    }
    system("pause");
    system("cls");
    Board(board);
    Winner(board, Player);
}

void Instruccions()
{
    cout << "TikTakToe\n";
    
}

char PlayerSymbol()
{
    string answer;
    bool exit = true;
    string par = "par";
    string impar = "impar";
    srand((unsigned)time(NULL));
    int random = ((rand() * rand()) % 5) +1;
    do
    {
        cout<<" quieres Par o inpar\n";
        cin >> answer;
        if (answer == par ||answer == impar )
        {
            if (answer == par)
            {
                if ((random % 2) == 0)
                {
                    return X;
                    exit = false;
                }
                else
                {
                    return O;
                    exit = false;
                }
            }
            else if(answer == impar)
            {
                if ((random % 2) == 1)
                {
                    return O;
                    exit = false;
                }
                else
                {
                    return X;
                    exit = false;
                }
            }
        }
    } while (exit);
    return EMPTY;
}

char Oponent(char Player)
{
    if (Player == X)
    {
        return O;
    }
    else
    {
        return X;
    }
}

void Board(const vector<char> board)
{
    for (int i = 0; i <= TOTAL_ROWS; i++)
    {
        if (i == 2 || i == 5 || i == 8)
        {
            if (board[i] == ' ')
            {
                cout << " " << i << "\n";
            }
            else
            {
                cout << " " << board[i] << "\n";

            }
        }
        else
        {
            if (board[i] == ' ')
            {
                cout << " " << i << " |";

            }
            else
            {
                cout << " " << board[i] << " |";
            }
        }
    }
}

char WinConditions(const vector<char> board)
{
    int emp=0;
    for (int i = 0; i <= 8; i++)
    {
        if ((i % 3) == 0 && board[i] == X && board[i] == board[i + 1] && board[i] == board[i + 2])
        {         
            return X;
        }
        else if ((i % 3) == 0 && board[i] == O && board[i] == board[i + 1] && board[i] == board[i + 2])
        {          
            return O;
        }
        else if (i == 0 && board[i] == X && board[i] == board[4] && board[i] == board[8])
        {            
            return X;
        }
        else if (i == 0 && board[i] == O && board[i] == board[4] && board[i] == board[8])
        {        
            return O;
        }
        else if (i < 3 && board[i] == X && board[i] == board[i + 3] && board[i] == board[i + 6])
        {          
            return X;
        }
        else if (i < 3 && board[i] == O && board[i] == board[i + 3] && board[i] == board[i + 6])
        {         
            return O;
        }
        else if (i == 2 && board[i] == X && board[i] == board[4] && board[i] == board[6])
        {           
            return X;
        }
        else if (i == 2 && board[i] == O && board[i] == board[4] && board[i] == board[6])
        {             
            return O;
        }
        if (board[i] != EMPTY)
        {
            emp++;
        }
    }
    if (emp==8)
    {
        return EMP;
    }
    else
    {
        return NO_ONE;
    }
}

void PlayMode(char Player, char Computer , vector<char>& board)
{
    int aux;
    bool exit = true;
    do
    {
        cout << "Turno de " << Player;
        cout << "\nSelecione una posicion\n";
        Board(board);
        cin >> aux;
       // aux = askNumber(NUM_SQUARES, 0);
        if (board[aux] != Computer)
        {
            if (Player == X)
            {
                if (board[aux] != X && aux >= 0 && aux < 9)
                {
                    board[aux] = X;
                    exit = false;
                }
            }
            else if (Player == O && aux >= 0 && aux < 9)
            {
                if (board[aux] != O)
                {
                    board[aux] = O;
                    exit = false;
                }
            }
        }
    } while (exit);
}

int askNumber(const int Max, int Min)
{
    int aux = 1;
    return aux;
}

void Winner(vector<char> board,char Player )
{
    if (WinConditions(board) != NO_ONE)
    {
        if (WinConditions(board) == X)
        {
            if (Player == X)
            {
                cout << " ganaron las X\n";
             
            }
            else
            {
                cout << " ganaron las O \n";
      
            }
        }
        else if(WinConditions(board)== O)
        {
            if (Player == O)
            {
                cout << "ganaron las O\n";
            
            }
            else
            {
                cout << "ganaron las X \n";

            }
        }
        else
        {
            cout << "empate\n";

        }
    }
}

void IA(char computer, char Player, vector<char>& board)
{
    bool exit = true;
    bool IAMove = true;

    // verificar si la computadora va a ganar
    if (IAMove)
    {
        IAMove = IAFIll(computer, computer, board);
    }

    // verificar si el player va a ganar 
    if (IAMove)
    {
        IAMove = IAFIll(Player, computer, board);
    }

   
    if (IAMove)
    {
        do
        {
            srand((unsigned) time(NULL));
            int random = ((rand()*rand()) % 7) + 1;
            if (board[random] == EMPTY)
            {
                board[random] = computer;
                exit = false;
                IAMove = false;
                cout << random << endl;
            }

        } while (exit);
    }

}

bool IAFIll(char Search, char fill, vector<char>& board)
{
    bool IAMove = true;
    int boardSolutions[8][3] = { {0, 1, 2},
                                 {3, 4, 5},
                                 {6, 7, 8},
                                 {0, 3, 6},
                                 {1, 4, 7},
                                 {2, 5, 8},
                                 {2, 4, 6},
                                 {0, 4, 8}, };

    for (int i = 0; i < TOTAL_ROWS; i++)
    {
        if ((IAMove = IALOgicSistem(board, fill, Search, boardSolutions[i][0], boardSolutions[i][1], boardSolutions[i][2])) == false)
        {
            return false;
        }
    }

    return true;
}

bool IALOgicSistem(vector<char>& board, char fill, char search, int n1 ,int n2 , int n3)
{
    if (board[n1] == search && board[n2] == search && board[n3] == EMPTY)
    {
        cout << n3 << endl;
        board[n3] = fill;
        return false;
    }
    else if (board[n2] == search && board[n3] == search && board[n1] == EMPTY)
    {
        cout << n1 << endl;
        board[n1] = fill;
        return false;
    }
    else if (board[n1] == search && board[n3] == search && board[n2] == EMPTY)
    {
        cout << n2 << endl;
        board[n2] = fill;
        return false;
    }
    return true;
}