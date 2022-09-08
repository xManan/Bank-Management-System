#include "string.h"

std::string trim_str( std::string str ) {
    // remove trailing white space
    while( !str.empty() && std::isspace( str.back() ) ) str.pop_back() ;

    // return residue after leading white space
    std::size_t pos = 0 ;
    while( pos < str.size() && std::isspace( str[pos] ) ) ++pos ;
    return str.substr(pos) ;
}

std::vector<std::string> split_str( std::string str, const char c ) {
    std::string buff;
    std::vector<std::string> res;

    for(std::string::iterator it=str.begin(); it!=str.end(); ++it){
        if(*it != c){
            buff.push_back(*it);
        } else if(!buff.empty()){
            res.push_back(buff);
            buff.clear();
        }
    }
    if(!buff.empty())
        res.push_back(buff);
    return res;
}
