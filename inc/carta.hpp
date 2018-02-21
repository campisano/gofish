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

#ifndef CARTA__HPP
#define CARTA__HPP

#include <iostream>

using std::cout;
using std::cin;

class Carta
{
public:
    Carta();

    int getVal();
    char * getSeed();

    void setVal(int);
    void setSeed(int);

    void azzera();

private:
    int val;
    int seed;

    static char * cu;
    static char * qu;
    static char * fi;
    static char * pi;
};

#endif
