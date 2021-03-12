#include "Entetes.h"
 
int main()
{
    /* initialisation du MT */
    init_genrand(21);
    
    int choix,
        temps;
  
    printf("1: Pour une version textuelle du glider \n");
    printf("2: Pour une version graphique du glider \n");
    printf("3: I'm Feeling lucky ! \n");

    scanf("%d", &choix);
    
    printf("Combien d'actualisation effectuer ? \n");
    scanf("%d", &temps);
    
    switch (choix)
    {
        case 1:
            _CA_Texte(temps);
        break;
        case 2:
            _CA_Graph(temps);
        break;
        case 3:
            _CA_Graph_WithLuck(temps);
        break;
        default:
            printf("Choix invalide");
        break;
    }


    
    return 0;
}
