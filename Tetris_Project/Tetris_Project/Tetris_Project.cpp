#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

#define END_Y 6
#define TABLE_X 15 //size of x
#define TABLE_Y 38 //size of y
#define LEFT 75 // ←
#define RIGHT 77  // →
#define UP 72 // ↑
#define DOWN 80 // ↓
#define SPACE 32 // spacebar

void CursorView(char show) {
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    ConsoleCursor.bVisible = show;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*block 1*/
const int block1[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 0, 0},
                        {2, 2, 2, 2},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0}
        },

};
/*block 2*/
const int block2[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },

};
/*block 3*/
const int block3[4][4][4] = {
        {
                        {0, 2, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 0, 2, 0},
                        {2, 2, 2, 0},
                        {0, 0, 0, 0}

        },

};
/*block 4*/
const int block4[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}
        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 0, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0}

        },
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 0},
                        {2, 2, 0, 0},
                        {0, 0, 0, 0}

        },

};
/*block 5*/
const int block5[4][4][4] = {
        {
                        {0, 0, 0, 0},
                        {0, 2, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}
        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 0},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 2, 2, 2},
                        {0, 0, 0, 0},
                        {0, 0, 0, 0}

        },
        {
                        {0, 0, 2, 0},
                        {0, 0, 2, 2},
                        {0, 0, 2, 0},
                        {0, 0, 0, 0}

        },

};

class Block {
protected:
    int shape[4][4][4]; // shape[rotate][y][x]
    int x; // x value
    int y; // y value
    int rotationCount; // shape[0][y][x], shape[1][y][x], shape[2][y][x], shaoe[3][y][x]
public:
    int getShape(int rotationCount, int y, int x) {
        return shape[rotationCount][y][x];
    }
    int getX() {
        return x;
    }
    int getY() {
        return y;
    }
    int getRotationCount() {
        return rotationCount;
    }
    void down() { // block go down
        y++;
    }
    void left() { // block go left
        x--;
    }
    void right() { // block go right
        x++;
    }
    void rotate() { // block rotate
        rotationCount = (rotationCount + 1) % 4; // express rotation as 0 , 1, 2 , 3 
    }
    void setX(int x) {
        this->x = x;
    }
    void setY(int y) {
        this->y = y;
    }
    void setRotationCount(int r) {
        this->rotationCount = r;
    }
    void setShape(int r, int y, int x, int value) {
        this->shape[r][y][x] = value;
    }
    void up() { // for hard drop 
        y--;
    }
};
/*block 1 class*/
class Block1 : public Block {
public:
    Block1() {
        x = TABLE_X / 2 - 2; // set block initially in middle
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block1[i][j][k]; // save block info
                }
            }
        }
    }
};
/*block 2 class*/
class Block2 : public Block {
public:
    Block2() {
        x = TABLE_X / 2 - 2; // set block initially in middle
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block2[i][j][k]; // save block info
                }
            }
        }
    }
};
/*block 3 class*/
class Block3 : public Block {
public:
    Block3() {
        x = TABLE_X / 2 - 2; // set block initially in middle
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block3[i][j][k]; // save block info
                }
            }
        }
    }
};
/*block 4 class*/
class Block4 : public Block {
public:
    Block4() {
        x = TABLE_X / 2 - 2; // set block initially in middle
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block4[i][j][k]; // save block info
                }
            }
        }
    }
};
/*block 5 class*/
class Block5 : public Block {
public:
    Block5() {
        x = TABLE_X / 2 - 2; // set block initially in middle
        y = 1;
        rotationCount = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    shape[i][j][k] = block5[i][j][k]; // save block info
                }
            }
        }
    }
};

class MainMenu {
public:
    MainMenu() {
        cout << "\n\n\n\n";
        cout << "\t\t"; cout << " $$$$$$$$$$  $$$$$$$$$$  $$$$$$$$$$  $$$$$$$    $    $$$$$$$$  \n";
        cout << "\t\t"; cout << "     $       $               $       $      $   $   $          \n";
        cout << "\t\t"; cout << "     $       $               $       $      $   $   $          \n";
        cout << "\t\t"; cout << "     $       $$$$$$$$$$      $       $ $ $ $    $    $$$$$$$$$ \n";
        cout << "\t\t"; cout << "     $       $               $       $   $      $             $\n";
        cout << "\t\t"; cout << "     $       $               $       $     $    $             $\n";
        cout << "\t\t"; cout << "     $       $$$$$$$$$$      $       $      $   $    $$$$$$$$$ \n\n\n\n\n";
        cout << "\t\t"; cout << "                      Press any Key.\n\n\n\n\n\n\n";
        getchar(); //wait any key
        system("cls"); // console clear
    }
};

