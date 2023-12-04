 #include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

const int panjang_papan = 25;

class Objek {
public:
    int posisi;

    Objek() : posisi(0) {}

    void Gerak(int langkah) {
        posisi += langkah;
    }

    bool ApakahFinish() const {
        return posisi >= panjang_papan;
    }

    void TampilkanPapan() const {
        for (int i = 0; i < panjang_papan; ++i) {
            cout << (i == posisi ? "O" : "-");
        }
        cout << endl;
    }
};

int LemparDadu() {
    return rand() % 6 + 1;
}

void TungguSpasi() {
    cout << "Tekan spasi untuk melempar dadu...";
    while (_getch() != ' ');
}

int main() {
    srand(time(0));

    Objek objek1, objek2;

    while (!objek1.ApakahFinish() && !objek2.ApakahFinish()) {
        TungguSpasi();
        
        int hasil_lempar_objek1 = LemparDadu();
        cout << "Hasil lemparan dadu objek 1: " << hasil_lempar_objek1 << endl;
        objek1.Gerak(hasil_lempar_objek1);

        TungguSpasi();
        int hasil_lempar_objek2 = LemparDadu();
        cout << "Hasil lemparan dadu objek 2: " << hasil_lempar_objek2 << endl;
        objek2.Gerak(hasil_lempar_objek2);

        cout << "Papan Permainan:\n";
        objek1.TampilkanPapan();
        objek2.TampilkanPapan();
        cout << endl;
    }

    if (objek1.ApakahFinish()) {
        cout << "Objek 1 mencapai garis finis!" << endl;
    } else {
        cout << "Objek 2 mencapai garis finis!" << endl;
    }

    return 0;
}
    
