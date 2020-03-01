#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string> 
#include <vector>
#include "Playlist.h"
#include "song.h"

//using namespace std;
Playlist& askForSongs(Playlist& play);
std::vector<Playlist>& addNewPlaylist(std::vector<Playlist>& play);
void displayAllPlaylists(const std::vector<Playlist>& plays);
int exitMenu();
void waitForEnter();

// Main Menu
int main()
{
    std::vector<Playlist> to_play(1); // at least 1 default element
    int choice = 0;
    do {
        std::cout << "\n***************************************************\n"
                     "*                                                 *\n"
                     "*             Playlist Manager                    *\n"
                     "*                                                 *\n"
                     "***************************************************\n"
                     "Where would you like to start? \n\n"
                     "1. Add Songs\n"
                     "2. Add New Playlist\n"
                     "3. View All Playlists \n"
                     "4. Exit\n\n"
                     "Enter Your Choice: ";
        std::cin >> choice;
        std::cin.ignore(1);
        
        // Set the numeric output formatting.
        std::cout << std::fixed << std::showpoint << std::setprecision(2);

        // Respond to the user's menu selection.
        switch(choice) {
        case 1:     // Add songs to a playlist
            askForSongs(to_play.at(0));
            break;
        case 2:
            addNewPlaylist(to_play);
            break;
        case 3:
            displayAllPlaylists(to_play);
            break;
        case 4:
            std::cout << "Happy Listening!\n";
            choice = exitMenu();
            break;
        default:
            break;
        }
    } while (0 < choice && choice < 4);
    waitForEnter();
    return 0;
}

Playlist& askForSongs(Playlist& play)
{
    std::string title;
    do {
        int i = 1;
        std::cout << "\nInsert new song into playlist"
                     " - leave title empty to end insertion."
                     "\nEnter title of song# " << i << ": ";
        std::getline(std::cin, title);
        if(title.empty()) { break; }

        std::cout << "Enter artist for this song: ";
        std::string artist;
        std::getline(std::cin, artist);
        
        std::cout << "Enter genre for this song: ";
        std::string genre;
        std::getline(std::cin, genre);
        
        std::cout << "Enter duration (in mins) for this song: ";
        double song_duration = 0.0;
        std::cin >> song_duration;
        std::cin.ignore(1);

        std::cout << "\nAdding " << genre << " song \"" << title 
                  << "\" by " << artist << ". Running time: " 
                  << song_duration << " mins \n";
        i++;
        Song song(title, artist, genre, song_duration);
//        play.addSong(std::move(song));
    } while (!title.empty());
    return play;
}

std::vector<Playlist>& addNewPlaylist(std::vector<Playlist>& play)
{
    std::cout << "\nEnter Playlist Name: ";
    std::string n_playlist;
    std::getline(std::cin, n_playlist);
    Playlist just_created(n_playlist);

    std::cout << "\nYour new playlist "<<  n_playlist  << " has been added! \n\n";
    char option = 'n';
    do {
        std::cout << "Would you like to add songs to your new playlist "
                   <<  n_playlist  <<"? (Y/N) ";
        std::cin >> option;
        std::cin.ignore(1);
        option = option;//std::toupper(option);
     //while (option not_eq 'Y' and option not_eq 'N');
	}while ((option != 'Y' || option != 'y') && (option != 'N' || option != 'n'));
    
    if(option == 'Y') { askForSongs(just_created); }
    
    play.push_back(just_created);

    return play;
}

void displayAllPlaylists(const std::vector<Playlist>& plays)
{ 
	for(const auto& a : plays)  
		std::cout << a;  //for each a in list
}

//Exit Menu
int exitMenu()
{
    std::cout << "\n\n";
    std::cout << "Would you like to exit the program? (Y/N) ";
    char answ = 'N';
    std::cin >> answ;
    std::cin.ignore(1);
    if(answ == 'Y' || answ == 'y') {
        return 4;
    }
    return 3; // == show playlists
}

void waitForEnter()
{
    std::cout << "\nPress ENTER to continue...\n";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
 
 
