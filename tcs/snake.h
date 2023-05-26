#include "point.h"
#include <vector>
#ifndef SNAKE_H_INCLUDED
#define SNAKE_H_INCLUDED
class snake{
public:
    snake(){body.push_back({7,7});body.push_back({8,7});}
    auto frame() -> void;
    auto checkFood() -> void;
    auto checkOver() -> void;
    auto generat() -> void;
    auto show() -> void;
    auto getDir() -> int{return direction;}
    auto setDir(int dir) -> void{direction=dir;}
private:
    int direction=0;
    std::vector<point>body;
};

#endif // SNAKE_H_INCLUDED
