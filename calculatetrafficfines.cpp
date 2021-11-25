#include "calculatetrafficfines.h"
#include <iostream>
#include <fstream>

CalculateTrafficFines::CalculateTrafficFines()
{

}

void CalculateTrafficFines::readCSV(){

    string filename("D:\\Uni\\Semester 3\\MMI & GUI\\Abgabe5\\A2\\Aufgabenzettel05\\BussgelderFliessverkehrJanuar2020.csv");
    ifstream file;
        file.open(filename, ios::in);
        if(file.is_open() != true){
            cerr << "Fehler beim Lesen!" << endl;
            file.close();
        }

        string line="";
        while(getline(file, line))
        {
            size_t pos = 0;
            int counter = 0;
            string ortHelper = "";
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
                    ortHelper = line.substr(0, pos);
                    break;
                case 3:
                    lineTat.ort = ortHelper + ", " + line.substr(0, pos);
                    break;
                case 4:
                    lineTat.tatbestand = line.substr(0, pos);
                    line.erase(0, pos + trennzeichen.length());
                    lineTat.geldbusse = line.substr(0, pos);
                    lineTat.geldbusse.pop_back(); // remove comma
                    lineTat.geldbusse.pop_back(); // remove comma
                    break;
                }
                line.erase(0, pos + trennzeichen.length());
                counter++;
            }

            m_taten.insert(m_taten.begin(), lineTat);
        }

    cout << m_taten.size() << endl;

    file.close();
}
