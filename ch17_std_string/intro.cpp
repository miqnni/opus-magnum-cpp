#include <iostream>
#include <string>

int main()
{
    char charArr[20] = {"Alabama!"};
    std::string s0{charArr};
    std::cout << s0 << std::endl;
    std::string s1{charArr, 4};
    std::cout << s1 << std::endl;

    std::string s2{13, '*'};
    std::string s3(13, '*');
    std::cout << s2 << std::endl;
    std::cout << s3 << std::endl;

    std::string sample({'a', 'b', 'c'});
    sample += "defghijklmnop";
    std::string s4(sample, 2, 5);
    std::cout << s4 << std::endl;

    return 0;
}
