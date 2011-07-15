/*###############################################################################
  Kodierung: UTF-8 ohne BOM
###############################################################################*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "eingaben.h"
#include "tilgung.h"

#include "eingaben.c"
#include "tilgung.c"

//###############################################################################
/**
  Das Programm dient der Erstellung eines Tilgungsplanes für die Tilgung
  von Krediten mittels nachschüssiger Annuitäten.

  @author Thomas Gerlach
  @version 1.0 
**/
//###############################################################################
int main(void)
{
  do {

    system("clear");
    printf("\n\n\tT i l g u n g s p l a n\n\n");
    printf("Das Programm dient der Erstellen eines Tilgungsplanes für die \nTilgung von Krediten mittels nachschüssiger Annuitäten.\n\n");

    double kredit = erfasse_gleitzahl("Bitte die Kreditsumme in Euro eingeben", 1.00, 100000000.00);
    double zinsen = erfasse_gleitzahl("Bitte die Zinsen in Prozent eingeben", 0.10, 20.00);
    int laufzeit = erfasse_ganzzahl("Bitte die Laufzeit in Jahre eingeben", 1, 100);

    schreibe_tilgung(kredit, zinsen, laufzeit);    

  } while (erfasse_antwort("Noch einmal? (j/n)"));

  printf("\n\n\tAuf Wiedersehen!\n\n");
}
