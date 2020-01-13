//
// Created by ratik on 10/23/19.
//

#include "json.hpp"
#include <fstream>
#include <vector>
#include <ctime>
#include <iostream>
#include "quicksort.h"
#include <sys/timeb.h>
#include "insertionsort.h"
#include "mergesort.h"
#include <iomanip>

using namespace std;

std::vector<int> get_vector(nlohmann::basic_json<> vec){
    vector <int> vect;
    for(int i  = 0; i <= vec.size() - 1; i++){
        vect.push_back(vec[i]);
    }
    return vect;
}

int get_count(){
    timeb tb;
    ftime(&tb);
    int count = tb.millitm + (tb.time & 0xfffff) * 1000;
    return count;
}

int time_span(int time_start){
    int span = get_count() - time_start;
    if(span < 0)
        span += 0x100000 * 1000;
    return span;
}

int main(int argc, char** argv) {
    if(argc <=2){
        std::ifstream file;
        file.open(argv[1]);
        nlohmann::json jsonObject;
        if(file.is_open()){
            file >> jsonObject;
        }
        // cout << jsonObject << endl;


        nlohmann::json metadataObj;
        nlohmann::json resultJSON;

        int val = (int)jsonObject["metadata"]["numSamples"];
        cout <<"Sample,InsertionSortTime,InsertionSortCompares,InsertionSortMemaccess,MergeSortTime,MergeSortCompares,MergeSortMemaccess,QuickSortTime,QuickSortCompares,QuickSortMemaccess" ;
        try{
            for(int i = 1; i <= val; i++) // Reading Sample1 to SampleN
            {
                string str;
                if(i<10)
                    str = "Sample0" + to_string(i);
                else
                    str = "Sample" + to_string(i);
                metadataObj[str] = jsonObject[str];
                vector<int> resultForInsertionSort ;
                vector<int> resultForQuickSort ;
                vector<int> resultForMergeSort ;

                std::cout << std::fixed;
                std::cout << std::setprecision(6);


                resultForInsertionSort = get_vector(metadataObj[str]);
                cout<<"\n"<<str<<',';
                int start1 = get_count();
                double milliSecondsElapsed1 = time_span(start1);
                cout<<milliSecondsElapsed1;
                InsertionSort(&resultForInsertionSort);


                resultForMergeSort = get_vector(metadataObj[str]);
                int start3 = get_count();
                double milliSecondsElapsed3 = time_span(start3);
                cout<<milliSecondsElapsed3;
                MergeSort(&resultForMergeSort);



                resultForQuickSort = get_vector(metadataObj[str]);
                int start = get_count();
                double milliSecondsElapsed = time_span(start);
                cout<<milliSecondsElapsed;
                QuickSort(&resultForQuickSort);

            }}catch (nlohmann::json::out_of_range &e){
        }
    }
}
