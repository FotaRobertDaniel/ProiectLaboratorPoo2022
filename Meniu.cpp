#include <iostream>
#include <string.h>

class Meniu {
    private:
        std::string supa;
        std::string fel;
        std::string desert;
    public:
        Meniu(std::string x, std::string y, std::string z) {
            supa = x;
            fel = y;
            desert = z;
        }
        void exportMeniu() {
                char delimeter1(';');
                char delimeter2('\n');
                std::ofstream fisier;
                fisier.open("Meniu.csv", std::ios_base::app);

                try
                {
                    if(fisier.is_open())
                    {
                        fisier<<"SUPA: ";
                        fisier<<supa;
                        fisier<<delimeter2;

                        fisier<<"FEL PRINCIPAL: ";
                        fisier<<fel;
                        fisier<<delimeter2;

                        fisier<<"DESERT: ";
                        fisier<<desert;
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