// Copyright 2023 Kosmatoff
#include "file.hpp"

std::ifstream openFile(const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    std::getline(file, line);
    return file;
}

void isRatingsFileCorrect(
    const std::string& tconst, const std::string& averageRating,
    const std::string& numVotesStirng
) {
    if (tconst.empty() || averageRating.empty() || numVotesStirng.empty()) {
        std::cerr << "ERROR: Argument is invalid 1" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void isBasicsFileCorrect(
     const std::string& tconst,  const std::string& titleType,
     const std::string& primaryTitle, std::string originalTitle,
      const std::string& isAdultStr, const std::string& startYearStr
) {
    if (tconst.empty() || titleType.empty() || primaryTitle.empty() ||
        originalTitle.empty() || isAdultStr.empty() || startYearStr.empty()) {
        std::cerr << "ERROR: Argument is invalid 2" << std::endl;
        exit(EXIT_FAILURE);
    }
}

void isTitleCorrect(
    const std::string& titleId,
    const std::string& indif,
    const std::string& titleLanguage,
    const std::string& language
) {
    if (titleId.empty() || indif.empty() || titleLanguage.empty() ||
        language.empty()) {
        std::cerr << "ERROR: Argument is invalid 3" << std::endl;
        exit(EXIT_FAILURE);
    }
}

