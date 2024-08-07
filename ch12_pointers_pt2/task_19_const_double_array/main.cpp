#include <iostream>

void display(const double arr[], int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << i << ": " << arr[i] << std::endl;
    }
}

int main()
{
    const double ar[]{2.5, 3.1, 2.764, 4.92, 5.6, -1.7, 5.012};
    int arSize = sizeof(ar) / sizeof(double);

    display(ar, arSize);
    return 0;
}