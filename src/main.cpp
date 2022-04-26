#include <iostream>
#include <windows.h>
#include "../include/LibraryItem.hpp"
#include "../include/Patron.hpp"
#include "../include/Library.hpp"


using namespace std;

int main() {
  Book b1("123", "C++ Early Objects", "Godfrey");
  Book b2("456", "Python for beginners", "Millar");
  Album a1("001", "Red", "Taylor");
  Album a2("002", "New Eyes", "Elisabeth");
  Movie m1("111", "Jurassic Park", "Steven");
  Movie m2("222", "Zootopia", "Byron");
  Patron p1("abc", "Daunte");
  Patron p2("def", "Helios");
  Patron p3("ghi", "Coopy");
  Library lib;
  lib.addPatron(&p1);
  lib.addPatron(&p2);
  lib.addPatron(&p3);
  lib.addLibraryItem(&b1);
  lib.addLibraryItem(&b2);
  lib.addLibraryItem(&a1);
  lib.addLibraryItem(&a2);
  lib.addLibraryItem(&m1);
  lib.addLibraryItem(&m2);
  cout << lib.checkOutLibraryItem("abc","123") << endl;
  cout << lib.checkOutLibraryItem("abc","002") << endl;


  //return invalid id [rli1]
  cout << "rli1 " << lib.returnLibraryItem("xxx") << endl;

  //return valid and existing id [rli2]
  cout << "rli2 " << lib.returnLibraryItem("123") << endl;

  //return valid but unowned id [rli3]
  cout << "rli3 " << lib.returnLibraryItem("456") << endl;


  cout << lib.requestLibraryItem("def","123") << endl;
  cout << lib.checkOutLibraryItem("ghi","001") << endl;
  cout << lib.checkOutLibraryItem("ghi","002") << endl;
  cout << lib.checkOutLibraryItem("ghi","123") << endl;
  // for (int i = 0; i < 25; i++) {
    lib.incrementCurrentDate();
  // }

  // cout << lib.payFine("abc", -0.4) << endl;
  // double p1Fine = p1.getFineAmount();
  // cout << lib.payFine("ghi", -0.8) << endl;
  // double p2Fine = p2.getFineAmount();
  
  return 0;
}
