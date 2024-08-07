// MODIFICATIONS TO `task_21_three_double_arrays/main.cpp`

double *arrayCreator(int whatSize)
{
    return new double[whatSize];
}

int main()
{
    int defaultSize{25};
    double *arr0 = arrayCreator(defaultSize);
    double *arr1 = arrayCreator(defaultSize);
    double *arr2 = arrayCreator(defaultSize);

    // The same code as in Task 21.

    delete[] arr0;
    delete[] arr1;
    delete[] arr2;
    arr0 = nullptr;
    arr1 = nullptr;
    arr2 = nullptr;

    return 0;
}
