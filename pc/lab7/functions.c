//
// Created by Vlad Fridman on 03.12.2025.
//
#include <stdio.h>
#include "gos.h"
#include <stdlib.h>
#include <string.h>
gos* create_array(int n) {
    gos* gosudarstvo = malloc(n * sizeof(gos));
    if (gosudarstvo == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    return gosudarstvo;
}



void zapolnenie_massiva(gos* gosudarstvo,int n,int m) {
    for (int i = m; i < n; i++) {
        printf("Введите название страны #%d", i);
        fgets(gosudarstvo[i].name, sizeof(gosudarstvo[i].name), stdin);
        char* pos = strchr(gosudarstvo[i].name, '\n');
        if (pos) *pos = '\0';

        printf("Введите название столицы");
        fgets(gosudarstvo[i].capital, sizeof(gosudarstvo[i].capital), stdin);
        pos = strchr(gosudarstvo[i].capital, '\n');
        if (pos) *pos = '\0';

        printf("Введите площадь страны ");
        scanf("%lu", &gosudarstvo[i].area);
        while (getchar() != '\n');

        printf("Введите кол-во населения страны ");
        scanf("%lu", &gosudarstvo[i].population);
        while (getchar() != '\n');

        printf("Введите ВВП страны ");
        scanf("%lu", &gosudarstvo[i].vvp);
        while (getchar() != '\n');
    }

}



int poiskelementa(gos* gosudarstvo, int n, char name[20]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(gosudarstvo[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}



void sorting(gos* gosudarstvo, int n) {
    gos temp;

    for (int i = 0; i < n - 1; i++) {
        if (gosudarstvo[i].population < gosudarstvo[i + 1].population) {
            temp = gosudarstvo[i];
            gosudarstvo[i] = gosudarstvo[i + 1];
            gosudarstvo[i + 1] = temp;
        }
    }
}



void redacting(gos* gosudarstvo,int i) {
    int deistvie;
    printf("введите действие для редактирования :\n"
           "1. имя\n2. столица\n 3. площадь\n4. население\n5. ВВП\n--> ");
    scanf("%d",&deistvie);
    switch (deistvie) {
        case 1:
            while (getchar() != '\n');
            printf("Введите новое название страны #%d", i);
            fgets(gosudarstvo[i].name, sizeof(gosudarstvo[i].name), stdin);
            char* pos = strchr(gosudarstvo[i].name, '\n');
            if (pos) *pos = '\0';
            break;
        case 2:
            while (getchar() != '\n');
            printf("Введите новое название столицы");
            fgets(gosudarstvo[i].capital, sizeof(gosudarstvo[i].capital), stdin);
            pos = strchr(gosudarstvo[i].capital, '\n');
            if (pos) *pos = '\0';
            break;
        case 3:
            printf("Введите новое площадь страны ");
            scanf("%lu", &gosudarstvo[i].area);
            while (getchar() != '\n');
            break;
        case 4:
            printf("Введите новое кол-во населения страны ");
            scanf("%lu", &gosudarstvo[i].population);
            while (getchar() != '\n');
            break;
        case 5:
            printf("Введите новое ВВП страны ");
            scanf("%lu", &gosudarstvo[i].vvp);
            while (getchar() != '\n');
            break;
            default: break;
    }
}


int add_element(gos** gosudarstvo, int *size, gos new_element) {
    gos* tmp = realloc(*gosudarstvo, (*size + 1) * sizeof(gos));
    if (tmp == NULL) {
        return -1;
    }
    *gosudarstvo = tmp;
    (*gosudarstvo)[*size] = new_element;
    zapolnenie_massiva(*gosudarstvo,(*size)+1,(*size));
    return (*size)+1;
}


int delete_element(gos** gosudarstvo, int *size, int id) {
    if (id <-1 || id > (*size)) {
        return -1;
    }
    for (int i = id; i < *size - 1; i++) {
        (*gosudarstvo)[i] = (*gosudarstvo)[i + 1];
    }
    gos* tmp = realloc(*gosudarstvo, (*size - 1) * sizeof(gos));
    if (tmp == NULL) {
        return -1;
    }
    *gosudarstvo = tmp;
    (*size)--;

    return (*size);
}



int add_elementik(gos** gosudarstvo, int *size, int id, gos new_element) {
    if (id <-1 || id > (*size)) {
        return -1;
    }
    gos* tmp = realloc(*gosudarstvo, (*size + 1) * sizeof(gos));
    if (tmp == NULL) {
        return -1;
    }
    *gosudarstvo = tmp;
    for (int i = *size; i > id; i--) {
        (*gosudarstvo)[i] = (*gosudarstvo)[i - 1];
    }
    zapolnenie_massiva(*gosudarstvo, id+1, id);
    (*size)++;

    return (*size);
}


void zapis_w_fail(gos* gosudarstvo, int size) {
    FILE* f = fopen("data.bin", "wb");
    if (!f) return;
    fwrite(gosudarstvo, sizeof(gos), size, f);
    fclose(f);
}


gos* chtenie_iz_faila() {
    FILE* f = fopen("data.bin", "rb");
    if (!f) {
        printf("Не удалось открыть файл\n");
        return NULL;
    }

    fseek(f, 0, SEEK_END);
    int long filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    int size = filesize / sizeof(gos);

    if (size <= 0) {
        fclose(f);
        return NULL;
    }

    gos* arr = malloc((size) * sizeof(gos));
    if (!arr) {
        fclose(f);
        return NULL;
    }

    fread(arr, sizeof(gos), size, f);
    fclose(f);

    return arr;

}

void vivod_v_console(gos* gosudarstvo,int n) {
    for (int i = 0; i < n; i++) {
        printf("%s\n", gosudarstvo[i].name);
        printf("%s\n", gosudarstvo[i].capital);
        printf("%lu\n", gosudarstvo[i].area);
        printf("%lu\n", gosudarstvo[i].population);
        printf("%lu\n", gosudarstvo[i].vvp);
        printf("\n");
    }
}