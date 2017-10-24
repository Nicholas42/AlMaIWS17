#include <iostream>
#include <string>

using namespace std;

int main(){
	cout << "Bitte Vornamen eingeben:" << endl;
	string vorname;
	cin >> vorname;
	cout << "Bitte Geburtsdatum eingeben:" << endl;
	int tag, monat, jahr;
	cout << "Tag:" << endl;
	cin >> tag;
	cout << "Monat:" << endl;
	cin >> monat;
	cout << "Jahr:" << endl;
	cin >> jahr;
  	cout << vorname << " ist am " << tag << "." << monat << "." << jahr<< " geboren." << endl;
	if(jahr%4 == 0){
	  cout << "Das Geburtsjahr ist ein Schaltjahr." << endl;
	}
	else
	{
	  cout << "Das Geburtsjahr ist kein Schaltjahr." << endl;
	}
	return 0;
}
