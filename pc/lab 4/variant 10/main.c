#include <stdio.h>
#include <stdlib.h>




int show_menu() {
    int choice;
    printf("-----меню(без скидок)----------------------------------\n"
        "1. Динамическое выделение памяти для двумерного массива\n"
        "2. Ввод элементов массива с клавиатуры\n"
        "3. Заполнение массива случайными числами\n"
        "4. Отсортировать нечетные столбцы массива\n"
        "   по убыванию с помощью метода «пузырька».\n"
        "5. Вывод элементов массива на экран\n"
        "6. Освобождение памяти, выделенной для массива \n"
        "7. Окончание работы программы\n" "--> ");
    scanf("%i",&choice);

    printf("-------------------------------------------------------\n");
    return choice;
}

int* create_array(int n ,int m,int *array) {
    array = (int*)malloc((n*m)*sizeof(int));
    if (array == NULL) {
        exit(1);
    }
    printf("массив создан\n");
    return array;
}


void vvod_s_klaviaturi(int n,int m,int *array) {
    printf("----ввод с клавиатуры-----\n");
    for(int i=0;i<n;i++) {
        printf("--------строка #%d---------\n",i);
        for(int j=0;j<m;j++) {
            printf("введите элемент #%d :" , j);
            scanf("%d",&array[i*m+j]);

        }
    }
}

void vvod_randomno(int n, int m,int *array) {
        printf("----ввод с rand()-----\n\n");
        for(int i=0;i<n*m;i++) {
            array[i] = rand()%100 - 50;

        }
        printf("-------успешно--------\n");
    }


void sorting(int n,int m,int *array) {
    int temp=0,f=1;
    printf("----cортировка-----\n\n");
    while(f) {
        f = 0;
        for(int i=0; i<n-1; i++) {
            for (int j=1; j<m; j+=2) {
                if (array[i*m+j] < array[(i+1)*m+j]) {
                    temp = array[i*m+j];
                    array[i*m+j] = array[(i+1)*m+j];
                    array[(i+1)*m+j] = temp;
                    f = 1;
                }
            }
        }
    }
    printf("-------успешно--------\n");
}


void vivod_massivsa(int n , int m,int *array) {
    printf("----вывод массива-----\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d\t",array[i*m+j]);
        }
        printf("\n");
    }
}

int* cleaning(int *array) {
    printf("----чистка-----\n");
    free(array);
    return array = NULL;
}

int main() {
    int choise = show_menu();
    int *array = NULL;
    int n = 4;
    int m = 5;
    while (choise != 7) {
        switch (choise) {
            case 1 : if (array == NULL) array = create_array(n,m,array);else printf("массив уже создан\n"); break;
            case 2 : if (array != NULL) vvod_s_klaviaturi(n,m,array);else printf("массив не создан\n"); break;
            case 3 : if (array != NULL) vvod_randomno(n,m,array);else printf("массив не создан\n"); break;
            case 4 : if (array != NULL) sorting(n,m,array);else printf("массив не создан\n"); break;
            case 5 : if (array != NULL) vivod_massivsa(n,m,array);else printf("массив не создан\n"); break;
            case 6 : if (array != NULL) array = cleaning(array);else printf("массив не создан\n"); break;
            default: break;
        }
        choise = show_menu();
    }

}