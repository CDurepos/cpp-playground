#include "walk.h"
#include <fstream>
#include <iostream>

int main() {
    std::ofstream out("monte-carlo.csv");

    if(out.is_open()) {
        out << "final_pos";
        out << endl;
        for(int i = 0; i < 10000; i++) {
            out << random_walk(1000, 4).back();
            out << endl;
        }

        out.close();
    }

    return 0;
}