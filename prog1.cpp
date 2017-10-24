#include <iostream>
#include <string>

using namespace std;

int main(){
  std::cout << "Bitte Vornamen eingeben:" << std::endl;
  std::string vorname;
  std::getline(std::cin, vorname);
  std::cout << "Bitte Geburtsdatum eingeben (DD.MM.YYYY):" << std::endl;
  int tag, monat, jahr;
  char d1;
  std::cin >> tag >> d1 >> monat >> d1 >> jahr;
  std::cout << vorname << " ist am " << tag << "." << monat << "." << jahr<< " geboren." << std::endl;
  std::cout << "Das Geburtsjahr ist ";
  if(jahr%4 == 0 && (jahr%400 == 0 || jahr%100 != 0)){
    std::cout << "ein ";
  }
  else{
    std::cout << "kein ";
  }
  std::cout << "Schaltjahr." << std::endl;
  return 0;
}
