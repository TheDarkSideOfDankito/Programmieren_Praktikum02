//
// Created by ganymed on 08/04/16.
//

#include <stdio.h>
#include "lagerdat.h"


FILE* lagerDataFile = NULL;


int openLager(void) {
    lagerDataFile = fopen("lager.bin", "r");

    return (lagerDataFile != NULL) ? OpeningLagerSuccess : OpeningLagerError;
}


int readNext(ArtikelStruct* pArtikel) {
    int result = fread(pArtikel, sizeof(ArtikelStruct), 1, lagerDataFile);

    return (result != 0) ? HasMoreData : AllDataRead;
}


void closeLager(void) {
    fclose(lagerDataFile);
}
