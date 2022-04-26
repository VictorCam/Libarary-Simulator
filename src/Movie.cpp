#include "../include/Movie.hpp"
#include "../include/LibraryItem.hpp"

using namespace std;

Movie::Movie(string idb, string bn, string ba): LibraryItem(idb, bn)
{
  director = ba;
}

string Movie::getMovieDirector()
{
  return director;
}

int Movie::getCheckOutLength()
{
  return CHECK_OUT_LENGTH;
}
