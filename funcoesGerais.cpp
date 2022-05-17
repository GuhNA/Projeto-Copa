#include "funcoesGerais.hpp"

string espacamento(int tam, int fim)
{
    string a = "";
    for(int i = 0; i < (fim-tam); i++)
    {
        a.push_back(32);
    }
    return(a);
}

void randomSemRpt(int vec[],int tam)
{
    srand(time(0));
    int random;
    int cont = 0;
    for(int i = 0; i < tam; i++)
    {
        vec[i] = 0;
    }
     while(cont != tam-1)
    {

        for(int i = 0; i < tam-1; i++)
        {
            random = rand() % tam;
            for(int j = 0; j < tam-1; j++)
            {
                if (vec[j] == random)
                {
                    i--;
                    break;
                }
            }
            if(vec[i] == 0)
            {
                vec[i] = random;
                cont++;
            }
        }
    }
}

void ordenar(int arra[], int tam)
{
    int k = 0, cont = 0;
   while (k != tam-1)
    {
        if(arra[k] < arra[k+1])
        {
            cont = arra[k];
            arra[k] = arra[k+1];
            arra[k+1] = cont;
            k = 0;
        }
        else
        {
            k++;
        }
    }
}
