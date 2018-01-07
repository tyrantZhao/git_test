//std::map::key_comp(), return ::std::map<key_type, mapped_type>::key_comp
#include <iostream>
#include <map>

int main()
{
    std::map<char, int> keyMap;
    keyMap['a'] = 1001;
    keyMap['b'] = 2002;
    keyMap['c'] = 3003;

    std::map<char, int>::key_compare keycomp = keyMap.key_comp();

    char cHigh = keyMap.rbegin()->first;
    std::map<char, int>::iterator it = keyMap.begin();

    do {
        std::cout << it->first << " =>" << it->second << std::endl;
    } while (keycomp((*it++).first, cHigh));

    return 0;
}
