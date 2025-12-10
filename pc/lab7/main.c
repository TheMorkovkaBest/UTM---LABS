#include <stdio.h>
#include "gos.h"


int main(void) {
    int n = 2;
    char name[20];
    user_data data = create_array(n);
    zapolnenie_massiva(data,0,data.n);
    scanf("%s",name);
    poiskelementa(data,name);
    sorting(data);
    redacting(data,1);
    add_element(data,2);
    delete_element(data,0);
    add_elementik(data,3);
    zapis_w_fail(data);
    chtenie_iz_faila(data);
    vivod_v_console(data);
    return 0;
}