//std::map::count(c), if c 's mapped_type is existed , then return 1, else return 0
#include <iostream>
#include <map>

int main()
{
    using MAPTYPE = std::map<char, int>;

    MAPTYPE map;
    map['a'] = 101;
    map['b'] = 102;
    map['c'] = 103;
    map['d'] = 104;
    map['e'] = 105;
    map['h'] = 110;

    for (auto v = 'a'; v < 'h'; ++v)
        std::cout << v << " : " << map.count(v) << std::endl;

    return 0;

}
