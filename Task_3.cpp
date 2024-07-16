#include<iostream>
using namespace std;
string currentplayer;
string playername1, playername2;

void getPlayername(string& playername1, string& playername2){
    cout<<"Enter the name of the 1st player - ";
    getline(cin, playername1);
    cout<<"Enter the name of the 2nd player - ";
    getline(cin, playername2);
    cout<<"@ "<<playername1<<" is the 1st player, so he/she will play first."<<endl;
    cout<<"@ "<<playername2<<" is the 2nd player, so he/she will play second."<<endl;
    currentplayer = playername1;
}

void displayboard(char board[3][3])
{
    cout<<"Current Board :- "<<endl;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            cout<<" "<<board[i][j]<<" ";
            if(j<2) cout<<"|";
        }
        cout<<endl;
        if(i<2) cout<<"---|---|---"<<endl;
    }
}

void switchplayer(){
     currentplayer = (currentplayer == playername1) ? playername2 : playername1;
}

bool makemove(char board[3][3], int row, int col){
    if(row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' '){
        return false;
    }   
    board[row][col] = (currentplayer == playername1) ? 'X' : '0';
    return true; 

}

bool checkwin(char board[3][3]){
    char symbol = (currentplayer == playername1) ? 'X' : '0';
    for(int i = 0; i < 3; i++){
        if(board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol)
            return true;
        if(board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol)
            return true;
    }
    if(board[0][0]==symbol && board[1][1] == symbol && board[2][2] == symbol)
        return true;
    if(board[2][0] == symbol && board[1][1] == symbol && board[0][2] == symbol)
        return true;
    
    return false;
}

bool checkdraw(char board[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == ' '){
                return false;
            }
        }
    }
    return true;
}

void game(char board[3][3])
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void play(char board[3][3])
{
    int move;
    while(true){
        displayboard(board);
        cout<<currentplayer<<" enter your move - ";
        cin>>move;
        int row = (move - 1)/3;
        int col = (move - 1)%3;
        if(makemove(board, row, col)){
            if(checkwin(board)){
                displayboard(board);
                cout<<currentplayer<<" Wins!!"<<endl;
                break;
            }
            if(checkdraw(board)){
                displayboard(board);
                cout<<" The Game is Draw !!"<<endl;
                break;
            }
            switchplayer();
        }
        else{
            cout<<"Invalid Move !!"<<endl;
        }
    }
}

int main()
{
    cout<<"\n                                 ***** Tic - Tac - Toe  Game *****"<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
    cout<<"                                         -: Instruction :-"<<endl<<endl;
    cout<<"1. Enter the names of the two players when prompted."<<endl;
    cout<<"2. The game board is a 3x3 grid, numbered 1 to 9 as follows:"<<endl;
    cout<<"                1 | 2 | 3"<<endl;
    cout<<"               ---|---|---"<<endl;
    cout<<"                4 | 5 | 6"<<endl;
    cout<<"               ---|---|---"<<endl;
    cout<<"                7 | 8 | 9"<<endl;
    cout<<"3. The first player uses 'X' and the second player uses 'O'."<<endl;
    cout<<"4. A player wins by getting three symbols in a row, column, or diagonal."<<endl;
    cout<<"5. If all cells are filled and no player has won, the game is a draw."<<endl;
    cout<<"6. After the game ends, you can choose to play again by entering 'Y' or 'y'."<<endl<<endl;
    cout<<"------------------------------------------------------------------------------------------------"<<endl;
    char board[3][3];
    char input;
    do{
        getPlayername(playername1, playername2);
        game(board);
        play(board);
        cout<<"Do you want to play again - ";
        cin>>input;
        cout<<endl;
        cin.ignore();
    }while (input == 'Y' || input == 'y'); 
}
