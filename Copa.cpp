#include "Copa.hpp"
#include "funcoesGerais.hpp"

Copa::Copa()
{
    this->eliminatorias = false;
}

//Setters
void Copa::setEliminatorias(bool eliminatorias)
{
    this->eliminatorias = true;
}

void Copa::setTimes(Time times, int pos)
{
    this->times[pos] = times;
}

void Copa::setSemifinal(Time semiFinal[])
{
    for(int i = 0; i < 4;i++)
    {
        this->semiFinal[i] = semiFinal[i];
    }
}

void Copa::setFinais(Time finais[])
{
    for(int i = 0; i < 2;i++)
    {
        this->finais[i] = finais[i];
    }
}

void Copa::setQfinal(Time qfinal, int pos)
{
    this->qfinal[pos] = qfinal;
}

//Getters
Time Copa::getTimes(int pos)
{
    return(this->times[pos]);
}

Time Copa::getQfinal(int pos)
{
    return(this->qfinal[pos]);
}
bool Copa::getEliminatorias()
{
    return(this->eliminatorias);
}

Time* Copa::getSemifinal()
{
    return(this->semiFinal);
}

Time Copa::getSemifinalPos(int pos)
{
    return(this->semiFinal[pos]);
}

Time Copa::getFinaisPos(int pos)
{
    return(this->finais[pos]);
}

Time* Copa::getFinais()
{
    return(this->finais);
}

Time Copa::getVencedor()
{
    return(this->vencedor);
}

//Metodos


void Copa::competicao()
{
    int t1, t2, escolha;
    Time vazio;
    if(!this->getEliminatorias())
    {
        for(int t = 0; t  < 3; t++)
        {
            for(int i = 0; i < 12; i+=2)
            {
                t1 = i;
                t2 = i+1;

                escolha = rand() % 3;
                switch(escolha)
                {
                case 0:
                    this->times[t1].setPontuacao(times[t1].getPontuacao()+3);
                    cout << this->times[t1].getNome() << " venceu" << endl;
                    break;
                case 1:
                    this->times[t2].setPontuacao(times[t2].getPontuacao()+3);
                    cout << this->times[t2].getNome() << " venceu" << endl;
                    break;
                default:
                    this->times[t1].setPontuacao(times[t1].getPontuacao()+1);
                    this->times[t2].setPontuacao(times[t2].getPontuacao()+1);
                    cout << this->times[t2].getNome() << " e " << this->times[t1].getNome() << " empataram" << endl;
                }
            }
            cout << endl;
            this->ordernarTimes(0);
        }
        this->ordernarTimes(0);
        for (int i = 0; i < 8; i++)
        {
            vazio = this->times[i];
            this->setQfinal(vazio, i);
        }
        this->mostrarTimes(1);
        this->setEliminatorias(true);
    }
    if(this->eliminatorias)
    {
        //for das semifinais;
        this->compElim(this->getSemifinal(),8,0);
        this->mostrarTimes(2);
        //for das finais;
        this->compElim(this->getFinais(),4,1);
        this->mostrarTimes(3);

        this->setVencedor();
    }

}

void Copa::compElim(Time arra[], int tam, int opcao)
{
    int escolha;
    Time vazio;
    for(int i = 0; i < tam; i+=2)
    {
        escolha = rand() % 2;

        switch(opcao)
        {
        case 0:
            switch(escolha)
            {
            case 0:
                vazio = this->getQfinal(i);
                cout << this->getQfinal(i).getNome() << " venceu" << endl;
                break;
            case 1:
                vazio = this->getQfinal(i+1);
                cout << this->getQfinal(i+1).getNome() << " venceu" << endl;
                break;
            }
            break;
        case 1:
            switch(escolha)
            {
            case 0:
                vazio = this->getSemifinalPos(i);
                cout << this->getSemifinalPos(i).getNome() << " venceu" << endl;
                break;
            case 1:
                vazio = this->getSemifinalPos(i+1);
                cout << this->getSemifinalPos(i+1).getNome() << " venceu" << endl;
                break;
            }
            break;
        }

        if(i == 0)
        {
            if(tam > 4)
            {
                arra[i] = vazio;
            }
            else
            {
                arra[i] = vazio;
            }
        }
        else
        {
            if(tam > 4)
            {
                arra[i/2] = vazio;
            }
            else
            {
                arra[i/2] = vazio;
            }
        }
    }
    cout << endl;
}

void Copa::ordernarTimes(int op)
{
    Time troca;
    int arra[12];
    for(int i = 0; i <12; i++)
    {
        arra[i] = times[i].getPontuacao();
    }
    ordenar(arra,12);

    for(int i = 0; i < 12; i++)
    {
        for(int j = i; j < 12; j++)
        if(this->times[j].getPontuacao() == arra[i])
        {
            troca = times[j];
            times[j] = times[i];
            times[i] = troca;
            break;
        }

    }
    this->mostrarTimes(op);
}

void Copa::mostrarTimes(int opcao)
{
    switch(opcao)
    {
    case 0:
        cout << "Posicao" << " Time " << espacamento(7,22) << "Pontuacao" << endl;
        for(int i = 0; i < 12; i++)
        {
            if(i < 9)
            {
                cout << "0" << i+1 << espacamento(2,8);
            }
            else
            {
                cout << i +1<< espacamento(2,8);
            }
            cout << this->times[i].getNome() << espacamento(this->times[i].getNome().length(),22);
            if(this->times[i].getPontuacao() < 10)
            {
                cout << "0" <<this->times[i].getPontuacao() << endl;
            }
            else
            {
                cout <<this->times[i].getPontuacao()<< endl;
            }
        }
        break;
    case 1:
        cout << "Eliminatorias" << endl;
        for(int i = 0; i < 8; i++)
        {
            cout << this->qfinal[i].getNome() << endl;
        }
        break;
    case 2:
        cout << "Eliminatorias" << endl;
            for(int i = 0; i < 4; i++)
            {
                cout << this->semiFinal[i].getNome() << endl;
            }
            break;
    case 3:
        cout << "Eliminatorias" << endl;
            for(int i = 0; i < 2; i++)
            {
                cout << this->finais[i].getNome() << endl;
            }
            break;
    }
    cout << endl;

}

void Copa::setVencedor()
{
    if(this->eliminatorias)
    {
         int escolha;
        escolha = rand() % 2;
        switch(escolha)
        {
        case 0:
            this->vencedor = getFinaisPos(0);
            cout << this->getFinaisPos(0).getNome() << " e o vencedor da copa" << endl << endl;
            break;
        case 1:
            this->vencedor = getFinaisPos(1);
            cout << this->getFinaisPos(1).getNome() << " e o vencedor da copa" << endl << endl;
            break;
        }
    }
}
