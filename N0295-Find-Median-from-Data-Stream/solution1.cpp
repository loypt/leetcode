//
//  main.cpp
//  LeetCode-Solution
//
//  Created by Loyio Hex on 2/28/22.
//

#include <iostream>
#include <chrono>
#include <vector>
#include <queue>

using namespace std;
using namespace std::chrono;

class MedianFinder {
    priority_queue<int, vector<int> ,less<int>> min_queue;
    priority_queue<int , vector<int>, greater<int>> max_queue;
public:
    MedianFinder() {
    }

    void addNum(int num) {
        if (min_queue.empty() || num <= min_queue.top()){
            min_queue.push(num);
            if (max_queue.size() + 1 < min_queue.size()){
                max_queue.push(min_queue.top());
                min_queue.pop();
            }
        }else{
            max_queue.push(num);
            if (max_queue.size() > min_queue.size()){
                min_queue.push(max_queue.top());
                max_queue.pop();
            }
        }
    }

    double findMedian() {
        if (min_queue.size() > max_queue.size()) {
            return min_queue.top();
        }else{
            return (min_queue.top() + max_queue.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main(int argc, const char * argv[]) {
    auto start = high_resolution_clock::now();

    // Main Start
    MedianFinder* medianFinder = new MedianFinder();
    medianFinder->addNum(1);
    medianFinder->addNum(2);
    cout << medianFinder->findMedian() << endl;
    medianFinder->addNum(3);
    cout << medianFinder->findMedian() << endl;
    // Main End

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Runnig time : " << duration.count() << "ms;" << endl;
    return 0;
}

