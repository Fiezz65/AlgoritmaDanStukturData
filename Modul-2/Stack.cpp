#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct stack
{
    int data[MAX];
    int atas;
};

stack Tumpuk;

int kosong()
{
    return Tumpuk.atas == -1;
}

int penuh()
{
    return Tumpuk.atas == MAX - 1;
}

void input(int data)
{
    if (kosong() == 1)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack";
    }
    else if(penuh()==0)
    {
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack";
    }
    else
        cout << "Tumpukan Penuh";
}

void hapus()
{
    if (kosong()==0)
    {
        cout << "Data Teratas Sudah Terambil";
        Tumpuk.atas--;
    }
    else
        cout << "Data Kosong";
}

void tampil()
{
    if (kosong()==0)
    {
        for (int i = Tumpuk.atas; i >= 0; i--)
        {
            cout << "\nTumpukan Ke-" << i << " = " << Tumpuk.data[i];
        }
    }
    else
        cout << "Tumpukan Kosong";
}

void bersih()
{
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong!";
}

void inisialisasi()
{
    Tumpuk.atas = -1;
}

int main()
{
    inisialisasi();
    int pilihan, data;
    do
    {
        cout << "       STACK       " << endl;
        cout << "===================" << endl;
        cout << "1. INPUT DATA" << endl;
        cout << "2. HAPUS DATA" << endl;
        cout << "3. TAMPILKAN STACK" << endl;
        cout << "4. RESET STACK" << endl;
        cout << "5. KELUAR" << endl;
        cout << "===================" << endl;
        cout << "PILIH MENU: ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                cout << "MASUKKAN ELEMEN: ";
                cin >> data;
                input(data);
                break;
            case 2:
                hapus();
                break;
            case 3:
                tampil();
                break;
            case 4:
                bersih();
                break;
            case 5:
                cout << "TERIMA KASIH.";
                break;
            default:
                cout << "PILIHAN TIDAK VALID!";
        }
        cout << "\n\nTekan tombol apapun untuk kembali ke menu";
        getch();
        system("cls");
    }
    while (pilihan < 5);

    return 0;
}