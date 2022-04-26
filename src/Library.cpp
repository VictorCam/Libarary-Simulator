#include "../include/Library.hpp"

using namespace std;

Library::Library()
{
  currentDate = 0;
}

void Library::addPatron(Patron* p)
{
  members.push_back(p);
}

void Library::addLibraryItem(LibraryItem* b)
{
  holdings.push_back(b);
}

string Library::checkOutLibraryItem(string patronID, string ItemID)
{
  if(getLibraryItem(ItemID)->getLocation() == ON_HOLD_SHELF) return "on hold by another patron";

  if(ItemID != getLibraryItem(ItemID)->getIdCode()) return "book not found";

  if(patronID != getPatron(patronID)->getIdNum()) return "patron not found";
  
  if(getLibraryItem(ItemID)->getLocation() == ON_SHELF){
    getLibraryItem(ItemID)->setLocation(CHECKED_OUT);
    getPatron(patronID)->addLibraryItem(getLibraryItem(ItemID)); //v2
    getLibraryItem(ItemID)->setCheckedOutBy(getPatron(patronID)); //v2
    return "book successfully checked out";
  }
  return "the book does not exist";
}

string Library::returnLibraryItem(string ItemID)
{

  //check if the book exists
  if(ItemID != getLibraryItem(ItemID)->getIdCode()) return "book not found";

  //check if the book is being held or on hold by a patron
  int location = getLibraryItem(ItemID)->getLocation();
  if(location == ON_SHELF || location == ON_HOLD_SHELF) return "you do not have this book checked out";

  //get the patron that is checking out the book
  Patron *patron = getLibraryItem(ItemID)->getCheckedOutBy();

  //check if the patron is holding the book
  if(patron->getIdNum() != getLibraryItem(ItemID)->getCheckedOutBy()->getIdNum()) return "you are not holding the book";
  
  //get the patron and remove the book from them
  getPatron(patron->getIdNum())->removeLibraryItem(getLibraryItem(ItemID));

  //we put the status to be on the shelf again
  getLibraryItem(ItemID)->setLocation(ON_SHELF);

  return "book returned successfully";
}

string Library::requestLibraryItem(string patronID, string ItemID)
{
  int val = 0;
  int val2 = 0;
  for (size_t i = 0; i < holdings.size(); i++) {
    if(ItemID == holdings.at(i)->getIdCode()){
      val = i;
      i = holdings.size();
    }
  }
  for (size_t k = 0; k < members.size(); k++) {
    if(patronID == members.at(k)->getIdNum()){
      val2 = k;
      k = members.size();
    }
  }

  if(ItemID != holdings.at(val)->getIdCode())
  {
    return "book not found";
  }
  if(patronID != members.at(val2)->getIdNum())
  {
    return "patron not found";
  }
  if(ItemID == holdings.at(val)->getIdCode() && patronID == members.at(val2)->getIdNum()){
    holdings.at(val)->setLocation(ON_HOLD_SHELF);
    return "request successful";
  }
  return "item already on hold";
}


string Library::payFine(string patronID, double payment)
{
  int val2 = 0;
  for (size_t k = 0; k < members.size(); k++) {
    if(patronID == members.at(k)->getIdNum()){
      val2 = k;
      k = members.size();
    }
  }

  if(members.at(val2)->getIdNum() == patronID){
    members.at(val2)->amendFine(payment);
    return "payment successful";
  }
  
  return "patron not found";
}

void Library::incrementCurrentDate()//
{
  currentDate++;
  cout << "total members: " << members.size() << endl;
  // cout << "member: " << members.at(0)->getIdNum() << endl;
  members.at(0)->getCheckedOutItems();
  // cout << "books checked out: " << members.at(0)->getCheckedOutItems().size() << endl;
  // for (size_t x = 0; x < members.size(); x++){
  
    // for (size_t y = 0; y < members.at(x)->getCheckedOutItems().size(); y++) {
    //   if (currentDate > members.at(x)->getCheckedOutItems().at(y)->getCheckOutLength() + members.at(x)->getCheckedOutItems().at(y)->getDateCheckedOut()){
    //     members.at(x)->amendFine(-0.1);
    //   }
    // }
  // }
}

Patron* Library::getPatron(string patronID)
{
  int val2 = 0;
  for (size_t k = 0; k < members.size(); k++) {
    if(patronID == members.at(k)->getIdNum()){
      val2 = k;
      k = members.size();
    }
  }
  return members.at(val2);
}



LibraryItem* Library::getLibraryItem(string ItemID)
{
  int val = 0;
  for (size_t i = 0; i < holdings.size(); i++) {
    if(ItemID == holdings.at(i)->getIdCode()){
      val = i;
      i = holdings.size();
    }
  }
  return holdings.at(val);
}
