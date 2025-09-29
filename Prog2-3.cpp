#include <iostream>
using namespace std;

int main() {

    int kuning = 3;
    int merah = 80;
    int hijau = 20;
    int mulai = 47;
    int durasi;
    int hasil;
    string warna;

    cout << "Masukkan durasi:" << endl;
    cin >> durasi;
    /*Soal Pemrograman 1 terdiri dari: 80, 135, 150, 212*/

    hasil = (durasi - mulai)%103;

    if (hasil <= 80) {
        warna = "Merah";
    }

    else if (hasil <= 100 and hasil > 80) {
        warna = "Hijau";
    }

    else if(hasil <= 103 and hasil > 100) {
        warna = "Kuning";
    }

    cout << "Warna APILL: " << warna << endl;

    return 0;
}
