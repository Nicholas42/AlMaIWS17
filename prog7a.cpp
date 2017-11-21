#include <iostream>


// naive Berechnung, häufige Aufrufe von naivFib -> exponentielle Laufzeit
int naivFib(int n){
	if (n<=1){
		return 1;
	}
	return naivFib(n-1)+naivFib(n-2);
}


// Durch Zwischenspeichern der letzten Werte lineare Laufzeit
/*
Beispielaufruf:
besserFib(5, 1, 1) 
-> besserFib(4, 2, 1)
  -> besserFib(3, 3, 2)
    -> besserFib(2, 5, 3)
      -> besserFib(1, 8, 5)
		returnt 8
      <- 8
    <- 8
  <- 8
<- 8
//*/
int besserFib(int n, int letzte, int vorletzte){
	if(n <= 1){
		return letzte;
	}
	else
	{
		return besserFib(n-1, letzte+vorletzte, letzte);
	}
}


// Behält alle Zahlen im Speicher und addiert stets die beiden letzten
// Gibt in linearer Laufzeit alle Fibonaccizahlen bis zur n-ten zurück
void gutFib(int* zahlen, int n, int bisher){
	if (bisher <= n){
		if(bisher <= 1){
			zahlen[bisher] = 1;
		}
		else{
			zahlen[bisher] = zahlen[bisher-1] + zahlen[bisher-2];
		}
		gutFib(zahlen, n, bisher + 1);
	}
}

int main(){
	int grenze = 10;
	int *zahlen = new int[10];
	int *zahlen2 = new int[10];
	// Rufe für alle Fibonaccizahlen einmal besserFib auf
	// -> n*(n-1)/2 aufrufe insgesamt -> quadratische Laufzeit
	for (int i = 0; i < grenze; i++){
		zahlen2[i] = besserFib(i, 1, 1);
	}
	gutFib(zahlen, grenze, 0);
	for (int i = 0; i < grenze; i++){
		// Ausgabe, natrülich geben beide das gleich zurück.
		std::cout << i << "\t" << zahlen2[i] << "\t" << zahlen[i] << std::endl;
	}	
	return 0;
}
