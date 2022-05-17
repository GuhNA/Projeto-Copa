#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "Includes.hpp"

class Jogador
{
    //atributos
private:
    string numero;
    string nome;
    string posicao;
    int maestria;


    //Setters
public:
    void setNumero(string numero);
    void setNome(string nome);
    void setPosicao(string posicao);
    void setMaestria(int maestria);

    //Getters
    string getNumero();
    string getNome();
    string getPosicao();
    int getMaestria();

    //Construtor

    Jogador();

};
#endif // JOGADOR_HPP
