#ifndef PATRON_HPP
#define PATRON_HPP

#include <iostream>
#include <string>
#include <vector>
#include "LibraryItem.hpp"

using namespace std;

class Patron
{
private:
    string idNum;
    string name;
    vector<LibraryItem*> checkedOutItems;
    double fineAmount = 0.0;
public:
    Patron(string idn, string n);
    string getIdNum();
    string getName();
    vector<LibraryItem*> getCheckedOutItems();
    void addLibraryItem(LibraryItem* b);
    void removeLibraryItem(LibraryItem* b);
    double getFineAmount();
    void amendFine(double amount);
};

#endif
