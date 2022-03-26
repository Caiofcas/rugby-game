// Standard headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t last_direction_a = DIR_DOWN_LEFT;
position_t *last_position_a = NULL;

direction_t new_direction_a()
{
  int r = rand();
  switch (r % 8)
  {
  case 0:
    return (direction_t)DIR_UP;
  case 1:
    return (direction_t)DIR_UP_RIGHT;
  case 2:
    return (direction_t)DIR_RIGHT;
  case 3:
    return (direction_t)DIR_DOWN_RIGHT;
  case 4:
    return (direction_t)DIR_DOWN;
  case 5:
    return (direction_t)DIR_DOWN_LEFT;
  case 6:
    return (direction_t)DIR_LEFT;
  default:
    return (direction_t)DIR_UP_LEFT;
  }
}

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy)
{

  if (last_position_a == NULL)
  {
    last_position_a = malloc(sizeof(struct position *));
    last_position_a->i = ULLONG_MAX;
    last_position_a->j = ULLONG_MAX;
    srand(time(NULL));
  }

  if (equal_positions(*last_position_a, attacker_position))
  {
    last_direction_a = new_direction_a();
  }

  last_position_a->i = attacker_position.i;
  last_position_a->j = attacker_position.j;

  UNUSED(defender_spy);

  return last_direction_a;
}
/*----------------------------------------------------------------------------*/
