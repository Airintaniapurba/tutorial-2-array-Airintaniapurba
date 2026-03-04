#include <stdio.h>   // Untuk fungsi input/output seperti printf dan scanf
#include <stdlib.h>  // Untuk fungsi umum, seperti EXIT_SUCCESS/EXIT_FAILURE
#include <limits.h>  // Untuk INT_MAX dan INT_MIN (nilai maksimum/minimum integer)
#include <float.h>   // Untuk DBL_MAX atau FLT_MAX (nilai maksimum float/double)
#include <string.h>  // Disertakan sesuai permintaan, meskipun tidak digunakan secara langsung

int main() {
    int n; // Variabel untuk menyimpan jumlah angka yang akan diinput selanjutnya
    printf("Masukkan nilai n (antara -100 dan 100): ");
    if (scanf("%d", &n) != 1) {
        printf("Input tidak valid. Harap masukkan bilangan bulat untuk n.\n");
        return EXIT_FAILURE; // Menghentikan program jika input n tidak valid
    }

    // Validasi rentang n
    if (n < -100 || n > 100) {
        printf("Nilai n harus berada di antara -100 dan 100.\n");
        return EXIT_FAILURE; // Menghentikan program jika n di luar rentang
    }

    // Jika n adalah 0 atau 1, beberapa perhitungan tidak dapat dilakukan dengan benar
    // Misalnya, rata-rata berturut-turut memerlukan setidaknya 2 angka masukan setelah n
    if (n == 0) {
        printf("Tidak ada angka yang dimasukkan setelah n.\n");
        printf("Keluaran:\n");
        printf("Min: N/A\n");
        printf("Max: N/A\n");
        printf("Rata-rata terendah: N/A\n");
        return EXIT_SUCCESS;
    }
    if (n == 1) {
        int single_num;
        printf("Masukkan 1 angka: ");
        if (scanf("%d", &single_num) != 1) {
            printf("Input tidak valid.\n");
            return EXIT_FAILURE;
        }
        printf("Keluaran:\n");
        printf("%d\n", single_num); // Nilai terkecil
        printf("%d\n", single_num); // Nilai terbesar
        printf("N/A\n"); // Rata-rata terendah tidak bisa dihitung
        return EXIT_SUCCESS;
    }


    int min_val = INT_MAX; // Inisialisasi nilai minimum dengan nilai integer terbesar
    int max_val = INT_MIN; // Inisialisasi nilai maksimum dengan nilai integer terkecil
    float min_avg = FLT_MAX; // Inisialisasi rata-rata minimum dengan nilai float terbesar
    int prev_num; // Untuk menyimpan angka sebelumnya

    printf("Masukkan %d angka berikutnya:\n", n);

    // Loop untuk membaca n angka berikutnya
    for (int i = 0; i < n; i++) {
        int current_num;
        if (scanf("%d", &current_num) != 1) {
            printf("Input tidak valid. Harap masukkan bilangan bulat.\n");
            return EXIT_FAILURE; // Menghentikan program jika input bukan angka
        }

        // Memperbarui nilai minimum dan maksimum
        if (current_num < min_val) {
            min_val = current_num;
        }
        if (current_num > max_val) {
            max_val = current_num;
        }

        // Untuk iterasi kedua dan seterusnya, hitung rata-rata dua angka berturut-turut
        if (i > 0) {
            float current_avg = (float)(prev_num + current_num) / 2.0;
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
        }

        prev_num = current_num; // Simpan angka saat ini untuk iterasi berikutnya
    }

    // Menampilkan hasil sesuai format yang diminta
    printf("Keluaran:\n");
    printf("%d\n", min_val);
    printf("%d\n", max_val);
    printf("%.2f\n", min_avg); // Format ke dua digit desimal

    return EXIT_SUCCESS; // Mengakhiri program dengan sukses
}