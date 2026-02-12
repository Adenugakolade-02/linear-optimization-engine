//learning matrix multiplication fundamentals in cpp
#include <iostream>
#include <vector>


//Defining prototypes
std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB);
void printMatrix(const std::vector<std::vector<int>>& matrix);

int main(){
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6},
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 1},
        {2, 3}
    };

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A);
    
    std::cout << "\nMatrix B:" << std::endl;
    printMatrix(B);

    std::vector<std::vector<int>> C = multiplyMatrices(A, B);

    std::cout << "\nResult Matrix C:" << std::endl;
    printMatrix(C);

    return 0;
}


std::vector<std::vector<int>> multiplyMatrices(const std::vector<std::vector<int>>& matrixA, const std::vector<std::vector<int>>& matrixB){

    //Extracting row and column info
    int r1 = matrixA.size();
    int c1 = matrixA[0].size();
    int r2 = matrixB.size();
    int c2 = matrixB[0].size();

    //Column count of Matrix A must equal the Row count of Matrix B
    if(c1!=r2){
        std::cout << "Invalid Matrix Dimensions\n";
        return {};
    }

    // creating an empty matrix of dimension r1 * c2 intialized with zeros;
    std::vector<std::vector<int>> result(r1, std::vector<int>(c2, 0));

    // Matrix multiplication
    for (size_t i=0; i < r1; i++){                              //iterates through the row of martixA
        for (size_t j=0; j< c2; j++){                           //iterates through the column of matrixB
            for (size_t k=0; k < c1; k++){                      // gets the common dimension to use for the multiplication
                result[i][j] += matrixA[i][k] * matrixB[k][j];  
            }
        }
    }

    return result;
}

void printMatrix(const std::vector<std::vector<int>>& matrix){
    for( const auto& row: matrix){
        for(auto val : row){
            std::cout << val << "\t";
        }
        std::cout << std::endl;
    }
}
