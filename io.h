//
// Created by ganymed on 05/04/16.
//

#ifndef INC_IO_H
#define INC_IO_H


/*      Input       */

int readIntFromCommandline();

int printTextAndReadIntFromCommandline(char* text);

void readIntArray(int inputArray[], int arrayLength);


float readFloatFromCommandline();

void readFloatArray(float inputArray[], int arrayLength);

// oh C, you're really an old, old language. Such a complicated Syntax for not such a complicated problem!
void readFloatMatrix(int countColumns, int countRows, float (*matrix)[countRows]);


/*      Output      */

void println();


void printString(char* output);

void printlnString(char* output);


void printInt(int output);

void printlnInt(int output);


void printFloat(float output);

void printFloat_LimitDecimalPlaces(float output, int countDecimalPlaces);

void printlnFloat(float output);

void printlnFloat_LimitDecimalPlaces(float output, int countDecimalPlaces);

void printFloatArray(int array[], int arrayLength);

void printFloatMatrix(int countColumns, int countRows, float (*matrix)[countRows]);


#endif //INC_IO_H
