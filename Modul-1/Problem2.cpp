#include <iostream>
using namespace std;

struct kendaraan
{
    string platnomor;
    string jenis;
    string namapemilik;
    string alamat;
    string kota;
};

void data (const kendaraan &k)
{
    cout << "Plat Nomor Kendaraan\t: " << k.platnomor << endl;
    cout << "Jenis Kendaraan\t\t: " << k.jenis << endl;
    cout << "Nama Pemilik\t\t: " << k.namapemilik << endl;
    cout << "Alamat\t\t\t: " << k.alamat << endl;
    cout << "Kota\t\t\t: " << k.kota << endl;
}

int main()
{
    kendaraan kendaraan = {"DA1234MK","RUSH","Andika Hartanto","Jl. Kayu Tangi 1","Banjarmasin"};
    data (kendaraan);

    return 0;
}