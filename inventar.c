//
// Created by ganymed on 08/04/16.
//

#include "inventar.h"


void printInventar() {
    ArtikelStruct article;
    int countArticles = 0;
    float articlesSum = 0.0;
    int result = 0;

    openLager();

    while(result == 0) {
        result = readNext(&article);
        if (result == HasMoreData) {
            countArticles++;
            articlesSum += article.preis;
        }
    }

    closeLager();

    printString("Gesamtzahl der Artikelarten: ");
    printlnInt(countArticles);

    printString("Gesamtwert der Artikel:      ");
    printlnFloat(articlesSum);
}

