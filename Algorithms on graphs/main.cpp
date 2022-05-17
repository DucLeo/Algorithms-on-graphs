#include "AdjacencyMatrix.h"

using namespace std;

int main()
{
    cout << "Flight price list:" << endl << endl;
    string fileName = "fileFlight.txt";
    ifstream file(fileName);
    if (!file.is_open()) throw invalid_argument("Could not open file!");
    else {
        string tmp;
        while (getline(file, tmp, '\n')) {
            cout << tmp << endl;
        }
        file.close();
    }
    AdjacencyMatrix matrix;
    matrix.takeData(fileName);
    matrix.FloydWarshall();

    string point1 = "Moscow";
    string point2 = "Khabarovsk";

    cout << "\nThe shorted path from " << point1 << " to " << point2 << " :\n\n";
    cout << matrix.shortedPath(point1, point2) << endl;

    cout << "\nThe minimum price from " << point1 << " to " << point2 << " : ";
    cout << matrix.weighthSortedPath(point1, point2) << " RUB" << endl;

}