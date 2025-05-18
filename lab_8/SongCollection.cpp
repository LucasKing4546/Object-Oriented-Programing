//
// Created by Lucas on 4/14/2025.
//

#include "SongCollection.h"
#include <fstream>
#include <iostream>
#include <algorithm>

#include <cstring>

SongCollection::SongCollection(const std::string& path) {
    std::ifstream infile(path);
    if (!infile.is_open()) {
        throw std::invalid_argument("Unable to open file " + path);
    }

    std::string line;

    std::string artist, title, lyrics;

    while (std::getline(infile, line)) {
        if (!line.empty()) {
            if (strstr(line.c_str(), "Artist") != nullptr) {
                artist = strchr(line.c_str(), ' ') + 1;
            }
            else if (strstr(line.c_str(), "Song") != nullptr) {
                title = strchr(line.c_str(), ' ') + 1;
            }
            else if (strstr(line.c_str(), "Lyrics") != nullptr) {
                std::getline(infile, line);
                lyrics += line + '\n';
            }
            else {
                lyrics += line + '\n';
            }
        }
        else {
            this->songs.push_back(Song(artist, title, lyrics));
            artist.clear();
            title.clear();
            lyrics.clear();
        }
    }
}


std::set<std::string> SongCollection::getArtists() {
    std::set<std::string> artists;
    std::for_each(songs.begin(), songs.end(),
        [&artists](Song &s){artists.insert(s.getArtist());});
    return artists;
}

void SongCollection::sortArtistsBySongs() {
    std::set artists = this->getArtists();
    std::vector<std::string> results(artists.begin(), artists.end());
    std::map<std::string, std::vector<Song>> buckets;


    auto sort_by_number_of_songs = [&buckets](const std::string& a1, const std::string& a2) {
        return buckets[a1].size() > buckets[a2].size();
    };

    for (auto artist: artists) {
        for (auto song : this->songs) {
            if (song.getArtist() == artist) {
                buckets[artist].push_back(song);
            }
        }
    }

    std::sort(results.begin(), results.end(), sort_by_number_of_songs);
    std::cout << "Top 10 Artists: " << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout<< results[i] << std::endl;
    }
}

void SongCollection::sort_by_artist() {
    auto sort = [](Song& s1, Song& s2) {
        return s1.getArtist() < s2.getArtist();
    };

    std::sort(songs.begin(), songs.end(), sort);
}

void SongCollection::sort_by_title() {
    auto sort = [](Song& s1, Song& s2) {
        return s1.getTitle() < s2.getTitle();
    };

    std::sort(songs.begin(), songs.end(), sort);
}

void SongCollection::sort_by_words() {
    auto sort = [](Song& s1, Song& s2) {
        return s1.getLyricsWords().size() < s2.getLyricsWords().size();
    };

    std::sort(songs.begin(), songs.end(), sort);
}




