#include <iostream>

char t[4][2][2];

int main()
{
    for (int i{}; i < 4; i++)
    {
        for (int j{}; j < 2; j++)
        {
            for (int k{}; k < 2; k++)
            {
                std::cout << "t[" << i << "][" << j << "][" << k << "]: " << t[i][j][k] << std::endl;
            }
        }
    }

    return 0;
}
