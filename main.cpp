#include <iostream>
#include <calculatetrafficfines.h>

using namespace std;

int main()
{
    CalculateTrafficFines fines;
    fines.readCSV();

    cout << "Avg: " << fines.averageFine() << endl;
    return 0;
}
