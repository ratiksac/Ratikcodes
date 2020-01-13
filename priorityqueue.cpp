#include <iostream>
#include "priorityqueue.h"
#include "/home/ratik/Desktop/json.hpp"
#include <algorithm>
using namespace std;

using namespace std;
PriorityQueue::PriorityQueue(std::size_t max_size) : nodes_(max_size + 1, KeyValuePair()),
                                                     max_size_(max_size),
                                                     size_(0)
{
}

void PriorityQueue::insert(Key k)
{
    insert(std::make_pair(k, std::make_pair(0, 0)));
}

void PriorityQueue::insert(KeyValuePair kv)
{
    // TODO: complete this function
    if (size_ == 0)
    {
        nodes_[0] = kv;
    }else{
        nodes_.push_back(kv);
       // nodes_[size_] = kv;
       // cout << kv.first;
        //size_++;

        }
     //cout << nodes_.size();
    size_++;
    heapifyUp(size_ - 1);
//    size_ += 1;
//    heapifyUp(size_-1);
    if(size_>max_size_) {
        max_size_ = size_;
    }
}



KeyValuePair PriorityQueue::min()
{
    // TODO: complete this function
    if (isEmpty())
        return KeyValuePair(0, Value(0, 0));
    else
        return nodes_[0];
}


KeyValuePair PriorityQueue::removeMin()
{
    // TODO: complete this function

    nodes_[0] = nodes_.back();
    //KeyValuePair re = nodes_.back();
    nodes_.pop_back();
    size_ -= 1;
    heapifyDown(0);
   /// return re;
}

bool PriorityQueue::isEmpty() const
{
    // TODO: complete this function
    if (size_ > 0)
        return false;
    else
        return true;
}

size_t PriorityQueue::size()
{
    // TODO: complete this function
    return size_;
}


nlohmann::json PriorityQueue::JSON() const
{
    nlohmann::json result;
    for (size_t i = 0; i < size_; i++)
    {
        nlohmann::json node;
        KeyValuePair kv = nodes_[i];
        node["key"] = kv.first;
        node["value"] = kv.second;
        if ((i+1) != ROOT)
        {
            node["parent"] = std::to_string((i-1) / 2 + 1);
        }
        if (2 * i + 1 < size_)
        {
            node["leftChild"] = std::to_string(2 * i + 2);
        }
        if (2 * i + 2 < size_)
        {
            node["rightChild"] = std::to_string(2 * i + 3);
        }
        result[std::to_string(i + 1)] = node;
    }
    result["metadata"]["max_size"] = max_size_;
    result["metadata"]["size"] = size_;
    return result;
}

void PriorityQueue::heapifyUp(size_t i)
{
    int parent = (i-1) / 2;
    if (i && nodes_[parent].first > nodes_[i].first)
    {
        // std::swap(*nodes_[i].first, *nodes_[parent].first);
        double temp = nodes_[i].first;
        nodes_[i].first = nodes_[parent].first;
        nodes_[parent].first = temp;

        Value valueTemp =  nodes_[i].second;
        nodes_[i].second = nodes_[parent].second;
        nodes_[parent].second = valueTemp;
        // std::cout << nodes_[parent].first << std::endl;
        // std::cout << nodes_[i].first << std::endl;
        i = parent;
        heapifyUp(i);
    }
}

void PriorityQueue::heapifyDown(size_t i)
{
    // get left and right child of node at index i
    unsigned int left = 2 * i + 1;
    unsigned int right = 2 * i + 2;
    unsigned int smallest = i;

    // compare A[i] with its left and right child
    // and find smallest value
    if (left < size() && nodes_[left].first < nodes_[i].first)
        smallest = left;

    if (right < size() && nodes_[right].first < nodes_[smallest].first)
        smallest = right;

    // swap with child having lesser value and
    // call heapify-down on the child
    if (smallest != i)
    {
        // std::swap(nodes_[i].first, nodes_[smallest].first);
        int temp = nodes_[i].first;
        nodes_[i].first = nodes_[smallest].first;
        nodes_[smallest].first = temp;

        Value tempValue = nodes_[i].second;
        nodes_[i].second = nodes_[smallest].second;
        nodes_[smallest].second = tempValue;

        heapifyDown(smallest);
    }
}

void PriorityQueue::removeNode(size_t i)
{
    nodes_.erase(nodes_.begin());
}

void PriorityQueue::insert_create(KeyValuePair kv) {
    if (size_ == 0)
    {
        nodes_[0] = kv;
    }else{
       // nodes_.push_back(kv);
         nodes_[size_] = kv;
        // cout << kv.first;
        //size_++;

    }
    //cout << nodes_.size();
    size_++;
    heapifyUp(size_ - 1);
//    size_ += 1;
//    heapifyUp(size_-1);
    if(size_>max_size_) {
        max_size_ = size_;
    }
}
KeyValuePair PriorityQueue::removeMin1() {
    nodes_[1]=nodes_.back();
    nodes_.pop_back();
    heapifyDown(1);
    size_--;
    // TODO: complete this function
}


Key PriorityQueue::getKey(size_t i) {
    return 0;
}
void PriorityQueue::heapifyUp1(size_t i) {
    if(nodes_[i].first<nodes_[i/2].first){
        std::swap(nodes_[i].first,nodes_[i/2].first);
        heapifyUp(i / 2);
    }
    // TODO: complete this function
}