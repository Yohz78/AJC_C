#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

void menu(){

    // Interroge l'user sur son souhait de chiffrer, dechiffrer ou quitter.
    printf("Bienvenu dans cette application de chiffrement de texte \n\n");
    printf("Souhaitez vous chiffrer ou dechiffrer un fichier? C/D. Q pour quitter \n");
    char cipheropt[1+1];
    scanf("%s",cipheropt);

    // Si l'user choisi de chiffrer un fichier
    if(strcmp(cipheropt,"C")==0){

        //On demande a l'user de préciser son choix.
        printf("Vous avez choisi de chiffrer un fichier. Merci de renseigner le nom du fichier a chiffrer. \n");
        char nfp[100+1];
        scanf("%s",nfp);
        printf("%s \n", nfp);
        printf("Vous avez choisi: %s \nDesirez vous vraiment chiffrer ce fichier ? Y/N. Q pour quitter. \n", nfp);
        char opt[1+1];
        scanf("%s",opt);

        //Si l'user confirme, appelle la chiffreuse.
        if(strcmp(opt,"Y")==0){
        chiffreuse(nfp);
        printf("Le fichier a été  chiffré. Vous trouverez le texte chiffré dans dest.crt \n");
        exit(0);
        }

        //Si l'user ne confirme pas, on redemarre le processus.
        if(strcmp(opt,"N")==0){
        printf("Vous avez choisi de ne pas chiffrer le fichier. Redémarrage du processus. \n");
        menu();
        }

        //Si l'user choisi de quitter, extinction du processus.
        if(strcmp(opt,"Q")==0){
        printf("Vous avez choisi de quitter l'application. Extinction du processus. \n");
        exit(0);
    }
    }

    // Si l'user choisi de dechiffrer un fichier
    if(strcmp(cipheropt,"D")==0){
        printf("Vous avez choisi de dechiffrer un fichier \n");
        exit(0);
    }

    // Si l'user choisi de quitter l'application
    if(strcmp(cipheropt,"Q")==0){
        printf("Vous avez choisi de quitter l'application. Extinction du processus. \n");
        exit(0);
    }
    // Si la saisie de l'user n'est pas valide
    printf("Vous avez choisi une valeur erronée. Redémarrage du processus. Choississez bien Y ou N. \n");
    menu();
}

void chiffreuse(char *fp)
{
    /* Ouverture du fichier*/
    FILE* fp1 = NULL;

    fp1 = fopen(fp, "r");
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
    printf("\n %s \n", cipherbuffer);

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

#endif // FUNCTIONS_H_INCLUDED
