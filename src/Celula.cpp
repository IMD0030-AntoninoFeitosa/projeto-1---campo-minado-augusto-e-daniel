#include  "Celula.hpp"

Celula::Celula(int ent1, bool ent2){
    estado = ent1;
    revelado = false;
    marcada = false;
    protegida = ent2;
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

bool Celula::isProtegida(){
    return protegida;
}

void Celula::setProtegida(bool ent){
    protegida = ent;
}