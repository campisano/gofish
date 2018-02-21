# GoFish!

#### Consegna progetto per esame fondamenti di informatica 1                 (validità 2002/2003)

![Alt text](/doc/README.md/output.png?raw=true "GoFish output")

Il compito assegnato prevede lo svolgimento di un progetto da scegliersi tramite un piccolo programma iniziale.
Questo programma deve convertire i caratteri del proprio nome e cognome in codice ascii, sommare questi caratteri e restituire il modulo 9 di questa somma: il risultato ottenuto corrisponde al numero del progetto (da 0 a 8) che il candidato deve svolgere.
In particolare, le cifre del nome e cognome devono essere date al programma con iniziali maiuscole, ed è calcolato nella somma il carattere di spaziatura (equivalente a 32 nella codifica ascii).

Questo compito preliminare non specificava con quante chiamate di input bisognasse acquisire il nome e cognome dall'utente, dunque per mio gusto personale ho preferito usare 2 chiamate cin (una per il nome e l'altra per il cognome) piuttosto che una cin.getline.
Come è èvidente, il carattere di spaziatura (che nell'esempio si trova nell'input dell'utente tra nome e cognome) è stato ugualmente considerato, aggiungendo 32 alla somma dei caratteri codificati.

Riporto di seguito la mia soluzione:



//  file ascii.c

     1  #include <iostream>
     2
     3  using std::cout;
     4  using std::cin;
     5
     6  int main ()
     7  {
     8
     9      //  inizializzo gli array
    10      char cin_frst [32]={0};
    11      char cin_scnd [32]={0};
    12      int word_len = sizeof(cin_frst);
    13
    14
    15
    16      //  input
    17      cout << "\nInserisci nome:\n";
    18      cin >> cin_frst;
    19      cout << "\nInserisci cognome:\n";
    20      cin >> cin_scnd;
    21
    22
    23
    24      //  output
    25      cout << "\nHai inserito ";
    26
    27      int frst_len=0;
    28      while (cin_frst[frst_len]){
    29          cout << cin_frst[frst_len];
    30          frst_len++; //  lunghezza di cin_frst
    31      }
    32      cout << " ";
    33
    34      int scnd_len=0;
    35      while (cin_scnd[scnd_len]){
    36          cout << cin_scnd[scnd_len];
    37          scnd_len++; //  lunghezza di cin_frst
    38      }
    39
    40      int len = frst_len+scnd_len;
    41
    42
    43
    44      cout << " (" << len << " caratteri)\n";
    45
    46      //  converto in ascii
    47      cout << "\nCodifica Ascii\n";
    48      cout << "n°\tascii\tchar\n";
    49      int ascii[len];
    50  //
    51      int j=0;
    52      while (cin_frst[j]){
    53          ascii[j] = (int)cin_frst[j];
    54          cout << j+1 << "\t" << ascii[j] << "\t(" << cin_frst[j] << ")\n";
    55          j++;
    56      }
    57
    58      cout << "\n";
    59
    60      int k=0;
    61      while (cin_scnd[k]){
    62          ascii[j+k] = (int)cin_scnd[k];
    63          cout << j+k+1 << "\t" << ascii[j+k] << "\t(" << cin_scnd[k] << ")\n";
    64          k++;
    65      }
    66
    67
    68
    69      //  calcolo modulo
    70      int mod = 32;/* questo perchè va sommato il carattere spazio (32),
    71              come da esempio */
    72
    73      for (int i=0; i<len; i++)
    74          mod += ascii[i];
    75
    76      mod = mod % 9;
    77
    78
    79      cout << "\a\n\tTi tocca il progetto " << mod << "\n\n";
    80  }
    81

Il programma è molto semplice:

dopo aver incluso la libreria per l'I/O iostream
dichiaro due array di 32 caratteri (inizializzati a 0) dove inserisco l'input dall'utente.

Successivamente stampo a schermo i caratteri inseriti dall'utente, usando lo stesso ciclo anche per calcolare la lunghezza degli array nome e cognome.

Con gli altri due cicli while codifico in ascii gli array (inserendo il risultato in un unico array di interi ascii[]) e stampo a schermo il risultato.

Con l'ultimo ciclo for, sommo gli elementi dell'array ascii,
dunque ne calcolo il modulo e stampo a schermo il numero equivalente al progetto che l'utente deve svolgere.

Seguendo l'output del programma, ho svolto il progetto n° 7.



Il progetto n° 7 consiste nel simulare il gioco di carte ``Go Fish!''.
Lo scopo del gioco è descritto come segue:


<<
    PROGETTO 7

Progettare e codificare delle classi C++ per simulare il gioco di carte ``Go fish!''. Le mosse del giocatore utente sono inserite da tastiera ogni volta, mentre le mosse del giocatore computer vengono decise indipendentemente, in modo casuale oppure secondo una determinata strategia.

Particolare credito verrà data a chi realizzerà strategie di gioco intelligenti e/o curerà l'interfaccia grafica.

Le regole del gioco sono le seguenti. Si gioca con un mazzo da 52 carte (A, 2-10, J, Q, K), e l'obiettivo è collezionare ``libri''. Un libro è costituito da quattro carte con lo stesso valore (ad esempio, quattro assi).

A ciascun giocatore vengono date sette carte, le restanti vengono lasciate in un mazzo coperto sul tavolo. In ciascun turno di gioco un giocatore chiede una carta di un certo valore all'avversario (``Dammi un sette!''), purché egli abbia già in mano una carta con lo stesso valore. Se l'avversario possiede tale carta la passa al giocatore, ed il giocatore, avendo indovinato, ha diritto a fare una nuova richiesta. Se invece l'avversario non possiede la carta richiesta risponde con ``Go fish!'', e il giocatore pesca una carta dal mazzo in mezzo al tavolo. Se la carta pescata ha lo stesso valore di quella richiesta, il giocatore ha diritto a fare un'altra richiesta all'avversario. Se invece la carta pescata ha un valore differente, tocca all'avversario fare richieste al giocatore, seguendo lo stesso schema.

Non appena un giocatore ottiene quattro carte con lo stesso valore, le cala sul tavolo. Il gioco termina quando un giocatore resta senza carte in mano, e vince colui che ha collezionato il maggior numero di ``libri'' (gruppi di quattro carte dello stesso valore).

>>

Nel testo non è stata considerata l'ipotesi di una partita che finisce con i giocatori che hanno lo stesso numero di libri,
e ho dato per scontato che in quel caso sia 'patta'.



Anche se penso che la programmazione strutturata sia più efficiente, l'esercizio va svolto usando codice orientato a oggetti.
Questo è di concezione più semplice e facile da modificare, ma ho notato una duplicazione del tempo di compilazione (almeno in ambiente Linux), dovuta probabilmente al linking dei vari oggetti.
Usando Linux non saprei davvero come scegliere una libreria grafica adatta anche su altri ambienti, le Allegro e le SDL usano male le interfacce a finestre (bottoni, font, campi di testo, menu) mentre le GTK non sono compatibili con Windows, e non sapendo che sistema operativo verrà usato per visionare il lavoro ho puntato sulla portabilità e ho usato output semplice a caratteri.



Nel forum (o discussion room, come si preferisce) è stato indicato di trascrivere in questo documento la descrizione top-down usata per scrivere questo codice.
Io ho letto quanto il libro di testo (e il materiale informatico) dice sulla logica top-down, sullo pseudocodice e sui diagrammi, ma non sono riuscito a concludere un gran che usando quei metodi: non riesco mai ad arrivare ad un raffinamento tale che mi permetta di scrivere codice C++, e mi ritrovo davanti all'editor di testo pensando cosa mi serva per ottenere un determinato risultato.
Visto che riesco ad ottenere qualcosa di buono anche facendomi qualche schizzo a matita e buttando giù man mano le idee, rinuncio allo pseudocodice; una descrizione simile dello sviluppo del progetto si trova di seguito, quando viene descritta l'implementazione della classe Partita. Per avere maggiori dettagli basta consultare le spiegazioni sulle implementazioni delle varie classi, che seguono il codice delle classi.



Per il mio progetto ho utilizzato 5 classi: la classe carta, la classe mazzo che non è altro che un array di oggetti carta, la classe giocatore e la classe avversario contenenti oltre l'array delle proprie carte e i metodi per gestirle, e la classe partita, nella quale si svolgono tutte le azioni; nella funzione main() c'è soltanto la dichiarazione di un oggetto partita.

Descrivo ora in dettaglio le mie soluzioni spiegando i ragionamenti che hanno portato a determinate scelte, includendo per ogni classe, nell'ordine, il codice dei file header, il significato delle proprietà (ovvero i dati membro, quasi tutti private), l'implementazione delle funzioni della classe, e le operazioni che questi metodi eseguono.



//  file carta.h

     1  #ifndef CARTA_H
     2  #define CARTA_H
     3
     4  #include <iostream>
     5  using std::cout;
     6  using std::cin;
     7
     8  class Carta {
     9      public:
    10          Carta();
    11
    12          int getVal();
    13          char*   getSeed();
    14
    15          void    setVal(int);
    16          void    setSeed(int);
    17
    18          void    azzera();
    19
    20      private:
    21          int val;
    22          int seed;
    23
    24          static char* cu;
    25          static char* qu;
    26          static char* fi;
    27          static char* pi;
    28
    29  };
    30
    31  #endif

La classe carta ha ovviamente due dati, il valore ed il seme (esempio asso di cuori),
e dei metodi necessari a visualizzare le sue proprietà e alla loro corretta manipolazione.
Sia il valore che il seme sono due interi, mentre i successivi puntatori sono static perchè sono in comune a tutti gli oggetti di questa classe.

//  file carta.c

     1  #include "carta.h"
     2
     3  char*   Carta::cu = "cuori";
     4  char*   Carta::qu = "quadri";
     5  char*   Carta::fi = "fiori";
     6  char*   Carta::pi = "picche";
     7
     8
     9  Carta::Carta(){
    10
    11      val=0;
    12      seed=0;
    13  }
    14
    15  int Carta::getVal(){
    16      return val;
    17  }
    18
    19  char*   Carta::getSeed(){
    20
    21      switch (seed){
    22          case 1:
    23              return cu;
    24          case 2:
    25              return qu;
    26          case 3:
    27              return fi;
    28          case 4:
    29              return pi;
    30          default:
    31              return "0";
    32      }
    33  }
    34
    35  void    Carta::setVal(int _val){
    36      if (_val<14 && _val>0)
    37          val=_val;
    38      else
    39          cout << "\nvalore sbagliato per carta\n";
    40  }
    41
    42  void    Carta::setSeed(int _seed){
    43      if (_seed<5 && _seed>0)
    44          seed=_seed;
    45      else
    46          cout << "\nseme sbagliato per carta\n";
    47  }
    48
    49  void    Carta::azzera(){
    50      val=0;
    51      seed=0;
    52  }
    53

Per prima cosa vengono inizializzati i puntatori static della classe carta, che servono a visualizzare il seme di ogni carta.
Questa scelta è stata fatta per non dover mettere in ogni oggetto carta un array di char per descriverne il tipo di seme, perchè sarebbe stato uno spreco di risorse. Utilizzare una funzione esterna friend della classe che restituisse il seme leggendo array di caratteri, dichiarati come globali o nella funzione main, sarebbe stato possibile, ma si sarebbe resa la classe Carta dipendente da dati esterni, ed è poco logico se si vuole utilizzare la programmazione orientata agli oggetti.

Il costruttore inizializza il valore e il seme della carta a 0, valore che permette ai gestori di capire che questa carta è 'nulla'.
Mi spiego meglio con un esempio: quando inizializzo l'array di carte del giocatore, tutte le carte sono 'nulle', difatti prima che si distribuiscano le carte i giocatori non hanno carte in mano. Per sapere se in una posizione dell'array c'è una carta, controllo che il suo valore sia diverso da 0.

I metodi getVal(), getSeed(), setVal() e setSeed() restituiscono e impostano il valore ed il seme della carta: il principio è del minimo privilegio? bene, in questo modo, rendendo le proprietà della classe private, controllo che i dati da inserire abbiano un significato secondo il tipo di dato.

Il metodo azzera() è soltanto una scorciatoia: settare quei valori alla carta è una cosa frequente, e non è necessario in questo modo controllare il valore da impostare visto che è definito qui; in teoria è per efficienza, in pratica il programma è talmente leggero che si potrebbe considerare eccessiva questa implementazione, ma è anche più veloce per il programmatore settare come 'nulla' una carta in questo modo.





//  file mazzo.h

     1  #ifndef MAZZO_H
     2  #define MAZZO_H
     3  #include <cstdlib>
     4  #include <iostream>
     5  using std::cout;
     6  using std::cin;
     7  #include "carta.h"
     8
     9  class Mazzo {
    10      public:
    11          Mazzo();
    12
    13          void    init();
    14          void    mischia();
    15          void    show();
    16          Carta   popCarta();
    17          int getPnt();
    18
    19      private:
    20          Carta   carte[52];
    21          int pnt;
    22  };
    23
    24  #endif

La classe Mazzo è composta da un array di oggetti Carta e da un intero che funge da puntatore per la posizione della prossima carta da pescare. Il nome dell'array carte[] è esso stesso un puntatore al primo elemento dell'array, e avrei potuto usare quello facendolo puntare all'elemento successivo, ma a parte la pericolosità nel giocare con i puntatori in questo modo, altre chiamate a quell'array, come quella per il debug che visualizza il contenuto dell'intero mazzo, non sarebbero state possibili non potendo controllare la posizione del puntatore rispetto al primo elemento dell'array (perchè complicarsi la vita per non usare un int di 4 bytes?).

//  file mazzo.c

     1  #include "mazzo.h"
     2
     3  Mazzo::Mazzo(){
     4
     5  //  inizializzo
     6      init();
     7
     8  //  show();     //? debug
     9
    10  //  e mischio
    11      mischia();
    12
    13  //  show();     //? debug
    14  }
    15
    16  //  inizializzo il mazzo:
    17  //  carte in ordine da 1 a 13
    18  //  e da cuori a picche
    19  void    Mazzo::init(){
    20
    21      Carta tempC;
    22      for (int j=0; j<52; j++){
    23          int k = j/13;
    24          tempC.setVal(1+(j%13));
    25          tempC.setSeed(1+(k%4));
    26
    27          carte[j]=tempC;
    28      }
    29      pnt=51;
    30  }
    31
    32  //  mischio il mazzo
    33  void    Mazzo::mischia(){
    34
    35
    36      for (int i=0; i<52; i++){
    37
    38      //  posizione a caso
    39          int r = rand()%52;
    40
    41      //  memorizza della carta alla posizione 'i'
    42          Carta x = carte[i];
    43
    44      //  metti nella posizione 'i' quella carta
    45          carte[i]=carte[r];
    46
    47      //  metti la carta che stava nella posizione 'i'
    48      //  nella posizione casuale 'r'
    49          carte[r]=x;
    50      }
    51  }
    52
    53  //  cede una carta
    54  Carta   Mazzo::popCarta(){
    55
    56      Carta tempCarta=carte[pnt];
    57      carte[pnt].azzera();
    58
    59      //  punta la carta precedente,
    60      //  ma ritorna quella che era l'attuale
    61      //  se l'incremento lo metto dopo return, lo salta.
    62      pnt--;
    63      return tempCarta;
    64  }
    65
    66  //  restituisce la posizione del puntatore
    67  int Mazzo::getPnt(){
    68      return pnt;
    69  }
    70
    71  //  visualizza il mazzo per il debug
    72  void    Mazzo::show(){
    73
    74      cout << "\n";
    75      for (int j=0; j<52; j++){
    76          cout << j << "\t" << carte[j].getVal();
    77          cout << "\t" << carte[j].getSeed() << "\n";
    78      }
    79      cout << "\n";
    80  }
    81

La classe Mazzo include le prime operazioni significative del programma.
Alla dichiarazione, il costruttore inizializza e mischia le carte.

Il metodo init() inizializza le carte in ordine, dall'asso di cuori al re di picche, come fosse un mazzo nuovo, da notare che il puntatore pnt è inizializzato a 51, ovvero alla fine dell'array e infatti verrà decrementato (è un caso, si sarebbe potuto fare benissimo il contrario, modificando di poco le implementazioni).

Il metodo() mischia scorre una sola volta l'array carte[], e ogni carta (dalla prima all'ultima) viene scambiata con una in una posizione casuale: questo sistema è semplice ed efficiente.

