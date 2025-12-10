//
// Created by Vlad Fridman on 03.12.2025.
//
#include <stdio.h>
#include "gos.h"
#include <stdlib.h>
#include <string.h>



user_data create_array(int n) {
    user_data m;
    m.data = malloc((n+1) * sizeof(gos));
    if (m.data == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    m.n = n;
    m.capacity = n+1;
    return m;
}



void zapolnenie_massiva(user_data gosudarstvo,int start_index , int stop_index) {//m - обьект с которого начинаем, чтобы можно было
    //заполнить не весь массив
    for (int i = start_index; i < stop_index; i++) {
        printf("Введите название страны #%d", i);
        fgets(gosudarstvo.data[i].name, sizeof(gosudarstvo.data[i].name), stdin);
        char* pos = strchr(gosudarstvo.data[i].name, '\n');
        if (pos) *pos = '\0';

        printf("Введите название столицы");
        fgets(gosudarstvo.data[i].capital, sizeof(gosudarstvo.data[i].capital), stdin);
        pos = strchr(gosudarstvo.data[i].capital, '\n');
        if (pos) *pos = '\0';

        printf("Введите площадь страны ");
        scanf("%lu", &gosudarstvo.data[i].area);
        while (getchar() != '\n');

        printf("Введите кол-во населения страны ");
        scanf("%lu", &gosudarstvo.data[i].population);
        while (getchar() != '\n');

        printf("Введите ВВП страны ");
        scanf("%lu", &gosudarstvo.data[i].vvp);
        while (getchar() != '\n');
    }

}



void poiskelementa(user_data gosudarstvo, char name[20]) {
    int flag = 0;
    for (int i = 0; i < gosudarstvo.n; i++) {
        if (strcmp(gosudarstvo.data[i].name, name) == 0) {
            printf("Id страны : %d\n", i);
            flag = 1;
        }
    }
    if (!flag) printf("Такой страны нет\n");
}



void sorting(user_data gosudarstvo) {
    gos temp;

    for (int i = 0; i <gosudarstvo.n - 1; i++) {
        if (gosudarstvo.data[i].population < gosudarstvo.data[i + 1].population) {
            temp = gosudarstvo.data[i];
            gosudarstvo.data[i] = gosudarstvo.data[i + 1];
            gosudarstvo.data[i + 1] = temp;
        }
    }
}



void redacting(user_data gosudarstvo,int id) {
    int deistvie;
    printf("введите действие для редактирования :\n"
           "1. имя\n2. столица\n 3. площадь\n4. население\n5. ВВП\n--> ");
    scanf("%d",&deistvie);
    switch (deistvie) {
        case 1:
            while (getchar() != '\n');
            printf("Введите новое название страны #%d", id);
            fgets(gosudarstvo.data[id].name, sizeof(gosudarstvo.data[id].name), stdin);
            char* pos = strchr(gosudarstvo.data[id].name, '\n');
            if (pos) *pos = '\0';
            break;
        case 2:
            while (getchar() != '\n');
            printf("Введите новое название столицы");
            fgets(gosudarstvo.data[id].capital, sizeof(gosudarstvo.data[id].capital), stdin);
            pos = strchr(gosudarstvo.data[id].capital, '\n');
            if (pos) *pos = '\0';
            break;
        case 3:
            printf("Введите новое площадь страны ");
            scanf("%lu", &gosudarstvo.data[id].area);
            while (getchar() != '\n');
            break;
        case 4:
            printf("Введите новое кол-во населения страны ");
            scanf("%lu", &gosudarstvo.data[id].population);
            while (getchar() != '\n');
            break;
        case 5:
            printf("Введите новое ВВП страны ");
            scanf("%lu", &gosudarstvo.data[id].vvp);
            while (getchar() != '\n');
            break;
            default: break;
    }
}


void add_element(user_data gosudarstvo , int quantity) {
    for (int i = 0; i < quantity; i++) {
        if (gosudarstvo.n + 1 < gosudarstvo.capacity) {
            zapolnenie_massiva(gosudarstvo,gosudarstvo.n ,gosudarstvo.n + 1);
        }
        else {
            gos* tmp = realloc(gosudarstvo.data, (gosudarstvo.capacity * 2) * sizeof(gosudarstvo));
            if (tmp == NULL) {
                printf("ошибка выделения памяти");
            }
            else {
                gosudarstvo.capacity = gosudarstvo.capacity*2;
                gosudarstvo.n = gosudarstvo.n + 1;
                gosudarstvo.data = tmp;
                zapolnenie_massiva(gosudarstvo,gosudarstvo.n ,gosudarstvo.n + 1);
            }
        }
    }
}


void delete_element(user_data gosudarstvo, int id) {
    if (id <-1 || id > (gosudarstvo.n)) {
        printf("Нет такого ID");
    }
    for (int i = id; i < gosudarstvo.n; i++) {
        gosudarstvo.data[i] = gosudarstvo.data[i + 1];
    }
    gosudarstvo.data[id].area = 0;
    gosudarstvo.data[id].population = 0;
    gosudarstvo.data[id].vvp = 0;
    memset(gosudarstvo.data[id].name, 0, sizeof(gosudarstvo.data[id].name));
    memset(gosudarstvo.data[id].capital, 0, sizeof(gosudarstvo.data[id].capital));

    gosudarstvo.n = gosudarstvo.n - 1;

    if (gosudarstvo.n+1 < gosudarstvo.capacity/2 ) {
        gos* tmp = realloc(gosudarstvo.data, (gosudarstvo.capacity / 2) * sizeof(gosudarstvo));
        if (tmp == NULL) {
            printf("ошибка выделения памяти");
        }
        else {
            gosudarstvo.capacity = gosudarstvo.capacity / 2;
            gosudarstvo.data = tmp;
        }

    }
}

void add_elementik(user_data gosudarstvo, int position_id) {
    if (position_id <-1 ||  position_id > (gosudarstvo.n)) {
        printf("Нет такого ID");
    }
    if (gosudarstvo.n < gosudarstvo.capacity) {
        for (int i = gosudarstvo.n; i > position_id; i--) {
            gosudarstvo.data[i] = gosudarstvo.data[i - 1];
        }
        zapolnenie_massiva(gosudarstvo,position_id ,position_id+1);
    }
    else {
        gos* tmp = realloc(gosudarstvo.data, (gosudarstvo.capacity * 2) * sizeof(gosudarstvo));
        if (tmp == NULL) {
            printf("ошибка выделения памяти");
        }
        else {
            gosudarstvo.capacity = gosudarstvo.capacity*2;
            gosudarstvo.n = gosudarstvo.n + 1;
            gosudarstvo.data = tmp;
            for (int i = gosudarstvo.n; i > position_id; i--) {
                gosudarstvo.data[i] = gosudarstvo.data[i - 1];
            }
            zapolnenie_massiva(gosudarstvo,position_id,position_id+1);
        }
    }
}

void zapis_w_fail(user_data gosudarstvo) {
    FILE* f = fopen("data.bin", "wb");
    if (!f) return;
    fwrite(gosudarstvo.data, sizeof(gos), gosudarstvo.n, f);
    fclose(f);
}


void chtenie_iz_faila(user_data gosudarstvo) {
    FILE* f = fopen("data.bin", "rb");
    if (!f) {
        printf("Не удалось открыть файл\n");
    }

    fseek(f, 0, SEEK_END);
    long filesize = ftell(f);
    fseek(f, 0, SEEK_SET);

    gosudarstvo.n = filesize / sizeof(gos);

    gosudarstvo.data = realloc(gosudarstvo.data, gosudarstvo.n * sizeof(gos));
    if (!gosudarstvo.data) {
        printf("Ошибка памяти\n");
        fclose(f);
    }

    fread(gosudarstvo.data, sizeof(gos), gosudarstvo.n, f);
    fclose(f);

    printf("Чтение удачно\n");
}

void vivod_v_console(user_data gosudarstvo) {
    for (int i = 0; i < gosudarstvo.n; i++) {
        printf("%s\n", gosudarstvo.data[i].name);
        printf("%s\n", gosudarstvo.data[i].capital);
        printf("%lu\n", gosudarstvo.data[i].area);
        printf("%lu\n", gosudarstvo.data[i].population);
        printf("%lu\n", gosudarstvo.data[i].vvp);
        printf("\n");
    }
}