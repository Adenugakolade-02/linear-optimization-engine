#pragma once
#include <vector>
#include <iostream>
#include <limits>


class SimplexSolver{
    private:
        std::vector<std::vector<double>> matrix;
        int pivotRowIndex;
        int pivotColumnIndex;
        double pivotElement;

    public:
        SimplexSolver(const std::vector<std::vector<double>>& matrix): matrix(matrix), pivotRowIndex(-1), pivotColumnIndex(-1), pivotElement(0){}
        bool updatePivots(){
            int rows = matrix.size();
            int columns = matrix[0].size();

            //finding pivot column
            double minValue = 0;
            pivotColumnIndex = -1;
            for(size_t i =0; i < columns -1; i++){
                if(matrix.back()[i]< minValue){
                    minValue = matrix.back()[i];
                    pivotColumnIndex = i;
                }
            }
            if(pivotColumnIndex==-1) return false;

            //finding the pivot row
            double minRatio = std::numeric_limits<double>::max();
            pivotRowIndex = -1;

            for (size_t i = 0; i < rows - 1; i++){
                double columnVal = matrix[i][pivotColumnIndex];
                if(columnVal > 0){
                    double ratio = matrix[i].back() / columnVal;
                    if(ratio < minRatio){
                         minRatio = ratio;
                         pivotRowIndex = i;
                    }
                }
            }
            if(pivotRowIndex == -1){
                std::cerr << "Problem is unbounded." << std::endl;
                return false;
            }

            pivotElement = matrix[pivotRowIndex][pivotColumnIndex];
            return true;
        }

        void performRowReduction(){
            for (size_t i = 0; i < matrix[0].size(); i++){
                matrix[pivotRowIndex][i] /= pivotElement;
            }
        }

        void performRowOperations(){
            for(size_t i = 0; i < matrix.size(); i++){ 
                double factor = matrix[i][pivotColumnIndex];
                if (i == pivotRowIndex)
                    continue;;
                for(size_t j = 0; j < matrix[0].size(); j++){ 
                    matrix[i][j] -= factor * matrix[pivotRowIndex][j];
                }
            }
        }


        void solve(){
            while (updatePivots())
            {
                performRowReduction();
                performRowOperations();
            }

            std::cout << "Optimal Value: " << matrix.back().back() << std::endl;
        }
};