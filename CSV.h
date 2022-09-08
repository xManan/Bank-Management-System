#ifndef CSV_H
#define CSV_H

#include <iostream>
#include <vector>
#include <string>
#include "string.h"

class CSV {
    public:
        static std::vector<std::vector<std::string>> parse(std::string str){
            std::vector<std::vector<std::string>> res;
            std::vector<std::string> lines = split_str(str, '\n');
            for(std::string line: lines){
                res.push_back(split_str(line, ','));
            }
            return res;
        }

        static std::string toString(std::vector<std::vector<std::string>> table){
            std::string res = "";
            for(std::vector<std::string> row: table){
                for(std::string str: row){
                    res.append(str+",");
                }
                res.replace(res.size()-1, 1, "\n");
            }
            res.pop_back();
            return res;
        }
};

#endif
