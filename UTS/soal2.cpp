#include <iostream>
using namespace std;

int main() {
    system("CLS");
    int n;
    string* nama_siswa = new string[n];
    int* menu = new  int[n];
    int* status = new int[n];


    for (int i = 0; i < n; i++) {
        cout << "siswa " << i + 1 << endl;
        cout << "Nama siswa: "; cin >> nama_siswa[i];
        cin.ignore();
        cout << "Skor "; cin >> status[i];
        cout << endl;
    }

      cout << "Masukkan nama: "; cin >> n;
    cout << endl;


    cout << "\nSkor\n";
    int nomor = 1;
    for (int i = 0; i < n; i++) {
        if (status[i] == 2) {
            for (int j = 0; j < nama_siswa[i].length(); j++) {
                nama_siswa[i][j] = toupper(nama_siswa[i][j]);
            }
            cout << nomor++ << ". " << nama_siswa[i] << " - " << menu[i] << " [VIP]" << endl;
        }
    }

    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            for (int j = 0; j < nama_siswa[i].length(); j++) {
                nama_siswa[i][j] = toupper(nama_siswa[i][j]);
            }
            cout << nomor++ << ". " << nama_siswa[i] << " - " << menu[i] << endl;
        }
    }

    delete[] nama_siswa;
    delete[] menu;
    delete[] status;

    return 0;
}