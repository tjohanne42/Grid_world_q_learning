executable : "bin/grid_world_q_learning"

To compile again do the rule "make re"

The algorithm has to go to home. If he hurts the man on the way, he gets a negative reward.

The map is contained in variable "int reward[]" in the file "src/main.c" in function "main" (first line)

exemple of map :
	int   reward[] = {0, 0, 1, 2, -1, 0, 0, 0, 0};

1 = house
-1 = the man
2 = the car
0 = nothing on this case

!! this project only able to do a map 3x3 with 1 house and 1 car (as much man as you wish) !!

another exemple of map :
	int   reward[] = {-1, 0, 1, 2, -1, 0, 0, 0, 0};