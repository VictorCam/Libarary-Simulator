#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <iostream>
#include <string>
#include "Library.hpp"
#include "LibraryItem.hpp"

using namespace std;

class Album: public LibraryItem
{
protected:
  string artist;
public:
  static const int CHECK_OUT_LENGTH = 14;
  Album(string idb, string bn, string ba);
  string getAlbumDirector();
  int getCheckOutLength();
};

#endif
