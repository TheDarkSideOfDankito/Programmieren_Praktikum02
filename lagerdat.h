//
// Created by ganymed on 08/04/16.
//

#ifndef INC_LAGERDAT_H
#define INC_LAGERDAT_H


#include "Artikel.h"


#define OpeningLagerSuccess 0
#define OpeningLagerError -1

#define HasMoreData 0
#define AllDataRead -1


int openLager(void);

int readNext(ArtikelStruct* pArtikel);

void closeLager(void);


#endif //INC_LAGERDAT_H
