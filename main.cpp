#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "src/Utils.hpp"


using namespace std;

int main()

{
    string file_name = "data.txt";
    double S = 0.0;
    size_t n = 0;
    double *w = nullptr;
    double *r = nullptr;
    double V = 0.0;
    if (!ImportData(file_name, S, n, w, r))
    {
        cerr << "Errore nell'apertura file" << endl;
        return 1;
    }
    else
        cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
        cout << "w = " << ArrayToString(n, w) << endl;
        cout << "r = " << ArrayToString(n, r) << endl;
    double Tasso = CalculateInterest(S, n, w, r);
    cout << "Rate of return of the portfolio: " << fixed << setprecision(4) << Tasso << endl;
    
    V = S * (1 + Tasso);
    cout << "V: " << fixed << setprecision(2) << V << endl;
    string outputFileName = "result.txt";   
    if (!ExportData(outputFileName, S, n, w, r,Tasso, V))
    {
        cerr << "Errore nel file di output" << endl;
        return 1;
    }
   
    delete[] w;
    delete[] r;

    return 0;
}
