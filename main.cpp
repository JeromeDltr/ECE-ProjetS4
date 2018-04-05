#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{
    int bo=1;
                int a;

    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    do
    {
        grman::init();

        /// Le nom du répertoire où se trouvent les images à charger
        grman::set_pictures_path("pics");
        Graph g;

        /// Un exemple de graphe
        g.make_example();

        /// Vous gardez la main sur la "boucle de jeu"
        /// ( contrairement à des frameworks plus avancés )
        while ( !key[KEY_ESC] )
        {
            /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
            g.update();

            /// Mise à jour générale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();

            if((mouse_b&1) && (mouse_x>=0) && (mouse_x<=100) && (mouse_y>=0) && (mouse_y<=100) && (bo!=2))
            {
                bo = 2;
                std::cout<<"Quel sommet voulez-vous supprimer ?"<<std::endl;
                std::cin >>a;
            }

            if(bo==2)
                bo = g.delet(a);
        }

        grman::fermer_allegro();

        std::cout<<"Voulez-vous continuer ? 0 pour continuer et 1 pour arreter"<<std::endl;
        std::cin>>bo;

    }
    while(bo!=1);

    return 0;
}
END_OF_MAIN();
