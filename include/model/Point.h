#ifndef SNAKE_POINT_H_
#define SNAKE_POINT_H_

#include "model/Pos.h"
#include <cstdint>

/*
Point on the game map.
*/
class Point {
public:
    typedef uint32_t ValueType;

    static const ValueType MAX_VALUE = UINT32_MAX;

    enum Type {
        EMPTY,
        WALL,
        FOOD,
        SNAKE_BODY,
        SNAKE_HEAD,
        SNAKE_TAIL,
        TEST_VISIT,
        TEST_PATH
    };

    Point();
    ~Point();

    void setType(Type type_);
    void setValue(const ValueType dist_);
    void setParent(const Pos &p_);
    void setVisit(const bool v);
    Type getType() const;
    ValueType getValue() const;
    Pos getParent() const;
    bool isVisit() const;

private:
    Type type;
    bool visit;
    Pos parent;

    /*
    This field has different usages:
    1. When searching the shortest path, it stores the minimum distance
       to the starting point.
    2. When searching the longest path, it stores the estimated distance
       to the destination.
    */
    ValueType val;
};

#endif
