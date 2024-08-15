#include <iostream>
#include <string>

int clusterModuleNumber(const std::string moduleName)
{
    const std::string namePrefix("Cluster_");
    const std::string letterSet("ABCDEFGJKLMNPQR");

    try
    {
        const size_t moduleSymbolPositionInName{namePrefix.size()};

        if (moduleName.substr(0, moduleSymbolPositionInName) != namePrefix)
            throw std::runtime_error("Incorrect prefix.");

        if (moduleName.size() != moduleSymbolPositionInName + 1)
            throw std::runtime_error("No one-letter module symbol.");

        // for (int i{}; i < letterSet.size(); i++)
        // {
        //     if (moduleName[moduleSymbolPositionInName] == letterSet[i])
        //         return i;
        // }
        // throw std::out_of_range("The provided module symbol could not be found in the set.");

        const size_t moduleSymbolPositionInSet{letterSet.find(moduleName.back())};
        if (moduleSymbolPositionInSet == std::string::npos)
            throw std::out_of_range("The provided module symbol could not be found in the set.");
        return moduleSymbolPositionInSet;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
    return -1;
}

int main()
{
    std::cout << clusterModuleNumber("Cluster_M") << std::endl;
    std::cout << clusterModuleNumber("Cluster_Q") << std::endl;
    std::cout << clusterModuleNumber("Cluster_B") << std::endl;
    std::cout << clusterModuleNumber("Cluster_H") << std::endl;
    std::cout << clusterModuleNumber("Cluster") << std::endl;
    std::cout << clusterModuleNumber("Cluster_GJ") << std::endl;

    return 0;
}