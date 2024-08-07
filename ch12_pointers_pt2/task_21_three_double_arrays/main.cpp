#include <iostream>
#include <iomanip> // std::setw()

void createThirdArray(double arrIn0[], double arrIn1[], double arrOut[], double commonSize)
{
    for (int i{}; i < commonSize; i++)
        arrOut[i] = arrIn0[i] * arrIn1[i];
}

int main()
{
    int defaultSize{25};
    double *arr0 = new double[defaultSize];
    double *arr1 = new double[defaultSize];
    double *arr2 = new double[defaultSize];

    for (int i{}; i < defaultSize; i++)
    {
        arr0[i] = 0.3 * (i + 2) / 6;
        arr1[i] = 215.6 / (1 + 3 * i * i);
    }

    createThirdArray(arr0, arr1, arr2, defaultSize);

    for (int i{}; i < defaultSize; i++)
    {
        std::cout << i << ":\t" << std::setw(5) << arr0[i]
                  << "\t" << std::setw(12) << arr1[i]
                  << "\t" << std::setw(12) << arr2[i] << std::endl;
    }

    delete[] arr0;
    delete[] arr1;
    delete[] arr2;
    arr0 = nullptr;
    arr1 = nullptr;
    arr2 = nullptr;

    return 0;
}
