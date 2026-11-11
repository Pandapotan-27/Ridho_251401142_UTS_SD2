#include <iostream> // Mengimpor pustaka iostream untuk fungsi input-output (cin, cout, endl)
#include <string> // Mengimpor pustaka string untuk mengolah tipe data string (kata)

using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std:: di setiap perintah

#define MAX 100 // Mendefinisikan konstanta makro MAX sebesar 100 (ukuran maksimum stack)

char stack[MAX]; // Deklarasi array char 'stack' berukuran MAX untuk menampung karakter
int top = -1; // Inisialisasi indeks top dengan -1 (menandakan stack dalam kondisi awal kosong)

// TODO : Menambahkan karakter ke stack
void push(char value) { // Fungsi untuk memasukkan satu karakter (value) ke atas stack
    if(top == MAX - 1){ // Memeriksa apakah stack sudah mencapai batas kapasitas maksimum
        cout << "Stack Penuh !\n"; // Menampilkan pesan peringatan jika stack penuh
    } else { // Kondisi jika stack masih muat
        top++; // Menggeser penunjuk top naik satu langkah
        stack[top] = value; // Menyimpan karakter value ke dalam stack posisi top saat ini
        cout << value << " ditambahkan dalam stack\n"; // Menampilkan konfirmasi karakter yang dimasukkan
    } // Penutup blok pengecekan kondisi stack
} // Penutup fungsi push

// TODO : Mengambil karakter paling atas
char pop() { // Fungsi untuk mengeluarkan/membaca karakter paling atas dari stack
    if(top == -1){ // Memeriksa apakah stack dalam kondisi kosong
        cout << "Stack kosong !\n"; // Menampilkan pesan peringatan jika stack kosong
        return '\0'; // Mengembalikan karakter null jika kosong untuk menghindari warning
    } else { // Kondisi jika stack memiliki elemen
        char c = stack[top]; // Menyimpan karakter teratas ke variabel sementara 'c'
        top--; // Mengurangi indeks top (menghapus karakter secara logis)
        return c; // Mengembalikan karakter teratas agar dapat dicetak secara bersih di main()
    } // Penutup blok kondisi penghapusan
} // Penutup fungsi pop

int main() { // Fungsi utama tempat program C++ mulai dieksekusi

    string kata; // Deklarasi variabel string untuk menyimpan kata input dari pengguna

    cout << "Masukkan sebuah kata: "; // Menampilkan perintah input kata ke layar
    cin >> kata; // Menerima input kata dari pengguna

    // TODO : Memasukkan setiap karakter ke stack
    for (char c : kata) { // Perulangan range-based loop untuk mengambil setiap karakter 'c' dari string 'kata'
        push(c); // Memasukkan setiap karakter satu per satu ke dalam stack
    } // Penutup perulangan pengisian stack

    // TODO Mengeluarkan karakter dari stack
    cout << "Hasil kebalikan: "; // Menampilkan teks label sebelum mencetak kata yang dibalik
    while (top != -1) { // Perulangan berjalan sampai seluruh karakter di dalam stack habis (top kembali ke -1)
        cout << pop(); // Memanggil pop() untuk mengambil karakter teratas (LIFO) lalu mencetaknya
    } // Penutup perulangan pengeluaran stack
    
         if (stack == kata){
        cout << "\n KATA INI ADALAH PALINDRON " << endl;
        else {(stack != kata){
        cout << "\n KATA INI BUKAN POLINDRON " << endl;
         }
        

    }

    cout << endl; // Memindahkan baris setelah seluruh kata terbalik selesai ditampilkan

    return 0; // Mengembalikan nilai 0 menandakan program selesai dan berjalan dengan sukses
} // Penutup fungsi main