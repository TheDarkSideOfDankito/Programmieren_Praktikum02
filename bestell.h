//
// Created by ganymed on 08/04/16.
//

#ifndef BESTELL_H
#define BESTELL_H


#include "Artikel.h"
#include "lagerdat.h"
#include "io.h"
#include <stdbool.h>


bool shouldArticleGetOrdered(ArtikelStruct article);

int getCountArticlesToOrder();

void printNachbestellungen();


#endif //BESTELL_H
