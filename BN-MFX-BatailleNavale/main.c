/*
 * Auteur: Mounir Fiaux
 * Projet: Bataille Navale
 * Titre: BN-MFX-BatailleNavale
 * Date: 22.03.19
 * Version: 1.3.1
 */
#include <stdio.h>
#include <windows.h>

#pragma execution_character_set("utf-8")
#define grille 10


int tableau1[grille][grille] =
        {{3, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {3, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {3, 0, 2, 2, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 1,}};

void top_border(int largeur)
{ //ligne du dessus
    printf("     ");
    for (int j = 0; j < largeur; ++j)
    {
        printf("%c   ", j + 'A');
    }
    printf("\n");
    printf("   ┌");
    for (int i = 0; i < largeur - 1; ++i)
    {
        printf("───┬");
    }
    printf("───┐\n");
}

void Total_Bar(int largeur, int m, int j)
{
    for (m = 0; m < largeur - 1; ++m)
    {
        printf("%3d", m + 1);
        for (j = 0; j < largeur; ++j) //première ligne
        {
            printf("│ %c ", '0' + tableau1[m][j]);
        }
        printf("│\n");
        printf("   ├");
        for (int k = 0; k < largeur - 1; ++k) //tout les sols sauf dernier
        {
            printf("───┼");
        }
        printf("───┤\n");
    }
    printf("%3d", largeur);
    for (j = 0; j < largeur; ++j) //autre ligne espacement
    {

        printf("│ %c ", '0' + tableau1[m][j]);
    }
    printf("│\n");
}

void Bottom_border(int largeur) //ligne du bas
{
    printf("   └");
    for (int l = 0; l < largeur - 1; ++l)
    {
        printf("───┴");
    }
    printf("───┘\n\n");
}

void tir()
{
    char tir[10];
    int ligne;
    int col;

    printf("entrez les coordonées (lettre en majuscule puis nombre)\n");
    scanf("%s", &tir);
    ligne = tir[0] - 65;
    col = tir[1] - 49;

    while (col < 0 || col > 9 || ligne < 0 || ligne > 9)
    {
        printf("ce n'est pas un choix\n");
        printf("entrez les coordonées (lettre en majuscule puis nombre)\n");
        scanf("%s", &tir);

        ligne = tir[0] - 65;
        col = tir[1] - 49;
    }

    if (tableau1 [col][ligne] == 1)
    {
        printf("Coulé\n");
    } else if (tableau1 [col][ligne] == 2)
    {
        printf("touché\n");
        tableau1 [col][ligne] = 6;
    } else if (tableau1 [col][ligne] == 3)
    {
        printf("touché\n");
        tableau1 [col] [ligne]= 6;
    } else
    {
        printf("pas touché\n");
    }
}


int main()
{
    int choix = 0;
    SetConsoleOutputCP(65001);

    printf(""
           ""
           ""
           "\"                                                                                                                                  _.\\n\"\n"
           "\"                                                                                                                            _.--\\\"' |\\n\"\n"
           "\"                                                                                                                      _.--\\\"'       |\\n\"\n"
           "\"                                                                                                                _.--\\\"'      _..,.  |\\n\"\n"
           "\"                                                                                                          _.--\\\"'            .==; '.|\\n\"\n"
           "\"                                                                                                    _.--\\\"'                     :   |'.\\n\"\n"
           "\"                                                                                              _.--\\\"'                            ;  |  '.\\n\"\n"
           "\"                                                                                        _.--\\\"'                                  :  |    '.\\n\"\n"
           "\"                                                                                  _.--\\\"'                                         ; |      '.\\n\"\n"
           "\"                                                                            _.--\\\"'                         _.                    : |        '.\\n\"\n"
           "\"                                                                      _.--\\\"'                              _.--^\\\"  :                   q I     --mmm--\\n\"\n"
           "\"                                                                _.--\\\"'                                   ;      _,.;_                 |_I____._\\\\___/___._.__\\n\"\n"
           "\"                                                          _.--\\\"'                                         :_.--^\\\"   :_]                |______|     ==\\\" \\\" \\\"_|'\\n\"\n"
           "\"                                                  |__.--\\\"'                                                  ;         ;|                |;I H| |_______'(|)|\\n\"\n"
           "\"                                              .   | :                                                           :     _   :|                |:I_H|_|______[ '._|    _.---.______\\n\"\n"
           "\"                                              I   | ;             ,    \\\\                    \\\\              ;__ [_]___;                |||____________| '_|    \\\\|   ;\\\"\\\"         |\\n\"\n"
           "\"                       ______.---._    ______ I  /|:        \\\\     ;\\\\    \\\\                    \\\\      ,d.-^'|| '-.b.     ___       L| I|  |\\\"  |   |_[_|_X__[|___:_,.-^>_.---.______ /|\\n\"\n"
           "\";                          \\\"\\\":\\\"|'|/    _\\\\--/  I_/_|;         \\\\    :/\\\\ __nm__                _nm   _d______||______b.__EEEE3       | I|__| m |___|__H_____|_ m__|'^|\\\"  \\\\|  ;  /|\\n\"\n"
           "\";      ______.---._<^-.,_____;___|]__\\\\|____|_|I___|] .--_____nm____; |_dHH|_|.-           |dHH|_|,-======''==_===;===|====|______|_I|__|_W_|___|__H_____^__W__|__|____|___:___,.--._nnn__m__//  _o\\n\"\n"
           "\":\\\\         \\\"\\\":   |/ \\\"|  |   __ m ___ .d88b. H m m || |_|-|-|-|-|-|-|  H*''|  .mmmmmmmmm^^\\\" '|m[]H\\\"m\\\"\\\"\\\"\\\"\\\"\\\"|   |_| []  [_]   /*  *  * * * * *|_|'\\\"7 |      * ;\\n\"\n"
           "\":_\\\\__,.,_n_m_;___|]_I|_[|__[__]W_____'Y88P'_H_W_W_||_|_|_|_|_|_|_|_|__H&[]|_____^MMMM^______|W__H$ &$__I_____ -'________.-'                | | /  |                                    ^(8)- \\n\"\n"
           "\"|<    H  * * *  * *  * *  *  * *  * * * * * * * *  *  *  *  *  *   *   *  *  *  *                                                                                       *  *  *   *  *       :\\n\"\n"
           "\"|  _|_H_|_                                           ___________________________________________________________________________________                                                    ;\\n\"\n"
           "\"'------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------'\"\n"
           "\"\"\n"
           "\"\"\n"
           "\"\"\n"
           "\"\"\n"
           "\n");

    while (1)
    {
        printf(""
               ""
               ""
               "choisissez:\n"
               "1:  pour afficher l'aide.\n"
               "2:  pour commencer une partie contre une IA.\n"
               "3:  pour lancer le didacticiel:\n");
        scanf("%d", &choix);
        if (choix == 0)
        {
            return 0;
        } else if (choix == 1)
        {
            printf("Une grille de jeu numérotée de 1 à 10 horizontalement et de A à J verticalement.\n"
                   "1 porte avion (5 cases)\n"
                   "1 croiseur (4 cases)\n"
                   "1 contre torpilleur (3 cases)\n"
                   "1 sous-marin (3 cases)\n"
                   "1 torpilleur (2 cases)\n\n\n");
        } else if (choix == 2)
        {
            while (1)
            {
                top_border(grille);
                Total_Bar(grille, tableau1[10][10], tableau1[10][10]);
                Bottom_border(grille);
                tir();
            }

        } else if (choix == 3)
        {
            printf("oighuklsdfhgs33333333333333333333333333333");
        } else
        {
            printf("ce n'est pas un choix\n");
        }
    }
}
