#include <iostream>
#include "mapa.h"
#include <fstream>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc > 1){
        if (strcmp(argv[1], "-d") == 0){
            if (strcmp(argv[2], "b") == 0){
                std::ofstream arquivo("config.cfg");
                arquivo << "beginner";
                arquivo.close();
            } else if (strcmp(argv[2], "i") == 0){
                std::ofstream arquivo("config.cfg");
                arquivo << "intermediary";
                arquivo.close();
            } else if (strcmp(argv[2], "a") == 0){
                std::ofstream arquivo("config.cfg");
                arquivo << "advanced";
                arquivo.close();
            }
        } else if (strcmp(argv[1], "-h") == 0){
            std::string retorno;
            std::ifstream arquivo("help.txt");

            while (getline(arquivo, retorno)){
                std::cout << retorno << std::endl;
            }
        }
    }

    Mapa map;

    std::string diff;
    std::ifstream config("config.cfg");

    std::getline(config, diff);

    map.criarMapa(diff);

    std::string acao;
    int loop = 1;

    while (loop == 1){
        char posx, posy;

        for (int i = 0; i < map.getSizeY(); i++){ //colinha pra ver o mapa inteiro
                std::cout << "  ";
                for (int j = 0; j < map.getSizeX(); j++){
                    std::cout << map.getCelula(i, j) << " ";
                }
                std::cout << std::endl;
            }

        std::cout << std::endl << map.mostrarMapa() << std::endl;

        std::cout << "escolha uma acao" << std::endl << ">>> ";
        std::cin >> acao;

        if (acao == "m"){
            std::cout << "escolha uma posiçao" << std::endl << ">>> ";
            std::cin >> posx;
            std::cin >> posy;

            if (map.revelarCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)) == false){
                std::cout << std::endl << map.mostrarMapa() << std::endl;
                std::cout << "BUM" << std::endl;
                loop = 0;
            } else if (map.getQntRevelados() == (map.getSizeX() * map.getSizeY() - map.getBombas())){
                std::cout << std::endl << map.mostrarMapa() << std::endl;
                std::cout << "Parabéns, você venceu!" << std::endl;
                loop = 0;
            }
        }
    }
    

   /*while (loop = 1){
        char posx;
        char posy;
        std::cout << std::endl << map.mostrarMapa() << std::endl;

        std::cin >> posx;
        std::cin >> posy;

        map.revelarCelula(static_cast<int>(posx-65), static_cast<int>(posy-65));
   }*/
   

    return 0;
}