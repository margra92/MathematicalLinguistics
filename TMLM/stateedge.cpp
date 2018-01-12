#include "stateedge.h"

StateEdge::StateEdge()
{
    nextState = 0;
    write = '-';
    direction = NONE;
}

StateEdge::StateEdge(int _nextState, char _write, Direction _direction)
{
    nextState = _nextState;
    write = _write;
    direction = _direction;
}
