#include "grman/grman.h"
#include <iostream>

#include "graph.h"

int main()
{
    int bo=1;
                int a, choice;

    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    do
    {
        grman::init();

        /// Le nom du r�pertoire o� se trouvent les images � charger
        grman::set_pictures_path("pics");
        Graph g;

        /// Un exemple de graphe
        choice = g.make_example();

        /// Vous gardez la main sur la "boucle de jeu"
        /// ( contrairement � des frameworks plus avanc�s )
        while ( !key[KEY_ESC] )
        {
            /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
            g.update();

            /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
            grman::mettre_a_jour();


                bo = g.button(choice);
                //g.save_file();                /               FAIRE POUR LES DIFFERENTS GRAPHES
        }

        grman::fermer_allegro();

        std::cout<<"Voulez-vous continuer ? 0 pour continuer et 1 pour arreter"<<std::endl;
        std::cin>>bo;

    }
    while(bo!=1);

    return 0;
}
END_OF_MAIN();
