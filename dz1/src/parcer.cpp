#include "../include/parcer.hpp"
#include "../include/read.hpp"

static const std::string movie = "movie";
static const std::string movie_tv = "tvMovie";
static const char splitter = '\t';
static const std::string adult = "0";
static const std::string alfa = "йцукенгшщзхъфывапролджэячсмитьбюЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ";

bool is_rus(const std::string& str) {
    for(int i = 0; i < str.size(); i++) {
        if (str[0] == alfa[i]) {
            return true;
        }
    }
    return false;
}


void parcer_line(std::string& line, std::string& date, std::vector<Entity>& entity) {
    std::stringstream ss(line);
    std::string title = "";
    bool flag_title_type = false;
    bool flag_rus = false;
    bool flag_date = false;
    bool flag_adult = false;
    std::string token = "";

    while(std::getline(ss, token, splitter)) {
    
        if(flag_title_type && title == "") {
            title = token;
        }

        if(token == movie || token == movie_tv) {
            flag_title_type = true;
        }

        if (is_rus(token)) {
            flag_rus = true;
        }

        if (token == date) {
            flag_date = true;
        }
        
        if (!flag_adult && token == adult) {
            flag_adult = true;
        }
    
    }
    
    if (flag_adult && flag_date && flag_title_type) {
        Entity e1 = {title, flag_rus};
        entity.push_back(e1);
    }
    
}