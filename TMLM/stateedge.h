#ifndef STATEEDGE_H
#define STATEEDGE_H


enum Direction
{
    LEFT,
    RIGHT,
    NONE

};

class StateEdge
{
public:
    int nextState;
    char write;
    Direction direction;
    StateEdge();
    StateEdge(int _nextState,char _write, Direction _direction);
};

#endif // STATEEDGE_H
