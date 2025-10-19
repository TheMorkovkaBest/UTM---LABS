#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>




int main() {

    const int n = 10;
    int arr[n][n] ;

for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++) {
        arr[i][j]= rand() % 100;
        printf("%d\t", arr[i][j]);
    }
    printf("\n");
}
    printf("\n\n");





for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {

        bool localmin = true;
        //sverhu
            if (i != 0 && arr[i][j]>arr[i-1][j]) localmin = false;
        //snizu
            if (i != n-1 && arr[i][j]>arr[i+1][j]) localmin = false;
        //sprava
            if (j != n-1 && arr[i][j]>arr[i][j+1]) localmin = false;
        //sleva
            if (j != 0 && arr[i][j]>arr[i][j-1]) localmin = false;


        if (localmin == true) printf("\x1b[32m%d\x1b[0m\t",arr[i][j]);
        if (localmin == false) printf("\x1b[31m%d\x1b[0m\t",arr[i][j]);
        }
    printf("\n");
    }
printf("\n");



int sum = 0;
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (j>i) sum += arr[i][j];
    }
}
printf("%d\t", sum);

    return 0;
}