#include <iostream>
#include <vector>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <sstream>
#include <algorithm>

#ifndef HIGHSCORE_H
#define HIGHSCORE_H

using namespace std;
struct scores{
        int score;
        string name;
};

class highscore{

        std::vector<scores> sort(std::vector<scores> highscores);
        scores split(std::string s);
        static bool compare(const scores &a, const scores &b);

        string delim;
        string filename;

public:
        highscore();
        ~highscore();
        void save(scores newscore);
        std::vector<scores> load();
        bool topscore(std::vector<scores> highscores, scores newscore);
        int numscores;

};

#endif
