#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Library.hpp"
#include "LibraryItem.hpp"

using namespace std;

class Movie: public LibraryItem
{
protected:
    string director;
public:
  static const int CHECK_OUT_LENGTH = 7;
  Movie(string idb, string bn, string ba);
  string getMovieDirector();
  int getCheckOutLength();
};

#endif
