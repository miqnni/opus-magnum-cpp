#include <iostream>
using std::cout;
using std::endl;

namespace my_types
{
    typedef int objheight_t;
    typedef int objwidth_t;
}

using Objarea = double;

Objarea calculate_container_area(my_types::objwidth_t width, my_types::objheight_t height)
{
    return (Objarea)(width * height);
}

namespace my_types
{
    using Objmass = unsigned long int;
}

main()
{
    struct sample_object
    {
        my_types::objwidth_t my_width_m;
        my_types::objheight_t my_height_m;
        my_types::Objmass my_mass_kg;
    };

    sample_object katowice_superunit_wall{
        188,
        51,
        900000,
    };

    Objarea katowice_superunit_wall_area{calculate_container_area(katowice_superunit_wall.my_width_m, katowice_superunit_wall.my_height_m)};
    cout << "Object area: " << katowice_superunit_wall_area << endl;

    return 0;
}
