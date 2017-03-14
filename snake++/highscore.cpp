#include "highscore.h"

void highscore::save(scores add)
{


        std::vector<scores> highscores;

        highscores = load();

        highscores.push_back(add);
        highscores = sort(highscores);

        ofstream myfile (filename);

        int savenum;

        if (numscores < highscores.size())
                savenum = numscores;
        else
                savenum = highscores.size();

        for (int i = 0; i < savenum; i++)
        {
                myfile << highscores[i].score << delim << highscores[i].name << "\n";
        }
        myfile.close();
}

std::vector<scores> highscore::load()
{
        std::vector<scores> highscores;
        scores tmpscore;
        string line;

        ifstream myfile(filename);

        if (myfile.is_open())
        {
                int i = 0;

                while ( getline (myfile,line) )
                {

                        tmpscore = split(line);
                        highscores.push_back(tmpscore);
                }

                myfile.close();
        }

        return highscores;
}

scores highscore::split(std::string s)
{
        vector<string> tmpline;
        scores line;

        size_t pos = 0;
        std::string token;
        while ((pos = s.find(delim)) != std::string::npos) {
                token = s.substr(0, pos);
                tmpline.push_back(token);
                s.erase(0, pos + delim.length());
        }

        tmpline.push_back(s);

        line.score = std::stoi(tmpline[0]);
        line.name = tmpline[1];

        return line;
}

std::vector<scores> highscore::sort(std::vector<scores> highscores)
{

        std::sort(highscores.begin(), highscores.end(), compare);

        return highscores;


}

bool highscore::compare(const scores &a, const scores &b)
{
        return a.score > b.score;

}

bool highscore::topscore(std::vector<scores> highscores, scores newscore)
{
        if (highscores.size() < numscores)
                return true;
        else if (newscore.score > highscores[numscores-1].score)
                return true;
        else
                return false;


}

highscore::highscore()
{
        delim = ":";
        filename = "highscore.txt";
        numscores = 10;

}


highscore::~highscore()
{

}

