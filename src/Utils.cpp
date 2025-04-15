#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Utils.hpp"
#include <iomanip> 

using namespace std;


bool ImportData(const string& file_name, double& S, size_t& n, double*& w, double*& r) {
    ifstream file(file_name);
    string line;
    size_t pos;
    getline(file, line);
    S = stod(line.erase(0, 2));
    getline(file, line);
    n = stoi(line.erase(0, 2));
    getline(file, line);
    w = new double[n];
    r = new double[n];
    for (unsigned int i = 0; i < n; i++) {
        getline(file, line);
        pos = line.find(";");
        r[i] = stod(line.substr(pos +1 , line.length() - 1));
        line.erase(pos, line.length() - 1);
        w[i] = stod(line);
    }
    file.close();
    if (file.fail()) {
        cerr << "Apertura file fallita" << endl;
        return false;
    }
    return true;
}

string ArrayToString(const size_t& n, 
    const double* const& v)
{
string str;
ostringstream toString;
toString << "[ ";
for (unsigned int i = 0; i < n; i++)
toString<< v[i]<< " ";
toString << "]";

return toString.str();
}

double CalculateInterest(const double& s, const size_t& n, const double* const& w, const double* const& r) {
    
    double valore = 0.0;  
    for (unsigned int i = 0; i < n; ++i) 
        valore += w[i] * r[i];
    return valore;
       

   
}
bool  ExportData(const string& file_name, const double& S, const size_t& n, const double* const& w, const double* const& r,const double& Tasso, const double& V)
{ 
    ofstream file;
    file.open(file_name);

    if (file.fail()) 
    {   
        cerr << "Errore nell'apertura del file output" << file_name << endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    file << "w = " << ArrayToString(n, w) << endl;
    file << "r = " << ArrayToString(n, r) << endl;
    file << "Rate of return of the portfolio: " << fixed << setprecision(4) << Tasso << endl;
    file << "V: " << fixed << setprecision(2) << V << endl;
    file.close();
    return true;
}