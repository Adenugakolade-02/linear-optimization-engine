#include <vector>
#include <iostream>

class Matrix{
    private:
        std::vector<std::vector<double>> matrix;

        

    public:
        Matrix(std::vector<std::vector<double>> matrix) : matrix(matrix) {}

        std::vector<std::vector<double>> transpose(){
            int row = matrix.size();
            int column = matrix[0].size();

            std::vector<std::vector<double>> new_matrix(column, std::vector<double>(row, 0));

            for (size_t i = 0; i < row; i++){
                for (size_t j = 0; j < column; j++){
                    new_matrix[j][i] = matrix[i][j];
                }
            }

            return new_matrix;
        }

        std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> rhs){
            int r1 = matrix.size();
            int c1 = matrix[0].size();
            int r2 = rhs.size();
            int c2 = rhs[0].size();

            if(c1!=r2){
                std::cout << "Invalid Matrix Dimensions\n";
                return {};
            }

            std::vector<std::vector<double>> result(r1, std::vector<double>(c2, 0));

            for (size_t i=0; i < r1; i++){                              //iterates through the row of martixA
                for (size_t j=0; j< c2; j++){                           //iterates through the column of matrixB
                    for (size_t k=0; k < c1; k++){                      // gets the common dimension to use for the multiplication
                        result[i][j] += matrix[i][k] * rhs[k][j];  
                    }
                }
            }
            return result;
        }

        std::vector<std::vector<double>> elementWiseDivision(double value){
            int row = matrix.size();
            int column = matrix[0].size();

            std::vector<std::vector<double>> newMatrix(row, std::vector<double>(column, 0));

            for (size_t i = 0; i < row; i++){
                for (size_t j = 0; j < column; j++){
                    newMatrix[i][j] = matrix[i][j] / value;
                }
            }
        }

        std::vector<double> rowSlice(int row){
            return matrix[row];
        }

        std::vector<double> columnSlice(int column){
            int row = matrix.size();
            int column = matrix[0].size();

            std::vector<double>newColumn;

            for (size_t i = 0; i < row; i++){
                newColumn.push_back(matrix[i][column]);
            }
        }
};
