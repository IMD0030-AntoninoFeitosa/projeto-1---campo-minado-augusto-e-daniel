#include  "Celula.hpp"

Celula::Celula(int ent1){
    estado = ent1;
    revelado = false;
    marcada = false;
};

int Celula::getEstado(){
    return estado;
};

void Celula::setEstado(int ent){
    estado = ent;
}

bool Celula::getRevelado(){
    return revelado;
}

void Celula::revelar(){
    revelado = true;
}

int Celula::mostrar(){
    if (revelado == false){
        return -1;
    } else {
        return estado;
    }
}

int Celula::getBombasVizinhas(){
    return bombasVizinhas;
}

void Celula::setBombasVizinhas(int ent){
    bombasVizinhas = ent;
}

bool Celula::getMarcada(){
    return marcada;
}

void Celula::setMarcada(bool ent){
    marcada = ent;
}