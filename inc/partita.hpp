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

#ifndef PARTITA__HPP
#define PARTITA__HPP

#include <avversario.hpp>
#include <giocatore.hpp>
#include <iostream>
#include <mazzo.hpp>

using std::cout;
using std::cin;

class Partita
{
public:
    Partita();

    void Distr();
    void Start();
    void End();

private:
    Giocatore Player;
    Avversario Computer;
    Mazzo Pack;
};

#endif
