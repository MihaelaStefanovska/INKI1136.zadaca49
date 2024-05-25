// INKI1136.zadaca49.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <map>
#include <iostream>
using namespace std;

void pecatiSortiranaMapaPoTemperaturi(map<string, int>& temp0606) {

    //Mapite avtomatski sortiraat po kluc, iskoristuvame mapa kade shto kluc ke bidi temperaturata, a vrednost - ime na grad.
    //Podatocite ke ni bidat sortirani po temperatura.
    //multimap dozvoluva mapa so poveke isti klucevi, ja koristime nea zatoa shto mozhe dva ili poveke gradovi da imaat ista temperatura.
    multimap<int, string> mm;

    //Vnesi gi podatocite od originalnata mapa vo novata:
    for (auto& it : temp0606) {
        mm.insert({ it.second, it.first });
    }
    // Pechati ja sortiranata mapa:
    for (auto& it : mm) {
        cout << it.second << ' ' << it.first << endl;
    }

}
int main()
{
    map<string, int> temp0606;
    temp0606["Skopje"] = 32;
    temp0606["Kumanovo"] = 32;
    temp0606["Bitola"] = 25;
    temp0606["Prilep"] = 26;
    temp0606["Ohrid"] = 31;
    temp0606["Struga"] = 30;
    temp0606["Kicevo"] = 27;
    temp0606["Tetovo"] = 37;
    temp0606["Gevgelija"] = 42;
    temp0606["Strumica"] = 38;

    cout << "Dali sakate da vnesete gradovi so temperatura ili da gi iskoristite postoechkite gradovi vo programata?\n";
    cout << "Za vnes napishete: da\n";
    string vnes;
    cin >> vnes;
    bool vnesi = false;
    if (vnes.compare("da") == 0) {
        vnesi = true;
    }
    
    if (vnesi) {
        //Isprazni ja mapata, korisnikot sam ke si vnesi podatoci:
        temp0606.clear();
        int temperatura; //Pomoshna varijabla za vnes na temperatura, za ime na grad ke ja reiskoristime string vnes varijablata.
        while (true) {
            cout << "Vnesi ime na grad ili kraj za da prestanite so vnesuvanje\n";
            cin >> vnes;
            if (vnes.compare("kraj") == 0) {
                break;
            }
            cout << "Vnesi temperatura vo gradot\n";
            cin >> temperatura;
            //Vnesi vo mapata kluc - ime na grad i vrednost - temperatura:
            temp0606[vnes] = temperatura;
        }
    }
    string porakaZaPecatenjeNaMapata = vnesi ? "Mapata so gradovi shto ja vnesovte izgleda vaka" : "Mapata so gradovi izgleda vaka";
    cout << "\n--- " << porakaZaPecatenjeNaMapata << " ---\n";
    for (auto& it : temp0606) {
        cout << it.first << " " << it.second << "\n";
    }

    cout << "\n--- Pechatenje na sortirana mapa po temperaturi ---\n";
    pecatiSortiranaMapaPoTemperaturi(temp0606);
    //Spored baranjata na krajot, vo mapata se dodavaat broj na indeks i ime na student so datum na raganje:
    temp0606["Inki"] = 1136;
    temp0606["Mihaela"] = 2510;
}