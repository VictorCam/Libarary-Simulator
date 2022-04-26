#include "../include/Album.hpp"
#include "../include/LibraryItem.hpp"

using namespace std;

Album::Album(string idb, string bn, string ba): LibraryItem(idb, bn)
{
  artist = ba;
}

string Album::getAlbumDirector()
{
  return artist;
}

int Album::getCheckOutLength()
{
  return CHECK_OUT_LENGTH;
}
