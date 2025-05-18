//
// Created by Lucas on 4/14/2025.
//

#include "Song.h"
#include <sstream>
#include <algorithm>


auto remove_numbers_and_punctuation = [](unsigned char c){return std::ispunct(c) || std::isdigit(c);};

Song::Song(std::string artist, std::string title, std::string lyrics) {
    this->artist = move(artist);
    this->title = move(title);

    std::stringstream ss(lyrics);
    std::string word;

    std::transform(lyrics.begin(), lyrics.end(), lyrics.begin(),
                    [](unsigned char c){ return std::tolower(c); });

    while (ss >> word) {
        word.erase(std::remove(
            word.begin(), word.end(),
            remove_numbers_and_punctuation), word.end());

        if (!word.empty()) {
            this->lyricsWords.push_back(word);
        }
    }
}

std::string Song::getArtist() {
    return artist;
}

std::string Song::getTitle() {
    return title;
}

std::vector<std::string> Song::getLyricsWords() {
    return lyricsWords;
}
