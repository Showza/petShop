#include <iostream>
#include <cstring>
#include <ctime>
#include "petShop.hpp"
using namespace std;

int main(int argc, char *argv[]){

//constante com os dias da semana =========================================
	const char* weekdays[] = { "Sunday", "Monday",
                           	  "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"};
    
//constante com os nomes dos petShops =====================================
    const string names[] = { "MeuCaninoFeliz", "VaiRex", "ChowChawgas" };

//recebimento dos dados de entrada ========================================
	string date = argv[1];
	int qntSmall = atoi(argv[2]);
	int qntBig = atoi(argv[3]);

//calculos para descobrir o dia da semana correspondente a data ===========
	string day = calcTime(weekdays, date);	

//vetor com os objetos dos petShops =======================================
	petShop vet[3] = {petShop(2,20,40,20,qntSmall,qntBig,day,weekdays,names[0]), 
				 petShop(1.7,15,50,20,55,qntSmall,qntBig,day,weekdays,names[1]),
				 petShop(0.8,30,45,qntSmall,qntBig,day,weekdays,names[2])
				};

// impressão dos resultados ===============================================
	print(selectPetShop(vet));

	return 0;
}