#include <iostream>
#include <cstring>
#include <ctime>
#include "petShop.hpp"
using namespace std;

petShop::petShop(double distance, double smallPrice, double bigPrice, int qntSmall, int qntBig, string date, const char* weekdays[], string name){
	setName(name);
	setDistance(distance);
	setAdd(0.0);
	setSmalPrice(smallPrice, date, qntSmall, weekdays);
	setbigPrice(bigPrice, date, qntBig, weekdays);
	setFinalPrice();
}
petShop::petShop(double distance, double smallPrice, double bigPrice, double add, int qntSmall, int qntBig, string date, const char* weekdays[], string name){
	setName(name);
	setDistance(distance);
	setAdd(add);
	setSmalPrice(smallPrice, date, qntSmall, weekdays);
	setbigPrice(bigPrice, date, qntBig, weekdays);
	setFinalPrice();
}

petShop::petShop(double distance, double smallPrice, double bigPrice, double smallPriceWeekend, double bigPriceWeekend, int qntSmall, int qntBig, string date, const char* weekdays[], string name){
	setName(name);
	setDistance(distance);
	setAdd(0.0);
	setSmalPrice(smallPrice, smallPriceWeekend, date, qntSmall, weekdays);
	setbigPrice(bigPrice, bigPriceWeekend, date, qntBig, weekdays);
	setFinalPrice();
}

petShop::petShop(){}

string petShop::getName() const{
	return name;
}
void petShop::setName(string value){
	name = value;
}

double petShop::getDistance() const{
	return distance;
}
void petShop::setDistance(double value){
	distance = value;
}

double petShop::getSmalPrice() const{
	return smallPrice;
}
void petShop::setSmalPrice(double value, string date, int qntSmall, const char* weekdays[]){
	if(date == weekdays[0] || date == weekdays[6]){
		smallPrice = (value + (value*(add/100)))*qntSmall;
	}
	else smallPrice = value*qntSmall;
}
void petShop::setSmalPrice(double value, double value2, string date, int qntSmall, const char* weekdays[]){
	if(date == weekdays[0] || date == weekdays[6]){
		smallPrice = value2*qntSmall;
	}
	else smallPrice = value*qntSmall;
}

double petShop::getbigPrice() const{
	return bigPrice;
}
void petShop::setbigPrice(double value, string date, int qntBig, const char* weekdays[]){
	if(date == weekdays[0] || date == weekdays[6]){
		bigPrice = (value + (value*(add/100)))*qntBig;
	}
	else bigPrice = value*qntBig;
}
void petShop::setbigPrice(double value, double value2, string date, int qntBig, const char* weekdays[]){
	if(date == weekdays[0] || date == weekdays[6]){
		bigPrice = value2*qntBig;
	}
	else bigPrice = value*qntBig;
}

double petShop::getAdd() const{
	return add;
}
void petShop::setAdd(double value){
	add = value;
}

void petShop::setFinalPrice(){
	finalPrice = smallPrice+bigPrice;
}
double petShop::getFinalPrice() const{
	return finalPrice;
}
//===========================================================

void separateDate(int* day,int* month,int* year,string date){
	string* aux = new string;
	for(int i = 0; i < 11; i++){
		if(date[i] != '/' && date[i] != '\0') {
			*aux += date[i];
		}
		else if(i < 3){
			*day = stoi(*aux);
			*aux = '0';
		}
		else if(i < 6){
			*month = stoi(*aux);
			*aux = '0';
		}
		else{
			*year = stoi(*aux);
		}
	}
	delete aux;
}
//=======================================================

string calcTime(const char* weekdays[], string date){
	int day, month, year;
	time_t rawtime;
  	struct tm * timeinfo;

	separateDate(&day,&month,&year,date);

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	timeinfo->tm_year = year - 1900;
	timeinfo->tm_mon = month - 1;
	timeinfo->tm_mday = day;

	mktime ( timeinfo );

	return weekdays[timeinfo->tm_wday];
}
//========================================================
void ordena(petShop* vet){
	petShop aux = petShop();
	if(vet[0].getFinalPrice() > vet[1].getFinalPrice()){
		aux = vet[0];
		vet[0] = vet[1];
		vet[1] = aux;
	}
	if(vet[0].getFinalPrice() > vet[2].getFinalPrice()){
		aux = vet[0];
		vet[0] = vet[2];
		vet[2] = aux;
	}
	if(vet[1].getFinalPrice() > vet[2].getFinalPrice()){
		aux = vet[1];
		vet[1] = vet[2];
		vet[2] = aux;
	}
}

petShop selectPetShop(petShop* vet){
	ordena(vet);
	if(vet[0].getFinalPrice() == vet[1].getFinalPrice()){
		if(vet[0].getDistance() < vet[1].getDistance()){
			return vet[0];
		}
		else{
			return vet[1];
		}
	}
	else{
		return vet[0];
	}
}

void print(petShop pet){
	cout << "\t+------------------------------------------+" << endl;
	cout << "\t O melhor PetShop:...... " << pet.getName() << "\n\t Valor total dos banhos:...... " << pet.getFinalPrice() << endl;
	cout << "\t+------------------------------------------+" << endl;

}

