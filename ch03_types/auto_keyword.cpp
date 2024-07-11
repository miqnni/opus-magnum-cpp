#include <iostream>

int main()
{
    const auto x_a{63L};
    constexpr auto x_b{64L};
    volatile auto x_c{65L};
    register auto x_d{66L};

    std::cout << "Step 0:" << std::endl
              << "\t A: " << x_a << std::endl
              << "\t B: " << x_b << std::endl
              << "\t C: " << x_c << std::endl
              << "\t D: " << x_d << std::endl
              << std::endl;

    auto y_a{x_a};
    auto y_b{x_b};
    auto y_c{x_c};
    auto y_d{x_d};
    // auto y_e; // error -- no initializer, cannot deduce type

    for (auto y_curr : {&y_a, &y_b, &y_c, &y_d})
        *y_curr += 10;

    std::cout << "Step 1:" << std::endl
              << "\t A: " << y_a << " (value changed!)" << std::endl
              << "\t B: " << y_b << " (value changed!)" << std::endl
              << "\t C: " << y_c << " (no volatile specifier)" << std::endl
              << "\t D: " << y_d << " (no register specifier)" << std::endl
              << std::endl;

    const auto z_a{y_a};
    constexpr auto z_b{x_b}; // y_b is not a constexpr, so we use x_b
    volatile auto z_c{y_c};
    register auto z_d{y_d};

    // z_a += 10; // error
    // z_b += 10; // error
    z_c += 10;
    z_d += 10;

    std::cout << "Step 2:" << std::endl
              << "\t A: " << z_a << " (value cannot be changed -- const)" << std::endl
              << "\t B: " << z_b << " (value cannot be changed -- constexpr)" << std::endl
              << "\t C: " << z_c << " (with volatile specifier)" << std::endl
              << "\t D: " << z_d << " (with register specifier)" << std::endl
              << std::endl;

    return 0;
}
