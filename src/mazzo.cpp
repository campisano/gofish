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

#include <mazzo.hpp>

Mazzo::Mazzo()
{

    // inizializzo
    init();

    // show();     //? debug

    // e mischio
    mischia();

    // show();     //? debug
}

// inizializzo il mazzo:
// carte in ordine da 1 a 13
// e da cuori a picche
void Mazzo::init()
{
    Carta tempC;

    for(int j = 0; j < 52; j++)
    {
        int k = j / 13;
        tempC.setVal(1 + (j % 13));
        tempC.setSeed(1 + (k % 4));

        carte[j] = tempC;
    }

    pnt = 51;
}

// mischio il mazzo
void Mazzo::mischia()
{
    for(int i = 0; i < 52; i++)
    {
        // posizione a caso
        int r = rand() % 52;

        // memorizza della carta alla posizione 'i'
        Carta x = carte[i];

        // metti nella posizione 'i' quella carta
        carte[i] = carte[r];

        // metti la carta che stava nella posizione 'i'
        // nella posizione casuale 'r'
        carte[r] = x;
    }
}

// cede una carta
Carta  Mazzo::popCarta()
{
    Carta tempCarta = carte[pnt];
    carte[pnt].azzera();

    // punta la carta precedente,
    // ma ritorna quella che era l'attuale
    //  se l'incremento lo metto dopo return, lo salta.
    pnt--;

    return tempCarta;
}

// restituisce la posizione del puntatore
int Mazzo::getPnt()
{
    return pnt;
}

// visualizza il mazzo per il debug
void Mazzo::show()
{
    cout << "\n";

    for(int j = 0; j < 52; j++)
    {
        cout << j << "\t" << carte[j].getVal();
        cout << "\t" << carte[j].getSeed() << "\n";
    }

    cout << "\n";
}
