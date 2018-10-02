// TestLecture.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "ImageASCII.h"

using namespace std;




int main()
{

	ImageASCII *img = new ImageASCII();

	if(img->genererImage("test.txt")){

		std::cout << " largeur  : " << img->getWidth();
		std::cout << " hauteur : "  << img->getHeight() << std::endl;
		img->parcourirTableau(img->getImage());

	}
	else {
		std::cout << "image non trouvée" << std::endl;
	}

    return 0;
}