class backup {
public:
    /*block backup*/
    static void updateBlock(Block* source, Block& backupBlock) {
        backupBlock.setX(source->getX()); // block's x value backup
        backupBlock.setY(source->getY()); // block's y value backup
        backupBlock.setRotationCount(source->getRotationCount()); // block's rotation value backup
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    backupBlock.setShape(i, j, k, source->getShape(i, j, k)); // block's shape backup
                }
            }
        }
    }
    /*table backup*/
    static void updateTable(vector<vector<int> >& source, vector<vector<int> >& backupTable) {
        backupTable.resize(source.size(), vector<int>(source.size()));
        copy(source.begin(), source.end(), backupTable.begin()); // backup table vector to backupTable vector
    }
};

class GameTable {
private:
    int x;
    int y;
    Block* blockObject;
    vector<vector<int> > table;
public:
    GameTable(int x, int y) {
        srand(time(0));
        blockObject = nullptr;
        this->x = x;
        this->y = y;
        for (int i = 0; i < y; i++) {
            vector<int> temp;
            for (int j = 0; j < x; j++) {
                temp.push_back(0);
            }
            table.push_back(temp);
        }
        // color the edges
        for (int i = 0; i < x; i++) {
            table[y - 1][i] = 1;
        }
        for (int i = 1; i < y ; i++) {
            table[i][0] = 1;
            table[i][x - 1] = 1;
        }
        // detect bottom edge
        for (int i = 1; i < x - 1; i++) {
            table[y - 1][i] = 4; // bottom value = 4
        }
        // end line
        for (int i = 1; i < x - 1; i++) {
            table[END_Y][i] = 5; // end line value = 5
        }

    }
    void DrawGameTable() {
        for (int i = 0; i < y; i++) { 
            for (int j = 0; j < x; j++) {
                if (table[i][j] == 1)cout << "□";
                else if (table[i][j] == 2 || table[i][j] == 3) cout << "■";
                else if (table[i][j] == 4) cout << "□";
                else if (table[i][j] == 5) cout << "◎ ";
                else cout << "  ";
            }
            cout << "\n";
        }
    }

