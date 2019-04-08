/*
 * Auteur: Mounir Fiaux
 * Projet: Bataille Navale
 * Titre: BN-MFX-BatailleNavale
 * Date: 05.04.19
 * Version: 1.5.1
 */
#include <stdio.h>
#include <windows.h>

#pragma execution_character_set("utf-8")
#define grille 10


int tableau1[grille][grille] =
        {{3, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {3, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {3, 0, 2, 2, 0, 0, 0, 5, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 5, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 5, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 5, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 5, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
         {0, 0, 4, 4, 4, 4, 0, 0, 0, 1,}};

int hits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,};
int compteur = 30;
int i;

int nextValue(FILE* fich)
{
    char c = fgetc(fich);
    while (c < '0' || c > '5')
    {
        c = fgetc(fich);
    }
    return c-48;
}

void charger_grille(){
    FILE* fich;     // Poignée de fichier

    fich = fopen("..\\Grille\\Grille1.txt", "r"); // On 'fixe' la poignée sur le fichier 'fichier.txt',
    for (int m = 0; m < grille ; ++m)
    {
        for (int n = 0; n < grille ; ++n)
        {
        tableau1[m][n] = nextValue(fich);
        }
    }
}


void coule()
{
    //Fonction Coulé
    for (i = 1; i <= 5; i++)
    {
        if (hits[i] == i)
        {
            printf(" vous avez coulé de %d\n",i);
            for (int s = 0; s < grille; s++) //for (x = 0; x < 9; x++)
            {
                for (int u = 0; u < grille; u++)
                {
                    if (tableau1[s][u] == 10 +
                                          i)// || tableau1[x][y] == 13 || tableau1[x][y] == 14)         // sa printf le nombre du bateau le coulé
                    {
                        tableau1[s][u] += 10;

                    }
                }
            }
        }
    }
}

void top_border(int largeur)
{ //ligne du dessus
    printf("     ");
    for (int j = 0; j < largeur; ++j)
    {
        printf("%c   ", j + 'A');
    }
    printf("\n");
    printf("   ┌");
    for (i = 0; i < largeur - 1; ++i)
    {
        printf("───┬");
    }
    printf("───┐\n");
}

void Total_Bar(int largeur, int m, int j)   // ligne total
{
    char display;
    for (m = 0; m < largeur - 1; ++m)
    {
        printf("%3d", m);
        for (j = 0; j < largeur; ++j) //première ligne
        {
            display = '~';
            if (tableau1[m][j] == -1)
            {
                display = '/';
            } else if (tableau1[m][j] > 10 && tableau1[m][j] < 20)
            {
                display = '*';
            } else if (tableau1[m][j] > 20 && tableau1[m][j] < 30)
            {
                display = 'X';
            }

            printf("│ %c ", display);
        }
        printf("│\n");
        printf("   ├");
        for (int k = 0; k < largeur - 1; ++k) //tout les sols sauf dernier
        {
            printf("───┼");
        }
        printf("───┤\n");
    }
    printf("%3d", largeur - 1);
    for (j = 0; j < largeur; ++j) //autre ligne espacement
    {
        display = '~';
        if (tableau1[m][j] == -1)
        {
            display = '/';
        } else if (tableau1[m][j] > 10 && tableau1[m][j] < 20)
        {
            display = '*';
        } else if (tableau1[m][j] > 20 && tableau1[m][j] < 30)
        {
            display = 'X';
        }

        printf("│ %c ", display);
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


    printf("entrez les coordonées (lettre en majuscule puis nombre), il vous reste %d coups a jouer\n", compteur);
    scanf("%s", &tir);
    compteur = compteur - 1;
    ligne = tir[0] - 65;
    col = tir[1] - 48;

    while (col < 0 || col > 9 || ligne < 0 || ligne > 9)
    {
        printf("ce n'est pas un choix, crétin!!!\n");
        printf("entrez les coordonées (lettre en majuscule puis nombre)\n");
        scanf("%s", &tir);
        compteur = compteur - 1;

        ligne = tir[0] - 65;
        col = tir[1] - 49;
    }
    //évaluer le résultat du tir
    int valcase = tableau1[col][ligne];
    if (valcase > 0 && valcase < 10)
    {
        printf("touché\n");

        hits[valcase]++;
        tableau1[col][ligne] += 10;
    } else if (valcase == 0)
    {
        printf("pas touché\n");

        tableau1[col][ligne] = -1;
    } else
    {
        printf("tir invalide\n");

    }
}

int gameover()
{
    if (compteur == 0) //le joueur à utilisé tout ses coups
    {
        return -1;
    }
    for (i = 1; i <= 5; i++) //vérifie si il reste des bateaux sur la grille
    {
        if (hits[i] != i)
        {
            return 0;  //oui: la partie continue
        }
    }
    return 1; //signifie que la partie est gagnée
}


int main()
{
    int choix = 0;
    SetConsoleOutputCP(65001);

    printf("\n"
           "\n"
           "\n"
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
            charger_grille();
            while (gameover() == 0)
            {
                top_border(grille);
                Total_Bar(grille, tableau1[10][10], tableau1[10][10]);
                Bottom_border(grille);
                tir();
                coule();
            }
            if (gameover() == 1)
            {
                printf(" __      __                                                                  \n"
                       " \\ \\    / /                                                                  \n"
                       "  \\ \\  / /__  _   _ ___    __ ___   _____ ____   __ _  __ _  __ _ _ __   ___ \n"
                       "   \\ \\/ / _ \\| | | / __|  / _` \\ \\ / / _ \\_  /  / _` |/ _` |/ _` | '_ \\ / _ \\\n"
                       "    \\  / (_) | |_| \\__ \\ | (_| |\\ V /  __// /  | (_| | (_| | (_| | | | |  __/\n"
                       "     \\/ \\___/ \\__,_|___/  \\__,_| \\_/ \\___/___|  \\__, |\\__,_|\\__, |_| |_|\\___|\n"
                       "                                                 __/ |       __/ |           \n"
                       "                                                |___/       |___/            \n\n");
            } else
            {
                printf(" __      __                                                        _         _ \n"
                       " \\ \\    / /                                                       | |       | |\n"
                       "  \\ \\  / /__  _   _ ___    __ ___   _____ ____  _ __   ___ _ __ __| |_   _  | |\n"
                       "   \\ \\/ / _ \\| | | / __|  / _` \\ \\ / / _ \\_  / | '_ \\ / _ \\ '__/ _` | | | | | |\n"
                       "    \\  / (_) | |_| \\__ \\ | (_| |\\ V /  __// /  | |_) |  __/ | | (_| | |_| | |_|\n"
                       "     \\/ \\___/ \\__,_|___/  \\__,_| \\_/ \\___/___| | .__/ \\___|_|  \\__,_|\\__,_| (_)\n"
                       "                                               | |                             \n"
                       "                                               |_|                             \n\n");
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

//#include <stdio.h>
//#include <windows.h>
//
//#define SIZE 100
//
//int nextValue(FILE* fich)
//{
//    char c = fgetc(fich);
//    while (c < '0' || c > '5')
//    {
//        c = fgetc(fich);
//    }
//    return c-48;
//}
//
//int main() {
//
//    SetConsoleOutputCP(65001); // Pour les accents
//
//    int tab[SIZE];  // données (modèle)
//    FILE* fich;     // Poignée de fichier
//
//    // ============ Lecture du fichier =============
//    fich = fopen("fichier1.txt", "r"); // On 'fixe' la poignée sur le fichier 'fichier.txt',
//
//    // en indiquant que l'on va lire ('r') cette fois
//    int i = 0; // compteur de caractères
//    for (int i=0; i<SIZE; i++)
//    {
//        tab[i] = nextValue(fich);         // Stocker le chiffre dans le modèle
//    }
//
//    // ============ Vérification =============
//    printf("Résultat (relecture du fichier): ");
//    for (int i=0; i < SIZE; i++)
//    {
//        printf("%d  ",tab[i]);
//    }
//    printf("\n");
//
//    return 0;
//}
