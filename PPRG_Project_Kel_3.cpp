#include <bits/stdc++.h>
#include <thread>
#include <conio.h>
using namespace std;

struct siswa {
    string nama;
    float nilai_mtk;
    float nilai_bindo;
    float rerata;
    bool status_siswa;
};

siswa biodata[1000];

void sort_siswa(int jumlah_pendaftar) {
    for(int i=1; i<jumlah_pendaftar; i++) {
        int temp = i;
        for(int j=i+1; j<=jumlah_pendaftar; j++) {
            if(biodata[temp].rerata<biodata[j].rerata) {
                temp = j;
            }
        }
        swap(biodata[temp], biodata[i]);
    }
}

int main() {
    int jumlah_pendaftar;
    int jumlah_kuota;
    string s = "-----SELAMAT DATANG PADA LAMAN REGISTRASI SISWA BARU TAHUN AJARAN 2024/2025-----";

    system("CLS");
    cout << "--------------------------------------------------------------------------------" << endl;
    for(int i=0; i<s.length(); i++) {
        this_thread::sleep_for(chrono::milliseconds(80));
        cout << s[i];
    }
    cout << endl;
    cout << "--------------------------------------------------------------------------------" << endl << endl;
    
    cout << "Masukkan jumlah pendaftar: ";
    cin >> jumlah_pendaftar;
    cout << "Masukkan jumlah kuota: ";
    cin >> jumlah_kuota;
    cout << endl << endl;

    system("CLS");
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "------------------------------Data siswa pendaftar------------------------------" << endl;
    cout << "--------------------------------------------------------------------------------" << endl << endl;
    for(int i=1; i<=jumlah_pendaftar; i++) {
        cout << "Nama pendaftar ke-" << i << setw(8) << ": ";
        cin.ignore();
        getline(cin, biodata[i].nama);
        cout << "Nilai matematika " << setw(10) << ": ";
        cin >> biodata[i].nilai_mtk;
        cout << "Nilai bahasa Indonesia" << setw(5) << ": ";
        cin >> biodata[i].nilai_bindo;
        biodata[i].rerata = (biodata[i].nilai_bindo+biodata[i].nilai_mtk)/2;
        cout << "Nilai rerata " << setw(14) << ": " << biodata[i].rerata;
        cout << endl << endl;
    }

    sort_siswa(jumlah_pendaftar);

    system("CLS");
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "------------------------------Daftar siswa diterima-----------------------------" << endl;
    cout << "--------------------------------------------------------------------------------" << endl << endl;
    for(int i=1; i<=jumlah_kuota; i++) {
        this_thread::sleep_for(chrono::milliseconds(80));
        cout << i << ". " << biodata[i].nama << " (" << biodata[i].rerata << ")" << endl;
    }
    cout << endl << endl;
}