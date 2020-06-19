//
// Created by Chunel on 2020/6/20.
//

#include <iostream>
#include <chrono>
#include "ThreadPool.h"

using namespace std;

void func() {
    cout << " working void func ..." << endl;
}

void func2(int i) {
    cout << " working int func..." << endl;
}


int main() {
    ThreadPool pool(3);
    pool.start();

    for (int i = 0; i < 100; i++) {
        pool.appendTask([] { return func2(2); });
    }

    this_thread::sleep_for(chrono::milliseconds(1000));
    pool.stop();

    return 0;
}