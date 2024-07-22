#include <iostream>
#include <vector>

int main()
{
    std::vector<int> worstStudentsIds{16, 8, 21};

    std::cout << worstStudentsIds[1] << std::endl;
    std::cout << "Worst student count: " << worstStudentsIds.size() << std::endl;

    for (size_t i{0}; i < worstStudentsIds.size(); i++)
    {
        std::cout << "\t- Student #" << worstStudentsIds[i] << std::endl;
    }
    std::cout << std::endl;

    return 0;
}
