#include <iostream>
#include <vector>
#include "simplex.h"
int main(){
    /*
    Z = 3x + 2y
    x + 2y <=4
    x + y <=3
    x,y>=0
    Extracting we have
    x + 2y +s1 = 4
    x + y + s2 = 3
     -3x - 2y -Z = 0
    */

    std::vector<std::vector<double>> tableau = {
        
        { 1,  2,  1,  0,  4}, 
        { 1,  1,  0,  1,  3},  
        {-3, -2,  0,  0,  0}  
        
        // {2, 3, 0, 1, 0, 0, 8},
        // {0, 2, 5, 0, 1, 0, 10},
        // {3, 2, 4, 0, 0, 1, 15},
        // {-3, -5, -4, 0, 0, 0, 0}
    };

    SimplexSolver solver(tableau);

    // Run the algorithm
    solver.solve();

    return 0;
}