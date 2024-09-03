#include <iostream>
#include <iomanip>
#include <string>

namespace myManip
{
    class center
    {
    private:
        using FillWidthType = unsigned int;
        std::string arg;
        FillWidthType width;

    public:
        // center(std::string arg) : arg(arg), width(-1) {}
        center(std::string arg, FillWidthType width = -1) : arg(arg), width(width) {}

        void run(std::ostream &os)
        {
            if (width == -1)
                width = os.std::ios::width();

            if (width <= arg.size())
            {
                os << arg;
                return;
            }

            FillWidthType fillWidthTotal{width - arg.size()};
            FillWidthType fillWidthLeft{fillWidthTotal / 2};
            FillWidthType fillWidthRight{fillWidthTotal - fillWidthLeft};

            std::ios::fmtflags currentFlagState{os.std::ios::flags()};

            os.std::ios::setf(std::ios::right, std::ios::adjustfield);
            os << std::setw(0); // !!! (Or, without this line, concatenate the strings in the line below instead of using miltiple `<<`.)
            os << std::string(fillWidthLeft, os.std::ios::fill()) << arg << std::string(fillWidthRight, os.std::ios::fill());

            // Reset previous flags.
            os.std::ios::flags(currentFlagState);
        }
    };
}

std::ostream &operator<<(std::ostream &os, myManip::center manip)
{
    manip.run(os);
    return os;
}

int main()
{
    std::cout << std::setfill('-');
    std::cout << "[" << std::setw(27) << myManip::center("Mission Complete") << "]" << std::endl;
    std::cout << "[" << myManip::center("Mission Complete", 27) << "]" << std::endl;
    std::cout << std::setfill(' ');
    // std::cout << "(Width check)" << "|" << std::endl;

    return 0;
}
