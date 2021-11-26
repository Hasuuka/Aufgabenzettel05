#ifndef CALCULATETRAFFICFINES_H
#define CALCULATETRAFFICFINES_H
#include <string>
#include <list>

using namespace std;

struct Tatbestand{
    string tag;
    string zeit;
    string ort;
    int geldbusse;
    string tatbestand;
};

class CalculateTrafficFines
{
public:
    CalculateTrafficFines();
    double averageFine();
    void readCSV();
private:
    list<Tatbestand> m_taten;
    const string trennzeichen = ";";
    FILE *file;
};

#endif // CALCULATETRAFFICFINES_H
