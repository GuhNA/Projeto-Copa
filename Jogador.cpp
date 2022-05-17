#include "Jogador.hpp"

Jogador::Jogador()
{
    this->numero = "";
    this->nome = "";
    this->maestria = rand() % 100+1;
    this->posicao = "";
}

//Setters

void Jogador::setNumero(string numero)
{
    this->numero = numero;
}

void Jogador::setNome(string nome)
{
    this->nome = nome;
}

void Jogador::setPosicao(string posicao)
{
    this->posicao = posicao;
}
void Jogador::setMaestria(int maestria)
{
    this->maestria = maestria;
}

//Getters

string Jogador::getNumero()
{
    return(this->numero);
}

string Jogador::getNome()
{
    return(this->nome);
}

string Jogador::getPosicao()
{
    return(this->posicao);
}

int Jogador::getMaestria()
{
    return(this->maestria);
}




