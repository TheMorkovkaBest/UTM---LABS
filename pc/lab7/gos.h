
#ifndef LAB7_GOS_H
#define LAB7_GOS_H

typedef struct {
    char name[20];
    char capital[20];
    unsigned long int area;
    unsigned long int population;
    unsigned long int vvp;
}gos;

typedef struct {
    gos* data;
    int n, capacity;
}user_data;

user_data create_array(int n);

void zapolnenie_massiva(user_data gosudarstvo,int start_index , int stop_index);

void poiskelementa(user_data gosudarstvo, char name[20]);

void sorting(user_data gosudarstvo);

void redacting(user_data gosudarstvo,int id);

void add_element(user_data gosudarstvo , int quantity);

void delete_element(user_data gosudarstvo, int id);

void add_elementik(user_data gosudarstvo, int position_id);

void zapis_w_fail(user_data gosudarstvo);

void chtenie_iz_faila(user_data gosudarstvo);

void vivod_v_console(user_data gosudarstvo);

#endif