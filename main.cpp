#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <iomanip>
#include <time.h>

#include "Cast.cpp"
#include "Figurant.cpp"
#include "Meniu.cpp"

using namespace std;

int randomNamesNumber = 500;
float cursDolarAmerican = 4.63;

int costTotal;
int costMachiajTotal;
int costMancareTotal;

//template <typename rndNr>
int random(int var) {   
    return rand() % var;
}

void writeExpenses(std::string str, int cost) {
    std::ofstream fisier;
    fisier.open("CosturiProductie.csv", std::ios_base::app);

    try
    {
        if(fisier.is_open())
        {
            fisier<<str;
            fisier<<": ";
            fisier<<cost;
            fisier<<";\n";
        }
        else throw 1;
    }
    catch(bool er)
    {
        if(er == 1)
        {
            std::cout<<"EROARE LA FISIER!"<< "\n";
        }
    }

    fisier.close();
}

void repartizareHotel(int nrCast, int nrFiguranti, int nrZile) {
    float costCastfloat = nrCast/2;
    float costFigurantifloat = nrFiguranti/3;
    int costCast = (int)costCastfloat * 350 * nrZile;
    int costFiguranti = (int)costFigurantifloat * 420 * nrZile;

    writeExpenses("Hotel Cast", costCast);
    writeExpenses("Hotel Figuranti", costFiguranti);
    costTotal += costCast;
    costTotal += costFiguranti;
}

void creareMeniu() {
    std::string supe[10] = {
        "Supa crema de legume",
        "Ciorba pui a-la grec",
        "Ciorba de fasole",
        "Ciorba de miel",
        "Supa de pui cu taitei",
        "Supa cu spanac",
        "Ciorba de vacuta",
        "Supa de peste",
        "Supa de linte",
        "Ciorba de perisoare"
    };
    std::string feluriPrincipale[10] = {
        "Puree cu chiftelute marinate",
        "Cordon Bleu cu tochitura taraneasca",
        "Cartofi prajiti cu piept de pui la gratar",
        "Paste tagliatele carbonara",
        "Paste fettucine alfredo",
        "Carnaciori cu varza",
        "Sarmalute in foaie de varza cu mamaliguta",
        "Snitel de porc cu cartofi prajiti si salata de varza",
        "Mamaliguta cu Hamsii in sos de usturoi",
        "Somon gourmet pe pat de spanac asezonat cu baby morcovi cu sos de reducere de otet balsamic"
    };
    std::string deserturi[10] = {
        "Panettone",
        "Tiramisu",
        "Savarina",
        "Amandina",
        "Prajitura padurea neagra",
        "Prajitura Kinder Pingui",
        "Prajitura Inghetata Falsa cu crema de vanilie",
        "Biscuiti oreo",
        "Tort biscuiti oreo",
        "Inghetata"
    };

    for(int i = 0; i < 3; i ++) {
        Meniu meniu(supe[random(10)], feluriPrincipale[random(10)], deserturi[random(10)]);
        meniu.exportMeniu();
    }
}

void inchiriereCastel(int nrZile) {
    int cost = 0;
    for(int i = 1; i <= nrZile; i ++) {
        cost+=10000;
        if(i%10==0) cost = (cost * 98)/100;
    }
    writeExpenses("CostCastel: ", cost);
    costTotal += cost;
}

void inchiriereAutocare(int nrCast, int nrFig) {
    int nrTotal = nrCast + nrFig;
    float floatAutocare = (float)nrTotal/50;
    int nrAutocare = floatAutocare;
    if((int)(floatAutocare)!=(int)(floatAutocare+0.99)) {
        nrAutocare++;
    }
    int cost = 2 * 5680 * nrAutocare;
    writeExpenses("CostAutocare: ", cost);
    costTotal += cost;
}

