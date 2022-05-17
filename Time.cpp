#include "Time.hpp"
#include "funcoesGerais.hpp"

Time::Time()
{
    this->nome = "";
    this->pontuacao = 0;
}

//Setters
void Time::setNome(string nome)
{
    this->nome = nome;
}

void Time::setPosicoes(string posicao, int posicao2)
{
    this->posicoes[posicao2] = posicao;
}

void Time::setPontuacao(int pontuacao)
{
    this->pontuacao = pontuacao;
}
 //Getters
 string Time::getNome()
{
     return(this->nome);
}

string Time::getPosicoes(int posicao)
{
    return(this->posicoes[posicao]);
}

int Time::getPontuacao()
{
    return(this->pontuacao);
}
//metodos
void Time::inserirJogador(Jogador jogador, int posicao)
{
    this->jogador[posicao] = jogador;
}

void Time::inserirReserva(Jogador reserva, int posicao)
{
    this->reserva[posicao] = reserva;
}

void Time::removerJogador(string numero)
{
    Jogador removedor;
    for(int i = 0; i < 11; i++)
    {
        if(this->jogador[i].getNumero() == numero)
        {
            cout << this->jogador[i].getNome() << " removido!!!" << endl << endl;
            this->jogador[i] = removedor;
        }
    }
}

void Time::definirCapitao(string numero)
{
    for(int i = 0; i < 11; i++)
    {
        if(this->jogador[i].getNumero() == numero)
        {
            cout << "Novo capitao do time: " << this->jogador[i].getNome() << endl << endl;
            this->capitao = this->jogador[i];
        }
    }
}

void Time::mostrarTime()
{
    int tam;
    tam = this->nome.length();
    tam = tam/2;
    // 15 + 15 + 3 + 2 = 35  35/2 =~ 17
    cout << espacamento(0,(17-tam)) << this->getNome() << endl << endl;
    cout << "Nome" << espacamento(4,15) << "Numero " << "Posicao" << espacamento(7,15) << "Maestria" << endl;
    for(int i = 0; i < 11; i++)
    {
        if(this->jogador[i].getNome() == this->capitao.getNome())
        {
            cout << this->jogador[i].getNome() <<"[C]"<< espacamento(this->jogador[i].getNome().length()+3,15);
        }
        else
        {
            cout << this->jogador[i].getNome() << espacamento(this->jogador[i].getNome().length(),15);
        }
        cout << this->jogador[i].getNumero() << espacamento(this->jogador[i].getNumero().length(),7);
        cout << this->jogador[i].getPosicao() << espacamento(this->jogador[i].getPosicao().length(),15);

        if(this->jogador[i].getMaestria() < 10)
        {
            cout << "0" <<this->jogador[i].getMaestria() << endl;
        }
        else
        {
            cout << this->jogador[i].getMaestria()<< endl;
        }
    }
    //reserva = 7  e 7 divido por 2 (3 ou 4)
    cout << endl << espacamento(0,(10-3)) << "Reserva" << endl << endl;
    cout << "Nome" << espacamento(4,15) << "Numero "<< "Maestria" << endl;
    for(int i = 0; i < 6; i++)
    {
        cout << this->reserva[i].getNome() << espacamento(this->reserva[i].getNome().length(),15);
        cout << this->reserva[i].getNumero() << espacamento(this->reserva[i].getNumero().length(),7);
        if(this->reserva[i].getMaestria() < 10)
        {
            cout << "0" <<this->reserva[i].getMaestria() << endl;
        }
        else
        {
            cout << this->reserva[i].getMaestria() << endl;
        }
    }
    cout << endl;
}

void Time::posicoesRandom()
{   string atrd;
    int passadas[11];
    randomSemRpt(passadas, 11);
        for(int i = 0; i < 11; i++)
        {
            atrd = this->getPosicoes(i);
            this->jogador[passadas[i]].setPosicao(atrd);
            atrd = " = ";
            this->setPosicoes(atrd,i);
            this->setPosicoes(this->jogador[passadas[i]].getNome(), i);
        }
}

void Time::definirPosicao(string posicao, string nome)
{
    for(int  i = 0; i < 11; i++)
    {
        if(this->jogador[i].getNome() == nome)
        {
            this->jogador[i].setPosicao(posicao);
        }
        else
        {
            cout << "Jogador não encontrado" << endl << endl;
        }
    }
}

void Time::substituicao(string titular, string reserva)
{
    Jogador subJogador;
    for(int i = 0; i < 11; i++)
    {
        if(this->jogador[i].getNome() == titular)
        {
            subJogador = this->jogador[i];
            for(int j = 0; j < 6; j++)
            {
                if(this->reserva[j].getNome() == reserva)
                {
                    this->inserirJogador(this->reserva[j], i);
                    this->inserirReserva(subJogador, j);
                }
            }
        }
    }
}




