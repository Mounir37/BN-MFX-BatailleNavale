#include <stdio.h>
#include <windows.h>
#pragma execution_character_set("utf-8")
#define STLC 218 // ┌, Single Top Left Corner
#define STRC 191 // ┐, Single Top Right Corner
#define SBLC 192 // └, Single Bottom Left Corner
#define SBRC 217 // ┘, Single Bottom Right Corner
#define SVSB 179 // │, Single Vertical Simple Border
#define SVRB 180 // ┤, Single Vertical Right Border
#define SVLB 195 // ├, Single Vertical Left Border
#define SHSB 196 // ─, Single Horizontal Simple Border
#define SHBB 193 // ┴, Single Horizontal Bottom Border
#define SHTB 194 // ┬, Single Horizontal Top Border
#define SC   197 // ┼, Single Center
#define grille 10

void Grille_S_Mod();
    int tableau [grille][grille];

    for(i = 0; i < grille; ++i)
    {
         for (a = 0; a < grille; ++a)
         {
            printf("test");
         }
    }



int main()
{

    int choix = 0;
    SetConsoleOutputCP(65001);

    while (1)
    {
        printf("choisissez:\n"
               "1:  pour afficher l'aide.\n"
               "2:  pour commencer une partie contre une IA.\n"
               "3:  pour lancer le didacticiel:\n");
        scanf("%d", &choix);
        if (choix == 1)
        {
            printf("Une grille de jeu numérotée de 1 à 10 horizontalement et de A à J verticalement.\n"
                   "1 porte avion (5 cases)\n"
                   "1 croiseur (4 cases)\n"
                   "1 contre torpilleur (3 cases)\n"
                   "1 sous-marin (3 cases)\n"
                   "1 torpilleur (2 cases)\n");

        }
        else if (choix == 2)
        {
            printf("jdfvhioszgiw2222222222222222222222222222222222222222");
            break;
        }
        else if (choix == 3)
        {
            printf("oighuklsdfhgs33333333333333333333333333333");
            break;
        }
        else
        {
            printf("ce n'est pas un choix\n");
        }
    }
    return 0;
}