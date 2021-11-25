#include "calculatetrafficfines.h"
#include <iostream>
#include <fstream>
#include <vector>


CalculateTrafficFines::CalculateTrafficFines()
{

}

void CalculateTrafficFines::readCSV(){

    string filename("/Users/battleranger/Documents/C++-Projekte/Aufgabenzettel05/test.csv");
    vector<char> bytes;

    data1 = fopen(filename.c_str(),"r");
    if(data1 == nullptr)
    {
        fprintf(stderr, "Fehler beim Oeffnen der Datei!\n");
        exit(EXIT_FAILURE);
    }

    string line="Tattag;Zeit;Tatort;Tatort 2;Tatbestand;Geldbuße,,";

    size_t pos = 0;
    int counter = 0;
    string sign;
    Tatbestand lineTat;

    while ((pos = line.find(trennzeichen)) != string::npos) {
        switch(counter){
        case 0:
            lineTat.tag = line.substr(0, pos);
            break;
        case 1:
            lineTat.zeit = line.substr(0, pos);
            break;

        case 2:
            lineTat.ort = line.substr(0, pos);
            break;
        case 3:
            lineTat.tatbestand = line.substr(0, pos);
            line.erase(0, pos + trennzeichen.length());
            lineTat.geldbusse = line.substr(0, pos);
            break;
        case 4:
            lineTat.geldbusse = line.substr(0, pos);
            break;
        }

        line.erase(0, pos + trennzeichen.length());
        counter++;
    }
    cout << lineTat.tag
            << lineTat.zeit
               << lineTat.ort
                  << lineTat.tatbestand
                  << lineTat.geldbusse
         << endl;


    fclose(data1);


}
