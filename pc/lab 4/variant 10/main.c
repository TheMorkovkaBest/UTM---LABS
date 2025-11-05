#include <stdio.h>
#include <stdlib.h>

int *array = NULL;
int n=3;
int m=3;

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

void create_array() {
    array = (int*)malloc((n*m)*sizeof(int));
    if (array == NULL) {
        exit(1);
    }

    printf("массив создан\n");
}


void vvod_s_klaviaturi() {
    printf("----ввод с клавиатуры-----\n");
    for(int i=0;i<n;i++) {
        printf("--------строка #%d---------\n",i);
        for(int j=0;j<m;j++) {
            printf("введите элемент #%d :" , j);
            scanf("%d",&array[i*m+j]);

        }
    }
}

void vvod_randomno() {
        printf("----ввод с rand()-----\n\n");
        for(int i=0;i<n*m;i++) {
            array[i] = rand()%100 - 50;

        }
        printf("-------успешно--------\n");
    }


void sorting() {
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


void vivod_massivsa() {
    printf("----вывод массива-----\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            printf("%d\t",array[i*m+j]);
        }
        printf("\n");
    }
}

void cleaning() {
    printf("----чистка-----\n");
    free(array);
    array = NULL;
}

int main() {
    int choise = show_menu();
    while (choise != 7) {
        switch (choise) {
            case 1 : create_array(); break;
            case 2 : if (array != NULL) vvod_s_klaviaturi();else printf("массив не создан\n"); break;
            case 3 : if (array != NULL) vvod_randomno();else printf("массив не создан\n"); break;
            case 4 : if (array != NULL) sorting();else printf("массив не создан\n"); break;
            case 5 : if (array != NULL) vivod_massivsa();else printf("массив не создан\n"); break;
            case 6 : if (array != NULL) cleaning();else printf("массив не создан\n"); break;
            default: break;
        }
        choise = show_menu();
    }

}