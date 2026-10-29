#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "ex19.h"

int Map_init(void *self)
{
    assert(self != NULL);

    Map *map = self;

    // make some rooms for a small map
    Room *entrance = NEW(Room, "Entrance");
    assert(entrance != NULL);
    Room *cave = NEW(Room, "The Cave");
    assert(cave != NULL);
    Room *dungeon = NEW(Room, "Dungeon, with the monster");
    assert(dungeon != NULL);

    // put the bad guy in the monster
    dungeon->bad_guy = NEW(Monster, "The evil monster");
    assert(dungeon->bad_guy != NULL);

    // setup the map rooms
    entrance->north = cave;
    cave->south = entrance;
    cave->west = dungeon;
    dungeon->east = cave;

    // start the map and the character off in the hall
    map->start = entrance;
    map->location = entrance;

    assert(map->start != NULL);
    assert(map->location != NULL);

    return 1;
}

int main(int argc, char *argv[])
{
    // simple way to setup the randomness

    time_t current_time = time(NULL);
    assert(current_time != (time_t)-1);
    srand((unsigned int)current_time);

    // make our map to work with 
    Map *game = NEW(Map, "The Entrance of the Monster.");
    assert(game != NULL);

    int ret = printf("You enter the ");
    assert(ret >= 0);

    game->location->_(describe)(game->location);

    while(process_input(game)) {
    }

    return 0;
}