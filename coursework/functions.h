#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
using namespace std;


// Table view:
// Code | Name | Genre | Release | Rating

// struct Product {
//     {1, "What's Eating Gilbert Grape", "Drama", 1993, 8.4},
//     {2, "Se7en", "Triller", 1995, 9.8},
//     {3, "Fight Club", "Triller", 1999, 8.6},
//     {4, "American Psycho", "Triller", 2000, 7.1},
//     {5, "Catch Me If You Can", "Criminal", 2002, 8.9},
// }

struct Table {
    int code;
    char movieName;
    char genre;
    int yearRelease;
    double rating;
};
