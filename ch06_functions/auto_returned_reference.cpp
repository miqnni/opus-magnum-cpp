#include <iostream>
#include <string>

double global0{1.2}, global1{2.4}, global2{7.2};

// ************************************************

double &referenceToGlobal(int whichGlobal);
const double &constReferenceToGlobal(int whichGlobal);

// ************************************************

int main()
{

    return 0;
}

// ************************************************

double &referenceToGlobal(int whichGlobal)
{
    switch (whichGlobal)
    {
    case 1:
        return global0;
        break;
    case 2:
        return global1;
        break;
    default:
        return global2;
        break;
    }
}

// ************************************************

// const double &constReferenceToGlobal(int whichGlobal)
// {
//     switch (whichGlobal)
//     {
//     case 1:
//         return global0;
//         break;
//     case 2:
//         return global1;
//         break;
//     default:
//         return global2;
//         break;
//     }
// }