Il metodo popCarta() è suggerito dal funzionamento dello stack in assembly: restituisce la carta e decrementa il puntatore.
In realtà prima salva la carta da restituire togliendola dal mazzo, poi decrementa il puntatore e solo dopo restituisce la carta salvata; questo perchè decrementare il puntatore dopo l'istruzione return sarebbe inutile, in quanto la funzione terminerebbe all'istruzione return e il decremento del puntatore non verrebbe effettuato.

Infine il metodo show() visualizza l'intero array di carte, in ordine, e serve solo per il debug.





//  file giocatore.h

     1  #ifndef GIOCATORE_H
     2  #define GIOCATORE_H
     3
     4  #include <iostream>
     5  #include <cstdlib>
     6  using std::cout;
     7  using std::cin;
     8  #include "carta.h"
     9
    10  class Giocatore {
    11      public:
    12          Giocatore();
    13
    14          int ask();
    15
    16          void    show();
    17          int findVal(int);
    18
    19          void    pushCarta(Carta);
    20          Carta   popNcarta(int);
    21
    22          void    scarta();
    23          int checkEnd();
    24          char*   getName();
    25          int getLibri();
    26
    27      private:
    28          Carta   carte[40];
    29          int nCarte;
    30          char    name[32];
    31          int pnt;
    32          int libri;
    33  };
    34
    35  #endif


