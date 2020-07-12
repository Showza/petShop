#include <cassert>

#include "functional.hpp"
#include "petShop.hpp"

//constante com os dias da semana =========================================
const char* weekdays[] = { "Sunday", "Monday",
                           	  "Tuesday", "Wednesday",
                              "Thursday", "Friday", "Saturday"};

//constante com os nomes dos petShops =====================================
const string names[] = { "MeuCaninoFeliz", "VaiRex", "ChowChawgas" };

void petShopCriationFunctionalTest(){ //verifica a funcionalidade das funções envolvidas na criação do objeto
	
	assert(petShop(2,20,40,20,3,5,"Wednesday",weekdays,names[0]).getValues() == "MeuCaninoFeliz 2.000000 60.000000 200.000000 260.000000");
	assert(petShop(1.7,15,50,20,55,3,5,"Wednesday",weekdays,names[1]).getValues() == "VaiRex 1.700000 45.000000 250.000000 295.000000");
	assert(petShop(0.8,30,45,3,5,"Wednesday",weekdays,names[2]).getValues() == "ChowChawgas 0.800000 90.000000 225.000000 315.000000");

}

void calcTimeFunctionalTest(){ //verifica a transformação da data ==========
	assert(calcTime(weekdays, "10/07/2020") == "Friday");
	assert(calcTime(weekdays, "11/07/2020") == "Saturday");
}

void selectPetShopFunctionalTest(){ //verifica seleção da melhor opção e as funções envolvidas
	petShop vet[3] = {petShop(2,20,40,20,3,5,"Wednesday",weekdays,names[0]), 
				 petShop(1.7,15,50,20,55,3,5,"Wednesday",weekdays,names[1]),
				 petShop(0.8,30,45,3,5,"Wednesday",weekdays,names[2])
				};

	assert(selectPetShop(vet).getValues() == "MeuCaninoFeliz 2.000000 60.000000 200.000000 260.000000");	
}