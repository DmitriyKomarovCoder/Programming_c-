// Copyright 2023 Kosmatoff
#pragma once

#include <string>
#include <fstream>

#include <iostream> 

//  пропускает 1 строку и возвращает поток
std::ifstream openFile(const std::string& fileName);

// проверка данных на валидность file ratings
void isRatingsFileCorrect(
    const std::string& tconst, const std::string& averageRating,
    const std::string& numVotesStirng);

// проверка данных на валидность file basics
void isBasicsFileCorrect(
    const std::string& tconst,  const std::string& titleType,
    const std::string& primaryTitle, std::string originalTitle,
    const std::string& isAdultStr, const std::string& startYearStr);

// проверка данных на валидность file akas
void isTitleCorrect(
    const std::string& titleId,
    const std::string& indif,
    const std::string& titleLanguage,
    const std::string& language);
