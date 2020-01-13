//
// Created by ratik on 11/9/19.
//

#ifndef CREATETEAMS_TEAMDATA_H
#define CREATETEAMS_TEAMDATA_H
#include <string>
class TeamData {

public:
    TeamData(std::string filename);
    int numPlayers() const;
    //double winPercentages(int i, int j) const { return winPercentages_[i][j]; }

private:
    // TODO: decide the type of this variable.
   // winPercentages_;

    int numPlayers_;

};  // class TeamData
#endif //CREATETEAMS_TEAMDATA_H
