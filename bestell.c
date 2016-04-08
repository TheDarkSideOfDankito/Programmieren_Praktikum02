//
// Created by ganymed on 08/04/16.
//

#include "bestell.h"
#include <string.h>



bool shouldArticleGetOrdered(ArtikelStruct article) {
    return article.bestand < article.minBestand;
}


int getCountArticlesToOrder() {
    ArtikelStruct article;
    int countArticlesToOrder = 0;
    int result = 0;

    openLager();

    while(result == 0) {
        result = readNext(&article);
        if (result == HasMoreData) {
            if(shouldArticleGetOrdered(article)) {
                countArticlesToOrder++;
            }
        }
    }

    closeLager();

    return countArticlesToOrder;
}

void bestellen(ArtikelStruct* articlesToOrder) {
    ArtikelStruct article;
    int currentArticleToOrderNumber = 0;
    int result = 0;

    openLager();

    while(result == 0) {
        result = readNext(&article);
        if (result == HasMoreData) {
            if(shouldArticleGetOrdered(article)) {
                articlesToOrder[currentArticleToOrderNumber] = article;
                currentArticleToOrderNumber++;
            }
        }
    }

    closeLager();
}

void printNachbestellungen() {
    int countArticlesToOrder = getCountArticlesToOrder();
    ArtikelStruct articlesToOrder[countArticlesToOrder];

    bestellen(articlesToOrder);
    float nachbestellungSum = 0.0;

    printlnString("Lfd. Nr Art.Nr. Artikel \t\t\t\t\tBestellanzahl   Einzelpreis   Gesamtpreis");
    printlnString("-------------------------------------------------------------------------------------");

    for(int i = 0; i < countArticlesToOrder; i++) {
        ArtikelStruct articleToOrder = articlesToOrder[i];
        int countToOrder = articleToOrder.minBestand * 5;
        float orderSum = countToOrder * articleToOrder.preis;
        nachbestellungSum += orderSum;

        printString("   ");
        printInt(i);

        printString("       ");
        printInt(articleToOrder.nr);

        printString("   ");
        printString(articleToOrder.name);

        printString("\t\t\t");
        if(strlen(articleToOrder.name) < 15) {
            printString("\t");
        }
        if(strlen(articleToOrder.name) < 19) {
            printString("\t");
        }
        printInt(countToOrder);

        printString("\t\t\t\t");
        printFloat_LimitDecimalPlaces(articleToOrder.preis, 2);

        printString("\t\t");
        if(orderSum < 100) {
            printString(" ");
        }
        printlnFloat_LimitDecimalPlaces(orderSum, 2);
    }

    printlnString("-------------------------------------------------------------------------------------");
    printString("                                                                   Summe:   ");
    printlnFloat_LimitDecimalPlaces(nachbestellungSum, 2);
}
