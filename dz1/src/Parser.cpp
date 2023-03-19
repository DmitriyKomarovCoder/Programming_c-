// Copyright 2023 Kosmatoff

#include "Parser.hpp"
#include "file.hpp"
#include "movie_const.hpp"

void Parser::parseRatingsFile(const std::string& fileNameRatings) {
    std::ifstream fileRatings = openFile(fileNameRatings);

    std::string line;
    std::string tconst, averageRating, numVotesStirng;

    while (std::getline(fileRatings, line)) {
        std::stringstream ss(line);

        std::string tconst, averageRating, numVotesStirng;
        std::getline(ss, tconst, splitter);
        std::getline(ss, averageRating, splitter);
        std::getline(ss, numVotesStirng, splitter);

        isRatingsFileCorrect(tconst, averageRating, numVotesStirng);

        int numVotes = std::stoi(numVotesStirng);
        if (numVotes >= 1000) {  // проверка на условие по рейтингу
            float rating = std::stof(averageRating);
            titleRating[tconst] = rating;
        }
    }
}

void Parser::parseTitleFile(const std::string& fileNameTitle) {
    std::ifstream fileTitle = openFile(fileNameTitle);

    std::string line;

    while (std::getline(fileTitle, line)) {
        std::string titleId, indif, titleLanguage, language;

        std::stringstream ss(line);

        std::getline(ss, titleId, splitter);
        std::getline(ss, indif, splitter);
        std::getline(ss, titleLanguage, splitter);
        std::getline(ss, language, splitter);

        isTitleCorrect(titleId, indif, titleLanguage, language);

        if (language == "RU") {
            titleRus[titleId] =  titleLanguage;
        }
    }
}

void Parser::parseBasicsFile(
      const std::string& fileNameBasics,
      const std::string& date,
      std::vector<Movie>& movies
) {
    std::ifstream fileBasics = openFile(fileNameBasics);

    std::string line;

    while (std::getline(fileBasics, line)) {
        std::stringstream ss(line);

        std::string tconst, titleType, primaryTitle;
        std::string originalTitle, isAdultStr, startYearStr;

        std::getline(ss, tconst, splitter);
        std::getline(ss, titleType, splitter);
        std::getline(ss, primaryTitle, splitter);
        std::getline(ss, originalTitle, splitter);
        std::getline(ss, isAdultStr, splitter);
        std::getline(ss, startYearStr, splitter);

        isBasicsFileCorrect(tconst, titleType, primaryTitle,
        originalTitle, isAdultStr, startYearStr);

        // зададим условия проверки
        bool isMovie = (titleType == movie);
        bool isNotAdult = !std::stoi(isAdultStr);
        bool isSameYear = (startYearStr == date);

        if (isMovie && isNotAdult && isSameYear) {
            auto itRating = titleRating.find(tconst);
            if (itRating != titleRating.end()) {
                std::string title = primaryTitle;
                auto ItRus = titleRus.find(tconst);
                if (ItRus != titleRus.end()) {
                    title = ItRus->second;
                }
                movies.push_back({title, itRating->second});
            }
        }
    }
}
