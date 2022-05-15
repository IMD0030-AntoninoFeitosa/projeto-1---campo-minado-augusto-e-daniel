#ifndef CELULA_H_
#define CELULA_H_

enum estados{
    NADA, BOMBA, NUMERO
};

class Celula{
    private:

    int estado;
    
    bool revelado;

    int bombasVizinhas;

    bool marcada;

    bool protegida;

    public:

    Celula(int ent1, bool protegida);

    int getEstado();

    void setEstado(int ent);

    bool getRevelado();

    void revelar();

    int mostrar();

    int getBombasVizinhas();

    void setBombasVizinhas(int ent);
    
    bool getMarcada();

    void setMarcada(bool ent);

    bool isProtegida();

    void setProtegida(bool ent);
};

#endif