#include "Entetes.h"

/* --------------------------------------------------------------------*/
/* _Origine       Déclare dinamiquement un tableau à double entrées    */      
/*                                                                     */
/* En sortie: int ** -> Pointeur sur le tableaux crée                  */
/* --------------------------------------------------------------------*/
int **  _Origine()
{
    int ** tab = calloc(TABLMAX,sizeof(int *));
    for(int i = 0 ; i < TABLMAX ; i ++)
    {
        tab[i] = calloc(TABLMAX,sizeof(int));
    }
    return tab;

}

/* --------------------------------------------------------------------*/
/* _Affichage       Parcour et affiche le contenu de notre grille      */      
/*                                                                     */
/* En entrée: int ** tab -> Pointeur sur la grile à afficher           */
/* --------------------------------------------------------------------*/
void _Affichage(int ** tab)
{
    for(int i = 0 ; i < TABLMAX ; i ++)
    {
        for(int y = 0 ; y < TABLMAX ; y ++)
        {
            printf("%d ",tab[i][y]);
        }
        printf("\n");
    }
    printf("\n");
}

/* --------------------------------------------------------------------*/
/* _VoisinsNbr       Détermine le nombre de voisines d'une cellule     */      
/*                                                                     */
/* En entrée: int ** tab -> Pointeur sur la grile à afficher           */
/*            int xo -> Coordonée de la cellule cible                  */
/*            int yo -> Coordonée de la cellule cible                  */
/*                                                                     */
/* En sortie: int    -> Nombre de voisines                             */
/* --------------------------------------------------------------------*/
int _VoisinsNbr(int ** tab,int xo,int yo)
{
    int result = 0,
        x = xo,
        y = yo;

    x = (xo - 1) ;
    y = (yo - 1) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
  
    x = (xo - 1) ;
    y = (yo    ) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
    
    x = (xo - 1) ;
    y = (yo + 1) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
    
    
    x = (xo    ) ;
    y = (yo - 1) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
    
 
    
    
    
    x = (xo    ) ;
    y = (yo + 1) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
    
     
    x = (xo + 1) ;
    y = (yo - 1) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
    
    
    x = (xo + 1) ;
    y = (yo    ) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
    
    x = (xo + 1) ;
    y = (yo + 1) ;
    if(tab[(TABLMAX + x) % TABLMAX][(TABLMAX + y) % TABLMAX] == 1) result ++;
    
    
    return(result);
}


/* --------------------------------------------------------------------*/
/* _Evolution       Détermine la grille en t + 1                       */      
/*                                                                     */
/* En entrée: int ** tab -> Pointeur sur la grile en t                 */
/* --------------------------------------------------------------------*/
void _Evolution(int ** tab)
{
    int ** tabsuite = _Origine();
    int nbrVoisin = 0;
    
    for(int x = 0 ; x < TABLMAX ; x ++)
    {
        for(int y = 0 ; y < TABLMAX ; y ++)
        {
            nbrVoisin = _VoisinsNbr(tab,x,y);
            if(tab[x][y] == 0 && nbrVoisin == 3  )
            {
                tabsuite[x][y] = 1;
            }
            if( ( (tab[x][y] == 1 ) && (nbrVoisin == 2) ) || (nbrVoisin == 3))
            {
                tabsuite[x][y] = 1;
            }
        }
    }
    for(int x = 0 ; x < TABLMAX ; x ++)
    {
        for(int y = 0 ; y < TABLMAX ; y ++)
        {
            tab[x][y] = tabsuite[x][y];
        }
    }
    free(tabsuite);
}


/* --------------------------------------------------------------------*/
/* _CA_Texte       Appels principaux et déclaration du Glider          */      
/*                                                                     */
/* En entrée: int temps -> Nombre d'application des régles             */
/* --------------------------------------------------------------------*/
void _CA_Texte(int temps)
{
    int ** tab = _Origine();
    
    tab[2][2] ++;
    tab[3][3] ++;
    tab[4][3] ++;
    tab[4][2] ++;
    tab[4][1] ++;
    
    _Affichage(tab);   
    
    for(int t = 0; t < temps; t ++ )
    {
        _Evolution(tab);
        _Affichage(tab);   
        
    }
    
}


