#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

struct Entity {    // возможно стоит вынести их в отдельную функцию
    std::string title;
    bool rus;
};

struct Comparator_Entity {
    bool operator()(const Entity& a, const Entity& b) const {
        return a.rus > b.rus;
    }
};

bool read_file(std::string& file, std::string& date, std::vector<Entity>& entity);

void output_entity(std::vector<Entity>& entity);