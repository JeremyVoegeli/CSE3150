#include <iostream>
#include <memory>
#include <vector>
#include <string>

struct Artist;

struct Song {
    std::string title;
    std::weak_ptr<Artist> artist;  // non-owning back-reference

    Song(const std::string& t) : title(t) {}

    void printArtist() const {
        if (auto locked = artist.lock()) {
            std::cout << "Artist: " << locked->name << std::endl;
        } else {
            std::cout << "No artist." << std::endl;
        }
    }

    void printArtist() const;
};

struct Artist {
    std::string name;
    std::vector<std::unique_ptr<Song>> songs;  // Artist exclusively owns its songs

    Artist(const std::string& n) : name(n) {}

    void addSong(std::unique_ptr<Song> s) {
        songs.push_back(std::move(s));  // transfer ownership into vector
    }
};

int main() {
    // shared_ptr because we want to demo multiple owners + weak_ptr
    std::shared_ptr<Artist> a1 = std::make_shared<Artist>("Beethoven");

    // Set weak_ptr BEFORE moving — s1/s2 become nullptr after addSong
    auto s1 = std::make_unique<Song>("Moonlight Sonata");
    auto s2 = std::make_unique<Song>("Symphony No. 5");
    s1->artist = a1;
    s2->artist = a1;
    a1->addSong(std::move(s1));
    a1->addSong(std::move(s2));

    // Access songs through the vector, not s1/s2 (they're nullptr now)
    std::cout << "--- Before reset ---" << std::endl;
    for (const auto& song : a1->songs) {
        song->printArtist();  // prints "Artist: Beethoven"
    }

    // Save a raw pointer to a song so we can call printArtist() after reset
    Song* songRef = a1->songs[0].get();

    // Reset the only shared_ptr — Artist is destroyed, weak_ptrs expire
    a1.reset();

    std::cout << "--- After reset ---" << std::endl;
    songRef->printArtist();  // prints "No artist." — weak_ptr detected expiry

    return 0;
}