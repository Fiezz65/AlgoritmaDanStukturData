#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define n 20
using namespace std;

struct Queue
{
    char Q[n];
    int F;
    int R;
};

Queue antrean;

bool kosong()
{
    return antrean.F == -1 || antrean.F > antrean.R;
}

bool penuh()
{
    return antrean.R == n - 1;
}

void inisialisasi()
{
    antrean.F = -1;
    antrean.R = -1;
}

void INSERT()
{
    char huruf;
    if (penuh())
    {
        cout << "Queue penuh!" << endl;
    }
    else
    {
        cout << "MASUKKAN ELEMEN: ";
        cin >> huruf;
        if (kosong()) {
            antrean.F = antrean.R = 0;
        }
        else
        {
            antrean.R++;
        }
        antrean.Q[antrean.R] = huruf;
        cout << "Data '" << huruf << "' berhasil dimasukkan ke queue." << endl;
    }
}

void DELETE()
{
    if (kosong())
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        cout << "Data '" << antrean.Q[antrean.F] << "' dihapus dari queue." << endl;
        antrean.F++;
        if (antrean.F > antrean.R)
        {
            inisialisasi();
        }
    }
}

void CETAKLAYAR()
{
    if (kosong())
    {
        cout << "Queue kosong!" << endl;
    }
    else
    {
        cout << "Isi Queue: ";
        for (int i = antrean.F; i <= antrean.R; i++)
        {
            cout << antrean.Q[i] << " ";
        }
        cout << endl;
    }
}

void RESET()
{
    inisialisasi();
    cout << "Queue telah dikosongkan!" << endl;
}

int main()
{
    char pilihan[1];
    int pil;

    inisialisasi();
    do
    {
        cout << "        QUEUE         " << endl;
        cout << "======================" << endl;
        cout << "1. INSERT" << endl;
        cout << "2. DELETE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. RESET QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "======================" << endl;
        cout << "PILIH MENU : "; cin >> pilihan;
        pil = atoi(pilihan);

        switch (pil)
        {
        case 1:
            INSERT();
            break;
        case 2:
            DELETE();
            break;
        case 3:
            CETAKLAYAR();
            break;
        case 4:
            RESET();
            break;
        case 5:
            cout << "TERIMA KASIH." << endl;
            break;
        default:
            cout << "PILIHAN TIDAK VALID!" << endl;
        }
        cout << "\nTekan tombol apapun untuk kembali ke menu";
        getch();
        system("cls");
    }
    while (pil < 5);

    return 0;
}