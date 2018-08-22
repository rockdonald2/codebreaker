#ifndef SZOTAR_H
#define SZOTAR_H

// a szotar fajl, amiben a jatek altal hasznalt szavak talalhatok meg

#include <vector>
#include <string>

using std::vector;
using std::string;

namespace Szotar
{
	vector<string> szotar{ "AHEM", "AHIS", "AHOY", "AIDS", "AIMS", "AIRS", "ALOE", "ALSO",
		"BYTE", "CABA", "CABS", "CACA", "DAAL", "DABS", "DACE", "DACK",
		"HIPT", "HIRE", "HISH", "HOAS", "HOAX", "HOBO", "ITAS", "ITCH", "ITEM",
		"VOWS", "VRIL", "VROT", "VROU",
		"SAAG", "SABE", "SABS", "SACK", "SCAB", "SCAD", "SCAG", "SCAM",
		"ROWS", "ROWT", "RUBE", "RUGA", "RUGS", "RUIN", "RUKH",
		"RYES", "RYFE", "RYKE",
		"PUMY", "PUNA", "PUNG", "PYIC", "PYIN", "PYNE",
		"MUNG", "MUNI", "MUNS", "MUNT", "MUZZ", "MWAH", "MYAL",
		"SAID", "SAIL", "SAIM", "SAIN", "SAIR",
		"OWLY", "OWNS", "OWRE", "OURN", "OURS", "OUST",
		"NABK", "NABS", "NACH", "NADA", 
		"TELL", "TELS", "TELT", "TEME", "THEY", "THIG", "THIN",
		"SNEE", "SNIB", "SNIG", "SNIP"
	};

	//cout << Szotar::szotar[0];
		//cout << Szotar::szotar[0].at(1);
}

#endif
