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

#ifndef AVVERSARIO__HPP
#define AVVERSARIO__HPP

#include <carta.hpp>
#include <iostream>

using std::cout;
using std::cin;

class Avversario
{
public:
    Avversario();

    void show();
    int findVal(int);

    void pushCarta(Carta);
    Carta popNcarta(int);

    int findTrace(int);
    void pushTrace(int);
    int popNtrace(int);

    void scarta();
    int checkEnd();
    int ask();
    char * getName();
    int getLibri();

private:
    Carta carte[40];
    int nCarte;
    char name[5];
    int pnt;

    //  tengo traccia delle carte che il giocatore chiede all'avversario,
    int trace[30];  //lo limito a 30, e faccio tornare il puntatore a 0
    int lenTrace;
    int pntTrace;
    int libri;
};

#endif
