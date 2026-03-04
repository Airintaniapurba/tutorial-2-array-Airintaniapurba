#include <stdio.h>   
#include <limits.h>  


int main() {
    int n;          
    int num;        
    int min_val;    
    int max_val;    

    
    min_val = INT_MAX;

   
    max_val = INT_MIN;

    
    printf("Masukkan jumlah bilangan (n): "); 
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Input jumlah bilangan tidak valid. Harap masukkan bilangan bulat positif.\n");
        return 1; 
    }

    
    printf("Masukkan %d bilangan, setiap bilangan pada baris baru:\n", n);
    for (int i = 0; i < n; i++) {
        
        if (scanf("%d", &num) != 1) {
            printf("Input bilangan ke-%d tidak valid. Harap masukkan bilangan bulat.\n", i + 1);
            return 1; 
        }

        
        if (num < min_val) {
            min_val = num;
        }       
        if (num > max_val) {
            max_val = num;
        }
    }   
    printf("Hasil:\n"); 
    printf("%d\n", min_val); 
    printf("%d\n", max_val); 

    return 0; 
}