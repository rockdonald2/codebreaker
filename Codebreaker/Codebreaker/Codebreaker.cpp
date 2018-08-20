// Egy Fallout 4 terminal hack típusú kódtörő játék

#include "pch.h"
#include <iostream>
#include <cassert>
#include "szotar.h"

using std::cout;

class Jatek
{
public:
	Jatek(){}

	void jatekKezdet(void)
	{
		// kezdodhet

		cout << "Udvozollek a ROBCo vallalat(TM) szerveren" << '\n';
		cout << "A belepeshez jelszo szukseges" << '\n';
	}

	void jatek(void)
	{
		cout << "Lehetseges probalkozasok szama: " << '\n';

		cout << Szotar::szotar[0];
		cout << Szotar::szotar[0].at(1);
	}

};

int main(void)
{
	Jatek cb;
		cb.jatekKezdet();
		cout << '\n';
			cb.jatek();

	return 0;
}