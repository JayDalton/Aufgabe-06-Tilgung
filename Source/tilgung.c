//###############################################################################
/** 
  Berechnet die Annuität mittels der uebergebenen Werte für Kredit, Zinsen und
  Laufzeit. Liefert die Annuität als Gleitzahl.
  
  @param  kredit  Höhe des Kredit
  @param  zinsen  Prozentsatz der Zinsen
  @param  laufzeit  Laufzeit in Jahren
  
  @return Berechnete Annuität
**/
//###############################################################################
double ermittle_annuitaet(double kredit, double zinsen, int laufzeit)
{
  double zins = (1 + zinsen / 100);
  double lauf = pow(zins, laufzeit);
  
  return kredit * lauf * ( (zins - 1) / (lauf - 1) );
}

//###############################################################################
/** 
  Berechnet die Tilgung über die Laufzeit und gibt das Ergebnis tabellarisch in
  der Standardausgabe aus.
  
  @param  kredit  Höhe des Kredit
  @param  zinsen  Prozentsatz der Zinsen
  @param  jahre  Laufzeit in Jahren
**/
//###############################################################################
void schreibe_tilgung(double kredit, double zinsen, int jahre)
{
  double zinssatz = zinsen / 100;
  double annuitat = ermittle_annuitaet(kredit, zinsen, jahre);
  
  double kredit_a = kredit;
  double zinswert = 0;
  double tilgung = 0;
  double kredit_e = 0;
  double aufwand = 0;
  
  system("clear");

  printf("\nTilgungsplan bei der Tilgung mit nachschuessigen Annuitaeten.\n");
  
  printf("\n%s: %12.2lf Euro %13s: %3.1lf %% %10s: %3d\n", 
    "Kredit", kredit, "Zinssatz", zinsen, "Jahre", jahre
  );
  
  printf("\n%5s%12s%12s%12s%12s%12s\n", 
    "Jahr", "Kredit A", "Zinsen", "Tilgung", "Annuität", "Kredit E"
  );
  
  for (int jahr = 1; jahr <= jahre; jahr++)
  {
    zinswert = kredit_a * zinssatz;
    aufwand += zinswert;
    tilgung = annuitat - zinswert;
    kredit_e = kredit_a - tilgung;
    printf("\n%5d%12.2lf%12.2lf%12.2lf%12.2lf%12.2lf", 
      jahr, kredit_a, zinswert, tilgung, annuitat, kredit_e
    );
    kredit_a = kredit_e;
  }
  
  printf("\n\n%5s %12.2lf Euro\n", "Gesamtaufwand:", kredit + aufwand);
}

