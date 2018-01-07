//std::map::value_comp(), compare within std::pair, if the first arg go before the second arg ,then return true
#include <iostream>
#include <map>

int main()
{
    ::std::map<char, int> ValueCompMap;
    ValueCompMap['x'] = 2002;
    ValueCompMap['y'] = 1001;
    ValueCompMap['z'] = 3003;

    ::std::cout << "ValueCompMap contains : " << ::std::endl;

    ::std::map<char, int>::value_compare vaCmp = ValueCompMap.value_comp();
    ::std::map<char, int>::iterator it  = ValueCompMap.begin();
    ::std::pair<char, int> HighPair     = *ValueCompMap.rbegin();
    do {
        ::std::cout << it->first << " => " << it->second << ::std::endl;
    } while (vaCmp(*it++, HighPair) );

    return 0;
}
