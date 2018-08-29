// Egy Fallout 4 terminal hack típusú kódtörő játék

#include "pch.h"
#include <iostream>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "szotar.h"
#include "memoriacimek.h"
#include "absztrakt.h"

using std::cout;
int randomSzam(int min, int max);

const int g_jatekmod = randomSzam(1, 3);

class Jatek
{
private:
	int m_probalkozasok = 4; // maximalis probalkozasok szama 4

	enum class Eredmeny // a jatek vegkifejletenek a csoportositasa
	{
		NYERT,
		VESZITETT
	};

const int m_sorhossz = 7;
std::vector<string> m_jelenlevok;
int m_jelenlevokIndex = 0;

public:
	Jatek() {}

	void jatekKezdet(void)
	{
		// kezdodhet

		cout << "Udvozollek a ROBCo vallalat(TM) szerveren" << '\n';
		cout << "A belepeshez jelszo szukseges" << '\n';
	}

	void jatekElokeszulet(void)
	{
		cout << "Lehetseges probalkozasok szama: ";

		cout << " | | | | ";
	}

	void jatek(void)
	{
		cout << '\n' << '\n';

		int sorok(0);
		while (sorok < 20)
		{
			// csak azt akarom, hogy az első sorban csak 0x15 legyen
			cout << Memoriacimek::memoriacimek[randomSzam(0, Memoriacimek::memoriacimek.size() - 16)] << ' ';

			int szamlaloE(0);
			for (szamlaloE; szamlaloE < randomSzam(1, 7); ++szamlaloE)
				cout << Absztrakt::absztrakt[randomSzam(0, Absztrakt::absztrakt.size() - 1)];

			if (randomSzam(0, 1))
			{
				m_jelenlevok.push_back(Szotar::szotar3[randomSzam(0, Szotar::szotar3.size() - 1)]);
				cout << m_jelenlevok[m_jelenlevokIndex++];
			}
			else
			{
				for (int szamlalo = 0; szamlalo < 4; ++szamlalo)
				{
					cout << Absztrakt::absztrakt[randomSzam(0, Absztrakt::absztrakt.size() - 1)];
				}
			}

			for (szamlaloE; szamlaloE < m_sorhossz; ++szamlaloE)
				cout << Absztrakt::absztrakt[randomSzam(0, Absztrakt::absztrakt.size() - 1)];

			cout << '\t';

			// itt meg azt akarom, hogy a második sorban csak 0x16 legyen
			cout << Memoriacimek::memoriacimek[randomSzam(16, Memoriacimek::memoriacimek.size() - 1)] << ' ';

			int szamlaloM(0);
			for (szamlaloM; szamlaloM < randomSzam(1, 7); ++szamlaloM)
				cout << Absztrakt::absztrakt[randomSzam(0, Absztrakt::absztrakt.size() - 1)];

			if (randomSzam(0, 1))
			{
				m_jelenlevok.push_back(Szotar::szotar3[randomSzam(0, Szotar::szotar3.size() - 1)]);
				cout << m_jelenlevok[m_jelenlevokIndex++];
			}
			else
			{
				for (int szamlalo = 0; szamlalo < 4; ++szamlalo)
				{
					cout << Absztrakt::absztrakt[randomSzam(0, Absztrakt::absztrakt.size() - 1)];
				}
			}

			for (szamlaloM; szamlaloM < m_sorhossz; ++szamlaloM)
				cout << Absztrakt::absztrakt[randomSzam(0, Absztrakt::absztrakt.size() - 1)];

			cout << '\n';

			++sorok;
		}
	}

	Eredmeny probalkozas(void)
	{
		std::string megoldas = m_jelenlevok[randomSzam(0, m_jelenlevok.size() - 1)];
		std::string tipp;
		int talalat(0);

		while (m_probalkozasok > 0)
		{
			cout << " > ";
			std::cin >> tipp;

			if (tipp == megoldas)
			{
				cout << "A jelszo feltorve!\n";

				return Eredmeny::NYERT;
			}

			else
			{
				for (int szamlalo = 0; szamlalo < 4; ++szamlalo)
				{
					if (tipp.at(szamlalo) == megoldas.at(szamlalo))
						++talalat;
				}

				cout << talalat << " karakteru egyezes van!\n";
				talalat = 0;

				--m_probalkozasok;
				if (m_probalkozasok != 0)
					cout << "Hatramaradt probalkozasok szama: ";
				for (int szamlalo = 1; szamlalo <= m_probalkozasok; ++szamlalo)
				{
					if (m_probalkozasok != 0)
						cout << "| ";
				}
				cout << '\n';
			}

			if (m_probalkozasok == 0)
			{
				cout << "\nSzamitogep lezarul!\n";
				return Eredmeny::VESZITETT;
			}
		}
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
			cb.jatekElokeszulet();
			cout << '\n';
				cb.jatek();
				cb.probalkozas();


	cout << '\n';

	// megakadalyozza az azonnali kilepest
	std::getchar();
	return 0;
}