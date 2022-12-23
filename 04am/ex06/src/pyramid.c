#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

static int find_path(
    unsigned int **map, unsigned int height,
    unsigned int depth, unsigned int pos)
{
    int left;
    int right;
    int current = map[depth][pos];

    if (depth >= height - 1)
        return (current);
    left = find_path(map, height, depth + 1, pos);
    right = find_path(map, height, depth + 1, pos == depth - 1 ? depth - 1 : pos + 1);
    return (current + (left < right ? left : right));
}
int pyramid_path(unsigned int size, unsigned int **map)
{
    if (map == NULL)
        return (0);
    return (find_path(map, size, 0, 0));
}