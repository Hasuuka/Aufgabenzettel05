#include "calculatetrafficfines.h"
#include <iostream>
#include <fstream>
#include <vector>


CalculateTrafficFines::CalculateTrafficFines()
{

}

void CalculateTrafficFines::readCSV(){

    string filename("test.csv");
    vector<char> bytes;

    data1 = fopen(filename.c_str(),"r");
    if(data1 == nullptr)
    {
        fprintf(stderr, "Fehler beim Oeffnen der Datei!\n");
        exit(EXIT_FAILURE);
    }

    unsigned char character = 0;
       while (!feof(data1)) {
          character = getc(data1);
          cout << character << "-";
       }
       cout << endl;
       fclose(data1);


}
