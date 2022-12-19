#ifndef _COLISIONMANAGER_H
#define _COLISIONMANAGER_H

#include "../../BaseClasses/Header/Entity.h"
#include "../../BaseClasses/Header/OrderedPair.h"
#include <stdbool.h>

int colided(Entity& e1, Entity& e2);

void mantainInsideScreen(Entity& e);

void verifyVisibility(Entity& e);

#endif