La classe Giocatore è composta dal solito array di carte, stavolta composto solamente da 40 elementi, perchè si possono avere solo 3 carte per ogni valore (perchè 4 carte dello stesso valore saranno scartate), 13 sono i tipi di valore dunque 13*3=39.
Ho scelto di avere un array di 40 elementi perchè in un solo caso uno dei due giocatori può arrivare ad avere in mano 40 carte:
nel caso poco probabile (quasi assurdo) che il giocatore abbia 3 valori per ogni tipo di carta, ovvero 39 carte, questi non può scartare, dunque alla richiesta del giocatore di una altra carta all'avversario (che comporterà solo successivamente lo scarto delle 4 carte dello stesso tipo), per un solo istante il giocatore avrà 40 carte, e se l'array fosse di sole 39 carte la 40 andrà persa e il giocatore non potrà scartare le altre 3 carte dello stesso valore della carta persa.

Ovviamente il giocatore avrà un nome, e 31 caratteri (l'ultimo è riservato per il char '\0') sono più che sufficienti.

Il puntatore pnt segue la stessa logica di quella del puntatore del mazzo.

La variabile intera libri è usata per calcolare il punteggio finale, ovvero viene incrementata ogni volta che il giocatore scarta una serie di 4 carte dello stesso valore, un 'libro' appunto.


//  file giocatore.h

     1  #include "giocatore.h"
     2
     3  Giocatore::Giocatore() {
     4
     5      nCarte=sizeof(carte)/sizeof(Carta);
     6
     7      pnt=-1; //  il fatto è che push ficca una carta a partire da
     8          //  dopo il puntatore, dunque la prima la ficca a zero
     9          //  e non c'è pericolo se le carte vengono
    10          //  messe solo con push...
    11      libri=0;
    12
    13      cout << "\nInserisci il tuo nome (max 30 char): ";
    14      cin.getline(name, 32);
    15  }
    16
    17  char*   Giocatore::getName(){
    18      return name;
    19      }
    20
    21  int Giocatore::getLibri(){
    22      return libri;
    23  }
    24
    25  int Giocatore::ask(){
    26
    27      int par;
    28      int find;
    29
    30  //  chiede una carta al giocatore finché questi non ne sceglie una fra quelle che ha
    31      do {
    32      //  chiede una carta al giocatore finché questi non ne sceglie una fra 1 e 13
    33          do {
    34              char arrChar[3]={'\n'};
    35
    36              cout << "\nInserisci un valore fra 1 e 13\n";
    37                  cin.clear();
    38                  cin.sync();
    39
    40                  if (arrChar[0]!='\n' && arrChar[1]!='\n' && arrChar[2]!='\n'){
    41                      while(cin.get()!='\n');
    42
    43                  }
    44                  cin.getline(arrChar, 3);
    45                  par=atoi(arrChar);
    46
    47              while (!par){
    48                  cout << "\aChe hai scritto?!?\n";
    49
    50                  cin.clear();
    51                  cin.sync();
    52
    53                  if (arrChar[0]!='\n' && arrChar[1]!='\n' && arrChar[2]!='\n'){
    54                      while(cin.get()!='\n');
    55
    56                  }
    57                  cin.getline(arrChar, 3);
    58                  par=atoi(arrChar);
    59              };
    60
    61          }while (par<1 || par>13);
    62
    63          find = findVal((char)par);
    64
    65          if (find<0)
    66              cout << "\nNon hai una carta di quel valore,\nscegli un'altra carta\n";
    67
    68      }while (find<0);
    69
    70      return par; //  se tutto è corretto ritorna il valore inserito dall'utente
    71  }
    72
    73  //  ritorna la posizione del primo valore trovato
    74  int Giocatore::findVal(int _val){
    75
    76      for (int j=0; j<nCarte; j++){
    77
    78          if (_val == carte[j].getVal())
    79              return j;
    80      }
    81  //  se non la trova
    82      return -1;
    83  }
    84
    85  //  restituisce la carta alla posizione specificata
    86  Carta   Giocatore::popNcarta(int _pnt){
    87
    88      Carta tempCarta=carte[_pnt];
    89      carte[_pnt].azzera();
    90
    91      return tempCarta;
    92  }
    93
    94  //  aggiunge una carta
    95  void    Giocatore::pushCarta(Carta _card){
    96      pnt++;
    97      carte[pnt] = _card;
    98  }
    99
   100  void    Giocatore::show(){
   101
   102      cout << "\n";
   103      int w=0;
   104      for (int j=0; j<nCarte; j++){
   105
   106          //  fa vedere solo le carte che ha
   107          int k = carte[j].getVal();
   108          if (k!=0){
   109              if (w%3==0)
   110                  cout << "\n\t";
   111
   112              cout << k << "   " << carte[j].getSeed() << "\t";
   113              w++;
   114          }
   115      }
   116      cout << "\n";
   117  }
   118
   119  void    Giocatore::scarta(){
   120
   121  //  per ogni tipo di valore
   122      for (int j=1; j<=13; j++){
   123
   124          int tmp = 0;
   125
   126      //  controlla quante carte di quel tipo ha
   127          for (int k=0; k<nCarte; k++)
   128              if (carte[k].getVal()==j)
   129                  tmp++;
   130
   131      //  se ha tutte le carte di questo valore, scartale
   132          if (tmp==4) {
   133              for (int w=0; w<nCarte; w++)
   134                  if (carte[w].getVal()==j)
   135                      carte[w].azzera();
   136
   137              cout << "\tScarto i " << j << "\n";
   138              libri++;
   139          }
   140      }
   141  }
   142
   143  int Giocatore::checkEnd(){
   144  //  se ha finito le carte la partita è finita
   145      int ended=1;
   146      for (int w=0; w<nCarte; w++)
   147          if (carte[w].getVal()!=0){
   148              ended=0;
   149              break;
   150          }
   151      return ended;
   152  }
   153


Per prima cosa il costruttore della classe inizializza il puntatore a -1.
Sembra strano, ma ciò è in funzione della logica del metodo pushCarta.

Poi il punteggio del giocatore, ovvero la variabile libri, viene inizializzata a 0.

Il metodo getNome() restituisce un puntatore all'array nome[]. Restituire un puntatore ad un dato di un oggetto, forse, non è troppo coerente con la programmazione orientata agli oggetti, ma ricopiare l'intera stringa è troppo dispendioso, in termini di memoria ma anche di lavoro per il programmatore.

Il metodo getLibri() serve per visualizzare il punteggio attuale, ed è usato alla fine del gioco.

Il metodo ask() è usato per chiedere all'utente quale carta vuole chiedere, e controllare che rispetti le regole del gioco.
Ci sono due cicli: come è commentato sul codice, il più esterno controlla che l'utente scelga una carta fra quelle che ha,
mentre il più interno controlla che l'input sia un valore compreso tra 1 e 13 inclusi, e ambedue ripetono la richiesta di input se l'utente non rispetta tali regole. Da notare che, per come è scritto il codice, viene eseguito prima il secondo ciclo (il più interno), e poi il primo (il più esterno).

Il metodo findVal() cerca una carta di un tipo di valore specificato, e restituisce la posizione della prima carta di quel valore che trova, mentre se non ne trova restituisce -1. So bene che in un ciclo o in una istruzione if il valore 0 è considerato falso e ogni valore positivo o negativo (quindi anche -1) è considerato vero, ma non potevo usare 0 come valore di ritorno nel caso che il metodo non trovi la carta specificata, perchè l'array nel quale cerca inizia da 0 e quindi la carta specificata si potrebbe trovare anche nella posizione 0 dell'array.

Il metodo popNcarta() restituisce la carta alla posizione specificata e la toglie dall'array del giocatore. Di solito il parametro passato a questo metodo è restituito dalla funzione findVal.

Il metodo pushCarta() incrementa il puntatore di 1 e aggiunge alla nuova posizione (ovvero quella dove punta il puntatore dopo l'incremento) l'oggetto Carta che il metodo ha ricevuto come argomento.

Il metodo show(), è ovvio, visualizza le carte in possesso del giocatore.

Il metodo scarta() controlla quante carte per ogni tipo di valore possiede il giocatore;
se sono 4, le toglie dall'array delle carte del giocatore e incrementa il valore di libri, che ricordo serve a tenere il conto dei punti fatti dal giocatore.

Infine il metodo checkEnd() controlla che il giocatore abbia ancora qualche carta in mano.
Se il giocatore non ha più carte in mano, la partita è finita e lo comunica restituendo 1.





//  file avversario.h

     1  #ifndef AVVERSARIO_H
     2  #define AVVERSARIO_H
     3
     4  #include <iostream>
     5  using std::cout;
     6  using std::cin;
     7  #include "carta.h"
     8
     9  class Avversario {
    10      public:
    11          Avversario();
    12
    13          void    show();
    14          int findVal(int);
    15
    16          void    pushCarta(Carta);
    17          Carta   popNcarta(int);
    18
    19          int findTrace(int);
    20          void    pushTrace(int);
    21          int popNtrace(int);
    22
    23          void    scarta();
    24          int checkEnd();
    25          int ask();
    26          char*   getName();
    27          int getLibri();
    28
    29      private:
    30          Carta   carte[40];
    31          int nCarte;
    32          char    name[5];
    33          int pnt;
    34
    35          //  tengo traccia delle carte che il giocatore chiede all'avversario,
    36          int trace[30];  //lo limito a 30, e faccio tornare il puntatore a 0
    37          int lenTrace;
    38          int pntTrace;
    39          int libri;
    40  };
    41
42 #endif

La classe Avversario è molto simile alla classe Giocatore.
Di nuovo ci sono i dati che vengono utilizzati per quella che azzardo a definire IA del giocatore, grazie ai quali cerco di stabilire una strategia di gioco.

Questi dati sono l'array di interi trace[], dove memorizzo le richieste di carte che l'utente fa al computer,
il puntatore pntTrace utilizzato per accedere agli elementi di trace[],
e lenTrace, ovvero l'intero che indica il numero di elementi di trace[], che la convenzione ISO mi impedisce di settare a 30 o ad un valore dinamico come sizeof(trace)/sizeof(int), e che quindi inizializzo nel costruttore della classe.

//  file avversario.c

     1  #include "avversario.h"
     2
     3  Avversario::Avversario() {
     4
     5      nCarte=sizeof(carte)/sizeof(Carta);
     6
     7      lenTrace=sizeof(trace)/sizeof(int);
     8      for (int j=0; j<lenTrace; j++)
     9          trace[j]=0; //inizializzo trace a 0
    10
    11      pnt=-1; //  il fatto è che push inserisce una carta a partire da
    12      //  dopo il puntatore, dunque la prima la ficca a zero
    13      //  e non c'è pericolo se le carte vengono
    14      //  messe solo con push...
    15      libri=0;
    16
    17      pntTrace=-1;
    18
    19      name[0]='T';
    20      name[1]='1';
    21      name[2]='t';
    22      name[3]='0';
    23      name[4]='\0';
    24  }
    25
    26  char*   Avversario::getName(){
    27
    28      return name;
    29  }
    30
    31  int Avversario::getLibri(){
    32
    33      return libri;
    34  }
    35
    36
    37  //  ritorna la posizione del primo valore trovato
    38  int Avversario::findVal(int _val){
    39
    40      for (int j=0; j<nCarte; j++){
    41
    42          if (_val == carte[j].getVal())
    43              return j;
    44      }
    45  //  se non la trova
    46      return -1;
    47  }
    48
    49  //  restituisce la carta alla posizione specificata
    50  Carta   Avversario::popNcarta(int _pnt){
    51
    52      Carta tempCarta=carte[_pnt];
    53      carte[_pnt].azzera();
    54
    55      return tempCarta;
    56  }
    57
    58  //  aggiunge una carta
    59  void    Avversario::pushCarta(Carta _card){
    60      pnt++;
    61      carte[pnt] = _card;
    62  }
    63
    64  void    Avversario::show(){
    65
    66      cout << "\n";
    67      int w=0;
    68      for (int j=0; j<nCarte; j++){
    69
    70          //  fa vedere solo le carte che ha
    71          int k = carte[j].getVal();
    72          if (k!=0){
    73              if (w%3==0)
    74                  cout << "\n\t\t\t\t\t";
    75
    76              cout << k << "   " << carte[j].getSeed() << "\t";
    77              w++;
    78          }
    79      }
    80      cout << "\n";
    81  }
    82
    83  void    Avversario::scarta(){
    84
    85  //  per ogni tipo di valore
    86      for (int j=1; j<=13; j++){
    87
    88          int tmp = 0;
    89
    90      //  controlla quante carte di quel tipo ha
    91          for (int k=0; k<nCarte; k++)
    92              if (carte[k].getVal()==j)
    93                  tmp++;
    94
    95      //  se ha tutte le carte di questo valore, scartale
    96          if (tmp==4) {
    97              for (int w=0; w<nCarte; w++)
    98                  if (carte[w].getVal()==j)
    99                      carte[w].azzera();
   100
   101              cout << "\tScarto i " << j << "\n";
   102              libri++;
   103          }
   104      }
   105  }
   106
   107  int Avversario::checkEnd(){
   108  //  se ha finito le carte la partita è finita
   109      int ended=1;
   110      for (int w=0; w<nCarte; w++)
   111          if (carte[w].getVal()!=0){
   112              ended=0;
   113              break;
   114          }
   115      return ended;
   116  }
   117
   118  ////////////////////////////
   119  //      I.A.
   120
   121
   122  //  ritorna la posizione del primo valore trovato fra le carte richieste da Player a Computer
   123  int Avversario::findTrace(int _val){
   124
   125      for (int j=0; j<lenTrace; j++){
   126
   127          if (_val == trace[j])
   128              return j;
   129      }
   130  //  se non la trova
   131      return -1;
   132  }
   133
   134  //  memorizza l'ultima carta richiesta da Player a Computer
   135  void    Avversario::pushTrace(int _val){
   136
   137      if (pntTrace<(lenTrace-1))
   138          pntTrace++; //scrivo sulla prossima posizione
   139      else
   140          pntTrace=0; //me se l'array è finito ricomincio da 0
   141
   142      trace[pntTrace] = _val;
   143  }
   144
   145  //  restituisce la carta alla posizione specificata fra quelle
   146  //  richieste da Player a Computer
   147  int Avversario::popNtrace(int _pnt){
   148
   149      int temp=trace[_pnt];
   150      trace[_pnt]=0;
   151
   152      return temp;
   153  }
   154
   155  //  restituisce la carta da chiedere a Player
   156      int Avversario::ask(){
   157
   158      int count[14]={0};  //count[0] resta inutilizzato
   159      int best=0;
   160      int max=0;
   161  //  per ogni tipo di valore
   162      for (int tipo=1; tipo<=13; tipo++){
   163
   164          int tmp=0;
   165      //  controlla quante carte di quel tipo ha
   166          for (int k=0; k<nCarte; k++){
   167              if (carte[k].getVal()==tipo)
   168                  tmp++;
   169          }
   170          count[tipo]=tmp;    //memorizza i valori
   171
   172      //  se questa carta che ho me l'ha chiesta anche il giocatore
   173      //  e ce ne ho in maggior numero della best precedente
   174          if(findTrace(tipo)!=-1 && count[best]<tmp){
   175              best=tipo;
   176          }
   177
   178      //  se count[0] era utilizzato questa istruzione dava problemi, perchè max all'inizio è =0
   179          if (count[max]<tmp)
   180              max=tipo;   //memorizza la carta che ho in maggior numero
   181
   182
   183      //  cout << tipo << ")\tmax: " << max << "\tbest: " << best << "";
   184      //  cout << "\tfind:  " << findTrace(tipo) << "\tcount[tipo]: " << count[tipo] << "\tcount[best]: " << count[best] << "\n";
   185
   186
   187      }
   188      //for (int z=0; z<lenTrace; z++)
   189      //  cout << trace[z] << "\n";
   190
   191      //  se con quel sistema non si è potuto scegliere una carta,
   192      //  chiede quella che ha in maggior numero
   193      if (best==0)
   194          best=max;
   195
   196      return best;
   197  }
   198  ////////////////////////////
   199


Anche l'implementazione dei metodi della classe Avversario è simile a quella della classe Giocatore.
Nel costruttore le uniche differenze con Giocatore è nell'inizializzazione dell'array nome[] e delle proprietà usate per l'IA,
ovvero lenTrace che viene inizializzato dinamicamente a seconda del numero degli elementi dell'array trace[], e gli elementi dell'array trace[] che vengono inizializzati tutti a 0.

Un altro metodo non presente nella classe Giocatore è findTrace(), ma come è intuibile funziona come findVal(), e cioè restituisce il primo valore che trova nell'array trace[].

Il metodo pushTrace() funziona simile a pushCarta(): se il puntatore corrente è minore di (lenTrace-1) incrementa il puntatore, altrimenti vuol dire che è finito lo spazio disponibile in trace[] e quindi impostando il puntatore a 0 ricomincia a scrivere dal primo elemento dell'array.
Diversamente dall'array delle carte, l'array trace[] memorizza le richieste che il giocatore fa all'avversario (poi vedremo per quale scopo); questo significa che se il giocatore è sfortunato e non indovina mai le carte che ha l'avversario, la partita può dilungarsi e le richieste del giocatore possono superare la grandezza dell'array trace. Viene controllato che il puntatore sia minore di lenTrace-1, invece di lenTrace, perchè il puntatore passa dai valori 0 fino a lenTrace-1; esempio: lenTrace è uguale a 5, il puntatore è uguale a 4; if(pntTrace<lenTrace) restituirebbe vero, dunque il puntatore sarebbe incrementato a 5 ed il valore verrebbe scritto su trace[5], mentre l'indice di un array di 5 elementi varia da 0 a 4.

Il metodo popNtrace() è praticamente uguale a popNcarta(), solo che estrae un valore in una determinata posizione dall'array trace[] invece dell'array carte[].

Il metodo ask() è quello che, in modo più o meno logico, permette all'avversario di scegliere una determinata carta da chiedere al giocatore.
Questo metodo prende in considerazione due array: l'array delle carte possedute dal computer (carte[]) e l'array di carte richieste dal giocatore (trace[]);
viene eseguito un loop: per ogni tipo di carta controlla quante carte di quel tipo si possiedono e memorizza i risultati nell'array count[14].
Il primo elemento di questo array è vuoto, mentre per ogni elemento successivo (dopo il ciclo precedente che confronta i due array) questo array contiene il numero delle carte di quel valore in possesso (ad esempio se si hanno 3 assi e 1 due il risultato è count[0]=0 count[1]=3 e count[2]=1).
Dopodichè il metodo controlla se quel tipo di valore è fra quelli richiesti dal giocatore (cioè li cerca nell'array trace[]).

Il risultato è che se vengono trovate una o più carte fra quelle dentro l'array trace[] che si trovano anche fra le carte del computer, il metodo restituisce il tipo di valore fra queste carte che si hanno in maggior numero, altrimenti restituisce semplicemente il valore di carta che il computer ha in numero maggiore.
E' complicato, lo so (l'ho scritto io!)...
un paio di esempi sono d'obbligo:
    caso 1)
fra le carte del computer ci sono 3 assi e 1 due, oltre ad altre carte che non ci interessano;
fra le carte chieste dall'utente al computer ci sono asso e due, oltre ad altre;
in questo caso il metodo restituisce uno,
ovvero una carta che l'utente ha (altrimenti perchè l'ha chiesta al giocatore?), che allo stesso tempo ha anche il computer (e dunque secondo le regole la può chiedere), e fra le carte che rispettano quest'ultima condizione, l'asso è quella che computer ha in maggior numero
(nell'esempio di prima anche il due era una carta sicura da chiedere, ma è meglio chiedere l'asso perchè se ne hanno già tre!)
    caso 2)
