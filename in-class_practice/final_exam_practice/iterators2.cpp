#include <iostream>
#include <string>

struct Song {
    std::string title;
    int duration;
    Song() : title(""), duration(0) {}
    Song(const std::string& t, int d) : title(t), duration(d) {}
};

class SongQueue {
public:
    static const int CAPACITY = 10;

    SongQueue() : size_(0) {}

    void enqueue(const Song& s) {
        if (size_ < CAPACITY) songs_[size_++] = s;
    }

    class Iterator {
        // TODO 1: What data does this iterator need to track its position?
        //         Hint: it needs access to the array and its current index.
        int index_;
        Song* songs_;
    public:
        // TODO 2: Write a constructor for the iterator
        Iterator(Song* songs, int val) : songs_(songs), index_(val){}
        // TODO 3: Implement operator* — return the Song at current position
        Song& operator*() const {
            return (songs_[index_]);
        }

        // TODO 4: Implement operator++ — advance to the next slot
        Iterator& operator++() {
            index_++;
            return *this;
        }

        // TODO 5: Implement operator!= 
        bool operator!=(const Iterator& other) const {
            return (index_ != other.index_);
        }
    };

    // TODO 6: Implement begin() — iterator pointing to first song
    Iterator begin() {
        return (Iterator(songs_, 0));
    }

    // TODO 7: Implement end() — iterator pointing one past the last song
    Iterator end() {
        return (Iterator(songs_, size_));
    }

    int size() const { return size_; }

private:
    Song songs_[CAPACITY];
    int size_;
};

int main() {
    SongQueue queue;
    queue.enqueue({"Moonlight Sonata", 337});
    queue.enqueue({"Symphony No. 5",   498});
    queue.enqueue({"Fur Elise",        175});
    queue.enqueue({"Ode to Joy",       222});

    // TODO 8: Use a range-based for loop to print each song's title and duration
    for (Song s : queue){
        std::cout << "Title - " << s.title << ", Duration - " << s.duration << std::endl;
    }
    // TODO 9: Use an explicit iterator loop to find and print
    //         the longest song's title
    Song longest = Song("Short", 0);
    for(auto it = queue.begin(); it != queue.end(); ++it){
        if((*it).duration > longest.duration){
            longest = *it;
        }
    }
    std::cout << "Longest song: " << longest.title << std::endl;

    return 0;
}