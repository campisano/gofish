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

#include <avversario.hpp>

Avversario::Avversario()
{
    nCarte = sizeof(carte) / sizeof(Carta);

    lenTrace = sizeof(trace) / sizeof(int);

    for(int j = 0; j < lenTrace; j++)
    {
        trace[j] = 0;   // inizializzo trace a 0
    }

    pnt = -1; // il fatto è che push inserisce una carta a partire da
    // dopo il puntatore, dunque la prima la ficca a zero
    // e non c'è pericolo se le carte vengono
    // messe solo con push...
    libri = 0;

    pntTrace = -1;

    name[0] = 'T';
    name[1] = '1';
    name[2] = 't';
    name[3] = '0';
    name[4] = '\0';
}

char * Avversario::getName()
{
    return name;
}

int Avversario::getLibri()
{
    return libri;
}

//  ritorna la posizione del primo valore trovato
int Avversario::findVal(int _val)
{
    for(int j = 0; j < nCarte; j++)
    {
        if(_val == carte[j].getVal())
        {
            return j;
        }
    }

    // se non la trova
    return -1;
}

// restituisce la carta alla posizione specificata
Carta Avversario::popNcarta(int _pnt)
{
    Carta tempCarta = carte[_pnt];
    carte[_pnt].azzera();

    return tempCarta;
}

// aggiunge una carta
void Avversario::pushCarta(Carta _card)
{
    pnt++;
    carte[pnt] = _card;
}

void Avversario::show()
{
    cout << "\n";
    int w = 0;

    for(int j = 0; j < nCarte; j++)
    {
        // fa vedere solo le carte che ha
        int k = carte[j].getVal();

        if(k != 0)
        {
            if(w % 3 == 0)
            {
                cout << "\n\t\t\t\t\t";
            }

            cout << k << "   " << carte[j].getSeed() << "\t";
            w++;
        }
    }

    cout << "\n";
}

void Avversario::scarta()
{
    // per ogni tipo di valore

    for(int j = 1; j <= 13; j++)
    {
        int tmp = 0;

        // controlla quante carte di quel tipo ha
        for(int k = 0; k < nCarte; k++)
        {
            if(carte[k].getVal() == j)
            {
                tmp++;
            }
        }

        // se ha tutte le carte di questo valore, scartale
        if(tmp == 4)
        {
            for(int w = 0; w < nCarte; w++)
            {
                if(carte[w].getVal() == j)
                {
                    carte[w].azzera();
                }
            }

            cout << "\tScarto i " << j << "\n";
            libri++;
        }
    }
}

int Avversario::checkEnd()
{
    // se ha finito le carte la partita è finita
    int ended = 1;

    for(int w = 0; w < nCarte; w++)
    {
        if(carte[w].getVal() != 0)
        {
            ended = 0;
            break;
        }
    }

    return ended;
}

////////////////////////////
//      I.A.

// ritorna la posizione del primo valore trovato
// fra le carte richieste da Player a Computer
int Avversario::findTrace(int _val)
{
    for(int j = 0; j < lenTrace; j++)
    {
        if(_val == trace[j])
        {
            return j;
        }
    }

    // se non la trova
    return -1;
}

// memorizza l'ultima carta richiesta da Player a Computer
void Avversario::pushTrace(int _val)
{
    if(pntTrace < (lenTrace - 1))
    {
        pntTrace++;     // scrivo sulla prossima posizione
    }
    else
    {
        pntTrace = 0;   // me se l'array è finito ricomincio da 0
    }

    trace[pntTrace] = _val;
}

// restituisce la carta alla posizione specificata fra quelle
// richieste da Player a Computer
int Avversario::popNtrace(int _pnt)
{
    int temp = trace[_pnt];
    trace[_pnt] = 0;

    return temp;
}

// restituisce la carta da chiedere a Player
int Avversario::ask()
{
    int count[14] = {0}; //count[0] resta inutilizzato
    int best = 0;
    int max = 0;

    // per ogni tipo di valore
    for(int tipo = 1; tipo <= 13; tipo++)
    {
        int tmp = 0;

        // controlla quante carte di quel tipo ha
        for(int k = 0; k < nCarte; k++)
        {
            if(carte[k].getVal() == tipo)
            {
                tmp++;
            }
        }

        count[tipo] = tmp;  // memorizza i valori

        // se questa carta che ho me l'ha chiesta anche il giocatore
        // e ce ne ho in maggior numero della best precedente
        if(findTrace(tipo) != -1 && count[best] < tmp)
        {
            best = tipo;
        }

        // se count[0] era utilizzato questa istruzione
        // dava problemi, perchè max all'inizio è =0
        if(count[max] < tmp)
        {
            max = tipo;    //memorizza la carta che ho in maggior numero
        }

        // cout << tipo << ")\tmax: " << max << "\tbest: " << best << "";
        // cout << "\tfind:  " << findTrace(tipo) << "\tcount[tipo]: "
        //      << count[tipo] << "\tcount[best]: " << count[best] << "\n";
    }

    // for (int z=0; z<lenTrace; z++)
    // {
    //     cout << trace[z] << "\n";
    // }

    // se con quel sistema non si è potuto scegliere una carta,
    // chiede quella che ha in maggior numero
    if(best == 0)
    {
        best = max;
    }

    return best;
}

////////////////////////////
