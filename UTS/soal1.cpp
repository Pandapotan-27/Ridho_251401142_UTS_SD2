#include <iostream> // Mengimpor pustaka iostream untuk operasi input-output (seperti cout)
using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std:: sebelum cout atau endl

int main(){
    // Deklarasi
    int array[2][3][4]; // Deklarasi array 3 dimensi berukuran 2 lapis x 3 baris x 4 kolom

    int angka = 3; // Inisialisasi variabel penyimpan bilangan ganjil, dimulai dari 1

    for (int i = 0; i < 2; i++ ){ 
        for (int j = 0; j < 3; j++){ 
            for (int k = 0; k < 4; k++){ 
                array[i][j][k] = angka; 
                angka += 2; 
            }
        } 
    } 

    for (int i = 0; i < 2; i++){ 
        cout << "Lapis " << i+1 << endl; 

        for(int j = 0; j < 3; j++){ 
            for(int k = 0; k < 4; k++){
                cout << array[i][j][k] << "\t"; 
            } 
            cout << endl; 
        } 
        cout << endl; 
    } 
    cout << endl; 

    return 0; 
}