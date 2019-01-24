
// версия 1.01 - программа не ломается, если вводить символы в строку координат



#include "pch.h"
#include <iostream>

using namespace std;
const int N = 3; // razmernost massiva

int tic_tac_toe[N][N]; // massiv 3x3
int a1, a2;
int x = 0; // ничья
int win;
int i = 0;
int rev; //  переменная определяющая реванш

void Full(); //заполнение массива
void CoordSystem(); // система координат
void TakeReveng(); // Функция "взять реванш"
void Input(char a, int b); //Ввод координат
void Show(); // фун выводи введенные координаты
void Check(int a); // алгоритм определения победителя
void Winner(int a); //


int main(int argc, const char * argv[]) {
    setlocale(LC_ALL, "RUS");
    cout << "Добро пожаловать в игру TicTacToe!" << endl;
    
link:
    // заполнение массива -1
    Full();
    CoordSystem();
        
    do {
        cout << endl;
        cout << "Игрок 1 (X): " << endl;
        Input(a1, 1);
        Show();
        Check(1);
        Winner(1);

        if ( win == 0){
            goto link1;
        }
        if( i == 9 ){
            x = 1;
            i = 0;
            goto link2;
        }
            cout << endl;
        cout << "Игрок 2 (O): " << endl;
        
        Input(a2, 0);
        Show();
        Check(0);
        Winner(2);
        if( i == 1){
            x = 1;
            i = 0;
            goto link2;
            }
        } while (win != 0);
link1:
    cout << endl;
link2:
    i = 0;
    if ( x == 1){
        x = 0;
        cout << "================\n   GAME OVER\nПобедила дружба \n================" << endl;
    }
    TakeReveng();
    if ( rev == 1){
        rev = 0;
        goto link;
    }
}


void Full(){
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            tic_tac_toe[i][j] = -1;
        }
    }
}

void CoordSystem(){
    cout << endl;
    cout << "Таблица координат ячеек:" <<endl;
    cout << " 1 " << " | "  << " 2 " << " | "  << " 3 " << " | " << endl;
    cout << " 4 " << " | "  << " 5 " << " | "  << " 6 " << " | " << endl;
    cout << " 7 " << " | "  << " 8 " << " | "  << " 9 " << " | " << endl;
}

void Input(char a, int b)
{

    link:
        cout << "Введите координату: " << endl;
        cin >> a;
        if ((int)a > 57 || (int)a < 49){
            goto link;
        }
    
    switch (a) {
        case '1':
            if (tic_tac_toe[0][0] != -1){
                goto link;
            }
            tic_tac_toe[0][0] = b;
            break;
        case '2':
            if (tic_tac_toe[0][1] != -1){
                goto link;
            }
            tic_tac_toe[0][1] = b;
            break;
        case '3':
            if (tic_tac_toe[0][2] != -1){
                goto link;
            }
            tic_tac_toe[0][2] = b;
            break;
        case '4':
            if (tic_tac_toe[1][0] != -1){
                goto link;
            }
            tic_tac_toe[1][0] = b;
            break;
        case '5':
            if (tic_tac_toe[1][1] != -1){
                goto link;
            }
            tic_tac_toe[1][1] = b;
            break;
        case '6':
            if (tic_tac_toe[1][2] != -1){
            goto link;
            }
            tic_tac_toe[1][2] = b;
            break;
        case '7':
            if (tic_tac_toe[2][0] != -1){
                goto link;
            }
            tic_tac_toe[2][0] = b;
            break;
        case '8':
            if (tic_tac_toe[2][1] != -1){
                goto link;
            }
            tic_tac_toe[2][1] = b;
            break;
        case '9':
            if (tic_tac_toe[2][2] != -1){
                goto link;
            }
            tic_tac_toe[2][2] = b;
            break;
        default:
            break;
    }
    
    i++;
}






void Show(){
    for (int i = 0; i < N; i++)
    {
        cout << endl;
        for (int j = 0; j < N; j++)
        {
            if (tic_tac_toe[i][j] == -1) {
                cout << " " << " | " ;
            }
            else if (tic_tac_toe[i][j] == 1) {
                cout << "X" << " | " ;
            }
            else if (tic_tac_toe[i][j] == 0) {
                cout << "0" << " | ";
            }
        }
    }
    cout << endl;
}


void Check(int a){
    win = 1;
    if (tic_tac_toe[0][0] == a && tic_tac_toe[0][1] == a && tic_tac_toe[0][2] == a) {
        win = 0;
    }if (tic_tac_toe[1][0] == a && tic_tac_toe[1][1] == a && tic_tac_toe[1][2] == a) {
        win = 0;
    }if (tic_tac_toe[2][0] == a && tic_tac_toe[2][1] == a && tic_tac_toe[2][2] == a) {
        win = 0;
    }if (tic_tac_toe[0][0] == a && tic_tac_toe[1][0] == a && tic_tac_toe[2][0] == a) {
        win = 0;
    }if (tic_tac_toe[0][1] == a && tic_tac_toe[1][1] == a && tic_tac_toe[2][1] == a) {
        win = 0;
    }if (tic_tac_toe[0][2] == a && tic_tac_toe[1][2] == a && tic_tac_toe[2][2] == a) {
        win = 0;
    }if (tic_tac_toe[0][0] == a && tic_tac_toe[1][1] == a && tic_tac_toe[2][2] == a) {
        win = 0;
    }if (tic_tac_toe[2][0] == a && tic_tac_toe[1][1] == a && tic_tac_toe[0][2] == a) {
        win = 0;
    }
    
}

void Winner(int a){
    if( a == 1){
        if (win == 0) {
        cout << "===============\n   GAME OVER\n\nПобедил игрок "<< a << "\n===============" << endl;
        }
    }
    if( a == 2){
        if (win == 0) {
            //a = 2;
            cout << "===============\n   GAME OVER\n\nПобедил игрок "<< a << "\n===============" << endl;
        }
    }
}



void TakeReveng(){
    
    cout << "Взять реванш? \n 1 - Да\n 0 - нет" << endl;
    do {
        cin >> rev;
    } while (rev != 1 && rev != 0 );
}


