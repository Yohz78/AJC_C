#include <stdio.h>
#include <stdlib.h>


void chiffreuse()
{
    /* Ouverture du fichier*/
    FILE* fp1 = NULL;
    char buffer[1000000];
    int data;

    fp1 = fopen("source.txt", "r");
    if (fp1 == NULL)
    {
        printf("\nImpossible d'ouvrir le fichier.");
        exit(-1);
    }

    /* Lecture du fichier source et ecriture dans le fichier destination*/
    FILE* fp2 = NULL;
    fp2 = fopen("dest.crt", "w+t");
    if (fp2 == NULL)
    {
        printf("\nImpossible de créer dest.crt");
        exit(-1);
    }

    fseek(fp1, 0, SEEK_SET);
    while(!feof(fp1)) //TANT QUE NON FIN DE FICHIER
    {
        fread(buffer, 1, 1000000, fp1);
        printf("%s\n", buffer);
        if (feof(fp1))
        {
            printf("\nFin Fichier !!!");
        }
    }
    int ret = fclose(fp1);
    if (ret != 0)
    {
        printf("\nErreur Close !!");
    }

}

/*
void ecrire(struct s_point* pDebut)
{
    FILE* fp = NULL;

    fp = fopen("courbe.txt", "w+t");
    if (fp == NULL)
    {
        printf("\nErreur Open !!");
        return EXIT_FAILURE;
    }

    struct s_point *pt = NULL;

    pt = pDebut;
    for (pt=pDebut; pt< pDebut + NP; pt++)
    {
        fwrite(pt, sizeof(struct s_point), 1, fp);
    }

    int ret = fclose(fp);
    if (ret != 0)
    {
        printf("\nErreur Close !!");
        return EXIT_FAILURE;
    }

}
*/

int main()
{
    chiffreuse();
}
