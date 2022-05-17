#ifndef TIME_HPP
#define TIME_HPP


#include "Jogador.hpp"

class Time
{
    //Atributos
private:
    string nome;
    Jogador jogador[11];
    Jogador reserva[6];
    Jogador capitao;
    int pontuacao;
    string posicoes[11] = {"goleiro","zagueiro 1", "zagueiro 2","lat.esquerdo",
                                       "lat.direito","meio campo 1", "meio campo 2", "meiocampo 3",
                                       "meia extremo 1", "meia extremo 2", "centroavante"};

public:
    //Setters
    void setNome(string nome);
    void setPosicoes(string posicao, int posicao2);
    void setPontuacao(int pontuacao);

    //Getters
    string getNome();
    string getPosicoes(int posicao);
    int getPontuacao();

    //Construtor
    Time();

    //Metodos
    void inserirJogador(Jogador jogador, int posicao);
    void inserirReserva(Jogador jogador, int posicao);
    void removerJogador(string numero);
    void definirCapitao(string numero);
    void mostrarTime();
    void definirPosicao(string posicao, string nome);
    void posicoesRandom();
    void substituicao(string titular, string reserva);

};

#endif
