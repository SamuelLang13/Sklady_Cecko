//BORIS VELICKA

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>


// MAKRA
#define WAREHOUSE_DB_FILE "warehouse_db.txt"
#define ITEMS_FOLDER "items"
#define MAX_NAME 100 // max. dlzka pre nazvy
#define RADIUS_EARTH_KM 6372 // polomer zeme
#define deg2rad(X) ((X)*M_PI/180) // makro na konverziu stupnov na radiany

// SEPARATOR ADRESAROV
#ifdef _WIN32
#define PATH_SEPARATOR "\\"
#else
#define PATH_SEPARATOR "/"
#endif

// DATOVE TYPY

// GPS poloha
typedef struct gps {
double lat; // latitude
double lon; // longitude
} GPS;

// polozka na sklade (tovar)
typedef struct item {
char name[MAX_NAME + 1]; // nazov
int price; // cena
} ITEM;

// sklad
typedef struct warehouse {
char name[MAX_NAME + 1]; // nazov
GPS gps; // poloha
int capacity; // kapacita skladu
int n; // aktualny pocet poloziek na sklade
ITEM *items; // databaza poloziek na sklade (dynamicke pole)
} WAREHOUSE;

// DEKLARACIE FUNKCII
double distance(GPS gps1, GPS gps2);

#define MAX_SIZE 250

int rowCounter(){
    int rowCount=0;
    FILE *ptrWarehouse;
    ptrWarehouse = fopen(WAREHOUSE_DB_FILE, "r");
    if(ptrWarehouse == NULL){
        return 1;
    }

    while((c = fgetc(ptrWarehouse)) != EOF){ //EOF == -1
        if(c == '\n') {
            rowCount++;
        }
    }
    return rowCount;
}



int main(int argc, char *argv[]) {

    int result;
    int linesCounter = 0;
    char c;
    const char *optstring = ":w:n:e:ad";

    while ((result= getopt(argc, argv, optstring)) != -1){
        switch (result){
            case 'w':
                break;
            case 'e':
                break;
            case 'n':
                break;
            case 'a':
                break;
            case 'd':
                break;
            case ':':
                return 1;
            case '?':
                return 1;
            default:
                return 1;
        }
    }

    //Vypocet riadkov v .txt

    printf("%d\n", linesCounter);

    return 0;
}

