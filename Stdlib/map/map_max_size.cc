#include <iostream>
#include <map>

int main()
{
    std::map<char, int> map;

    std::cout << "map maxsize : " << map.max_size() << std::endl;

    return 0;
}
