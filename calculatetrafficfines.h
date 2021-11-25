#ifndef CALCULATETRAFFICFINES_H
#define CALCULATETRAFFICFINES_H
#include <string>

using namespace std;

struct Tatbestand{
    string tag;
    string zeit;
    string ort;
    int geldbusse;
    int tatbestand;
};

class CalculateTrafficFines
{
public:
    CalculateTrafficFines();
    void readCSV();
private:
    Tatbestand tatbestand;
    const string trennzeichen = ";";
    FILE *data1;
};

#endif // CALCULATETRAFFICFINES_H
