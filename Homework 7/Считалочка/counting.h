#pragma once

#include <stdio.h>

#include "cycle.h"

// returns the position of the last surviving soldier depending on given number of soldiers and step according to which they stab each other
size_t findSurvivor(size_t number, size_t step);