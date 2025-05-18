//
// Created by Lucas on 4/14/2025.
//

#ifndef SONG_H
#define SONG_H
#include <vector>
#include <string>

class Song {
protected:
    std::string artist;
    std::string title;
private:
    std::vector<std::string> lyricsWords;
public:
    Song(std::string artist, std::string title, std::string lyrics);

    std::string getArtist();
    std::string getTitle();
    std::vector<std::string> getLyricsWords();
};

#endif SONG_H


