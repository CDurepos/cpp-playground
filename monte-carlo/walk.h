#include <vector>
#include <random>

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