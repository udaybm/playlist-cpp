#ifndef MY_SONG_CLASS
#define MY_SONG_CLASS


#include <string>

class Song {
private:
public:
    //member variables
    std::string songTitle;
    std::string artistName;
    std::string songGenre;
    double songLength;// {0.0};

    // functions
    Song();
    Song(const std::string& title, const std::string& artist, 
         const std::string& genre, double length);

    // Sets a name for the song
    void setSongTitle(const std::string& st);
    
    // Sets the artist name of the song
    void setArtistName(const std::string& ar);

    // Sets the album name of the song
    void setSongGenre(const std::string& sg);

    //Sets the song length of the song
    void setSongLength(double sl);

    // Gets the name of the song
    std::string getSongName();

    // Gets the name of the artist
    std::string getArtistName();

    // Gets the album name of the song
    std::string getSongGenre();

    //Gets the song length of the song
    double getSongLength();
};


#endif // MY_SONG_CLASS 
