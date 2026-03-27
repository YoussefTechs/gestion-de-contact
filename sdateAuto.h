#ifndef SDATEAUTO_H
#define SDATEAUTO_H

#include <chrono>
#include <iostream>
#include <string>

#include "date/date.h"
#include "date/chrono_io.h"

using namespace date;
using namespace std::chrono;
using day_point = std::chrono::time_point<std::chrono::system_clock, days>;
using namespace std;

struct sdateAuto {
    day jour;
	month mois;
	year annee;
};

#endif
