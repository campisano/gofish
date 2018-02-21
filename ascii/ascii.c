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

#include <iostream>

using std::cout;
using std::cin;

int main ()
{

    //  inizializzo gli array
    char cin_frst [32]={0};
    char cin_scnd [32]={0};
    int word_len = sizeof(cin_frst);



    //  input
    cout << "\nInserisci nome:\n";
    cin >> cin_frst;
    cout << "\nInserisci cognome:\n";
    cin >> cin_scnd;



    //  output
    cout << "\nHai inserito ";

    int frst_len=0;
    while (cin_frst[frst_len]){
        cout << cin_frst[frst_len];
        frst_len++; //  lunghezza di cin_frst
    }
    cout << " ";

    int scnd_len=0;
    while (cin_scnd[scnd_len]){
        cout << cin_scnd[scnd_len];
        scnd_len++; //  lunghezza di cin_frst
    }

    int len = frst_len+scnd_len;



    cout << " (" << len << " caratteri)\n";

    //  converto in ascii
    cout << "\nCodifica Ascii\n";
    cout << "n°\tascii\tchar\n";
    int ascii[len];
//
    int j=0;
    while (cin_frst[j]){
        ascii[j] = (int)cin_frst[j];
        cout << j+1 << "\t" << ascii[j] << "\t(" << cin_frst[j] << ")\n";
        j++;
    }

    cout << "\n";

    int k=0;
    while (cin_scnd[k]){
        ascii[j+k] = (int)cin_scnd[k];
        cout << j+k+1 << "\t" << ascii[j+k] << "\t(" << cin_scnd[k] << ")\n";
        k++;
    }



    //  calcolo modulo
    int mod = 32;/* questo perchè va sommato il carattere spazio (32),
            come da esempio */

    for (int i=0; i<len; i++)
        mod += ascii[i];

    mod = mod % 9;


    cout << "\a\n\tTi tocca il progetto " << mod << "\n\n";
}
