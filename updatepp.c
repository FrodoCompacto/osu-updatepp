#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


int main(void){

    FILE *arq;
    arq = fopen("login.upp", "r+");
    long int playerid;


    if(arq == NULL){
        fclose(arq);
        arq = fopen("login.upp", "w+");

        if (arq == NULL){
            printf("Problem with file creation.\n");
            return(0);
        }

        char input[25] = "";
        int length, i;

        printf("Please insert your account id: ");
        scanf ("%s", input);
        length = strlen (input);
        for (i=0;i<length; i++)
        if (!isdigit(input[i])){
            printf ("Your account id must be a number.\n");
            fclose(arq);
            remove("login.upp");
            system("pause");
            exit(1);
        }

        fprintf(arq,input);
        system("cls");
        printf("The account with the id %s has been recorded, to use another account delete the file login.upp.\n", input);
        playerid = atol(input);
    }

    char comando[50];

    fscanf(arq, "%d", &playerid);
    sprintf(comando, "python ppython.py %d pp.txt",playerid);

    printf("##########################################\n");
    printf("##########################################\n");
    printf("################Running...################\n");
    printf("##########################################\n");
    printf("##########################################\n");
    printf("#While this window is open your PeppyPoints will be updated every 10 seconds.");
    printf("\n#github.com/FrodoCompacto");
    system(comando);


    fclose(arq);
}





