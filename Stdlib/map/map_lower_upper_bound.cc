//std::map::lower_bound/upper_bound
#include <iostream>
#include <map>

int main()
{
    using MAPTYPE = std::map<char, int>;

    MAPTYPE map, copyMap;
    MAPTYPE::iterator itLow, itUp;
    map['a'] = 100;
    map['b'] = 200;
    map['c'] = 300;
    map['d'] = 400;
    map['e'] = 500;

    copyMap.swap(map);

    itLow   = copyMap.lower_bound('b');
    itUp    = copyMap.upper_bound('d');

    copyMap.erase(itLow, itUp); // [itLow, itUp)

    for (auto it = map.begin(); it != map.end(); ++it) {
        std::cout << it->first << " => " << it->second << std::endl;
    }

    return 0;
}
