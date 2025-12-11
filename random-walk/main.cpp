#include <vector>
#include <random>
#include <fstream>
#include <iostream>

using namespace std;

vector<double> random_walk(int num_steps, double step_size) {
    vector<double> steps;

    // Random numbers
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distrib(0.0, 1.0);

    for (int t = 0; t < num_steps; t++) {
        int x = steps.size() > 0 ? steps.back() : 0;
        int dir = distrib(gen) > 0.5 ? 1 : -1;
        steps.push_back( x + ( dir * step_size) );
    }

    return steps;
}

int main() {
    // Walk
    vector<double> walk = random_walk(100, 3.0);

    // Output
    ofstream out("walk.csv");
    out << "time,pos";
    out << endl;
    
    if(out.is_open()) {
        for (int i = 0; i < walk.size(); i++) {
            out << walk[i];
            out << ",";
            out << i;
            out << endl;
        }

        out.close();
    }

    return 0;
}