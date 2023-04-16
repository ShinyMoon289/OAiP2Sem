#pragma once
#include<forward_list>
#include<string>

struct information
{
    std::string Name=" ";
    std::string Author=" ";
    std::string Medium=" ";
    unsigned int Volume=0;
};

extern std::forward_list<information> listOfInfos;

extern void intCheck();
extern unsigned int getMenu();
extern const information getInfo(std::forward_list<information>::const_iterator);
extern void displayInfos();
extern void addInfo();
extern unsigned int getSize();
extern const information findMax();
extern const information findMin();
extern bool nameCompare(const information& , const information& );
extern bool sameName(const information& , const information& );