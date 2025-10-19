#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {

    int n;
    printf("введите размер масива: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) {
        printf("введите элемент ""%d"" :",(i+1));
        scanf("%d",&arr[i]);
    }

     //1 nomer
    int min = abs(arr[0]);
    for(int i=1;i<n;i++) {
        if (min>abs(arr[i])) {
            min=abs(arr[i]);
        }

    }
    printf("минимальный элемент""%i""\n",min);

    //2 nomer
    long int sum = 0;
    for (int i=0; i<n; i++) {
        if (abs(arr[i])==0) {
            for (int j=i; j<n; j++) {
                sum += abs(arr[j]);
            }
            break;
        }
    }
    printf("сумма после 0 : ""%ld""\n",sum);


    // 1 2 3 4 5 6 7 8 9
    int k= 1,m;

    //3 nomer
    for(int i=n-1;i>=0;i--) {
        if (i%2==0) {
            m = arr[k];
            arr[k] = arr[i];
            arr[i] = m;
        }
    }


    for (int i=0; i<n; i++) {
        printf("%i"" , ",arr[i]);
    }



    return 0;
}