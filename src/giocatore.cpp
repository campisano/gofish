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

#include <giocatore.hpp>

Giocatore::Giocatore()
{
    nCarte = sizeof(carte) / sizeof(Carta);

    pnt = -1; // il fatto è che push ficca una carta a partire da
    // dopo il puntatore, dunque la prima la ficca a zero
    // e non c'è pericolo se le carte vengono
    // messe solo con push...
    libri = 0;

    cout << "\nInserisci il tuo nome (max 30 char): ";
    cin.getline(name, 32);
}

char * Giocatore::getName()
{
    return name;
}

int Giocatore::getLibri()
{
    return libri;
}

int Giocatore::ask()
{
    int par;
    int find;

    // chiede una carta al giocatore finchè
    // questi non ne sceglie una fra quelle che ha
    do
    {
        // chiede una carta al giocatore
        // finchè questi non ne sceglie una fra 1 e 13
        do
        {
            char arrChar[3] = {'\n'};

            cout << "\nInserisci un valore fra 1 e 13\n";
            cin.clear();
            cin.sync();

            if(arrChar[0] != '\n' && arrChar[1] != '\n' && arrChar[2] != '\n')
            {
                while(cin.get() != '\n');

            }
            cin.getline(arrChar, 3);
            par = atoi(arrChar);

            while(!par)
            {
                cout << "\aChe hai scritto?!?\n";

                cin.clear();
                cin.sync();

                if(
                    arrChar[0] != '\n' &&
                    arrChar[1] != '\n' &&
                    arrChar[2] != '\n'
                )
                {
                    while(cin.get() != '\n');

                }
                cin.getline(arrChar, 3);
                par = atoi(arrChar);
            }

        }
        while(par < 1 || par > 13);

        find = findVal((char)par);

        if(find < 0)
        {
            cout << "\nNon hai una carta di quel valore,\n"
                 << "scegli un'altra carta\n";
        }

    }
    while(find < 0);

    return par;     // se tutto è corretto
    // ritorna il valore inserito dall'utente
}

// ritorna la posizione del primo valore trovato
int Giocatore::findVal(int _val)
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
Carta Giocatore::popNcarta(int _pnt)
{
    Carta tempCarta = carte[_pnt];
    carte[_pnt].azzera();

    return tempCarta;
}

// aggiunge una carta
void Giocatore::pushCarta(Carta _card)
{
    pnt++;
    carte[pnt] = _card;
}

void Giocatore::show()
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
                cout << "\n\t";
            }

            cout << k << "   " << carte[j].getSeed() << "\t";
            w++;
        }
    }

    cout << "\n";
}

void Giocatore::scarta()
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

int Giocatore::checkEnd()
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
