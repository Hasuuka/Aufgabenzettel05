#include "calculatetrafficfines.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

CalculateTrafficFines::CalculateTrafficFines()
{

}
/**
 * Takes all the fines and divides them by the number of fines
 * @returns double value with the average fine
 * @throws runtime_error if the average is above 30
 */
double CalculateTrafficFines::averageFine(){
    double avg = 0.0;

    list<Tatbestand> tatenCopy = m_taten;

    while(tatenCopy.size() > 0){
        //cout << "Avg: " << tatenCopy.front().geldbusse << endl;

        avg += tatenCopy.front().geldbusse; // string to double
        tatenCopy.pop_front();
    }

    avg /= m_taten.size();

    if(avg > 30){
        throw std::runtime_error("avg is above 30");
    }

    return avg;
}
/**
 * reads a csv file with entries above fines
 * every line is a fine which gets added to a list of fines
 * in the CalculateTrafficFines class
 * checks if a line has 6 or 8 values
 * and ignores the headline
 * @throws runtime_error if the file could not be opened
 */
void CalculateTrafficFines::readCSV(){

    string filename("D:\\Uni\\Semester 3\\MMI & GUI\\Abgabe5\\A2\\Aufgabenzettel05\\BussgelderFliessverkehrJanuar2020.csv");
    ifstream file;

    file.open(filename);
    if(file.is_open() != true){
        throw std::runtime_error("file could not be opened");
    }
    string line="";
    string conversionHelper = ""; // used to convert string with ,, at the end to int
    int lineCounter = 0;
    while(getline(file, line))
    {
        lineCounter++;
        if(lineCounter < 2){
            continue;
        }

        size_t pos = 0;

        //check for occurence of ;
        // 5x; and 7x; needs to be handled differently
        size_t trennzeichenCounter = std::count(line.begin(), line.end(), ';');

        int counter = 0; //
        string ortHelper = ""; // string to build "ort"
        Tatbestand lineTat; // elements that gets added to the list

        if(trennzeichenCounter == 5){
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
                    conversionHelper = line.substr(0, pos);
                    conversionHelper.pop_back(); // remove comma
                    conversionHelper.pop_back(); // remove comma
                    lineTat.geldbusse = stoi(conversionHelper);
                    break;
                }
                line.erase(0, pos + trennzeichen.length());
                counter++;
            }
        }else{
            while ((pos = line.find(trennzeichen)) != string::npos) {
                switch(counter){
                case 0: //tag
                    lineTat.tag = line.substr(0, pos);
                    break;
                case 1: //zeit
                    lineTat.zeit = line.substr(0, pos);
                    break;
                case 2: // ort 1-3
                    ortHelper = line.substr(0, pos);
                    line.erase(0, pos + trennzeichen.length());
                    ortHelper += ", " + line.substr(0, pos);
                    line.erase(0, pos + trennzeichen.length());
                    ortHelper += ", " + line.substr(0, pos);
                    line.erase(0, pos + trennzeichen.length());
                    break;
                case 3: //ort 4
                    lineTat.ort = ortHelper + ", " + line.substr(0, pos);
                    break;
                case 4: //tatbestand + geldbusse
                    lineTat.tatbestand = line.substr(0, pos);
                    line.erase(0, pos + trennzeichen.length());
                    conversionHelper = line.substr(0, pos);
                    conversionHelper.pop_back(); // remove comma
                    conversionHelper.pop_back(); // remove comma
                    lineTat.geldbusse = stoi(conversionHelper);

                    // fallback to avoid errors
                    if(lineTat.geldbusse > 1000){
                        lineTat.tatbestand = line.substr(0, 6);
                        line.erase(0, 7);
                        conversionHelper = line.substr(0, pos);
                        conversionHelper.pop_back(); // remove comma
                        conversionHelper.pop_back(); // remove comma
                        lineTat.geldbusse = stoi(conversionHelper);
                    }
                    break;
                }
                line.erase(0, pos + trennzeichen.length());
                counter++;
            }
        }

        m_taten.insert(m_taten.begin(), lineTat);
    }

    cout << "Anzahl der Taten: " << m_taten.size() << endl;

    file.close();

}



