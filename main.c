#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void chiffreuse()
{
    /* Ouverture du fichier*/
    FILE* fp1 = NULL;

    fp1 = fopen("source.txt", "r");
    if (fp1 == NULL)
    {
        printf("\nImpossible d'ouvrir le fichier.");
        exit(-1);
    }

    FILE* fpq = NULL;

    fpq = fopen("peroq.def","r");
    if (fpq == NULL)
    {
        printf("\nImpossible d'ouvrir le perroquet.");
        exit(-1);
    }


    /*Looking for source file lenght.*/

    fseek(fp1, 0, SEEK_END);    // Go to end of the file
    size_t length = ftell(fp1); // read the position which is the size
    fseek(fp1, 0, SEEK_SET); // return at the start of the file to set up for reading later on.
    char buffer[length];

    /*Looking for peroq file lenght.*/
    fseek(fpq, 0, SEEK_END);    // Go to end of the file
    size_t lengthpq = ftell(fpq); // read the position which is the size
    fseek(fpq, 0, SEEK_SET); // return at the start of the file to set up for reading later on.
    char pqbuffer[lengthpq];

    /* Set up fp2 to written and created as dest.crt*/
    FILE* fp2 = NULL;
    fp2 = fopen("dest.crt", "w+t");
    if (fp2 == NULL)
    {
        printf("\nImpossible de créer dest.crt");
        exit(-1);
    }

    /*Read file and save it into the buffer*/
    fread(buffer, 1, length, fp1);
    fread(pqbuffer, 1,  lengthpq, fpq);
    buffer[length]='\0';
    pqbuffer[lengthpq]='\0';

    /*Time to cipher it*/
    char cipherbuffer[length];

    for(int i=0; i<length; i++){
        cipherbuffer[i]=buffer[i]-pqbuffer[i%lengthpq];
    }

    /*write buffer into the file p2*/
    fwrite(cipherbuffer, 1, length, fp2);

    /* deciphering it */
    for(int i=0; i<length; i++){
        char test =cipherbuffer[i]+pqbuffer[i%lengthpq];
        printf("%c \n", test);
    }

    /*Close opened files after the algorithm has done its job.*/
    int ret1 = fclose(fp1);
    int ret2 = fclose(fp2);
    int ret3 = fclose(fpq);
    if (ret1 != 0)
    {
        printf("\nProbleme a la fermeture du fichier source");
    }
    if (ret2 != 0)
    {
        printf("\nProbleme a la fermeture du fichier destination");
    }
    if (ret3 != 0)
    {
        printf("\nProbleme a la fermeture du perroquet");
    }
}


int main()
{
    chiffreuse();
}
