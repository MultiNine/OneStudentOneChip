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
    Room *hall = NEW(Room, "The great Hall");
    assert(hall != NULL);
    Room *throne = NEW(Room, "The throne room");
    assert(throne != NULL);
    Room *arena = NEW(Room, "The arena, with the minotaur");
    assert(arena != NULL);
    Room *kitchen = NEW(Room, "Kitchen, you have the knife now");
    assert(kitchen != NULL);
    Room *storage = NEW(Room, "The Storage, with the minotaur");
    assert(storage != NULL);

    // put the bad guy in the arena
    arena->bad_guy = NEW(Monster, "The evil minotaur");
    assert(arena->bad_guy != NULL);

    // put the bad guy in the storage
    storage->bad_guy = NEW(Monster, "The evil minotaur");
    assert(storage->bad_guy != NULL);


    // setup the map rooms
    hall->north = throne;

    throne->west = arena;
    throne->east = kitchen;
    throne->south = hall;

    arena->east = throne;
    kitchen->west = throne;
    kitchen->north = storage;
    storage->south = kitchen;

    // start the map and the character off in the hall
    map->start = hall;
    map->location = hall;

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
    Map *game = NEW(Map, "The Hall of the Minotaur.");
    assert(game != NULL);

    int ret = printf("You enter the ");
    assert(ret >= 0);

    game->location->_(describe)(game->location);

    while(process_input(game)) {
    }

    return 0;
}