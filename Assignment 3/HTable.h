/*  Wei Chen C3355372
    Assignment 3
    11/06/2022
    HTable.h: header definition for Hash Table class
*/

#ifndef RUSHED_HTable
#define RUSHED_HTable

#include <ostream>  //for using ostream
#include "Cities.h" //for using cities

//generic template
template <typename T>
class HTable{
    public:
        //de/constructor
        HTable(); 
        ~HTable();
        
        //mutators
        void add(T& newData);   //adds to hash table
        void remove(T& key);    //removes from position that match

        //query functions
        void print(std::ostream& out);          //prints all non-default data
        int calculateTotalPop();                //calculate total population in non-default data
        int calculatePopGreaterThan(int lim);   //calculate population in non-default data greater than lim
    
    private:
        const static int TABLE_SIZE = 10000;    //table size provided by assignment spec
        Cities c;                               //this city is used as default city
        T table [TABLE_SIZE];                   //array used as underlying data structure
        hashfun(const T& value);                //assignment spec-provided secret sauce hash function
        
};
//generic overloaded << operator
template <typename T>
std::ostream& operator << (std::ostream& out, HTable<T>& h);

#include "HTable.hpp"

#endif