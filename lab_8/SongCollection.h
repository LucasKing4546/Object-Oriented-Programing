//
// Created by Lucas on 4/14/2025.
//

#ifndef SONGCOLLECTION_H
#define SONGCOLLECTION_H
#include <map>
#include <vector>
#include <set>
#include "Song.h"

class SongCollection {
private:
    std::vector<Song> songs;
public:
    SongCollection(const std::string& path);
    std::set<std::string> getArtists();
    void sortArtistsBySongs();
    void sort_by_artist();
    void sort_by_title();
    void sort_by_words();

};

#endif SONGCOLLECTION_H
