#include "../include/Patron.hpp"

using namespace std;

Patron::Patron(string idn, string n)
{
  idNum = idn;
  name = n;
}

string Patron::getIdNum()
{
  return idNum;
}

string Patron::getName()
{
  return name;
}

vector<LibraryItem*> Patron::getCheckedOutItems()
{
  return checkedOutItems;
}

void Patron::addLibraryItem(LibraryItem* b)
{
  checkedOutItems.push_back(b);
}

void Patron::removeLibraryItem(LibraryItem* b)
{
  for (size_t i = 0; i < checkedOutItems.size(); i++) {
    if(b->getIdCode() == checkedOutItems.at(i)->getIdCode())
    {
     checkedOutItems.erase(checkedOutItems.begin()+i);
     break;
  }
}
}

double Patron::getFineAmount()
{
  return fineAmount;
}

void Patron::amendFine(double amount)
{
  fineAmount += amount;
}
