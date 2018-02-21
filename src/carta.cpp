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

#include <carta.hpp>

char * Carta::cu = "cuori";
char * Carta::qu = "quadri";
char * Carta::fi = "fiori";
char * Carta::pi = "picche";

Carta::Carta()
{
    val = 0;
    seed = 0;
}

int Carta::getVal()
{
    return val;
}

char * Carta::getSeed()
{
    switch(seed)
    {
    case 1:
        return cu;
    case 2:
        return qu;
    case 3:
        return fi;
    case 4:
        return pi;
    default:
        return "0";
    }
}

void Carta::setVal(int _val)
{
    if(_val < 14 && _val > 0)
    {
        val = _val;
    }
    else
    {
        cout << "\nvalore sbagliato per carta\n";
    }
}

void Carta::setSeed(int _seed)
{
    if(_seed < 5 && _seed > 0)
    {
        seed = _seed;
    }
    else
    {
        cout << "\nseme sbagliato per carta\n";
    }
}

void Carta::azzera()
{
    val = 0;
    seed = 0;
}
