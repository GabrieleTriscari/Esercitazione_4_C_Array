#pragma once

#include <iostream>
#include <string>

using namespace std;


// LA funzione ImportData importa i dati da un file di testo e li memorizza in variabili
bool ImportData(const string& file_name, double& S, size_t& n, double*& w, double*& r);



//La funzione CalculateInterest calcola il valore totale di un portafoglio di investimenti dopo aver applicato i pesi e i tassi di rendimento alla dimensione iniziale del portafoglio. Prende in input quattro parametri:
double CalculateInterest(const double& s, const size_t& n, const double* const& w, const double* const&  v);

//La funnzione ArraytoString converte un array di double in una stringa formattata
string ArrayToString(const size_t& n,
    const double* const& v);  


// La funzione EsportaRisultato esporta i risultati in un file di testo: result.txt
bool  ExportData(const string& file_name, const double& S, const size_t& n, const double* const& w, const double* const& r,const double& Tasso, const double& V);
