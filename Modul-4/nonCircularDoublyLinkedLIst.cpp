#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode{
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string dataBaru;

void initH();
void initHT();
int kosongH();
int kosongHT();

void tambahDepanH();
void tambahDepanHT();
void tambahBelakangH();
void tambahBelakangHT();
void tampilkanH();
void tampilkanHT();
void hapusDepanH();
void hapusDepanHT();
void hapusBelakangH();
void hapusBelakangHT();
void resetH();
void resetHT();

int main(){
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "=======================================" << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "=======================================" << endl;
    cout << "Pilihan : ";
    cin >> menu;

    if(menu == 1){
        system("cls");
        do{
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "==============================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "==============================================" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch(pil){
                case 1:
                    tambahDepanH();
                    break;
                case 2:
                    tambahBelakangH();
                    break;
                case 3:
                    tampilkanH();
                    break;
                case 4:
                    hapusDepanH();
                    break;
                case 5:
                    hapusBelakangH();
                    break;
                case 6:
                    resetH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }
            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil < 7);

    } else if(menu == 2){
        system("cls");
        do{
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "=======================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "=======================================================" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);
            
            switch(pil){
                case 1:
                    tambahDepanHT();
                    break;
                case 2:
                    tambahBelakangHT();
                    break;
                case 3:
                    tampilkanHT();
                    break;
                case 4:
                    hapusDepanHT();
                    break;
                case 5:
                    hapusBelakangHT();
                    break;
                case 6:
                    resetHT();
                    break;
                default:
                    system("cls");
                    goto menu;
            }
            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil < 7);
        
    } else {
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by Hafiz Perdana (2410817210027)." << endl;
        getch();
        system("cls");
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int kosongH(){
    if(head == NULL) return true;
    else return false;
}

int kosongHT(){
    if(tail == NULL) return true;
    else return false;
}

void tambahDepanH(){
    cout << "Masukkan Data : ";
    cin >> dataBaru;
    TNode *baru;
    baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(kosongH() == true){
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian depan.";
}

void tambahDepanHT(){
    cout << "Masukkan data : ";
    cin >> dataBaru;
    TNode *baru;
    baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(kosongHT() == true){
        head = baru;
        tail = baru;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian depan.";
}

void tambahBelakangH(){
    cout << "Masukkan Data : ";
    cin >> dataBaru;
    TNode *baru, *bantu;
    baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(kosongH() == true){
        head = baru;
    }
    else{
        bantu = head;
        while(bantu->next != NULL){
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang.";
}

void tambahBelakangHT(){
    cout << "Masukkan Data : ";
    cin >> dataBaru;
    TNode *baru;
    baru = new TNode;
    baru->data = dataBaru;
    baru->next = NULL;
    baru->prev = NULL;

    if(kosongHT() == true){
        head = baru;
        tail = baru;
    }
    else{
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Data \""<<dataBaru<<"\" berhasil dimasukkan di bagian belakang.";
}

void tampilkanH(){
    TNode *bantu;
    bantu = head;

    if(kosongH() == false){
        while(bantu != NULL){
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void tampilkanHT(){
    TNode *bantu;
    bantu = head;

    if(kosongHT() == false){
        while(bantu != tail->next){
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void hapusDepanH(){
    TNode *hapus;
    string data;

    if(kosongH() == false){
        hapus = head;
        data = hapus->data;
        if(head->next != NULL){
            head = head->next;
            head->prev = NULL;
        }
        else{
            initH();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void hapusDepanHT(){
    TNode *hapus;
    string data;

    if(kosongHT() == false){
        hapus = head;
        data = hapus->data;
        if(head->next != NULL){
            head = head->next;
            head->prev = NULL;
        }
        else{
            initHT();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void hapusBelakangH(){
    TNode *hapus;
    string data;

    if(kosongH() == false){
        hapus = head;
        while(hapus->next != NULL){
            hapus = hapus->next;
        }
        data = hapus->data;
        if(head->next != NULL){
            hapus->prev->next = NULL;
        }
        else{
            initH();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di belakang telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void hapusBelakangHT(){
    TNode *hapus;
    string data;

    if(kosongHT() == false){
        hapus = tail;
        data = hapus->data;
        if(head->next != NULL){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            initHT();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void resetH(){
    TNode *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initH();
    cout << "Seluruh data pada Linked List telah dibersihkan.";
}

void resetHT(){
    TNode *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initHT();
    cout << "Seluruh data pada Linked List telah dibersihkan.";
}