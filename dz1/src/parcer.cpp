#include "../include/parcer.hpp"

bool read_ratings_file(const std::string& file_name_ratings, std::unordered_map<std::string, float>& title_rating) { // читаем и сохраняем в map данные по условию > 1000
    std::ifstream file_ratings(file_name_ratings);
    if (!file_ratings.is_open()) {
        return false;
    }

    std::string line;
    std::getline(file_ratings, line); 
    std::string tconst, average_Rating, num_Votes; 

    while (std::getline(file_ratings, line)) { // читаем данные из файла
        std::stringstream ss(line);
        std::string tconst, average_Rating, num_Votes; 

        std::getline(ss, tconst, splitter);
        std::getline(ss, average_Rating, splitter);
        std::getline(ss, num_Votes, splitter);
        
        int num_votes = std::stoi(num_Votes);
        if (num_votes >= 1000) { // проверка на условия по рейтингу
            float rating = std::stof(average_Rating);
            title_rating[tconst] = rating;
        }
    }
    return true;
}

bool read_title_file(const std::string& file_name_title, std::unordered_map<std::string, // читаем и сохраняем в map данные по условию "RU"
                     std::string>& title_rus) {
                      
    std::ifstream file_title(file_name_title);
    if (!file_title.is_open()) {
        return false;
    }
    std::string line;
    std::getline(file_title, line); 
    std::string title_id, indif, title_language, language;

    while (std::getline(file_title, line)) {
        std::stringstream ss(line);
        
        std::getline(ss, title_id, splitter);
        std::getline(ss, indif, splitter);
        std::getline(ss, title_language, splitter);
        std::getline(ss, language, splitter);
        
        if (language == "RU") {
            title_rus[title_id] =  title_language;
        }
    }
    return true;
}

bool read_basics_file(const std::string& file_name_basics, const std::string& date, 
                      const std::unordered_map<std::string, float>& title_rating, 
                      const std::unordered_map<std::string, std::string>& title_rus, 
                      std::vector<Movie>& movies) {
    std::ifstream file_basics(file_name_basics);
    if (!file_basics.is_open()) {
        return false;
    }
    std::string line;
    std::getline(file_basics, line); // пропуск заголовка

    while (std::getline(file_basics, line)) {
        
        std::stringstream ss(line);
        std::string tconst, title_type, primary_title, original_title, is_adult_str, start_year_str;

        std::getline(ss, tconst, splitter);
        std::getline(ss, title_type, splitter);
        std::getline(ss, primary_title, splitter);
        std::getline(ss, original_title, splitter);
        std::getline(ss, is_adult_str, splitter);
        std::getline(ss, start_year_str, splitter);

        if ( (title_type == movie || title_type == movie_tv) && !std::stoi(is_adult_str) && start_year_str == date) {
            auto it_rating = title_rating.find(tconst);
            if (it_rating != title_rating.end()) {
                std::string title = primary_title;
                auto it_rus = title_rus.find(tconst);
                if (it_rus != title_rus.end()) {
                    title = it_rus->second;
                }
                movies.push_back({title, it_rating->second});
            }
        }
    }
    return true;
}
