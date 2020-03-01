//#include "stdafx.h"
#include "Song.h"

// Default constructor
// --------------------------------------------------------------------------
 // Note: you don't need to initialize std::strings.
 //std::string is an object which is initialized as an empty string by its
 //own constructor.
 // -------------------------------------------------------------------------- 
Song::Song()
{}

Song::Song(const std::string& title, const std::string& artist, 
           const std::string& genre, double length)
{
    songTitle = title;
    artistName = artist;
    songGenre = genre;
    songLength = length;
}

void Song::setSongTitle(const std::string& st)
{
    songTitle = st;
}


void Song::setArtistName(const std::string& ar)
{
    artistName = ar;
}


void Song::setSongGenre(const std::string& sg)
{
    songGenre = sg;
}


void Song::setSongLength(double sl)
{
    songLength = sl;
}

std::string Song::getSongName()
{
    return songTitle;
}

std::string Song::getArtistName()
{
    return artistName;
}

std::string Song::getSongGenre()
{
    return songGenre;
}

double Song::getSongLength()
{
    return songLength;
}