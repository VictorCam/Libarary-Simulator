#ifndef LIBRARY_ITEM_HPP
#define LIBRARY_ITEM_HPP

#include <iostream>
#include <string>

class Patron;

// These three locations are mutually exclusive, but note that
// a LibraryItem can be on request for a Patron while being checked
// out to another Patron.  In that case the LibraryItem's location is
// CHECKED_OUT, and when it is returned, it's location will
// become ON_HOLD_SHELF.
enum Locale {ON_SHELF, ON_HOLD_SHELF, CHECKED_OUT};

using namespace std;

class LibraryItem
{
private:
    string idCode;
    string title;
    Locale location;
    Patron* checkedOutBy;
    Patron* requestedBy;
    int dateCheckedOut;
public:
    LibraryItem(string idc, string t);
    virtual int getCheckOutLength() = 0;
    string getIdCode();
    string getTitle();
    Locale getLocation();
    void setLocation(Locale);
    Patron* getCheckedOutBy();
    void setCheckedOutBy(Patron*);
    Patron* getRequestedBy();
    void setRequestedBy(Patron*);
    int getDateCheckedOut();
    void setDateCheckedOut(int);
};


#endif