fra le carte del computer non c'è neanche una carta fra quelle che l'utente ha chiesto;
in questo caso qualsiasi carta va bene, e il metodo restituisce il valore più frequente fra le sue carte
(se ha 2 quattro, 3 cinque e 1 sette il metodo restituisce cinque)





//  file partita.h

     1  #ifndef PARTITA_H
     2  #define PARTITA_H
     3
     4  #include <iostream>
     5  using std::cout;
     6  using std::cin;
     7  #include "mazzo.h"
     8  #include "giocatore.h"
     9  #include "avversario.h"
    10
    11  class Partita {
    12      public:
    13          Partita();
    14
    15          void    Distr();
    16          void    Start();
    17          void    End();
    18
    19      private:
    20          Giocatore   Player;
    21          Avversario  Computer;
    22          Mazzo       Pack;
    23  };
    24
25 #endif

La classe partita è semplice, contiene come dati membro il mazzo e i due giocatori necessari per fare una partita a carte.

//  file partita.c

     1  #include "partita.h"
     2
     3  Partita::Partita() {
     4
     5  //  stampa messaggio di benvenuto...
     6      cout << "\033[H\033[J\n\n\n\t\t\tGoFish!\n";
     7
     8  //  distribuisci carte
     9      Distr();
    10
    11  //  inizia il gioco
    12      Start();
    13  }
    14
    15  //  distribuisci carte
    16  void Partita::Distr(){
    17
    18
    19  //  per 14 carte del mazzo (7 per ciascuno)
    20  //  a partire dalla Pack.pnt
    21      int pnt = Pack.getPnt();
    22
    23      for (int j=pnt; j>pnt-14; j--){
    24
    25      //  se è pari
    26          if (j%2==0){
    27
    28          //  dai la carta al player
    29          //  e levala dal mazzo
    30              Player.pushCarta (Pack.popCarta());
    31
    32
    33      //  altrimenti
    34          }else{
    35
    36          //  dai la carta al player
    37          //  e levala dal mazzo
    38              Computer.pushCarta (Pack.popCarta());
    39          }
    40      }
    41  }
    42
    43  //  inizio la partita...
    44  void Partita::Start(){
    45
    46          //  questa parte si potrebbe implementare in un metodo
    47          //  specifico (= probab. non riutilizzabile)
    48          //  di nome gofish, tanto per levarlo da qui...
    49
    50  //  il loop continua finché la partita non è finita
    51  //  il controllo viene effettuato durante il gioco,
    52  //  ogni volta che uno dei giocatori scarta...
    53      while (true){
    54
    55          cout << "\n";
    56          //cout << "\033[H\033[J";
    57
    58          //////////////////////////////////
    59          //              //
    60          //  tocca a Player      //
    61          //              //
    62          //////////////////////////////////
    63
    64          cout << "\n\n\n------------------------------" << Player.getName() << "-------------------------Libri: " << Player.getLibri() << "\n";
    65
    66          int find;   //  mi serve anche dopo il prossimo blocco
    67          //  Player chiede un'altra carta se indovina la prossima carta del mazzo
    68          do {
    69
    70              cout << "\n\tChiedi una carta all'avversario:\n";
    71              //Pack.show();      //  ?debug
    72              //Computer.show();  //  ?debug
    73              Player.show();
    74
    75              int val = Player.ask();
    76              find = Computer.findVal(val);
    77          //  comunico all'IA di Computer
    78          //  quale carta Player gli abbia chiesto
    79              Computer.pushTrace(val);
    80
    81          //  Player chiede un'altra carta se ne ha chiesta una che Computer ha
    82              while(find!=-1){
    83
    84              //  Computer passa a Player la carta
    85                  Player.pushCarta(Computer.popNcarta(find));
    86              //  scarta se possibile
    87                  Player.scarta();
    88
    89              //  se un dei due è rimasto senza carte, la partita è finita
    90                  if (Player.checkEnd() || Computer.checkEnd())
    91                      End();
    92
    93                  cout << "\a\n\t\t\t\t\tCe l'ho!\n";
    94                  cout << "Chiedi un'altra carta\n";
    95                  //Pack.show();      //  ?debug
    96                  //Computer.show();  //  ?debug
    97                  Player.show();
    98
    99                  val = Player.ask();
   100                  find = Computer.findVal(val);
   101
   102              //  comunico all'IA di Computer
   103              //  quale carta Player gli abbia chiesto
   104                  Computer.pushTrace(val);
   105              }
   106
   107              cout << "\n\t\t\t\t\tGoFish!\n";
   108
   109          //  prendi una carta dal mazzo
   110              Carta dalMazzo = Pack.popCarta();
   111              Player.pushCarta(dalMazzo);
   112
   113          //  scarta se possibile
   114              Player.scarta();
   115
   116          //  se Player è rimasto senza carte, la partita è finita
   117              if (Player.checkEnd())
   118                  End();
   119
   120          //  se ha il valore di quella chiesta a Computer
   121              if (dalMazzo.getVal()==val) {
   122
   123                  //Pack.show();      //  ?debug
   124
   125                  cout << "\a\nHai pescato la carta che hai chiesto!\n";
   126
   127              //  chiedi di nuovo una carta a Computer
   128                  find=0;
   129
   130                  //Computer.show();      //  ?debug
   131                  //Player.show();        //  ?debug
   132                  cout << "\n";
   133              }
   134
   135          }while (find>=0);
   136
   137
   138          //////////////////////////////////
   139          //              //
   140          //  tocca a Computer    //
   141          //              //
   142          //////////////////////////////////
   143
   144          cout << "\n\n\n------------------------------" << Computer.getName() << "-----------------------Libri: " << Computer.getLibri() << "\n";
   145
   146          int findComp;   //  mi serve anche dopo il prossimo blocco
   147      //  Computer chiede un'altra carta se indovina la prossima carta del mazzo
   148          do {
   149
   150              //Pack.show();          //  ?debug
   151              //Computer.show();      //  ?debug
   152              Player.show();
   153              int asked=Computer.ask();
   154
   155              cout << "\n\t\t\t\t\tTi chiedo un " << asked << "\nPremi [invio] per continuare...\n";
   156              char null[10];      //  pausa
   157              cin.getline(null,10);   //  pausa
   158
   159              findComp = Player.findVal(asked);
   160
   161          //  Computer chiede un'altra carta se ne ha chesta una che Player ha
   162              while(findComp!=-1){
   163
   164              //  Player passa a Computer la carta
   165                  Computer.pushCarta(Player.popNcarta(findComp));
   166
   167              //  scarta se possibile
   168                  Computer.scarta();
   169
   170              //  se un dei due è rimasto senza carte, la partita è finita
   171                  if (Computer.checkEnd() || Player.checkEnd())
   172                      End();
   173
   174                  //Pack.show();      //  ?debug
   175                  //Computer.show();  //  ?debug
   176                  cout << "\a\n\t\t\t\t\tC'e l'hai!\n";
   177                  Player.show();
   178                  cout << "\n";
   179
   180
   181                  asked=Computer.ask();
   182
   183                  cout << "\n\t\t\t\t\tTi chiedo un " << asked << "\nPremi [invio] per continuare...\n";
   184                  char null[10];      //  pausa
   185                  cin.getline(null,10);   //  pausa
   186
   187                  findComp = Player.findVal(asked);
   188              }
   189
   190          //  se computer non ha indovinato una carta di Player,
   191          //  è possibile che Player abbia avuto e poi finito le carte di quel tipo
   192          //  dunque per l'IA di Computer è meglio togliere queste carte dalla lista
   193          //  delle carte che Computer pensa siano in possesso di Player
   194
   195              int posT = Computer.findTrace(asked);       //cerca la carta richiesta dal computer sulla sua lista
   196
   197              while (posT!=-1){               //finché ne trova una
   198                  Computer.popNtrace(posT);       //la leva dalla lista
   199                  posT = Computer.findTrace(asked);   //cerca la prossima carta dello stesso tipo
   200              }
   201              cout << "\nNiente.\t\t\t\tPesco dal mazzo\n";
   202
   203          //  prendi una carta dal mazzo
   204              Carta dalMazzoC = Pack.popCarta();
   205              Computer.pushCarta(dalMazzoC);
   206
   207          //  scarta se possibile
   208              Computer.scarta();
   209
   210          //  se Computer è rimasto senza carte, la partita è finita
   211              if (Computer.checkEnd())
   212                  End();
   213
   214          //  se ha il valore di quella chiesta a Player
   215              if (dalMazzoC.getVal()==asked) {
   216                  //Pack.show();      //  ?debug
   217
   218                  cout << "\a\n\t\t\t\t\tHo pescato la carta che ho chiesto!\n";
   219
   220              //  chiedi di nuovo una carta a Player
   221                  findComp=0;
   222
   223                  //Computer.show();      //  ?debug
   224                  //Player.show();        //  ?debug
   225              }
   226
   227          }while(findComp>=0);
   228      }
   229  }
   230
   231
   232
   233  void    Partita::End(){
   234
   235      int p=Player.getLibri();
   236      int c=Computer.getLibri();
   237
   238      if (p>c){
   239          cout << "\a\n\n\n";
   240          cout << Player.getName();
   241          cout << ", hai vinto!\n";
   242          cout << "hai collezionato " << p << " libri contro " << c << " di ";
   243          cout << Computer.getName();
   244          cout << "\n";
   245      }else if (p<c){
   246          cout << "\a\n\n\n\t\t\t\t\t" << "Hai perso!\n";
   247          cout << Computer.getName();
   248          cout << " ha collezionato " << c << " libri contro i tuoi " << p << "\n";
   249      }else{
   250          cout << "\a\n\n\n" << "E' patta:\n";
   251          cout << " avete collezionato " << p << " libri ciascuno.\n";
   252      }
   253
   254      exit (0);
   255  }
   256


