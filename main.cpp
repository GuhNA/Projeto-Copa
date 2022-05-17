#include "Copa.hpp"

int main()
{
        //Nao sei pq a seed quando resetada dentro da funcao n funciona direito.
        srand(time(0));
        Jogador J1, J2, J3, J4, J5, J6, J7, J8, J9, J10, J11, J12, J13, J14, J15, J16,J17;
        J1.setNome("Quessia");
        J2.setNome("Frajuca");
        J3.setNome("Goncalves");
        J4.setNome("Zayn");
        J5.setNome("Castanheda");
        J6.setNome("Beltrao");
        J7.setNome("Roberta");
        J8.setNome("Sabala");
        J9.setNome("Lamenha");
        J10.setNome("Hossana");
        J11.setNome("Osorio");
        J12.setNome("Antonio");
        J13.setNome("Remigio");
        J14.setNome("Mikaela ");
        J15.setNome("Valim");
        J16.setNome("Mieiro");
        J17.setNome("Paiva");
        J1.setNumero("25");
        J2.setNumero("39");
        J3.setNumero("17");
        J4.setNumero("49");
        J5.setNumero("33");
        J6.setNumero("43");
        J7.setNumero("13");
        J8.setNumero("89");
        J9.setNumero("57");
        J10.setNumero("79");
        J11.setNumero("74");
        J12.setNumero("12");
        J13.setNumero("49");
        J14.setNumero("42");
        J15.setNumero("76");
        J16.setNumero("28");
        J17.setNumero("32");



        Time T1;
        T1.setNome("Cavaleiros do odio");
        T1.inserirJogador(J1,0);
        T1.inserirJogador(J2,1);
        T1.inserirJogador(J3,2);
        T1.inserirJogador(J4,3);
        T1.inserirJogador(J5,4);
        T1.inserirJogador(J6,5);
        T1.inserirJogador(J7,6);
        T1.inserirJogador(J8,7);
        T1.inserirJogador(J9,8);
        T1.inserirJogador(J10,9);
        T1.inserirJogador(J11,10);
        T1.inserirReserva(J12,1);
        T1.inserirReserva(J13,2);
        T1.inserirReserva(J14,3);
        T1.inserirReserva(J15,4);
        T1.inserirReserva(J16,5);
        T1.inserirReserva(J17,0);
        T1.definirCapitao("49");
        T1.mostrarTime();
        T1.substituicao("Osorio", "Paiva");
        T1.mostrarTime();
        T1.posicoesRandom();
        T1.mostrarTime();
        Time T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12;
        T2.setNome("Cavaleiros de ouro");
        T3.setNome("Cavaleiros de bronze");
        T4.setNome("A Fenix");
        T5.setNome("Pegasus Force");
        T6.setNome("Cavaleiros do amor");
        T7.setNome("Cavaleiros nao sei");
        T8.setNome("Porque Cavaleiros?");
        T9.setNome("Soldadinhos de chumbo");
        T10.setNome("Argnarujne");
        T11.setNome("Navradski");
        T12.setNome("Soldata");
        Copa C1;
        C1.setTimes(T1,0);
        C1.setTimes(T2,1);
        C1.setTimes(T3,2);
        C1.setTimes(T4,3);
        C1.setTimes(T5,4);
        C1.setTimes(T6,5);
        C1.setTimes(T7,6);
        C1.setTimes(T8,7);
        C1.setTimes(T9,8);
        C1.setTimes(T10,9);
        C1.setTimes(T11,10);
        C1.setTimes(T12,11);
        C1.mostrarTimes(0);
        C1.competicao();

    return 0;
}
