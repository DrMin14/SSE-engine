#include "algorithm.hpp"



uint32_t 
check_colision(
      const frect_t&    _x
    , const frect_t&    _y
    , fpoint_t*         _overlap)
{
    float min_x = _x.x;
    float max_x = _x.x + _x.w;
    float min_y = _x.y;
    float max_y = _x.y + _x.h;

    float other_min_x = _y.x;
    float other_max_x = _y.x + _y.w;
    float other_min_y = _y.y;
    float other_max_y = _y.y + _y.h;
    
    if (max_x <= other_min_x || min_x >= other_max_x) /**<x-axis check*/
        return 0;
    if (max_y <= other_min_y || min_y >= other_max_y) /**<y-axis check*/
        return 0;

    /**겹침 계산*/
    float overlap_x = std::min(max_x, other_max_x) - std::max(min_x, other_min_x);
    float overlap_y = std::min(max_y, other_max_y) - std::max(min_y, other_min_y);

    if (nullptr != _overlap) /**오버렙*/
        *_overlap = { overlap_x, overlap_y };

    /**겹침 방향 측정*/
    if (overlap_x < overlap_y)      /**<horizontal collision*/
    {
        if (min_x < other_min_x)
            return 0b0001; // right
        else
            return 0b0010; // left
    }
    else                            /**<vertical collision*/
    {
        if (min_y < other_min_y)
            return 0b0100; // bottom
        else
            return 0b1000; // top
    }
}
