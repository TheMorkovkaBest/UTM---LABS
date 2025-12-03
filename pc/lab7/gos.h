//
// Created by Vlad Fridman on 03.12.2025.
//

#ifndef LAB7_GOS_H
#define LAB7_GOS_H

typedef struct {
    char name[20];
    char capital[20];
    unsigned long int area;
    unsigned long int population;
    unsigned long int vvp;
}gos;

gos* create_array(int n);

void zapolnenie_massiva(gos* gosudarstvo,int n,int m);

int poiskelementa(gos* gosudarstvo, int n, char name[20]);

void sorting(gos* gosudarstvo, int n);

void redacting(gos* gosudarstvo,int i);

int add_element(gos** gosudarstvo, int *size, gos new_element);

int delete_element(gos** gosudarstvo, int *size, int id);

int add_elementik(gos** gosudarstvo, int *size, int id, gos new_element);

void zapis_w_fail(gos* gosudarstvo, int size);

gos* chtenie_iz_faila();

void vivod_v_console(gos* gosudarstvo,int n);

#endif