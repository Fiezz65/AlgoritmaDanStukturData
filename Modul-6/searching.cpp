#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target){
    vector<int> indices;

    for (auto i = 0; i < nums.size(); i++){
        if (nums[i] == target) indices.push_back(i);
    }
    if (indices.empty()) cout << "Angka " << target << " tidak ditemukan pada array" << endl;
    else {
        cout << "Angka " << target << " terdapat pada array sebanyak " << indices.size() << " kali" << endl;
        cout << "Angka " << target << " ditemukan pada indeks ke-";
        for (auto i = 0; i < indices.size(); i++){
            cout << indices[i];
            if (i != indices.size() - 1) cout << ", ";
        }
        cout << endl;
    }
}

void binarySearch(const vector<int> &nums, int target){
    int high = nums.size() - 1;
    int low = 0;
    int index = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;

        if (nums[mid] == target){
            index = mid;
            break;
        }
        if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (index == -1) cout << "Angka " << target << " tidak ditemukan pada array" << endl;
    else cout << "Angka " << target << " ditemukan pada indeks ke-" << index << endl;
}

void clearScreen(){
    system("cls");
}

void explain() {
    cout << "\nANALISIS PERBANDINGAN ALGORITMA PENCARIAN: SEQUENTIAL SEARCH DENGAN BINARY SEARCH" << endl;

    cout << "\nSEQUENTIAL SEARCH (PENCARIAN LINEAR)" << endl;
    cout << "=====================================" << endl;
    cout << "Prinsip Dasar:" << endl;
    cout << "> Bekerja dengan memeriksa setiap elemen dalam koleksi data (misalnya, array) secara berurutan (satu per satu) dari awal hingga akhir." << endl;
    cout << "> Setiap elemen dibandingkan dengan nilai target. Jika cocok, pencarian berhasil. Jika seluruh koleksi diperiksa tanpa menemukan target, pencarian gagal." << endl;

    cout << "\nAnalisis Kompleksitas:" << endl;
    cout << "> Waktu: O(n) pada kasus terburuk dan rata-rata (n adalah jumlah elemen). Alasannya, algoritma mungkin perlu mengunjungi semua elemen." << endl;
    cout << "         O(1) pada kasus terbaik (target di elemen pertama)." << endl;
    cout << "> Ruang: Umumnya O(1) untuk ruang tambahan (auxiliary space), karena hanya memerlukan variabel internal untuk iterasi dan penyimpanan target." << endl;

    cout << "\nPrasyarat:" << endl;
    cout << "> Tidak memerlukan kondisi data terurut. Dapat langsung diterapkan pada koleksi data acak." << endl;

    cout << "\nKelebihan:" << endl;
    cout << "  + Implementasi sederhana dan mudah dipahami." << endl;
    cout << "  + Efektif untuk koleksi data berukuran kecil." << endl;
    cout << "  + Dapat digunakan pada data yang tidak terurut." << endl;
    cout << "  + Mudah dimodifikasi untuk menemukan semua kemunculan target (seperti pada kode Anda)." << endl;

    cout << "\nKekurangan:" << endl;
    cout << "  - Tidak efisien untuk koleksi data berukuran besar karena kompleksitas waktu linear O(n)." << endl;
    cout << "  - Kinerja menurun drastis seiring bertambahnya jumlah data." << endl;

    cout << "\nContoh Aplikasi:" << endl;
    cout << "  - Pencarian pada list kecil atau data yang sering berubah sehingga pengurutan tidak praktis." << endl;
    cout << "  - Pencarian pada struktur data seperti linked list (yang aksesnya memang sekuensial)." << endl;

    cout << "\n\nBINARY SEARCH (PENCARIAN BINER)" << endl;
    cout << "=================================" << endl;
    cout << "Prinsip Dasar:" << endl;
    cout << "> Menerapkan strategi 'divide and conquer' pada koleksi data yang *sudah terurut*." << endl;
    cout << "> Membandingkan target dengan elemen tengah. Berdasarkan perbandingan, ruang pencarian dipersempit menjadi setengah bagian (kiri atau kanan)." << endl;
    cout << "> Proses ini diulang hingga target ditemukan atau ruang pencarian habis." << endl;

    cout << "\nAnalisis Kompleksitas:" << endl;
    cout << "> Waktu: O(log n) pada kasus terburuk dan rata-rata. Alasannya, setiap langkah mengurangi separuh ruang pencarian." << endl;
    cout << "         O(1) pada kasus terbaik (target adalah elemen tengah pada iterasi pertama)." << endl;
    cout << "> Ruang: O(1) untuk implementasi iteratif. Untuk implementasi rekursif, bisa mencapai O(log n) karena tumpukan pemanggilan fungsi (call stack)." << endl;

    cout << "\nPrasyarat Utama:" << endl;
    cout << "> Koleksi data *wajib* dalam keadaan terurut (ascending atau descending)." << endl;

    cout << "\nKelebihan:" << endl;
    cout << "  + Sangat efisien untuk koleksi data besar yang terurut (kompleksitas waktu O(log n))." << endl;
    cout << "  + Kinerja pencarian jauh lebih cepat dibandingkan sequential search untuk dataset besar." << endl;

    cout << "\nKekurangan:" << endl;
    cout << "  - Memerlukan data yang sudah terurut. Jika data belum terurut, diperlukan biaya tambahan untuk proses pengurutan (misalnya, O(n log n) untuk algoritma sortir yang efisien)." << endl;
    cout << "  - Kurang efisien untuk dataset yang sangat kecil, di mana overhead pengurutan (jika diperlukan) mungkin tidak sebanding dengan kecepatan pencarian." << endl;
    cout << "  - Implementasi sedikit lebih kompleks dibandingkan sequential search." << endl;
    cout << "  - Tidak cocok untuk struktur data yang tidak mendukung akses acak efisien (random access), seperti linked list." << endl;

    cout << "\nContoh Aplikasi:" << endl;
    cout << "  - Pencarian dalam kamus atau buku telepon (yang sudah terurut)." << endl;
    cout << "  - Operasi pencarian pada database yang diindeks." << endl;
    cout << "  - Sebagai sub-rutin dalam algoritma lain yang memerlukan pencarian cepat pada data terurut (misalnya, dalam beberapa algoritma machine learning atau grafika komputer)." << endl;
}

