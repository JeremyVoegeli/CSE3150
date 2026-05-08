#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <algorithm>

struct Song {
    std::string title;
    int duration;  // seconds
    Song(const std::string& t, int d) : title(t), duration(d) {}
};

// TODO 1: Implement using iterators (no indexing with [])
// Print all songs in the playlist with their duration
void printPlaylist(const std::list<Song>& playlist) {
    for(auto it = playlist.begin(); it != playlist.end(); it++){
        std::cout << "Song - " << it->title << ", Duration - " << it->duration << std::endl;
    }
}

// TODO 2: Implement using iterators
// Return the total duration of all songs
int totalDuration(const std::list<Song>& playlist) {
    int total = 0;
    for(auto it = playlist.begin(); it != playlist.end(); it++){
        total += it->duration;
    }
    return total;
}

// TODO 3: Implement using iterators
// Remove all songs shorter than minDuration seconds
// Hint: be careful about iterator invalidation!
void removeShorterThan(std::list<Song>& playlist, int minDuration) {
    for(auto it = playlist.begin(); it != playlist.end();){
        if(it->duration < minDuration){
            playlist.erase(it);
        } else {
            it++;
        }
    }
}

// TODO 4: Implement using iterators
// Return a new vector<Song> with the playlist in reverse order
std::vector<Song> reversed(const std::list<Song>& playlist) {
    std::vector<Song> reversed;
    for(auto it = playlist.rbegin(); it != playlist.rend(); it++){
        reversed.push_back(*it);
    }
    return reversed;
}

// TODO 5: Implement using std::find_if and iterators
// Find and return an iterator to the first song with the given title
// Return playlist.end() if not found
std::list<Song>::const_iterator findSong(const std::list<Song>& playlist, const std::string& title) {
    auto it = std::find_if(playlist.begin(), playlist.end(), [&title](Song s){
        return s.title == title;
    });
    return it;
}

int main() {
    std::list<Song> playlist = {
        {"Moonlight Sonata", 337},
        {"Symphony No. 5",   498},
        {"Fur Elise",        175},
        {"Ode to Joy",       222},
        {"The Entertainer",  164}
    };

    printPlaylist(playlist);
    std::cout << "Total: " << totalDuration(playlist) << "s\n\n";

    removeShorterThan(playlist, 200);
    std::cout << "--- After removing short songs ---\n";
    printPlaylist(playlist);

    auto rev = reversed(playlist);
    std::cout << "--- Reversed ---\n";
    for (auto it = rev.begin(); it != rev.end(); ++it) {
        std::cout << it->title << "\n";
    }

    auto found = findSong(playlist, "Symphony No. 5");
    if (found != playlist.end()) {
        std::cout << "\nFound: " << found->title << "\n";
    }

    return 0;
}