Nel costruttore della classe partita vengono chiamati due metodi di Partita.
Il metodo Distr() distribuisce 14 carte, 7 carte ciascuno alternate.

Nel metodo Start() si svolge l'intera partita, in un ciclo continuo (while(true)) che alterna il gioco dell'utente e del computer.
Nel gioco dell'utente c'è un altro ciclo nel quale, dopo aver stampato a schermo le carte dell'utente, gli viene chiesto di scegliere una carta:
finché questo sceglie una carta che il computer ha, oppure finché la carta scelta viene pescata dal mazzo, il calcolo viene ripetuto e viene chiesto all'utente di scegliere un'altra carta. Da notare che ogni carta che l'utente inserisce viene riferita al computer, che la memorizza nel suo array trace[] che userà per stabilire una strategia di gioco.
Quando l'utente indovina una carta che l'avversario ha, questa carta viene passata dall'avversario all'utente, e viene chiamato il metodo Player.Scarta() che se è il caso penserà a scartare le carte secondo le regole del gioco; quindi viene controllato che i giocatori abbiano ancora carte usando if(Player.checkEnd() || Computer.checkEnd()): se scartando l'utente finisce le carte il metodo Player.checkEnd() restituisce 1, oppure se dando la carta che l'utente ha chiesto il computer rimane senza carte il metodo Computer.checkEnd() restituisce 1; in ambedue i casi viene chiamato il metodo End() che provvederà a contare i punti e a terminare il programma.
Quando l'utente non ha indovinato una delle carte che ha il computer, pesca una carta e viene chiamato nuovamente il metodo Player.Scarta() e ovviamente anche il metodo Player.checkEnd()il quale, nel caso l'utente scartando sia rimasto senza carte, chiama il metodo End() che termina la partita.
Dopodichè, se la carta pescata è uguale a quella richiesta dall'utente, viene ripetuto il ciclo e viene chiesta una nuova carta all'utente, altrimenti il controllo passa al computer.

Lo stesso vale per il computer: gli viene chiesta una carta e finché questa è fra quelle dell'utente, o è dello stesso valore di quella che pesca nel mazzo, chiede altre carte all'utente e scarta, e quando non indovina il controllo passa nuovamente al giocatore.





//  file goFish.c

     1  #include <iostream>
     2  #include <cstdlib>
     3
     4  #include "carta.h"
     5  #include "mazzo.h"
     6  #include "giocatore.h"
     7  #include "avversario.h"
     8  #include "partita.h"
     9
    10
    11  using std::cout;
    12  using std::cin;
    13
    14  int main(){
    15
    16      Partita Game;
    17
    18      return 0;
    19  }
    20

Come è evidente, il programma dichiara soltanto un oggetto di tipo Partita e di nome Game,
dunque il controllo passa al costruttore di Game, dove inizierà il gioco.



## License

![Alt text](/doc/README.md/COPYING.png?raw=true "License")

This project is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
