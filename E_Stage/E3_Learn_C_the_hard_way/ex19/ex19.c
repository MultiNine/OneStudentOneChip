#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>
#include "ex19.h"


int Monster_attack(void *self, int damage)
{
    assert(self != NULL);
    assert(damage >= 0);

    Monster *monster = self;

    int ret = printf("You attack %s!\n", monster->_(description));
    assert(ret >= 0);

    monster->hit_points -= damage;

    if(monster->hit_points > 0) {
        ret = printf("It is still alive.\n");
        assert(ret >= 0);
        return 0;
    } else {
        ret = printf("It is dead!\n");
        assert(ret >= 0);
        return 1;
    }
}

int Monster_init(void *self)
{
    assert(self != NULL);

    Monster *monster = self;
    monster->hit_points = 10;
    return 1;
}

Object MonsterProto = {
    .init = Monster_init,
    .attack = Monster_attack
};


void *Room_move(void *self, Direction direction)
{
    assert(self != NULL);

    Room *room = self;
    Room *next = NULL;

    if(direction == NORTH && room->north) {
        int ret = printf("You go north, into:\n");
        assert(ret >= 0);
        next = room->north;
    } else if(direction == SOUTH && room->south) {
        int ret = printf("You go south, into:\n");
        assert(ret >= 0);
        next = room->south;
    } else if(direction == EAST && room->east) {
        int ret = printf("You go east, into:\n");
        assert(ret >= 0);
        next = room->east;
    } else if(direction == WEST && room->west) {
        int ret = printf("You go west, into:\n");
        assert(ret >= 0);
        next = room->west;
    } else {
        int ret = printf("You can't go that direction.");
        assert(ret >= 0);
        next = NULL;
    }

    if(next) {
        next->_(describe)(next);
    } else {
        // move failed, do not show description
    }

    return next;
}


int Room_attack(void *self, int damage)
{
    assert(self != NULL);
    assert(damage >= 0);

    Room *room = self;
    Monster *monster = room->bad_guy;

    if(monster) {
        monster->_(attack)(monster, damage);
        return 1;
    } else {
        int ret = printf("You flail in the air at nothing. Idiot.\n");
        assert(ret >= 0);

        return 0;
    }
}


Object RoomProto = {
    .move = Room_move,
    .attack = Room_attack
};


void *Map_move(void *self, Direction direction)
{
    assert(self != NULL);

    Map *map = self;

    Room *location = map->location;
    assert(location != NULL);

    Room *next = NULL;

    next = location->_(move)(location, direction);

    if(next) {
        map->location = next;
    }

    return next;
}

int Map_attack(void *self, int damage)
{
    assert(self != NULL);
    assert(damage >= 0);

    Map* map = self;

    Room *location = map->location;
    assert(location != NULL);

    return location->_(attack)(location, damage);
}


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

    // put the bad guy in the arena
    arena->bad_guy = NEW(Monster, "The evil minotaur");
    assert(arena->bad_guy != NULL);

    // setup the map rooms
    hall->north = throne;

    throne->west = arena;
    throne->east = kitchen;
    throne->south = hall;

    arena->east = throne;
    kitchen->west = throne;

    // start the map and the character off in the hall
    map->start = hall;
    map->location = hall;

    assert(map->start != NULL);
    assert(map->location != NULL);

    return 1;
}

Object MapProto = {
    .init = Map_init,
    .move = Map_move,
    .attack = Map_attack
};

int process_input(Map *game)
{

    assert(game != NULL);
    assert(game->location != NULL);

    int ret = printf("\n> ");
    assert(ret >= 0);

    int ch = getchar();

    if(ch == EOF) {
        int ret = printf("Giving up? You suck.\n");
        assert(ret >= 0);
        return 0;
    }

    getchar(); // eat ENTER

    int damage = rand() % 4;

    switch(ch) {
        case 'n':
            game->_(move)(game, NORTH);
            break;

        case 's':
            game->_(move)(game, SOUTH);
            break;

        case 'e':
            game->_(move)(game, EAST);
            break;

        case 'w':
            game->_(move)(game, WEST);
            break;

        case 'a':

            game->_(attack)(game, damage);
            break;
        case 'l':
            ret = printf("You can go:\n");
            assert(ret >= 0);
            if(game->location->north) {
                ret = printf("NORTH\n");
                assert(ret >= 0);
            }
            if(game->location->south) {
                ret = printf("SOUTH\n");
                assert(ret >= 0);
            }
            if(game->location->east) {
                ret = printf("EAST\n");
                assert(ret >= 0);
            }
            if(game->location->west) {
                ret = printf("WEST\n");
                assert(ret >= 0);
            }
            break;

        default:
            ret = printf("What?: %d\n", ch);
            assert(ret >= 0);
    }

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