#ifndef PETSHOP_HPP 
#define PETSHOP_HPP

#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

class petShop{
private:
	string name;
	double distance;
	double smallPrice;
	double bigPrice;
	double add;
	double finalPrice;
public:
//construtores para os diferentes tipos de cobranças dos petshops ============================================================================
	petShop(double distance, double smallPrice, double bigPrice, int qntSmall, int qntBig, string date, const char* weekdays[], string name);//não tem diferença no preço do final de semana
	petShop(double distance, double smallPrice, double bigPrice, double add, int qntSmall, int qntBig, string date, const char* weekdays[], string name);//tem diferença no preço do final de semana baseado em uma porcentagem;
	petShop(double distance, double smallPrice, double bigPrice, double smallPriceWeekend, double bigPriceWeekend, int qntSmall, int qntBig, string date, const char* weekdays[], string name); //tem diferença no preço do final de semana baseado em um valor fixo;
	petShop();

//geters e seters ============================================================================================================================
	string getName() const;
	void setName(string);
	
	double getDistance() const;
	void setDistance(double);

	double getSmalPrice() const;
	void setSmalPrice(double, string, int, const char*[]);
	void setSmalPrice(double, double, string, int, const char*[]);

	double getbigPrice() const;
	void setbigPrice(double, string, int, const char*[]);
	void setbigPrice(double, double, string, int, const char*[]);

	double getAdd() const;
	void setAdd(double);

	double getFinalPrice() const;
	void setFinalPrice();

	string getValues();
};

//declaração das demais funções ============================================================================================================================

void separateDate(int* day,int* month,int* year,string date);
string calcTime(const char* weekdays[], string date);
petShop selectPetShop(petShop* vet);
void ordena(petShop* vet);
void print(petShop pet);

#endif