#include <vector>
#include <random>
#include <fstream>
#include <iostream>

using namespace std;

vector< vector<double> > random_walk(int dim, int num_steps, double step_size) {
    vector< vector<double> > history;

    // Random numbers
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distrib(0.0, 1.0);

    for (int t = 0; t < num_steps; t++) {
        vector<double> point;
        for (int i = 0; i < dim; i ++) {
            int coord = history.size() ? history.back()[i] : 0;
            int dir = distrib(gen) > 0.5 ? 1 : -1;
            point.push_back( coord + ( dir * step_size) );
        }
        history.push_back(point);
    }
    return history;
}

int main() {
    int dim = 3;

    // Walk
    vector< vector<double> > walk = random_walk(dim, 10000, 10);

    // Output
    ofstream out("walk.csv");

    // Write
    if(out.is_open()) {
        out << ( dim == 3 ?  "x,y,z" : (
            dim == 2 ? "x,y" : "x"
        ));
        out << endl;
        for (int i = 0; i < walk.size(); i++) {
            for(int j = 0; j < walk[i].size(); j++) {
                out << walk[i][j];
                out << ( (j == walk[i].size()-1) ? "\n" : ",") ;
            }
        }

        out.close();
    }

    return 0;
}