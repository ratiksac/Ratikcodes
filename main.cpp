#include <vector>
#include <iostream>
#include <fstream>
#include "/home/ratik/Desktop/json.hpp"
#include "priorityqueue.h"
#include "teamdata.h"
#include <cstdlib>
#include <string>

using namespace std;


int main(int argc,char** argv) {
    if(argc <=2){
        std::ifstream file;
        file.open(argv[1]);
        //   TeamData::Teamdata(file);
        nlohmann::json jsonObject;
        if(file.is_open()){
            file >> jsonObject;}
        // double l;
        //std::vector<float>h;
//cout<< ;
        // std::vector<int>l;

        try{
            PriorityQueue volleyBall(jsonObject["teamStats"].size()-1);
            for(int i = 0;i <= jsonObject["teamStats"].size()-1;i++){

                int playerOne = jsonObject["teamStats"][i]["playerOne"];
                //int playerTwo = 0;
                //double winPercent = 0;
                int playerTwo = jsonObject["teamStats"][i]["playerTwo"];
                double winPercent = abs( (double) jsonObject["teamStats"][i]["winPercentage"]- 50.0  );
                Key key = winPercent;
                //cout<<key;
                Value players = make_pair(playerOne,playerTwo);
                KeyValuePair kv = make_pair(key, players);
                volleyBall.insert(kv);


            vector<Value> teams;

            unsigned int l= 0;
            while(!volleyBall.isEmpty()) {
                // cout<< volleyBall.JSON().dump(2);

                Value team = volleyBall.removeMin().second;
                bool insert = true;

                for (Value localTeam : teams) {
                    if ((localTeam.first == team.first || localTeam.second == team.first ||
                         localTeam.first == team.second || localTeam.second == team.second)) {
                        insert = false;
                    }
                }

                if (insert || teams.empty()) {
                    teams.push_back(team);
                }
            }
//                       }

            //cout << volleyBall.JSON().dump(2);
            for(int i=0; i<teams.size();i++){
                cout<<"Team"<<i+1<<": "<<teams[i].first<<","<<teams[i].second;
                cout<<'\n';
            }

        }}
        catch (nlohmann::detail::type_error &e){
            cout << e.what();
        }

    }}
