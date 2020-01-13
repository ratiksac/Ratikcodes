#include <iostream>
#include <fstream>
#include "json.hpp"
#include <vector>
using namespace std;

std::vector<int>check_mismatch(std::vector<int> &vec1, std::vector<int> &vec2){
    vector <int> vect;
    for(int i = 0; i < vec1.size(); i++){
        if(vec1[i] != vec2[i]){
            vect.push_back((i));
        }
    }
    return vect;
}

int main(int argc, char** argv) {
    if(argc <=3){
        std::ifstream file;
        std::ifstream file2;
        file.open(argv[1]);
        nlohmann::json jsonObject;
        file2.open(argv[2]);
        nlohmann::json jsonObject2;

        if(file.is_open()){
            file >> jsonObject;}
        if(file2.is_open()){
            file2 >> jsonObject2;}

        nlohmann::json metadataObj;
        nlohmann::json resultJSON;

        // cout << argv[1] << endl << argv[2] << endl;

        int val = (int)jsonObject["metadata"]["numSamples"];
        int sampleWithProblem = 0;
        try{
            for(int i = 1; i <= val; i++)
            {
                string str;
                if (i<10)
                    str = "Sample0" + to_string(i);
                else
                    str = "Sample" + to_string(i);
                metadataObj[str]=jsonObject[str];
                vector <int> vect1 = jsonObject[str];
                vector <int> vect2 = jsonObject2[str];
                vector <int> vect3 = check_mismatch(vect1, vect2);
                if(vect3.size() > 0) {
                    resultJSON[str][argv[1]] = jsonObject[str];
                    resultJSON[str][argv[2]] = jsonObject2[str];
                    sampleWithProblem++;
                }
                for(int j : vect3) {
                    resultJSON[str]["Mismatches"][to_string(j)] = {vect1[j], vect2[j]};
                }
            }
        }catch (nlohmann::json::out_of_range &e){
            std::cout << e.what() <<endl;}

        nlohmann::json metadataJson;
        metadataJson["File1"]["name"] = std::string(argv[1]);
        metadataJson["File1"]["arraySize"] = jsonObject["metadata"]["arraySize"];
        metadataJson["File1"]["numSamples"] = jsonObject["metadata"]["numSamples"];

        metadataJson["File2"]["name"] = std::string(argv[2]);
        metadataJson["File2"]["arraySize"] = jsonObject2["metadata"]["arraySize"];
        metadataJson["File2"]["numSamples"] = jsonObject2["metadata"]["numSamples"];

        metadataJson["samplesWithConflictingResults"] = sampleWithProblem;

        resultJSON["metadata"] = metadataJson;
        cout << resultJSON.dump(2) << "\n" << endl;



    }}