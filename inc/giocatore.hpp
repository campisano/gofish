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

#ifndef GIOCATORE__HPP
#define GIOCATORE__HPP

#include <carta.hpp>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;

class Giocatore
{
public:
    Giocatore();

    int ask();

    void show();
    int findVal(int);

    void pushCarta(Carta);
    Carta popNcarta(int);

    void scarta();
    int checkEnd();
    char * getName();
    int getLibri();

private:
    Carta carte[40];
    int nCarte;
    char name[32];
    int pnt;
    int libri;
};

#endif