    void createBlock() {
        srand((unsigned int)time(NULL));
        int select = rand() % 5 + 1; // 1 ~ 5 block
        if (select == 1) blockObject = new Block1(); // create block1
        else if (select == 2)blockObject = new Block2(); // create block2
        else if (select == 3)blockObject = new Block3(); // create block3
        else if (select == 4)blockObject = new Block4(); // create block4
        else if (select == 5)blockObject = new Block5(); // create block5

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue;
                table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                //update block on table
            }
        }
    }
    /*move block*/
    void MoveBlock(int key) {
        /*backup*/
        Block backupBlock; // block for backup
        vector<vector<int> > backupTable; // table vector for backup
        backup::updateBlock(blockObject, backupBlock); // block backup
        backup::updateTable(table, backupTable); // table backup

        /*delete block in table */
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();
                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue;
                if (table[Y][X] == 2) { // if block
                    table[Y][X] = 0; // delete on table
                }
            }
        }

        /*move block*/
        if (key == DOWN) blockObject->down(); // if key is down arrow, move block down
        else if (key == LEFT) blockObject->left();  // if key is left arrow, move block left
        else if (key == RIGHT) blockObject->right(); // if key is right arrow, move block right

        /*save the rotated block or cancel*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();

                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; //prevent array out of range

                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //get value of block

                if (blockValue != 2) continue; // ignore if not block (block = 2)

                if (table[Y][X] == 0) { // if empty (update)
                    table[Y][X] = blockValue; // move block
                }
                else if (table[Y][X] == 1) { // if touch side edges (cancel)
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table backup
                    blockObject->setX(backupBlock.getX()); // block's x value backup
                    blockObject->setY(backupBlock.getY()); // block's y value backup
                    return;
                }
                else if (table[Y][X] == 3) { // if touch to builded block
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table backup
                    blockObject->setX(backupBlock.getX()); // block's x value backup
                    blockObject->setY(backupBlock.getY()); // block's y value backup
                    if (key == DOWN) {  // if enter down arrow
                        BuildBlock(); // build a block
                        createBlock(); // create new block
                    }
                    return;
                }
                else if (table[Y][X] == 4) { //if touch to bottom edge
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table backup
                    blockObject->setX(backupBlock.getX()); // block's x value backup
                    blockObject->setY(backupBlock.getY()); // block's y value backup
                    if (key == DOWN) { // if enter down arrow
                        BuildBlock(); // build a block
                        createBlock(); // create new block
                    }
                    return;
                }

            }
        }

    }
    /*rotate block*/
    void RotateBlock() {
        /*backup*/
        Block backupBlock; // block for backup
        vector<vector<int> > backupTable; // table vector for backup
        backup::updateBlock(blockObject, backupBlock); // block backup
        backup::updateTable(table, backupTable); // table backup

        /*delete block on table*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();

                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // prevent array out of range

                if (table[Y][X] == 2) { // if block
                    table[Y][X] = 0; // delete on table
                }
            }
        }

        /*rotate the block*/
        blockObject->rotate();

        /*save the rotated block or cancel*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();

                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // prevent array out of range

                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //get value of block

                if (blockValue != 2) continue; // ignore if not block (block = 2)

                if (table[Y][X] == 0) { //if empty, update info of block in table
                    table[Y][X] = blockObject->getShape(blockObject->getRotationCount(), i, j);
                }
                else if (table[Y][X] == 1 || table[Y][X] == 3 || table[Y][X] == 4) { // cancel if touch block&block or block&edge
                    copy(backupTable.begin(), backupTable.end(), table.begin()); // table backup
                    blockObject->setRotationCount(backupBlock.getRotationCount()); // backup before rotation
                    return; 
                }
            }
        }
    }
    /*build block in table*/
    void BuildBlock() {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();

                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // prevent array out of range

                int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //get value of block
                if (blockValue != 2) continue; // ignore if not block (block = 2)
                table[Y][X] = 3;
            }
        }
    }
    /*if press spacebar, drop immidiately*/
    void HardDropBlock() {
        /*delete block in table*/
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                int Y = j + blockObject->getY();
                int X = i + blockObject->getX();

                if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // prevent array out of range

                if (table[Y][X] == 2) { // if block
                    table[Y][X] = 0; // delete on table
                }
            }
        }
        while (true) { //repeat until touch block or edges
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    int Y = j + blockObject->getY();
                    int X = i + blockObject->getX();
                    int blockValue = blockObject->getShape(blockObject->getRotationCount(), i, j); //get value of block

                    if (Y < 0 || X < 0 || Y >= TABLE_Y || X >= TABLE_X) continue; // prevent array out of range

                    if (blockValue != 2) continue; // ignore if not block (block = 2)

                    if (table[Y][X] == 3 || table[Y][X] == 4) { // if meet block or edges
                        blockObject->up(); // move 1 up
                        BuildBlock(); // build block
                        createBlock(); // create new block
                        return;
                    }
                }
            }
            blockObject->down(); // move block down
        }
    }

    /*delect line*/
    void DeleteLinear() {
        for (int Y = END_Y + 1; Y < TABLE_Y - 1; Y++) {
            bool isLinear = true;
            for (int X = 1; X < TABLE_X - 1; X++) {
                if (table[Y][X] != 3) isLinear = false;
            }
            if (isLinear) {
                for (int i = Y; i > END_Y - 1; i--) {
                    for (int j = 1; j < TABLE_X - 1; j++) {
                        table[i][j] = table[i - 1][j];
                    }
                }
            }
        }
    }
    /*check if built block reach end line*/
    bool isReachEnding() {
        for (int X = 1; X < TABLE_X - 1; X++) {
            if (table[END_Y][X] == 3) return true;
        }
        return false;
    }
};


/*start game*/
class GamePlay {
private:
    GameTable* gt;
public:
    GamePlay() {
        gt = new GameTable(TABLE_X, TABLE_Y);
        gt->createBlock(); // create initial block
        gt->DrawGameTable(); // draw game table
        int timer = 0;
        clock_t start, end;
        start = clock();
        float time;
        while (true) { // press any arrow key
            int nSelect;
            end = clock();
            time = ((float)(end - start) / CLOCKS_PER_SEC);
            if (time >= 1.5) { // about 1.5sec
                gt->MoveBlock(DOWN); //move the block down
                start = clock(); // start new timer
            }
            if (_kbhit()) {
                nSelect = _getch();
                if (nSelect == 224) {
                    nSelect = _getch();
                    switch (nSelect) {
                    case UP: // press up arrow
                        gt->RotateBlock(); // rotate the block 90 degree
                        break;
                    case DOWN: // press down arrow
                        gt->MoveBlock(DOWN); // move the block down
                        break;
                    case LEFT: // press left arrow
                        gt->MoveBlock(LEFT); // move the block left
                        break;
                    case RIGHT: // press right arrow
                        gt->MoveBlock(RIGHT); // move the block right
                        break;
                    default:
                        break;
                    }
                }
                else if (nSelect == SPACE) { // press spacebar
                    gt->HardDropBlock(); // drop the block
                }
            }
            if (gt->isReachEnding())return;
            gt->DeleteLinear();
            gotoxy(0, 0);
            gt->DrawGameTable(); // redraw
        }
    }
    ~GamePlay() { // end the game
        system("cls");
        gotoxy(10, 10);
        cout << "Game Over!";
        delete gt;
    }
};

int main() {
    CursorView(false);
    system("mode con cols=100 lines=40 | title tetris game");
    GameTable gt(TABLE_X, TABLE_Y);
    MainMenu();
    GamePlay();
    getchar();
    return 0;
}