void costuriAdapatAnimale(int nrCast, int nrFig, int nrZile) {
    int nrTotal = nrCast + nrFig;

    float floatCafea = 0.5 * (float)nrTotal;
    float floatSuc = 0.8 * (float)nrTotal;

    int litriApa = nrTotal;
    int litriCafea = floatCafea;
    int litriSuc = floatSuc;

    if((int)(floatCafea)!=(int)(floatCafea+0.99)) {
        litriCafea++;
    }
    if((int)(floatSuc)!=(int)(floatSuc+0.99)) {
        litriSuc++;
    }

    int costApa = 3 * litriApa * nrZile;
    int costCafea = 30 * litriCafea * nrZile;
    int costSuc = 4 * litriSuc * nrZile;

    writeExpenses("CostApa: ", costApa);
    writeExpenses("CostCafea: ", costCafea);
    writeExpenses("CostSuc: ", costSuc);

    costTotal = costTotal + costApa + costCafea + costSuc;
}

void writeTotalCost() {
    std::ofstream fisier;
    fisier.open("CosturiProductie.csv", std::ios_base::app);

    try
    {
        if(fisier.is_open())
        {
            fisier<<"CostTotal: ";
            fisier<<costTotal;
            fisier<<"Ron;\n";
            fisier<<"CostTotal: ";
            fisier<<(int)(costTotal/cursDolarAmerican);
            fisier<<"$;\n";
        }
        else throw 1;
    }
    catch(bool er)
    {
        if(er == 1)
        {
            std::cout<<"EROARE LA FISIER!"<< "\n";
        }
    }

    fisier.close();
}

void writeCosturiMachiajMancare() {
    writeExpenses("CostMachiaj: ", costMachiajTotal);
    writeExpenses("CostMancare: ", costMancareTotal);
}

void generateCast(int nrCast, int nrZile) {
    char delimeter1(' ');
    char delimeter2('\n');

    int costMachiaj=0;
    int costMancare=0;

    for(int i = 0; i < nrCast; i ++) {
        std::string nume;
        std::string prenume;

        int randomLine = random(randomNamesNumber);
        int aux = 0;

        ifstream RandomNames;
        RandomNames.open("RandomNames.csv");
        while(aux != randomLine) {

            getline(RandomNames, nume, delimeter1);
            getline(RandomNames, prenume, delimeter2);
            aux++;
        }
        RandomNames.close();

        Cast obiect(nume, prenume);
        costMachiaj += obiect.getMachiajCost() * nrZile;
        costMancare += obiect.getMancareCost() * nrZile;
        obiect.exportCast();
    }
    costMachiajTotal += costMachiaj;
    costMancareTotal += costMancare;
    costTotal += costMachiaj;
    costTotal += costMancare;
}

void generateFiguranti(int nrFig, int nrZile) {
    char delimeter1(' ');
    char delimeter2('\n');

    int costMachiaj=0;
    int costMancare=0;

    for(int i = 0; i < nrFig; i ++) {
        std::string nume;
        std::string prenume;

        int randomLine = random(randomNamesNumber);
        int aux = 0;

        ifstream RandomNames;
        RandomNames.open("RandomNames.csv");
        while(aux != randomLine) {

            getline(RandomNames, nume, delimeter1);
            getline(RandomNames, prenume, delimeter2);
            aux++;
        }
        RandomNames.close();

        Figurant obiect(nume, prenume);
        costMachiaj += obiect.getMachiajCost() * nrZile;
        costMancare += obiect.getMancareCost() * nrZile;
        obiect.exportFigurant();
    }
    costMachiajTotal += costMachiaj;
    costMancareTotal += costMancare;
    costTotal += costMachiaj;
    costTotal += costMancare;
}

int main() {
    srand(time(0));
    int nrCast = 550;
    int nrFig = 132;
    int nrZile;

    cout << "Cate zile ai dori?";
    cin >> nrZile;

    generateCast(nrCast, nrZile);
    generateFiguranti(nrFig, nrZile);

    inchiriereAutocare(nrCast, nrFig);
    repartizareHotel(nrCast, nrFig, nrZile);
    writeCosturiMachiajMancare();
    costuriAdapatAnimale(nrCast, nrFig, nrZile);
    inchiriereCastel(nrZile);
    creareMeniu();

    writeTotalCost();
}