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
        cipher(nfp);
        printf("Le fichier a été  chiffré. Vous trouverez le texte chiffré dans dest.crt \nRetour au menu.\n");
        printf("*********************************************************************\n");
        menu();
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

        //Si la saisie est erronée, redémarrage du processus.
        printf("Vous avez choisi une valeur erronée. Redémarrage du processus. Choississez bien Y, N ou Q. \n");
        menu();
    }

    // Si l'user choisi de dechiffrer un fichier
    if(strcmp(cipheropt,"D")==0){

        //On demande a l'user de préciser son choix.
        printf("Vous avez choisi de dechiffrer un fichier. Merci de renseigner le nom du fichier a dechiffrer. \n");
        char nfp[100+1];
        scanf("%s",nfp);
        printf("%s \n", nfp);
        printf("Vous avez choisi: %s \nDesirez vous vraiment dechiffrer ce fichier ? Y/N. Q pour quitter. \n", nfp);
        char opt[1+1];
        scanf("%s",opt);

        //Si l'user confirme, appelle la dechiffreuse.
        if(strcmp(opt,"Y")==0){
        decipher(nfp);
        printf("Le fichier a été  dechiffré. Vous trouverez le texte dechiffré dans decipher.txt \nRetour au menu\n");
        printf("*********************************************************************\n");
        menu();
        }

        //Si l'user ne confirme pas, on redemarre le processus.
        if(strcmp(opt,"N")==0){
        printf("Vous avez choisi de ne pas dechiffrer le fichier. Retour au menu. \n");
        menu();
        }

        //Si l'user choisi de quitter, extinction du processus.
        if(strcmp(opt,"Q")==0){
        printf("Vous avez choisi de quitter l'application. Extinction du processus. \n");
        exit(0);
        }

        //Si la saisie est erronée, redémarrage du processus.
        printf("Vous avez choisi une valeur erronée. Retour au menu. Choississez bien Y ou N. \n");
        menu();

        decipher();
        exit(0);
    }

    // Si l'user choisi de quitter l'application
    if(strcmp(cipheropt,"Q")==0){
        printf("Vous avez choisi de quitter l'application. Extinction du processus. \n");
        exit(0);
    }
    // Si la saisie de l'user n'est pas valide
    printf("Vous avez choisi une valeur erronée. Retour au menu. Choississez bien Y ou N. \n");
    menu();
}

#endif // FUNCTIONS_H_INCLUDED
