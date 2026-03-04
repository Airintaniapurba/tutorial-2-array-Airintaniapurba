#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <limits.h>  // Untuk INT_MAX dan INT_MIN
#include <float.h>   // Untuk FLT_MAX dan -FLT_MAX

// Fungsi utama program
int main() {
    int n;          // Variabel untuk menyimpan jumlah bilangan yang akan dimasukkan
    int num;        // Variabel sementara untuk menyimpan setiap bilangan yang diinput
    int min_val;    // Variabel untuk menyimpan nilai terkecil
    int max_val;    // Variabel untuk menyimpan nilai terbesar
    int prev_num;   // Variabel untuk menyimpan bilangan sebelumnya untuk perhitungan rata-rata berturut-turut
    float max_consecutive_avg; // Variabel untuk menyimpan rata-rata tertinggi dari dua bilangan berturut-turut
    float min_consecutive_avg; // Variabel untuk menyimpan rata-rata terendah dari dua bilangan berturut-turut

    // Inisialisasi min_val dengan nilai integer maksimum yang mungkin.
    min_val = INT_MAX;
    // Inisialisasi max_val dengan nilai integer minimum yang mungkin.
    max_val = INT_MIN;

    // Inisialisasi max_consecutive_avg dengan nilai float negatif terbesar,
    // agar rata-rata pertama yang dihitung pasti akan lebih besar.
    max_consecutive_avg = -FLT_MAX;

    // Inisialisasi min_consecutive_avg dengan nilai float positif terbesar,
    // agar rata-rata pertama yang dihitung pasti akan lebih kecil.
    min_consecutive_avg = FLT_MAX;

    // Membaca input pertama: jumlah bilangan (n)
    printf("Masukkan jumlah bilangan (n): "); // Pesan panduan untuk pengguna
    if (scanf("%d", &n) != 1 || n <= 0) { // Validasi dasar: memastikan input adalah angka dan positif
        printf("Input jumlah bilangan tidak valid. Harap masukkan bilangan bulat positif.\n");
        return 1; // Keluar dengan kode error
    }

    if (n == 0) {
        printf("Hasil:\n"); // Sesuai format output, bahkan jika tidak ada data
        printf("Tidak ada bilangan untuk diproses.\n");
        return 0;
    }

    // Membaca bilangan pertama secara terpisah untuk inisialisasi awal min_val, max_val, dan prev_num
    printf("Masukkan %d bilangan, setiap bilangan pada baris baru:\n", n);
    if (scanf("%d", &num) != 1) { // Validasi dasar: memastikan input adalah angka
        printf("Input bilangan pertama tidak valid. Harap masukkan bilangan bulat.\n");
        return 1; // Keluar dengan kode error
    }
    min_val = num;
    max_val = num;
    prev_num = num; // Bilangan pertama menjadi bilangan sebelumnya untuk iterasi berikutnya

    // Loop mulai dari bilangan kedua (i=1) hingga bilangan terakhir
    for (int i = 1; i < n; i++) {
        // Membaca setiap bilangan.
        if (scanf("%d", &num) != 1) { // Validasi dasar: memastikan input adalah angka
            printf("Input bilangan ke-%d tidak valid. Harap masukkan bilangan bulat.\n", i + 1);
            return 1; // Keluar dengan kode error
        }

        // Membandingkan dengan nilai terkecil yang sudah ditemukan
        if (num < min_val) {
            min_val = num;
        }

        // Membandingkan dengan nilai terbesar yang sudah ditemukan
        if (num > max_val) {
            max_val = num;
        }

        // Hitung rata-rata pasangan berturut-turut (prev_num dan num)
        // Casting (float) penting agar hasil pembagian menjadi desimal
        float current_avg = (float)(prev_num + num) / 2.0f;

        // Bandingkan dengan rata-rata tertinggi yang sudah ditemukan
        if (current_avg > max_consecutive_avg) {
            max_consecutive_avg = current_avg;
        }

        // Bandingkan dengan rata-rata terendah yang sudah ditemukan
        if (current_avg < min_consecutive_avg) {
            min_consecutive_avg = current_avg;
        }

        // Update prev_num untuk iterasi berikutnya
        prev_num = num;
    }

    // Menampilkan hasil nilai terkecil, terbesar, rata-rata terendah, dan rata-rata tertinggi
    printf("Hasil:\n");
    printf("%d\n", min_val);         // Menampilkan nilai terkecil
    printf("%d\n", max_val);         // Menampilkan nilai terbesar
    
    // Menampilkan rata-rata hanya jika ada minimal dua bilangan (untuk membentuk pasangan)
    if (n >= 2) {
        printf("%.2f\n", min_consecutive_avg); // Menampilkan rata-rata terendah dengan 2 digit presisi
        printf("%.2f\n", max_consecutive_avg); // Baris ini DIKEMBALIKAN untuk menampilkan rata-rata tertinggi
    } else {
        printf("N/A\n"); // Atau pesan lain jika tidak ada pasangan untuk rata-rata
    }

    return 0; // Menandakan program berakhir dengan sukses
}