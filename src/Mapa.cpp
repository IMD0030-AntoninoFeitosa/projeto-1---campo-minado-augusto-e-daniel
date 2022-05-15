#include "Mapa.hpp"

bool Mapa::getPerdeu(){
    return perdeu;
}

void Mapa::setPerdeu(bool ent){
    perdeu = perdeu;
}

int Mapa::getBombas(){
    return qtdBombas;
}

void Mapa::addCelula(std::vector<Celula> linha){
    celulas.push_back(linha);
}

bool Mapa::revelarCelula(int x, int y){ 
    if (celulas[y][x].getRevelado() == false && celulas[y][x].getMarcada() == false){
        celulas[y][x].revelar();
        qntRevelados++;
    }
    std::vector<std::pair<int, int>> proximos;

    if (celulas[y][x].getEstado() == NADA && celulas[y][x].getMarcada() == false){

        if (validar(y-1, x-1) == true){
            if (((celulas[y-1][x-1].getEstado() == NADA) || (celulas[y-1][x-1].getEstado() == NUMERO)) && celulas[y-1][x-1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y-1, x) == true){
            if (((celulas[y-1][x].getEstado() == NADA) || (celulas[y-1][x].getEstado() == NUMERO)) && celulas[y-1][x].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y-1, x+1) == true){
            if (((celulas[y-1][x+1].getEstado() == NADA) || (celulas[y-1][x+1].getEstado() == NUMERO)) && celulas[y-1][x+1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y, x-1) == true){
            if (((celulas[y][x-1].getEstado() == NADA) || (celulas[y][x-1].getEstado() == NUMERO)) && celulas[y][x-1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y;
                proximos.push_back(proximo);
            }
        }    
        if (validar(y, x+1) == true){
            if (((celulas[y][x+1].getEstado() == NADA) || (celulas[y][x+1].getEstado() == NUMERO)) && celulas[y][x+1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y;
                proximos.push_back(proximo);
            }
        }
        if (validar(y+1, x-1) == true){
            if (((celulas[y+1][x-1].getEstado() == NADA) || (celulas[y+1][x-1].getEstado() == NUMERO)) && celulas[y+1][x-1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y+1, x) == true){
            if (((celulas[y+1][x].getEstado() == NADA) || (celulas[y+1][x].getEstado() == NUMERO)) && celulas[y+1][x].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y+1, x+1) == true){
            if (((celulas[y+1][x+1].getEstado() == NADA) || (celulas[y+1][x+1].getEstado() == NUMERO)) && celulas[y+1][x+1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        }    

        for (int i = 0; i < proximos.size(); i++){
            revelarCelula(proximos[i].first, proximos[i].second);
        }

        return true;
    } else if (celulas[y][x].getEstado() == BOMBA && celulas[y][x].getMarcada() == false){
        return false;
    } else if (celulas[y][x].getEstado() == NUMERO && celulas[y][x].getMarcada() == false && celulas[y][x].getRevelado() == false){
        if (validar(y-1, x-1) == true){
            if (((celulas[y-1][x-1].getEstado() == NADA)) && celulas[y-1][x-1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y-1, x) == true){
            if (((celulas[y-1][x].getEstado() == NADA)) && celulas[y-1][x].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y-1, x+1) == true){
            if (((celulas[y-1][x+1].getEstado() == NADA)) && celulas[y-1][x+1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y, x-1) == true){
            if (((celulas[y][x-1].getEstado() == NADA)) && celulas[y][x-1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y;
                proximos.push_back(proximo);
            }
        }    
        if (validar(y, x+1) == true){
            if (((celulas[y][x+1].getEstado() == NADA)) && celulas[y][x+1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y;
                proximos.push_back(proximo);
            }
        }
        if (validar(y+1, x-1) == true){
            if (((celulas[y+1][x-1].getEstado() == NADA)) && celulas[y+1][x-1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y+1, x) == true){
            if (((celulas[y+1][x].getEstado() == NADA)) && celulas[y+1][x].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        }
        if (validar(y+1, x+1) == true){
            if (((celulas[y+1][x+1].getEstado() == NADA)) && celulas[y+1][x+1].getRevelado() == false){
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        }    

        for (int i = 0; i < proximos.size(); i++){
            revelarCelula(proximos[i].first, proximos[i].second);
        }
    }
    return true;
}

void Mapa::revelaTeste(int j, int i){
    if (validar(j, i) == true){
        celulas[i][j].revelar();
    }
}

bool Mapa::validar(int y, int x){
    if ((x >= 0 && x < sizeX) && (y >= 0 && y <sizeY)){
        return true;
    } else {
        return false;
    }
}

void Mapa::criarMapa(std::string diff, int posx, int posy){
    unsigned seed = time(0);
    srand(seed);
    qtdBombas = 0;
    qntRevelados = 0;

    if (diff == "beginner"){
        sizeY = 10;
        sizeX = 10;
        maxBombas = 10;
    } else if (diff == "intermediary"){
        sizeY = 15;
        sizeX = 15;
        maxBombas = 40;
    } else if (diff == "advanced"){
        sizeY = 15;
        sizeX = 30;
        maxBombas = 100;
    }

      for (int i = 0; i < sizeY; i++){
        std::vector<Celula> linha;
        for (int j = 0 ; j < sizeX; j++){
            int val = rand()%11;
            bool protegida;
            if (i == posy && j == posx && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy-1 && posx-1 && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy-1 && posx && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy-1 && posx+1 && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy && posx-1 && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy && posx+1 && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy+1 && posx-1 && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy+1 && posx && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (i == posy+1 && posx+1 && diff == "intermediary"){
                val = 0;
                protegida = true;
            } else if (val == 1 && qtdBombas < maxBombas){
                qtdBombas++;
                protegida = false;
            } else if (val == 1 && qtdBombas >= maxBombas){
                val = 0;
                protegida = false;
            } else if (val != 0 && val != 1){
                val = 0;
                protegida = false;
            }

            Celula entrada(val, protegida);
            entrada.setBombasVizinhas(0);
            linha.push_back(entrada);
        }
        addCelula(linha);
    }

    while (qtdBombas < maxBombas){
        if (qtdBombas < maxBombas){
            for (int i = 0; i < sizeY; i++){
                for (int j = 0; j < sizeX; j++){
                    int val = rand()%11;
                    if (i == posy && j == posx){
                        int val2 = rand()%8;
                        celulas[i][j].setEstado(NADA);
                        std::cout << val2 << std::endl;
                        switch (val2){
                            case 0:
                            if (validar(i-1, j-1) == true){
                                celulas[i-1][j-1].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                            case 1:
                            if (validar(i-1, j) == true){
                                celulas[i-1][j].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                            case 2:
                            if (validar(i-1, j+1) == true){
                                celulas[i-1][j+1].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                            case 3:
                            if (validar(i, j-1) == true){
                                celulas[i][j-1].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                            case 4:
                            if (validar(i, j+1) == true){
                                celulas[i][j+1].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                            case 5:
                            if (validar(i+1, j-1) == true){
                                celulas[i+1][j-1].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                            case 6:
                            if (validar(i+1, j) == true){
                                celulas[i+1][j].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                            case 7:
                            if (validar(i+1, j+1) == true){
                                celulas[i+1][j+1].setEstado(BOMBA);
                                qtdBombas++;
                            } break;
                        }
                    }
                    else if (celulas[i][j].getEstado() == NADA && (val == 1 && qtdBombas < maxBombas) && celulas[i][j].isProtegida() == false){
                        celulas[i][j].setEstado(BOMBA);
                        qtdBombas++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < sizeY; i++){
        for (int j = 0; j < sizeX; j++){
            int bombasVizinhas = 0;
            if (validar(i-1, j-1) == true){
                if (celulas[i-1][j-1].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }
            if (validar(i-1, j) == true){
                if (celulas[i-1][j].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }
            if (validar(i-1, j+1) == true){
                if (celulas[i-1][j+1].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }
            if (validar(i, j-1) == true){
                if (celulas[i][j-1].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }
            if (validar(i, j+1) == true){
                if (celulas[i][j+1].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }
            if (validar(i+1, j-1) == true){
                if (celulas[i+1][j-1].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }
            if (validar(i+1, j) == true){
                if (celulas[i+1][j].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }
            if (validar(i+1, j+1) == true){
                if (celulas[i+1][j+1].getEstado() == BOMBA){
                    bombasVizinhas++;
                }
            }

            if (bombasVizinhas > 0 && celulas[i][j].getEstado() != BOMBA){
                celulas[i][j].setBombasVizinhas(bombasVizinhas);
                celulas[i][j].setEstado(NUMERO);
            }
        }
    }

}

std::string Mapa::mostrarMapa(){
    std::string retorno;
    system("clear");
    char coord1 = 'A';
    char coord2 = 'A';

    for (int i = -1; i < sizeX; i++){
        if (i == -1){
            retorno = retorno + "  ";
        } else {
            retorno = retorno + static_cast<char>(coord1+i) + " ";
        }
    }

    retorno = retorno + '\n';

    for (int i = 0 ; i < sizeY; i++){
        for (int j = -1; j < sizeX; j++){
            if (j == -1){
                retorno = retorno + static_cast<char>(coord2) + " ";
                coord2 = coord2 + 1;
            } else {
                    if (celulas[i][j].getRevelado() == false){
                        if (celulas[i][j].getMarcada() == true){
                            retorno = retorno + "!" + " ";
                        } else {
                            retorno = retorno + "-" + " ";
                        }
                } else {
                    switch(celulas[i][j].getEstado()){
                        case NADA:
                        retorno = retorno + " " + " "; break;
                        case BOMBA:
                        retorno = retorno + "B" + " "; break;
                        case NUMERO:
                        retorno = retorno + std::to_string(celulas[i][j].getBombasVizinhas()) + " "; break;
                    }
                }
            }
        }
        retorno = retorno + '\n';
    }

    return retorno;
}

std::string Mapa::teste(){
    std::string retorno;

    for (int i = 0 ; i < 10; i++){
        for (int j = 0; j < 10; j++){
            if (celulas[i][j].getEstado() == BOMBA){
                retorno = retorno + "B";
            }
        }
    }

    return retorno;
}

int Mapa::getQntRevelados(){
    return qntRevelados;
}

void Mapa::botarBandeira(int x, int y){
    if (celulas[y][x].getRevelado() == false){
        if (celulas[y][x].getMarcada() == false){
            celulas[y][x].setMarcada(true);
        } else {
            celulas[y][x].setMarcada(false);
        }
    }
}

void Mapa::revelarNumero(int x, int y){
    std::vector<std::pair<int, int>> proximos;
    
    if (celulas[y][x].getEstado() == NUMERO && celulas[y][x].getRevelado() == true){
        int qntBandeiras = 0;

        if (validar(y-1, x-1) == true){
            if (celulas[y-1][x-1].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        } if (validar(y-1, x) == true){
            if (celulas[y-1][x].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        } if (validar(y-1, x+1) == true){
            if (celulas[y-1][x+1].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y-1;
                proximos.push_back(proximo);
            }
        } if (validar(y, x-1) == true){
            if (celulas[y][x-1].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y;
                proximos.push_back(proximo);
            }
        } if (validar(y, x+1) == true){
            if (celulas[y][x+1].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y;
                proximos.push_back(proximo);
            }
        } if (validar(y+1, x-1) == true){
            if (celulas[y+1][x-1].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x-1;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        } if (validar(y+1, x) == true){
            if (celulas[y+1][x].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        } if (validar(y+1, x+1) == true){
            if (celulas[y+1][x+1].getMarcada() == true){
                qntBandeiras++;
            } else {
                std::pair<int, int> proximo;
                proximo.first = x+1;
                proximo.second = y+1;
                proximos.push_back(proximo);
            }
        }

        if (qntBandeiras == celulas[y][x].getBombasVizinhas()){
            for (int i = 0; i < proximos.size(); i++){
                revelarCelula(proximos[i].first, proximos[i].second);
            }
        }
    }
}