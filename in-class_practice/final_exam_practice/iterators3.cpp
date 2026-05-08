#include <iostream>
#include <string>
#include <stdexcept>

struct Song {
    std::string title;
    int duration;
    Song() : title(""), duration(0) {}
    Song(const std::string& t, int d) : title(t), duration(d) {}
};

// TODO 1: Define a custom exception called InvalidSongError that inherits
//         from std::exception. It should accept and store a message string,
//         and return it from what().
class InvalidSongError : public std::exception {
private:
std::string message = "Song is invalid!";
public:
    InvalidSongError(std::string m) : message(m) {}

    const char* what() const noexcept override{
        return message.c_str();
    }
};

class Playlist {
public:
    static const int CAPACITY = 10;

    Playlist() : size_(0) {}

    // TODO 2: Implement addSong. It should throw:
    //         - InvalidSongError if duration <= 0
    //         - std::runtime_error if the playlist is full
    void addSong(const Song& s) {
        try{
            if (s.duration <= 0){
                throw InvalidSongError("Song's duration must be greater than zero!");
            }
            if (size_ == CAPACITY){
                throw std::runtime_error("Playlist is full!");
            }
            songs_[size_] = s;
            size_++;
        }catch (const InvalidSongError& e){
            std::cerr << e.what() << std::endl;
        } catch (const std::runtime_error& e){
            std::cerr << e.what() << std::endl;
        }
    }

    // TODO 3: Implement removeSong by title.
    //         Throw std::invalid_argument if the title is not found.
    void removeSong(const std::string& title) {
        int title_idx = 0;
        for(;title_idx < size_; title_idx++){
            if((songs_[title_idx]).title == title){
                break;
            }
        }

        try{
            if (title_idx == size_){
                throw std::invalid_argument("Title not found");
            }

            while(title_idx < size_ - 1){
                songs_[title_idx] = songs_[title_idx + 1];
                title_idx++;
            }
            size_--;

        }catch (const std::invalid_argument& e){
            std::cerr << e.what() << std::endl;
        }
    }

    class Iterator {
        Song* songs_;
        int index_;
    public:
        // TODO 4: Implement the iterator constructor, operator*, operator++,
        //         and operator!=
        Iterator(Song* s, int i) : songs_(s), index_(i) {}

        Song& operator*() const {
            return songs_[index_];
        }

        Iterator& operator++() {
            index_++;
            return *this;
        }

        bool operator!=(const Iterator& other){
            return (index_ != other.index_);
        }
    };

    // TODO 5: Implement begin() and end()
    Iterator begin() { return Iterator(songs_, 0); }
    Iterator end()   { return Iterator(songs_, size_); }

    int size() const { return size_; }

private:
    Song songs_[CAPACITY];
    int size_;
};

int main() {
    Playlist p;

    // TODO 6: Wrap in a try/catch — add valid songs, then try adding:
    //         a) a song with duration 0
    //         b) a song with negative duration
    //         Print the exception message in the catch block.
    
    // TODO 7: Wrap in a try/catch — try removing a song that doesn't exist.
    //         Print the exception message in the catch block.

    // TODO 8: Use a range-based for loop to print all songs.

    // TODO 9: Use an explicit iterator loop to calculate and print
    //         the average duration of all songs.

    return 0;
}