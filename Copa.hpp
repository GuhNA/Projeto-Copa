#ifndef COPA_HPP
#define COPA_HPP

#include "Time.hpp"

class Copa
{
    //Atributos
private:
    Time times[12];
    Time qfinal[8];
    Time semiFinal[4];
    Time finais[2];
    Time vencedor;
    bool eliminatorias;

    //Metodos
public:
    void setTimes(Time times, int pos);
    void setQfinal(Time qfinal, int pos);
    void setEliminatorias(bool eliminatorias);
    void setSemifinal(Time semiFinal[]);
    void setFinais(Time finais[]);

    Time getTimes(int pos);
    bool getEliminatorias();
    Time* getSemifinal();
    Time getSemifinalPos(int pos);
    Time* getFinais();
    Time getFinaisPos(int pos);
    Time getVencedor();
    Time getQfinal(int pos);
    void setVencedor();

    void compElim(Time arra[], int tam, int opcao);
    void competicao();
    void ordernarTimes(int op);
    void mostrarTimes(int opcao);

    //Construtor
    Copa();
};

#endif // COPA_HPP
