#include <iostream>

constexpr int ARR_SIZE = 8000;

int main()
{
    const int alignment = alignof(long); // alignof(type_name)

    alignas(alignment) char my_byte;
    alignas(alignof(long)) char big_arr[ARR_SIZE];

    std::cout << "Alignment value: " << alignment << std::endl;
    my_byte = 'c';
    big_arr[0] = 'b';
    std::cout << my_byte << big_arr[0] << std::endl;

    return 0;
}
