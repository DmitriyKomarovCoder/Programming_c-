// Copyright 2023 Kosmatoff

#include "Movie.hpp"

std::ostream& operator<<(std::ostream& os, const std::vector<Movie>& movies) {
    for (const auto& movie : movies) {
        os << movie.title << std::endl;
    }
    return os;
}