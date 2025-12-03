#include <stdio.h>
#include "gos.h"
#include <stdlib.h>
#include <string.h>
// динамическиски выделить
int main(void) {
    int n = 1;//кол/во стран
    gos* gosudarstvo = create_array(n);



    zapolnenie_massiva(gosudarstvo, n,0);

    char name[20];

    fgets(name, sizeof(name), stdin);
    char* pos = strchr(name, '\n');
    if (pos) *pos = '\0';
    int idelement = poiskelementa(gosudarstvo, n, name);
    printf("%d\n",idelement);


    int variant_redacting ;
    scanf("%d",&variant_redacting);
    redacting(gosudarstvo,variant_redacting);
    sorting(gosudarstvo, n);
    n = add_element(&gosudarstvo , &n, gosudarstvo[0] );

    n = delete_element(&gosudarstvo, &n ,n);
    n = add_elementik(&gosudarstvo, &n, 1 , gosudarstvo[0]);

    vivod_v_console( gosudarstvo,n);
    zapis_w_fail(gosudarstvo,n);


    gosudarstvo = chtenie_iz_faila();
    vivod_v_console( gosudarstvo ,n);

    free(gosudarstvo);
    gosudarstvo = NULL;


    return 0;
}