int getValidPositiveInteger(const string& promptMessage) {
    int value;
    while (true) {
        cout << promptMessage;
        cin >> value;

        if (cin.good() && value > 0) {
            return value;
        } else {
            cout << "Error: Mohon masukkan bilangan bulat positif (lebih besar dari 0)." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int getIntegerInput(const string& promptMessage) {
    int value;
    while (true) {
        cout << promptMessage;
        cin >> value;

        if (cin.good()) {
            return value;
        } else {
            cout << "Error: Mohon masukkan bilangan bulat yang valid." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}


int main() {
    int opt, target;
    do {
        cout << " ________________________________________________________________" << endl;
        cout << "|                           Pilih Menu                           |" << endl;
        cout << "|________________________________________________________________|" << endl;
        cout << "|1. Sequential Searching                                         |" << endl;
        cout << "|2. Binary Searching                                             |" << endl;
        cout << "|3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!|" << endl;
        cout << "|4. Exit                                                         |" << endl;
        cout << "|________________________________________________________________|" << endl;

        opt = getIntegerInput("Pilih: ");

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << "Generating 100 numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                
                target = getIntegerInput("Masukkan angka yang ingin dicari: ");

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size = getValidPositiveInteger("Masukkan jumlah data: ");

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                sort(nums.begin(), nums.end());

                cout << "Generating " << size << " numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                
                target = getIntegerInput("Masukkan angka yang ingin dicari: ");

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Program was made by Hafiz Perdana (2410817200127)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
        }
        getch();
        clearScreen();

    } while (opt != 4);

    return 0;
}