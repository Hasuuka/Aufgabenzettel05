#ifndef CALCULATETRAFFICFINES_H
#define CALCULATETRAFFICFINES_H
#include <string>
#include <list>

using namespace std;

struct Tatbestand{
    string tag;
    string zeit;
    string ort;
    string geldbusse;
    string tatbestand;
};

class CalculateTrafficFines
{
public:
    CalculateTrafficFines();
    void readCSV();
private:
    list<Tatbestand> m_taten;
    const string trennzeichen = ";";
    FILE *data1;
};

#endif // CALCULATETRAFFICFINES_H
