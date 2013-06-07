#include <iostream>
#include <vector>
#include <string>

using namespace std;
static int BOARD_SIZE = 8;
static string empty = "........";
vector <string> chessboard(BOARD_SIZE, empty);

void initialChessBoard(int&, int&, int&, int&);
bool checkKing(int, int, bool);
char getletter(char, bool);
bool checkEachletter(char, int, int);

int main() {
    string line;
    cin>>line;
    int count = 1;
    
    while (line != "") {
        //read chess board
        int black_i, black_j, white_i, white_j;
        chessboard[0] = line;
        black_i = black_j = white_i = white_j = -1;
        for (int i = 1; i < BOARD_SIZE; i++) {
            cin>>line;
            chessboard[i] = line;
        }
        //check the end
        bool isEnd = true;
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (chessboard[i] != empty) {
                isEnd = false;
                break;
            }
        }
        if (isEnd)
            break;
        
        //find kings
        initialChessBoard(black_i, black_j, white_i, white_j);
        
        //check king
        cout<<"Game #"<<count++<<": ";
        if(checkKing(white_i, white_j, 1))
            cout<<"white";
        else if(checkKing(black_i, black_j, 0))
            cout<<"black";
        else
            cout<<"no";
        cout<<" king is in check."<<endl;

        cin>>line;
    }
  
  return 0;
}


void initialChessBoard(int &black_i, int &black_j, int &white_i, int &white_j){
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            //search for white and black king
            if (chessboard[i][j] == 'k') {
                black_i = i; black_j = j;
            }
            else if (chessboard[i][j] == 'K') {
                white_i = i; white_j = j;
            }
        }
    }
}



bool checkKing(int king_i, int king_j, bool isWhite){
    //check whether king is in check
    string king = isWhite?"white":"black";
    
    bool isCheck = 0;
    int i,j;
    //check vertical/horizontal for rook, queen
    i = king_i; j = king_j;
    while (i > 0 && !isCheck) {
        i--;
        isCheck = checkEachletter(getletter('q', isWhite), i, j) ||
        checkEachletter(getletter('r', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }
    
    i = king_i; j = king_j;
    while (i < BOARD_SIZE-1 && !isCheck) {
        i++;
        isCheck = checkEachletter(getletter('q', isWhite), i, j) ||
        checkEachletter(getletter('r', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }
    
    i = king_i; j = king_j;
    while (j > 0 && !isCheck) {
        j--;
        isCheck = checkEachletter(getletter('q', isWhite), i, j) ||
        checkEachletter(getletter('r', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }
    
    i = king_i; j = king_j;
    while (j < BOARD_SIZE-1 && !isCheck) {
        j++;
        isCheck = checkEachletter(getletter('q', isWhite), i, j) ||
        checkEachletter(getletter('r', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }   
    
    
    //check pawn
    if (!isCheck) {
        i = king_i; j = king_j;
        if (isWhite) {
            isCheck = checkEachletter(getletter('p', isWhite), i-1, j+1) ||
            checkEachletter(getletter('p', isWhite), i-1, j-1);
        }
        else{
            isCheck = checkEachletter(getletter('p', isWhite), i+1, j+1) ||
            checkEachletter(getletter('p', isWhite), i+1, j-1);
        }
    }
    
    //check king
    if (!isCheck) {
        i = king_i; j = king_j;
        isCheck = checkEachletter(getletter('k', isWhite), i+1, j+1) ||
        checkEachletter(getletter('k', isWhite), i+1, j-1) ||
        checkEachletter(getletter('k', isWhite), i+1, j) ||
        checkEachletter(getletter('k', isWhite), i, j-1) ||
        checkEachletter(getletter('k', isWhite), i, j+1) ||
        checkEachletter(getletter('k', isWhite), i-1, j-1) ||
        checkEachletter(getletter('k', isWhite), i-1, j) ||
        checkEachletter(getletter('k', isWhite), i-1, j+1);
    }
    
    //check diagonal for bishop, queen
    i = king_i; j = king_j;
    while (j > 0 && i > 0 && !isCheck) {
        j--; i--;
        isCheck = checkEachletter(getletter('b', isWhite), i, j) ||
        checkEachletter(getletter('q', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }
    
    i = king_i; j = king_j;
    while (i < BOARD_SIZE-1 && j < BOARD_SIZE-1 && !isCheck) {
        j++;i++;
        isCheck = checkEachletter(getletter('q', isWhite), i, j) ||
        checkEachletter(getletter('b', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }
    i = king_i; j = king_j;
    while (j > 0 && i < BOARD_SIZE-1 && !isCheck) {
        j--;i++;
        isCheck = checkEachletter(getletter('q', isWhite), i, j) ||
        checkEachletter(getletter('b', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }
    
    i = king_i; j = king_j;
    while (j < BOARD_SIZE-1 && i > 0 && !isCheck) {
        j++; i--;
        isCheck = checkEachletter(getletter('q', isWhite), i, j) ||
        checkEachletter(getletter('b', isWhite), i, j);
        if (!isCheck && chessboard[i][j] != '.')
            break;
    }
    
    i = king_i; j = king_j;
    
    //check knight
    if (!isCheck) {
        isCheck = checkEachletter(getletter('n', isWhite), i-2, j-1) ||
        checkEachletter(getletter('n', isWhite), i-1, j-2) ||
        checkEachletter(getletter('n', isWhite), i+2, j-1) ||
        checkEachletter(getletter('n', isWhite), i+1, j-2) ||
        checkEachletter(getletter('n', isWhite), i+2, j+1) ||
        checkEachletter(getletter('n', isWhite), i+1, j+2) ||
        checkEachletter(getletter('n', isWhite), i-2, j+1) ||
        checkEachletter(getletter('n', isWhite), i-1, j+2);
    }
    
    return isCheck;

}

bool checkEachletter(char letter, int index_i, int index_j){
    bool isCheck = 0;
    if (index_i >= 0 && index_i < BOARD_SIZE && index_j >= 0 && index_j < BOARD_SIZE) {
        if(chessboard[index_i][index_j] == letter)
            isCheck = 1;
    }
    
    return isCheck;
}

char getletter(char c, bool isWhite){
    return isWhite?c:toupper(c);
}

