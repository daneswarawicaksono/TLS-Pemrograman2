#include <iostream>
#include <string>
using namespace std;

bool vocal(char v) {
    v = tolower(v);
    return (v == 'a' || v == 'i' || v == 'u' || v == 'e' || v == 'o');
}


string balik(string s) {
    string hasil = "";
    for (int i = s.size() - 1; i >= 0; i--) {
        hasil += s[i];
    }
    return hasil;
}

string encrypt(string huruf) {
    if (huruf.empty()) return "";


    char KarakterKe1 = huruf[0];
    int kodeASCII = (int)KarakterKe1;


    string tanpaVokal = "";
    for (char a : huruf) {
        if (!vocal(a)) {
            tanpaVokal += a;
        }
    }


    string terbalik = balik(tanpaVokal);


    int tengah = terbalik.size() / 2;
    string result = terbalik.substr(0, tengah) + to_string(kodeASCII) + terbalik.substr(tengah);

    return result;
}

void decrypt(string kode) {
    int n = kode.size();
    string angka = "";
    int posisi = -1;


    for (int i = 0; i < n; i++) {
        if (isdigit(kode[i])) {
            if (posisi == -1) posisi = i;
            angka += kode[i];
        }
    }

    
    int kodeASCII = stoi(angka);
    char KarakterKe1 = (char)kodeASCII;

    
    string temp = kode.substr(0, posisi) + kode.substr(posisi + angka.size());


    string dibalikLagi = balik(temp);

    cout << "Kode sandi   : " << kode << endl;
    cout << "ASCII terdeteksi : " << kodeASCII << " ---> huruf pertama = " << KarakterKe1 << endl;
    cout << "Hasil setelah dibalik kembali (tanpa vokal) : " << dibalikLagi << endl;
    cout << "Kemungkinan kata asli diawali dengan huruf '" << KarakterKe1 << "'" << endl;
    cout << "Dimana kemungkinan kata tersebut adalah German atau Germania" << endl;
}

int main() {
    
    cout << " --- HASIL MESIN ENKRIPSI ---" << endl;
    cout << "banana    ---> " << encrypt("banana") << endl;
    cout << "Jakarta   ---> " << encrypt("Jakarta") << endl;
    cout << "TANGERANG ---> " << encrypt("TANGERANG") << endl;

    
    cout << "\n--- HASIL MESIN DEKRIPSI ---" << endl;
    decrypt("nm71rG");

    return 0;
}
