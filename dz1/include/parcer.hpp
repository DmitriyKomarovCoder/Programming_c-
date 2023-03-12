#pragma once

#include <string>
#include <fstream>
#include <sstream>

#include <vector>
#include <unordered_map>
#include <algorithm>

#include "../include/Movie.hpp"
#include "../include/movie_const.hpp"


bool read_ratings_file(const std::string& file_name_ratings, std::unordered_map<std::string, float>& title_rating);
bool read_title_file(const std::string& file_name_title, std::unordered_map<std::string, std::string>& title_rus);
bool read_basics_file(const std::string& file_name_basics, const std::string& date, 
                      const std::unordered_map<std::string, float>& title_rating, 
                      const std::unordered_map<std::string, std::string>& title_rus, 
                      std::vector<Movie>& movies);