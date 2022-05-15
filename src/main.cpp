#include <iostream>
#include "Mapa.hpp"
#include "records.hpp"
#include <fstream>
#include <string.h>
#include <chrono>

int main(int argc, char* argv[]){
    std::vector<Record> Records;

    std::string diff;
    std::ifstream config("config.cfg");

    if (argc > 1){
        if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--difficulty") == 0){
            if (strcmp(argv[2], "b") == 0 || strcmp(argv[2], "beginner") == 0){
                std::ofstream arquivo("config.cfg");
                arquivo << "beginner";
                arquivo.close();
            } else if (strcmp(argv[2], "i") == 0 || strcmp(argv[2], "intermediary") == 0){
                std::ofstream arquivo("config.cfg");
                arquivo << "intermediary";
                arquivo.close();
            } else if (strcmp(argv[2], "a") == 0 || strcmp(argv[2], "advanced") == 0){
                std::ofstream arquivo("config.cfg");
                arquivo << "advanced";
                arquivo.close();
            }
        } else if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0){
            std::string retorno;
            std::ifstream arquivo("help.txt");
            while (getline(arquivo, retorno)){
                std::cout << retorno << std::endl;
            }
            return 0;
        } else if(strcmp(argv[1], "-r") || strcmp(argv[1], "--records")){

            std::getline(config, diff);
            readRecordsFile(Records, diff);

            if(diff == "b" || diff == "beginner"){
                std::cout << "LEADERBOARD - BEGINNER" << std::endl;
                printRecords(Records);
            }
            else if (diff == "i" || diff == "intermediary"){
                std::cout << "LEADERBOARD - INTERMEDIARY" << std::endl;
                printRecords(Records);
            }
            else if (diff == "a" ||diff == "advanced"){
                std::cout << "LEADERBOARD - ADVANCED" << std::endl;
                printRecords(Records);
            }
            else
                std::cout << "ERROR 404 - Recordes não foram encontrados!" << std::endl;
            
            return 0;
        }
    }
    system("clear");
    std::cout <<"              ! BEM-VINDO AO CAMPO MINADO !       \n";
    std::cout <<"            Para começar a jogar, digite ENTER    \n";
    std::cout <<"            Para entender como o jogo funciona    \n";
    std::cout <<"        use --help ou -h como argumento ao iniciar \n";
    std::cin.ignore();
    Mapa map;
    std::getline(config, diff);
    readRecordsFile(Records, diff);
    
    std::string acao = "";
    char posx, posy;
    int loop = 1;

    bool mapaPronto = false;

    Mapa mapaAux;
    mapaAux.criarMapa(diff, 0, 0);
    std::cout << mapaAux.mostrarMapa() << std::endl;

    

    while(acao != "r"){
        std::cout << "Escolha uma ação:\nr : Revela uma posição\n" << std::endl << ">>> ";
        std::cin >> acao;

        if (acao == "r"){
                std::cout << "Escolha a posição [Coluna] [Linha]" << std::endl << ">>> ";
                std::cin >> posx;
                std::cin >> posy;

                if (mapaPronto == false){
                    map.criarMapa(diff, static_cast<int>(posx-65), static_cast<int>(posy-65));
                    mapaPronto = true;
                }

                if (map.getCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)).getRevelado() == false){
                    if (map.revelarCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)) == false){
                        std::cout << std::endl << map.mostrarMapa() << std::endl;
                        std::cout << "BUM, VOCÊ PERDEU!" << std::endl;
                        loop = 0;
                    } 
                } else if (map.getCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)).getRevelado() == true && map.getCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)).getEstado() == NUMERO){
                    map.revelarNumero(static_cast<int>(posx-65), static_cast<int>(posy-65));
                    if (map.getPerdeu() == true){
                        std::cout << map.mostrarMapa() << std::endl;
                        std::cout << "BUM, VOCÊ PERDEU" << std::endl;
                        loop = 0;
                    }
                }
            }
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    while(loop == 1){

        for (int i = 0; i < map.getSizeY(); i++){ //colinha pra ver o mapa inteiro
                std::cout << "  ";
                for (int j = 0; j < map.getSizeX(); j++){
                    std::cout << map.getCelula(j, i).getEstado() << " ";
                }
                std::cout << std::endl;
            }
        
        std::cout << std::endl << map.mostrarMapa() << std::endl;

        if (acao == "t"){
            std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
            std::cout << "Tempo atual: " << std::chrono::duration_cast<std::chrono::seconds>(now - begin).count() << " segundos\n" << std::endl;
        }

        std::cout << "Escolha uma ação:\nr : Revela uma posição\nb : Marcar uma bomba\nt : Ver o tempo atual do jogo\n" << std::endl << ">>> ";
        std::cin >> acao;

        if (acao == "r"){
            std::cout << "Escolha a posição [Coluna] [Linha]" << std::endl << ">>> ";
            std::cin >> posx;
            std::cin >> posy;

            if (map.getCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)).getRevelado() == false){
                    if (map.revelarCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)) == false){
                    std::cout << std::endl << map.mostrarMapa() << std::endl;
                    std::cout << "BUM, VOCÊ PERDEU!" << std::endl;
                    loop = 0;
                } else if (map.getQntRevelados() == (map.getSizeX() * map.getSizeY() - map.getBombas())){

                    std::cout << std::endl << map.mostrarMapa() << std::endl;
                    std::cout << "Parabéns, voce venceu!" << std::endl;
                    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
                    double recordTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
                    std::cout << "Seu tempo foi de: " << recordTime/1000 << " segundos\n" << std::endl;
                    saveRecord(recordTime, Records);
                    sortRecords(Records);
                    writeRecordsFile(Records, diff);
                    loop = 0;
            }
            } else if (map.getCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)).getRevelado() == true && map.getCelula(static_cast<int>(posx-65), static_cast<int>(posy-65)).getEstado() == NUMERO){
                map.revelarNumero(static_cast<int>(posx-65), static_cast<int>(posy-65));
                if (map.getPerdeu() == true){
                    std::cout << map.mostrarMapa() << std::endl;
                    std::cout << "BUM, VOCÊ PERDEU" << std::endl;
                    loop = 0;
                }
            }
        } else if (acao == "b"){
            std::cout << "Escolha a posição [Coluna] [Linha]" << std::endl << ">>> ";
            std::cin >> posx;
            std::cin >> posy;

            if (map.validar(static_cast<int>(posy-65), static_cast<int>(posx-65)) == true){
                map.botarBandeira(static_cast<int>(posx-65), static_cast<int>(posy-65));
            }
        } else if (acao == "hackW"){ // APENAS PARA TESTES!
            std::cout << std::endl << map.mostrarMapa() << std::endl;
            std::cout << "Parabéns, voce venceu!" << std::endl;
            std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
            double recordTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
            std::cout << "Seu tempo foi de: " << recordTime/1000 << " segundos\n" << std::endl;
            saveRecord(recordTime, Records);
            sortRecords(Records);
            writeRecordsFile(Records, diff);
            loop = 0;
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