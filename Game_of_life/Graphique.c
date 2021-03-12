#include "Entetes.h"
 
/* --------------------------------------------------------------------*/
/* initialisation_sdl       Génére une surface "blitable"              */      
/*                                                                     */
/* En sortie: SDL_Surface * -> Surface                                 */
/* --------------------------------------------------------------------*/
SDL_Surface * initialisation_sdl()
{
    
    if(SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr,"Erreur SDL :%s\n", SDL_GetError()) ;
        exit(EXIT_FAILURE) ;
    }
    SDL_Surface * ecran = NULL ;

    if((ecran = SDL_SetVideoMode(40*TABLMAX,40*TABLMAX,32, SDL_HWSURFACE)) == NULL)
    {    
        fprintf(stderr,"Erreur VideoMode %s\n",SDL_GetError());
        exit(EXIT_FAILURE) ;
    }
    SDL_WM_SetCaption("Jeu de la vie de John Conway", NULL);
    return(ecran);
    
}

/* --------------------------------------------------------------------*/
/* _AffichageGrille    Apose les textures appropriées sur l'écran.     */      
/*                                                                     */
/* En entrée: int ** tab -> Pointeur sur la grile à afficher           */
/*            SDL_Surface * ecran -> Surface utilisé                   */
/* --------------------------------------------------------------------*/
void _AffichageGrille(int ** tab,SDL_Surface * ecran)
{
    SDL_Rect position;
    position.x=0 ;
    position.y=0 ;

    /*On charge toutes les textures */
    SDL_Surface* celluleV = SDL_LoadBMP("bmp/celluleV.bmp");
    SDL_Surface* celluleM = SDL_LoadBMP("bmp/celluleM.bmp");
    
    /* On vérifie que aucun probléme n'est apparu */
    if( !celluleV ||  !celluleM )
    {
        printf("Erreur de chargement de l'image : %s",SDL_GetError());
        exit(EXIT_FAILURE) ;
    }
    
    /*Selon notre plateaux actuel et celui d'origine, l'on génére chaque cases avec la bonne texture*/
    for(int i=0;i<TABLMAX;i++)
    {
            position.x=0;

        for(int j=0;j<TABLMAX;j++)
        {
            if(tab[i][j] == 0 ){
                SDL_BlitSurface(celluleM,NULL,ecran,&position) ;
            }
            else{
                SDL_BlitSurface(celluleV,NULL,ecran,&position) ;
            }

            position.x+=40;
        }
        position.y+=40;
    }


    SDL_FreeSurface(celluleV);
    SDL_FreeSurface(celluleM);

    SDL_Flip(ecran);

}


/* --------------------------------------------------------------------*/
/* _CA_Graph    Fait les appels principaux                             */      
/*                                                                     */
/* En entrée: int temps -> Nombre d'actualisations                     */
/* --------------------------------------------------------------------*/
void _CA_Graph(int temps)
{
    int ** tab = _Origine();
    
    tab[2][2] ++;
    tab[3][3] ++;
    tab[4][3] ++;
    tab[4][2] ++;
    tab[4][1] ++;    
    
    
    SDL_Surface * ecran = initialisation_sdl();


    for(int i = 0; i <temps; i ++ )
    {
        _Evolution(tab);
        _AffichageGrille(tab,ecran);  
        SDL_Delay(500);
        
    }
    
        
    SDL_Quit();
    
}

/* --------------------------------------------------------------------*/
/* _CA_Graph    Fait les appels principaux                             */      
/*                                                                     */
/* En entrée: int temps -> Nombre d'actualisations                     */
/* --------------------------------------------------------------------*/
void _CA_Graph_WithLuck(int temps)
{
    int ** tab = _Origine();

    for(int x = 0 ; x < TABLMAX ; x ++)
    {
        for(int y = 0 ; y < TABLMAX ; y ++)
        {
            tab[x][y] = (int)(2 * genrand_real2());
        }
    }
    
    SDL_Surface * ecran = initialisation_sdl();


    for(int i = 0; i <temps; i ++ )
    {
        _Evolution(tab);
        _AffichageGrille(tab,ecran);  
        SDL_Delay(100);
        
    }
    
        
    SDL_Quit();
    
}


