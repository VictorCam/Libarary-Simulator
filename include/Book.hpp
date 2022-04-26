#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
#include "Library.hpp"
#include "LibraryItem.hpp"

using namespace std;

class Book: public LibraryItem
{
protected:
    string bookAuthor;
public:
  static const int CHECK_OUT_LENGTH = 21;
  Book(string idb, string bn, string ba);
  string getbookAuthor();
  int getCheckOutLength();
};

#endif
