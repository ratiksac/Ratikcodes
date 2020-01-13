//
// Created by ratik on 11/9/19.
//

#ifndef CREATETEAMS_PRIORITYQUEUE_H
#define CREATETEAMS_PRIORITYQUEUE_H

#include <vector>
#include <utility>
#include "/home/ratik/Desktop/json.hpp"

typedef double                  Key;
typedef std::pair<int, int>     Value;
typedef std::pair<Key, Value>   KeyValuePair;

class PriorityQueue {
public:
    explicit PriorityQueue(std::size_t max_nodes);
    void insert(Key k);
    void insert(KeyValuePair kv);
    KeyValuePair min();
    KeyValuePair removeMin();
    bool isEmpty() const;
    size_t size();
    nlohmann::json JSON() const;
    void insert_create(KeyValuePair kv);


private:
    void heapifyUp(size_t i);
    void heapifyDown(size_t i);
    void removeNode(size_t i);
    static Key getKey(size_t i);


    std::vector<KeyValuePair>   nodes_;
    size_t                      max_size_;
    size_t                      size_;

    const static size_t         ROOT = 1;
};  // class PriorityQueue


#endif //CREATETEAMS_PRIORITYQUEUE_H
