// Egy Fallout 4 terminal hack típusú kódtörő játék

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include "szotar.h"
#include "memoriacimek.h"
#include "absztrakt.h"

using std::cout;
int randomSzam(int min, int max);

class Jatek
{
private:
	int m_probalkozasok = 4; // maximalis probalkozasok szama 4

	enum class Eredmeny // a jatek vegkifejletenek a csoportositasa
	{
		NYERT,
		VESZITETT
	};

public:
	Jatek(){}

	void jatekKezdet(void)
	{
		// kezdodhet

		cout << "Udvozollek a ROBCo vallalat(TM) szerveren" << '\n';
		cout << "A belepeshez jelszo szukseges" << '\n';
	}

	Eredmeny jatek(void)
	{
		cout << "Lehetseges probalkozasok szama: ";

		if (m_probalkozasok == 4)
			cout << "| | | |";
		else if (m_probalkozasok == 3)
			cout << "| | |";
		else if (m_probalkozasok == 2)
			cout << "| |";
		else if (m_probalkozasok == 1)
			cout << "|";
		else
			return Eredmeny::VESZITETT;

		cout << '\n' << '\n';

		cout << Memoriacimek::memoriacimek[randomSzam(0, Memoriacimek::memoriacimek.size())] << ' ';
		for (int szamlalo = 0; szamlalo < 4; ++szamlalo)
			cout << Absztrakt::absztrakt[randomSzam(0, Absztrakt::absztrakt.size())];
		cout << Szotar::szotar[randomSzam(0, Szotar::szotar.size())];
		
		
	}

	bool probalkozas(void)
	{

	}

};

int randomSzam(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0);
	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

int main(void)
{
	srand(static_cast<unsigned int>(time(0)));
	rand(); // elvetjuk az elso sor random szamot


	Jatek cb;
		cb.jatekKezdet();
		cout << '\n';
			cb.jatek();

	cout << '\n';

	// megakadalyozza az azonnali kilepest
	std::getchar();
	return 0;
}