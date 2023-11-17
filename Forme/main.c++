
#include "Carre.h"
#include "Cercle.h"
#include "Cube.h"

int main() {
    // Programme Principal
    Carre carre(5);
        carre.Afficher(); std::cout<<std::endl;
        std::cout << "Aire du carre : " << carre.Surface()<<" cm^2" << std::endl;
        std::cout << "Perimetre du carre : " << carre.Perimetre() << " cm^3" <<std::endl;

    Cercle cercle(1,2,5);
        cercle.Afficher();std::cout<<std::endl;
        std::cout << "Aire du Cercle : " << cercle.Surface() <<" cm^2" << std::endl;
        std::cout << "Perimetre du Cercle : " << cercle.Perimetre() <<"cm" << std::endl;

    Cube cube(3);
         cube.Afficher();std::cout<<std::endl;
        std::cout << "Aire du cube : " << cube.Surface() <<" cm^2" << std::endl;
        std::cout << "Volume du cube : " << cube.Volume() <<" cm^3" << std::endl;
    return 0;
}