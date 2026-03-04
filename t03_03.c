#include <stdio.h>
#include <stdlib.h> // Untuk exit() jika diperlukan, atau atoi/atol jika input dari string. Tidak terlalu krusial di sini.
#include <string.h> // Tidak digunakan secara langsung dalam solusi ini, tetapi disertakan sesuai permintaan.
#include <float.h>  // Untuk DBL_MAX, DBL_MIN saat inisialisasi rata-rata

int main() {
    int n;
    
    // 1. Membaca jumlah baris masukan berikutnya (n)
    scanf("%d", &n);

    // Memastikan n positif
    if (n <= 0) {
        // Handle kasus n tidak valid, misalnya keluar dari program
        // Atau bisa juga mencetak pesan error
        return 1; // Keluar dengan kode error
    }

    int current_val;
    int prev_val;
    int min_val;
    int max_val;

    double min_avg = DBL_MAX; // Inisialisasi dengan nilai double terbesar
    double max_avg = DBL_MIN; // Inisialisasi dengan nilai double terkecil
    double current_avg;

    // Membaca angka pertama untuk inisialisasi min_val dan max_val
    scanf("%d", &current_val);
    min_val = current_val;
    max_val = current_val;
    prev_val = current_val; // Simpan sebagai prev_val untuk potensi rata-rata berikutnya

    // Jika hanya ada satu angka, tidak ada rata-rata berurutan
    if (n == 1) {
        printf("%d\n", min_val);
        printf("%d\n", max_val);
        // Untuk n=1, tidak ada rata-rata berurutan, jadi bisa mencetak 0.00 atau tidak sama sekali
        // Sesuai contoh output, asumsi minimum n=2 untuk rata-rata,
        // Tapi jika n=1 dan user meminta output 2.50 dan 46.50 maka akan ambigu.
        // Berdasarkan contoh, n=8 dan ada 4 output, jadi kita asumsikan untuk n=1, 
        // 2 baris terakhir tidak relevan dan bisa dilewatkan.
        // Namun, jika harus 4 baris, kita bisa cetak "0.00" atau semacamnya
        printf("0.00\n"); // Mengisi placeholder
        printf("0.00\n"); // Mengisi placeholder
        return 0;
    }

    // Loop untuk membaca n-1 angka berikutnya
    for (int i = 1; i < n; i++) {
        scanf("%d", &current_val);

        // Update nilai min dan max
        if (current_val < min_val) {
            min_val = current_val;
        }
        if (current_val > max_val) {
            max_val = current_val;
        }

        // Hitung rata-rata dari prev_val dan current_val
        // Cast ke double agar perhitungan tidak integer division
        current_avg = (double)(prev_val + current_val) / 2.0;

        // Update min_avg dan max_avg
        if (i == 1) { // Inisialisasi min_avg dan max_avg pada pasangan pertama
            min_avg = current_avg;
            max_avg = current_avg;
        } else {
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
            if (current_avg > max_avg) {
                max_avg = current_avg;
            }
        }
        
        // Perbarui prev_val untuk iterasi berikutnya
        prev_val = current_val;
    }

    // Output sesuai spesifikasi
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", min_avg); // Format 2 digit presisi
    printf("%.2f\n", max_avg); // Format 2 digit presisi

    return 0; // Program berhasil dieksekusi
}