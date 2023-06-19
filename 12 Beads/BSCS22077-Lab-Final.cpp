#include<iostream>
#include<fstream>
#include<Windows.h>
#include<conio.h>
using namespace std;
struct pos {
    int ri;
    int ci;
};

void getRowColbyLeftClick(int& rpos, int& cpos)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD Events;
    INPUT_RECORD InputRecord;
    SetConsoleMode(hInput, ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT | ENABLE_EXTENDED_FLAGS);
    do
    {
        ReadConsoleInput(hInput, &InputRecord, 1, &Events);
        if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
        {
            cpos = InputRecord.Event.MouseEvent.dwMousePosition.X;
            rpos = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            break;
        }
    } while (true);
}
void gotoRowCol(int rpos, int cpos)
{
    COORD scrn;
    HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = cpos;
    scrn.Y = rpos;
    SetConsoleCursorPosition(hOuput, scrn);
}
void SetClr(int clr)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), clr);
}
void init(char**& b, int& dim, int& turn, string pname[]) {
    srand(time(0));
    ifstream rdr("board.txt");
    dim = 5;
    b = new char* [5];
    for (int i = 0; i < dim; i++) {
        b[i] = new char[dim];
    }
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            rdr >> b[i][j];
        }
    }
    turn = rand() % 2;
    cout << "Enter player 1 name: ";
    cin >> pname[0];
    cout << "Enter player 2 name: ";
    cin >> pname[1];
}
void print_X(int dim,int boxDim) {
    int cn = (dim - 1) * boxDim;
    for (int r = 0; r < (dim - 1) * boxDim; r++) {
        for (int c = 0; c < (dim - 1) * boxDim; c++) {
            if (r == c) {
                gotoRowCol(r, c);
                cout << char(-37);
            }
        }
        gotoRowCol(r, cn);
        cout << char(-37);
        cn--;
    }
}
void printBoard(char** B, int dim, int BoxDim) {
    system("cls");
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < (dim - 1) * BoxDim; c++) {
            gotoRowCol(r * BoxDim, c);
            cout << char(-37);
        }
    }
    for (int r = 0; r < (dim - 1) * BoxDim; r++) {
       for (int c = 0; c < dim; c++) {
           gotoRowCol(r, c * BoxDim);
            cout << char(-37);

       }
    }
    print_X(dim, BoxDim);
    
    int sc = 0;
    for (int r = (dim / 2) * BoxDim; r < (dim - 1) * BoxDim; r++) {
        gotoRowCol(r, sc);
        cout << char(-37);
        sc++;
    }
    sc = 0;
    for (int c = (dim / 2) * BoxDim; c < (dim - 1) * BoxDim; c++) {
        gotoRowCol(sc, c);
        cout << char(-37);
        sc++;
    }
    for (int c = (dim - 1) * BoxDim; c >= (dim / 2) * BoxDim; c--) {
        gotoRowCol(sc, c);
        cout << char(-37);
        sc++;
    }
    sc = 0;
    for (int c = (dim / 2) * BoxDim; c >= 0; c--) {
        gotoRowCol(sc, c);
        cout << char(-37);
        sc++;
    }
    for (int r = 0; r < dim; r++) {
        for (int c = 0; c < dim; c++) {
            gotoRowCol(r * BoxDim, c * BoxDim);
            char sym = B[r][c];
            if (sym == 'o') {
                SetClr(4);
                cout << char(toupper(sym));
            }
            else if (sym == '-') {
                SetClr(6);
                cout << sym;
            }
            else {
                SetClr(2);
                cout << sym;
            }
        }
    }
    SetClr(15);
}
void turnMsg(string name) {
    cout << endl << name << "'s turn" << endl;
}
int turnChange(int turn) {
    turn++;
    turn = turn % 2;
    return turn;
}
void cSwap(char& s1, char& s2) {
    char t = s1;
    s1 = s2;
    s2 = t;
}
void updateBoard(char** b, pos s, pos d) {
    cSwap(b[s.ri][s.ci], b[d.ri][d.ci]);
}
bool isMyPiece(char sym, int turn) {
    if (turn == 0 and sym == 'o')
        return true;
    if (turn == 1 and sym == 'O') {
        return true;
    }
    return false;
}
bool isValidSorce(char** b, int turn, pos s) {
    return isMyPiece(b[s.ri][s.ci], turn);
}
bool isValidDest(char** b, int turn, pos d) {
    return (b[d.ri][d.ci] == '-');
}
bool isHoriantalMove(pos s, pos d) {
    return (s.ri == d.ri);
}
bool isVerticalMove(pos s, pos d) {
    return (s.ci == d.ci);
}
bool isDiagonalMove(pos s, pos d) {
    int r = abs(d.ri - s.ri);
    int c = abs(d.ci - s.ci);
    return r == c;
}
int steps(pos s, pos d) {
    if (isHoriantalMove(s, d)) {
        return (d.ci - s.ci);
    }
    else if (isVerticalMove(s, d) or isDiagonalMove(s, d)) {
        return (d.ri - s.ri);
    }
    return 0;
}
bool isHorPathClr(char** b, pos s, pos d, pos& killP) {
    int sc, ec;
    if (s.ci < d.ci) {
        sc = s.ci;
        ec = d.ci;
    }
    else {
        sc = d.ci;
        ec = s.ci;
    }
    for (int i = sc + 1; i < ec; i++) {
        if (b[s.ri][i] != '-') {
            killP.ri = s.ri;
            killP.ci = i;
            return false;
        }
    }
    return true;
}
bool isVrtPathClr(char** b, pos s, pos d, pos& killP) {
    int sr, er;
    if (s.ri < d.ri) {
        sr = s.ri;
        er = d.ri;
    }
    else {
        sr = d.ri;
        er = s.ri;
    }
    for (int i = sr + 1; i < er; i++) {
        if (b[i][s.ci] != '-') {
            killP.ri = i;
            killP.ci = s.ci;
            return false;
        }
    }
    return true;
}
bool isD1PathClr(char** b, pos s, pos d, pos& killP) {
    if (s.ri < d.ri) {
        int t = d.ri - s.ri;
        for (int i = 1; i < t; i++) {
            if (b[s.ri + i][s.ci + i] != '-') {
                if (killP.ri == -1 and killP.ci == -1) {
                    killP.ri = s.ri + i;
                    killP.ci = s.ci + i;
                }
                return false;
            }
        }
    }
    else {
        int t = s.ri - d.ri;
        for (int i = 1; i < t; i++) {
            if (b[d.ri + i][d.ci + i] != '-') {
                if (killP.ri == -1 and killP.ci == -1) {
                    killP.ri = d.ri + i;
                    killP.ci = d.ci + i;
                }
                return false;
            }
        }
    }
    return true;
}
bool isD2PathClr(char** b, pos s, pos d, pos& killP) {
    if (s.ri < d.ri) {
        int t = d.ri - s.ri;
        for (int i = 1; i < t; i++) {
            if (b[s.ri + i][s.ci - i] != '-') {
                if (killP.ri == -1 and killP.ci == -1) {
                    killP.ri = s.ri + i;
                    killP.ci = s.ci - i;
                }
                return false;
            }
        }
    }
    else {
        int t = s.ri - d.ri;
        for (int i = 1; i < t; i++) {
            if (b[s.ri - i][s.ci + i] != '-') {
                if (killP.ri == -1 and killP.ci == -1) {
                    killP.ri = s.ri - i;
                    killP.ci = s.ci + i;
                }
                return false;
            }
        }
    }
    return true;
}
bool isD1move(pos s, pos d) {
    if (d.ri > s.ri and d.ci > s.ci)
        return true;
    if (s.ri > d.ri and s.ci > d.ci)
        return true;
    return false;
}
bool isD2Move(pos s, pos d) {
    if (d.ri < s.ri and d.ci > s.ci)
        return true;
    if (d.ri > s.ri and d.ci < s.ci)
        return true;
}
bool isValidMove(char** b, pos s, pos d, pos& killPiece,int turn) {
    if ((s.ri + s.ci) % 2 == 1) {
        if (isHoriantalMove(s, d) and isHorPathClr(b, s, d, killPiece) and (steps(s, d) == 1 or steps(s, d) == -1))
            return true;
        if (isVerticalMove(s, d) and isVrtPathClr(b, s, d, killPiece) and (steps(s, d) == 1 or steps(s, d) == -1))
            return true;
        if (isHoriantalMove(s, d) and !isHorPathClr(b, s, d, killPiece) and !isMyPiece(b[killPiece.ri][killPiece.ci],turn) and (steps(s, d) == 2 or steps(s, d) == -2))
            return true;
        if (isVerticalMove(s, d) and !isVrtPathClr(b, s, d, killPiece) and !isMyPiece(b[killPiece.ri][killPiece.ci], turn) and (steps(s, d) == 2 or steps(s, d) == -2))
            return true;
        return false;
    }
    if (isHoriantalMove(s, d) and isHorPathClr(b, s, d, killPiece) and (steps(s, d) == 1 or steps(s, d) == -1))
        return true;
    if (isVerticalMove(s, d) and isVrtPathClr(b, s, d, killPiece) and (steps(s, d) == 1 or steps(s, d) == -1))
        return true;
    if (isDiagonalMove(s, d) and (isD1PathClr(b, s, d, killPiece) or isD2PathClr(b, s, d, killPiece)) and
        (steps(s, d) == 1 or
            steps(s, d) == -1))
        return true;
    if (isHoriantalMove(s, d) and !isHorPathClr(b, s, d, killPiece) and !isMyPiece(b[killPiece.ri][killPiece.ci], turn) and (steps(s, d) == 2 or steps(s, d) == -2))
        return true;
    if (isVerticalMove(s, d) and !isVrtPathClr(b, s, d, killPiece) and !isMyPiece(b[killPiece.ri][killPiece.ci], turn) and (steps(s, d) == 2 or steps(s, d) == -2))
        return true;
    killPiece.ri = -1;
    killPiece.ci = -1;
    if (isDiagonalMove(s, d)){
        if (isD1move(s, d))
            return (!isD1PathClr(b, s, d, killPiece) and !isMyPiece(b[killPiece.ri][killPiece.ci], turn) and
                (steps(s, d) == 2 or
                    steps(s, d) == -2));
        else if (isD2Move(s, d))
            return !isD2PathClr(b, s, d, killPiece) and !isMyPiece(b[killPiece.ri][killPiece.ci], turn) and
            (steps(s, d) == 2 or
                steps(s, d) == -2);
    }
    return false;
}
void kill(char**& b, pos killP) {
    b[killP.ri][killP.ci] = '-';
}
bool iskill(pos killP) {
    if (killP.ri != -1 and killP.ci != -1)
        return true;
    return false;
}
bool isIntegralMultiple(int z, int brows) {
    for (int i = 0; i <= z; i++) {
        if (i * brows == z)
            return true;
    }
    return false;
}
bool isWin(char** b, int turn, int dim) {
    turn = turnChange(turn);
    int count = 0;
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if (isMyPiece(b[i][j], turn))
                count++;
        }
    }
    if (count == 0) {
        return true;
    }
    return false;
}
void mouseClick(pos& p, int boxDim) {
    int sr, sc;
    do {
        getRowColbyLeftClick(sr, sc);
    } while (!isIntegralMultiple(sr, boxDim) and !isIntegralMultiple(sc, boxDim));
    p.ri = sr / boxDim;
    p.ci = sc / boxDim;
}
void PrintScore(string name, int scr) {
    cout <<endl<< name << "'s score is: " << scr << endl;
}
int main() {
    char** b;
    int dim, turn = 0;
    string Pnames[2];
    pos s;
    pos d;
    int Box_dim = 17;
    init(b, dim, turn, Pnames);
    printBoard(b, dim, Box_dim);
    pos killPointer;
    killPointer.ri = -1;
    killPointer.ci = -1;
    int score[2] = {};
    while (true) {
        PrintScore(Pnames[0], score[0]);
        PrintScore(Pnames[1], score[1]);
        turnMsg(Pnames[turn]);
        do {
            do {
                cout << "Src: " << endl;
                mouseClick(s, Box_dim);
            } while (!isValidSorce(b, turn, s));
            cout << "dst: " << endl;
            mouseClick(d, Box_dim);
        } while (!isValidDest(b, turn, d) or !isValidMove(b, s, d, killPointer,turn));
        if (iskill(killPointer)) {
            kill(b, killPointer);
            score[turn]++;
            killPointer.ri = -1; Box_dim;
            killPointer.ci = -1; Box_dim;
            turn=turnChange(turn);

        }
        updateBoard(b, s, d);
        printBoard(b, dim, Box_dim);
        if (isWin(b, turn, dim)) {
            cout <<endl<< Pnames[turn] << " Wins...";
            break;
        }
        turn = turnChange(turn);
    }
    return _getch();
    return 0;
}