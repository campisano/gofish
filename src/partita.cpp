// Copyright (C) 2003 Riccardo Campisano <riccardo.campisano@gmail.com>
//
// This file is part of GoFish project.
//
// This project is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This project is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this project. If not, see <http://www.gnu.org/licenses/>.

#include <partita.hpp>

Partita::Partita()
{
    // stampa messaggio di benvenuto...
    cout << "\033[H\033[J\n\n\n\t\t\tGoFish!\n";

    // distribuisci carte
    Distr();

    // inizia il gioco
    Start();
}

// distribuisci carte
void Partita::Distr()
{
    // per 14 carte del mazzo (7 per ciascuno)
    // a partire dalla Pack.pnt
    int pnt = Pack.getPnt();

    for(int j = pnt; j > pnt - 14; j--)
    {
        // se è pari
        if(j % 2 == 0)
        {
            // dai la carta al player
            // e levala dal mazzo
            Player.pushCarta(Pack.popCarta());
        }
        else        // altrimenti
        {
            // dai la carta al player
            // e levala dal mazzo
            Computer.pushCarta(Pack.popCarta());
        }
    }
}

// inizio la partita...
void Partita::Start()
{
    // questa parte si potrebbe implementare in un metodo
    // specifico (= probab. non riutilizzabile)
    // di nome gofish, tanto per levarlo da qui...

    // il loop continua finchè la partita non è finita
    // il controllo viene effettuato durante il gioco,
    // ogni volta che uno dei giocatori scarta...
    while(true)
    {
        cout << "\n";
        // cout << "\033[H\033[J";

        //////////////////////////////////
        //                              //
        //  tocca a Player              //
        //                              //
        //////////////////////////////////

        cout << "\n\n\n------------------------------" << Player.getName() <<
             "-------------------------Libri: " << Player.getLibri() << "\n";

        int find;   // mi serve anche dopo il prossimo blocco
        // Player chiede un'altra carta se indovina la prossima carta del mazzo
        do
        {
            cout << "\n\tChiedi una carta all'avversario:\n";
            // Pack.show();     // ?debug
            // Computer.show(); // ?debug
            Player.show();

            int val = Player.ask();
            find = Computer.findVal(val);
            // comunico all'IA di Computer
            // quale carta Player gli abbia chiesto
            Computer.pushTrace(val);

            // Player chiede un'altra carta se ne ha chiesta una che Computer ha
            while(find != -1)
            {
                // Computer passa a Player la carta
                Player.pushCarta(Computer.popNcarta(find));
                // scarta se possibile
                Player.scarta();

                // se un dei due è rimasto senza carte, la partita è finita
                if(Player.checkEnd() || Computer.checkEnd())
                {
                    End();
                }

                cout << "\a\n\t\t\t\t\tCe l'ho!\n";
                cout << "Chiedi un'altra carta\n";
                // Pack.show();     // ?debug
                // Computer.show(); // ?debug
                Player.show();

                val = Player.ask();
                find = Computer.findVal(val);

                // comunico all'IA di Computer
                // quale carta Player gli abbia chiesto
                Computer.pushTrace(val);
            }

            cout << "\n\t\t\t\t\tGoFish!\n";

            // prendi una carta dal mazzo
            Carta dalMazzo = Pack.popCarta();
            Player.pushCarta(dalMazzo);

            // scarta se possibile
            Player.scarta();

            // se Player è rimasto senza carte, la partita è finita
            if(Player.checkEnd())
            {
                End();
            }

            // se ha il valore di quella chiesta a Computer
            if(dalMazzo.getVal() == val)
            {
                // Pack.show();     // ?debug
                cout << "\a\nHai pescato la carta che hai chiesto!\n";

                // chiedi di nuovo una carta a Computer
                find = 0;

                // Computer.show(); // ?debug
                // Player.show();   // ?debug
                cout << "\n";
            }
        }
        while(find >= 0);

        //////////////////////////////////
        //                              //
        //  tocca a Computer            //
        //                              //
        //////////////////////////////////

        cout << "\n\n\n------------------------------" << Computer.getName()
             << "-----------------------Libri: " << Computer.getLibri() << "\n";

        int findComp;   // mi serve anche dopo il prossimo blocco

        // Computer chiede un'altra carta
        // se indovina la prossima carta del mazzo
        do
        {
            // Pack.show();         // ?debug
            // Computer.show();     // ?debug
            Player.show();
            int asked = Computer.ask();

            cout << "\n\t\t\t\t\tTi chiedo un " << asked
                 << "\nPremi [invio] per continuare...\n";
            char null[10];          // pausa
            cin.getline(null, 10);  // pausa

            findComp = Player.findVal(asked);

            // Computer chiede un'altra carta se ne ha chiesta una che Player ha
            while(findComp != -1)
            {
                // Player passa a Computer la carta
                Computer.pushCarta(Player.popNcarta(findComp));

                // scarta se possibile
                Computer.scarta();

                // se un dei due è rimasto senza carte, la partita è finita
                if(Computer.checkEnd() || Player.checkEnd())
                {
                    End();
                }

                // Pack.show();     // ?debug
                // Computer.show(); // ?debug
                cout << "\a\n\t\t\t\t\tC'e l'hai!\n";
                Player.show();
                cout << "\n";

                asked = Computer.ask();

                cout << "\n\t\t\t\t\tTi chiedo un " << asked
                     << "\nPremi [invio] per continuare...\n";
                char null[10];          // pausa
                cin.getline(null, 10);  // pausa

                findComp = Player.findVal(asked);
            }

            // se computer non ha indovinato una carta di Player,
            // è possibile che Player abbia avuto e poi finito
            // le carte di quel tipo dunque per l'IA di Computer è meglio
            // togliere queste carte dalla lista delle carte che Computer
            // pensa siano in possesso di Player

            // cerca la carta richiesta dal computer sulla sua lista
            int posT = Computer.findTrace(asked);

            // finchè ne trova una
            while(posT != -1)
            {
                // la leva dalla lista
                Computer.popNtrace(posT);
                // e cerca la prossima carta dello stesso tipo
                posT = Computer.findTrace(asked);
            }

            cout << "\nNiente.\t\t\t\tPesco dal mazzo\n";

            // prendi una carta dal mazzo
            Carta dalMazzoC = Pack.popCarta();
            Computer.pushCarta(dalMazzoC);

            // scarta se possibile
            Computer.scarta();

            // se Computer è rimasto senza carte, la partita è finita
            if(Computer.checkEnd())
            {
                End();
            }

            // se ha il valore di quella chiesta a Player
            if(dalMazzoC.getVal() == asked)
            {
                // Pack.show();     // ?debug

                cout << "\a\n\t\t\t\t\tHo pescato la carta che ho chiesto!\n";

                // chiedi di nuovo una carta a Player
                findComp = 0;

                // Computer.show(); // ?debug
                // Player.show();   // ?debug
            }
        }
        while(findComp >= 0);
    }
}

void Partita::End()
{
    int p = Player.getLibri();
    int c = Computer.getLibri();

    if(p > c)
    {
        cout << "\a\n\n\n";
        cout << Player.getName();
        cout << ", hai vinto!\n";
        cout << "hai collezionato " << p << " libri contro " << c << " di ";
        cout << Computer.getName();
        cout << "\n";
    }
    else if(p < c)
    {
        cout << "\a\n\n\n\t\t\t\t\t" << "Hai perso!\n";
        cout << Computer.getName();
        cout << " ha collezionato " << c
             << " libri contro i tuoi " << p << "\n";
    }
    else
    {
        cout << "\a\n\n\n" << "E' patta:\n";
        cout << " avete collezionato " << p << " libri ciascuno.\n";
    }

    exit(0);
}
