#include <stdio.h> // Untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h> // Umumnya disertakan, meskipun mungkin tidak langsung digunakan untuk kasus ini

int main() {
    int n; // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int angka; // Variabel untuk menyimpan setiap bilangan yang dibaca
    int min_val; // Variabel untuk menyimpan nilai terkecil
    int max_val; // Variabel untuk menyimpan nilai terbesar

    // Langkah 1: Membaca bilangan bulat positif 'n' sebagai jumlah baris masukan berikutnya
    // printf("Masukkan jumlah bilangan (n): "); // Pesan opsional untuk pengguna
    scanf("%d", &n);

    // Pastikan n setidaknya 1 untuk memproses input
    if (n <= 0) {
        printf("Jumlah bilangan harus positif.\n");
        return 1; // Keluar dengan kode error
    }

    // Langkah 2: Membaca bilangan pertama untuk inisialisasi min_val dan max_val
    // printf("Masukkan bilangan ke-1: "); // Pesan opsional untuk pengguna
    scanf("%d", &angka);
    min_val = angka; // Inisialisasi nilai terkecil dengan bilangan pertama
    max_val = angka; // Inisialisasi nilai terbesar dengan bilangan pertama

    // Langkah 3: Melakukan perulangan untuk membaca sisa (n-1) bilangan
    // dan memperbarui min_val serta max_val
    for (int i = 1; i < n; i++) {
        // printf("Masukkan bilangan ke-%d: ", i + 1); // Pesan opsional untuk pengguna
        scanf("%d", &angka);

        if (angka < min_val) {
            min_val = angka; // Perbarui min_val jika ditemukan nilai yang lebih kecil
        }

        if (angka > max_val) {
            max_val = angka; // Perbarui max_val jika ditemukan nilai yang lebih besar
        }
    }

    // Langkah 4: Menampilkan hasil nilai terkecil dan terbesar
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    return 0; // Mengembalikan 0 menandakan program berakhir dengan sukses
}