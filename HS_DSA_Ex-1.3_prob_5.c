#include <stdio.h>
#define MAXSIZE 100

int f(int x) {
    return x % 5;  // example function with only 5 possible outputs
}

int main() {
    int arr[MAXSIZE], fval[MAXSIZE];
    int n, i, j;
    
    printf("Enter number of distinct inputs (n): ");
    scanf("%d", &n);
    
    if(n > MAXSIZE) {
        printf("Too many inputs\n");
        return 1;
    }

    printf("Enter %d distinct integer inputs:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        fval[i] = f(arr[i]);
    }

    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(fval[i] == fval[j]) {
                printf("Found: f(%d) = f(%d) = %d\n", arr[i], arr[j], fval[i]);
                return 0;
            }
        }
    }

    printf("No duplicates found in range values. Pigeonhole Principle not violated (this should not happen if n > number of possible outputs).\n");
    return 0;
}
