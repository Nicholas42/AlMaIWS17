#include <iostream>

// https://de.wikipedia.org/wiki/Sieb_des_Eratosthenes

int main(){
  unsigned int n;
  std::cout << "Grenze?" <<std::endl;	
  std::cin >> n;
  
  bool *gestrichen = new bool[n+1];
  
  // Zu Beginn ist keine Zahl gestrichen
  for(int i = 0; i <= n; i++){
    gestrichen[i] = false;
  }
  
  //Nun gehen wir alle Zahlen ab 2 durch
  for(int i = 2; i*i <= n; i++){
    // Sollte die Zahl noch gestrichen sein, ist sie prim
    if(!(gestrichen[i])){
      // also geben wir sie aus
      std::cout << i << std::endl;
      // und streiche alle Vielfachen dieser Zahl
      for(int j = i; i*j <= n; j++){
	// hierbei beginnen wir bei i^2, da alle vorherigen Vielfachen
	// von i schon vorher gestrichen wurden.
	gestrichen[i*j] = true;
      }
    }
  }
  return 0;
}
