//
// Created by ganymed on 08/04/16.
//

#ifndef INC_ARTIKEL_H
#define INC_ARTIKEL_H


#define MAXCHAR 84


typedef struct ArtikelStruct  {
    int nr;
    char name[MAXCHAR];
    double preis;
    int bestand;
    int minBestand;
} ArtikelStruct;


#endif //INC_ARTIKEL_H
