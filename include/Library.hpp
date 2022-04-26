#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <iostream>
#include <vector>
#include <string>
#include "Book.hpp"
#include "Album.hpp"
#include "Movie.hpp"
#include "Patron.hpp"

using namespace std;

class Library
{
private:
    vector<LibraryItem*> holdings;
    vector<Patron*> members;
    int currentDate;
public:
    Library();
    void addLibraryItem(LibraryItem*);
    void addPatron(Patron*);
    string checkOutLibraryItem(string patronID, string ItemID);
    string returnLibraryItem(string ItemID);
    string requestLibraryItem(string patronID, string ItemID);
    string payFine(string patronID, double payment);
    void incrementCurrentDate();
    Patron* getPatron(string patronID);
    LibraryItem* getLibraryItem(string ItemID);
  };

#endif
