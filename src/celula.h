#ifndef celula
#define celula

enum estados{
    NADA, BOMBA, NUMERO
};

class Celula{
    private:

    int estado;
    
    bool revelado;

    int bombasVizinhas;

    bool marcada;

    public:

    Celula(int ent1);

    int getEstado();

    void setEstado(int ent);

    bool getRevelado();

    void revelar();

    int mostrar();

    int getBombasVizinhas();

    void setBombasVizinhas(int ent);
    
    bool getMarcada();

    void setMarcada(bool ent);
};

#endif