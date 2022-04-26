#include "../include/Book.hpp"
#include "../include/LibraryItem.hpp"

using namespace std;

Book::Book(string idb, string bn, string ba): LibraryItem(idb, bn)
{
  bookAuthor = ba;
}

string Book::getbookAuthor()
{
  return bookAuthor;
}

int Book::getCheckOutLength()
{
  return CHECK_OUT_LENGTH;
}
