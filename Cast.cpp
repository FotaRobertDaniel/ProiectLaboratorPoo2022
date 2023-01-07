#include <iostream>
#include <string.h>

class Cast {
    private:
        std::string nume;
        std::string prenume;
        std::string rol;
        std::string dieta;
    public:
        template <typename rndNr>
        rndNr random(rndNr var)
        {
            return rand() % var;
        }
        int costMachiaj;
        int costMancare;

        std::string roluri[5] = {"Vampir", "Varcolac", "Sierna", "Clarvazator", "Om"};
        std::string diete[3] = {"Apta sa manance orice", "Vegetariana", "Flexitariana"};
        Cast(std::string x, std::string y) {
            nume = x;
            prenume = y;
            rol = roluri[random(5)];
            dieta = diete[random(3)];

            if(rol == "Vampir") {
                costMachiaj = 230;
            }
            else if(rol == "Varcolac") {
                costMachiaj = 555;
            }
            else if(rol == "Sierna") {
                costMachiaj = 345;
            }
            else if(rol == "Clarvazator") {
                costMachiaj = 157;
            }
            else if(rol == "Om") {
                costMachiaj = 55;
            }
            else {
                costMachiaj = 0;
            }
            
            if(dieta == "Apta sa manance orice") {
                costMancare = 44;
            }
            else if(dieta == "Vegetariana") {
                costMancare = 33;
            }
            else if(dieta == "Flexitariana") {
                costMancare = 46;
            }
            else {
                costMancare = 0;
            }
            
        }
        int getMachiajCost() {
            return costMachiaj;
        }
        int getMancareCost() {
            return costMancare;
        }
        void exportCast() {
            char delimeter1(';');
            char delimeter2('\n');
            std::ofstream fisier;
            fisier.open("CastInitial.csv", std::ios_base::app);

            try
            {
                if(fisier.is_open())
                {
                    fisier<<nume;
                    fisier<<" ";

                    fisier<<prenume;
                    fisier<<delimeter1;

                    fisier<<rol;
                    fisier<<delimeter1;

                    fisier<<dieta;
                    fisier<<delimeter2;
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
        
};