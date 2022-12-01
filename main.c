#include <stdio.h>
#include <stdlib.h>

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

    /*Looking for file lenght.*/

    fseek(fp1, 0, SEEK_END);    // Go to end of the file
    size_t length = ftell(fp1); // read the position which is the size
    fseek(fp1, 0, SEEK_SET); // return at the start of the file to set up for reading later on.
    char buffer[length];

    /* Set up fp2 to written and created as dest.crt*/
    FILE* fp2 = NULL;
    fp2 = fopen("dest.crt", "w+t");
    if (fp2 == NULL)
    {
        printf("\nImpossible de créer dest.crt");
        exit(-1);
    }

    /*Read and write while loop*/
    while(!feof(fp1)) //TANT QUE NON FIN DE FICHIER
    {
        fread(buffer, 1, length, fp1);
        printf("%s\n", buffer);
        fwrite(buffer, 1, length, fp2);
        if (feof(fp1))
        {
            printf("\nFin Fichier !!!");
        }
    }

    /*Close opened files after the algorithm has done its job.*/
    int ret1 = fclose(fp1);
    int ret2 = fclose(fp2);
    if (ret1 != 0)
    {
        printf("\nProbleme a la fermeture du fichier source");
    }
    if (ret2 != 0)
    {
        printf("\nProbleme a la fermeture du fichier destination");
    }

}


int main()
{
    chiffreuse();
}
