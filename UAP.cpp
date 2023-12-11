#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ncurses/ncurses.h>

int LINTASAN = 120;
int TINGGI = 20;

class Dinosaur {
public:
    int x, y;
    bool lompat;

    Dinosaur() : x(10), y(18), lompat(false) {}

    void jump() {
        if (!lompat) {        
            lompat = true;
            ketinggianlompat = 0;
        }
    }

    void update() {
        if (lompat) {
            y -= 1;
            ketinggianlompat += 1;
            if (ketinggianlompat >= 5) {
                lompat = false;
            }
        } else if (y < TINGGI - 2) {
            y += 1;
            if (y >  TINGGI - 2) {
                y = TINGGI - 2;
            }
        }
    }

    void gambardino() {
        mvprintw(y, x,     "  3>>");
        
    }

    bool sudahditanah() {
        return y == TINGGI - 2;
    }

private:
    int ketinggianlompat;
};

class Rintangan {
public:
    int x, y;

    Rintangan(int startX) : x(startX), y(TINGGI - 2) {}

    void move() {
        x--;
        if (x < 0) {
            x = LINTASAN - 1;
        }
    }

    void drawrintangan() {
        mvprintw(y, x, "X");
    }
};

int main() {
    initscr();
    noecho();
    curs_set(0);

    timeout(30);

    

    Dinosaur dino;
    Rintangan Rintangan(LINTASAN - 1);

    int score = 0;

    // Menampilkan pesan untuk memulai permainan
    mvprintw( 10 ,  45 , "TEKAN SPACE UNTUK MELOMPAT");
    refresh();
    getch();
	
    while (true) {
        int ch = getch();
        if (ch == ' '&& dino.sudahditanah()) {
            dino.jump();
        } else if (ch == 'q') {
            break;
        }

        clear();

        dino.update();  
        Rintangan.move();

        if (dino.x == Rintangan.x && dino.y == Rintangan.y) {
            // Game over
            mvprintw( 10, 45, "kamu kalah hahahahahahahahah!");
            refresh();
            getch();
            break;
        }

        if (Rintangan.x == LINTASAN - 1) {
            score++;
        }

        dino.gambardino();
        Rintangan.drawrintangan();

        // Menampilkan tanah
        for (int i = 0; i < LINTASAN; ++i) {
            mvprintw(TINGGI - 1, i, "=");
        }

        // Menampilkan skor
        mvprintw(0, 0, "Score: %d", score);

        refresh();
    }

    endwin();
    return 0;
}
