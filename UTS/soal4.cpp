#include <iostream> // Mengimpor pustaka iostream untuk operasi input-output (cin, cout, endl)
using namespace std; // Menggunakan namespace standar agar tidak perlu menulis std:: sebelum cin, cout, atau endl

struct Node { // Mendefinisikan tipe data struktur bernama Node untuk elemen pada pohon (tree)
    int data; // Variabel integer untuk menyimpan nilai/data pada node
    Node* kiri; // Pointer yang menunjuk ke anak cabang sebelah kiri (left child)
    Node* kanan; // Pointer yang menunjuk ke anak cabang sebelah kanan (right child)
}; // Penutup definisi struct Node

// Membuat node baru
Node* buatNode(int data) { // Fungsi untuk mengalokasikan dan menginisialisasi node pohon baru
    Node* baru = new Node; // Memesan memori untuk objek Node baru di heap

    baru->data = data; // Mengisi variabel data pada node baru dengan parameter 'data'
    baru->kiri = NULL; // Inisialisasi pointer anak kiri dengan NULL (belum memiliki anak kiri)
    baru->kanan = NULL; // Inisialisasi pointer anak kanan dengan NULL (belum memiliki anak kanan)

    return baru; // Mengembalikan alamat dari node baru yang telah dibuat
} // Penutup fungsi buatNode

// TODO : Memasukkan data ke Binary Search Tree
Node* insert(Node* akar, int data) { // Fungsi rekursif untuk menyisipkan nilai 'data' ke dalam BST
    // jika posisi kosong, maka akan buat node baru
    if(akar == NULL){ // Memeriksa apakah posisi/sub-tree saat ini dalam keadaan kosong
        return buatNode(data); // Membuat node baru dan mengembalikannya sebagai akar/sub-akar baru
    } // Penutup kondisi basis rekursi

    // jika data lebih kecil maka akan masuk ke kiri
    if(data < akar -> data){ // Memeriksa apakah nilai yang disisipkan lebih kecil dari nilai node saat ini
        akar->kiri = insert(akar->kiri, data); // Panggilan rekursif ke cabang kiri dan menyambungkan hasilnya
    } // Penutup kondisi penelusuran cabang kiri
    
    // jika data lebih besar, maka akan masuk ke kanan
    else if(data > akar -> data){ // Memeriksa apakah nilai yang disisipkan lebih besar dari nilai node saat ini
        akar->kanan = insert(akar->kanan, data); // Panggilan rekursif ke cabang kanan dan menyambungkan hasilnya
    } // Penutup kondisi penelusuran cabang kanan
    return akar; // Mengembalikan pointer akar yang telah diperbarui struktur cabangnya
} // Penutup fungsi insert


// TODO : In-order (Kiri - Root - Kanan)
void inOrder(Node* akar) { // Fungsi rekursif traversal pohon dengan urutan In-order
      if (akar != NULL){ // Memeriksa apakah node saat ini tidak kosong
        inOrder(akar->kiri); // Kunjungi seluruh sub-pohon kiri terlebih dahulu (Kiri)
        cout << akar->data << " "; // Cetak data node utama/akar (Root)
        inOrder(akar->kanan); // Kunjungi seluruh sub-pohon kanan (Kanan)
    } // Penutup kondisi pengecekan node
    
} // Penutup fungsi inOrder

int findMin(Node* akar) {
    if (akar == NULL) return -1;
    while (akar->kanan != NULL) {
        akar = akar->kiri;
    }
    return akar->data;
}
int findMax(Node* akar) {
    if (akar == NULL) return -1;
    while (akar->kanan != NULL) {
        akar = akar->kanan;
    }
    return akar->data;
}


int main() { // Fungsi utama tempat program C++ mulai dieksekusi

    Node* akar = NULL; // Inisialisasi pointer akar (root) bertipe Node dengan NULL (pohon awal kosong)
    int angka; // Deklarasi variabel integer 'angka' untuk menampung input pengguna

    cout << "Masukkan angka (0 untuk berhenti):\n"; // Menampilkan petunjuk cara penginputan data

    while (true) { // Perulangan tanpa batas untuk terus menerima input angka

        cout << "Input: "; // Menampilkan prompt input
        cin >> angka; // Membaca masukan angka dari pengguna

        // Berhenti jika pengguna memasukkan 0
        if (angka == 0) // Pengecekan kondisi kriteria penghentian input
        { // Pembuka blok penghentian
            break; // Keluar dari perulangan while
        } // Penutup blok kondisi penghentian
        
    
        // Angka dimasukkan ke tree
        akar = insert(akar, angka); // Memanggil fungsi insert untuk memasukkan angka ke dalam BST dan memperbarui 'akar'
    } // Penutup perulangan penginputan data

    cout << "\nHasil Traversal:\n"; // Menampilkan teks header untuk output traversal

    cout << "\nIn-order   : "; // Menampilkan label traversal In-order
    inOrder(akar); // Memanggil fungsi traversal In-order (menghasilkan urutan angka terurut naik)

     cout << "\nNilai terkecil : " << findMin(akar) << endl;
    cout << "\nNilai terbesar : " << findMax(akar) << endl; 

    cout << endl; // Memindahkan baris akhir
    return 0; // Mengembalikan nilai 0 menandakan program selesai dan berjalan dengan sukses
} // Penutup fungsi main