#ifndef MAPA_H_
#define MAPA_H_

#include <vector>
#include "Celula.hpp"
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

class Mapa{
    private:

    int qtdBombas;

    std::vector<std::vector<Celula>> celulas;

    int sizeY;
    int sizeX;

    int maxBombas;

    int qntRevelados;

    bool perdeu;

    public:

    int getBombas();

    void criarMapa(std::string diff, int posx, int posy);

    std::string mostrarMapa();

    void addCelula(std::vector<Celula> linha);

    bool revelarCelula(int i, int j);

    std::string teste();

    bool validar(int y, int x);

    void revelaTeste(int i, int j);
    
    Celula getCelula(int x, int y){
        return celulas[y][x];
    }

    int getQntRevelados();

    int getSizeY(){
        return sizeY;
    }

    int getSizeX(){
        return sizeX;
    }

    void botarBandeira(int x, int y);

    void revelarNumero(int x, int y);

    bool getPerdeu();

    void setPerdeu(bool ent);
};

#endif