#include <gtest/gtest.h>

#include "Archer.h"

TEST(Something, something1)
{
	Archer archer1;
	EXPECT_EQ(archer1.GetHealth(),5);
}

/*
#include "Test_Game.h"

TEST(Unit_Test, Test1){
EXPECT_EQ(archer1_health1,5);
EXPECT_EQ(archer1_health2,4);
EXPECT_EQ(archer1_health3,0);
EXPECT_EQ(archer1_health4,5);
EXPECT_EQ(archer1_health5,1);
EXPECT_EQ(archer1_power2,4);
EXPECT_EQ(archer1_cost,2);
EXPECT_EQ(archer1_distance_of_attack,2);
EXPECT_EQ(archer1_distance_of_walk,1);
EXPECT_EQ(archer1_id,0);
EXPECT_EQ(archer1_max_power1,5);
EXPECT_EQ(archer1_power1,5);
EXPECT_EQ(archer1_max_health,5);

}
TEST(Factory_test, Test2){
EXPECT_EQ(archer1_health1,archer2_health1);
EXPECT_EQ(archer1_health2,archer2_health2);
EXPECT_EQ(archer1_health3,archer2_health3);
EXPECT_EQ(archer1_health4,archer2_health4);
EXPECT_EQ(archer1_health5,archer2_health5);
EXPECT_EQ(archer1_power2,archer2_power2);
EXPECT_EQ(archer1_cost,archer2_cost);
EXPECT_EQ(archer1_distance_of_attack,archer2_distance_of_attack);
EXPECT_EQ(archer1_distance_of_walk,archer2_distance_of_walk);
EXPECT_EQ(archer1_id,archer2_id);
EXPECT_EQ(archer1_max_power1,archer2_max_power1);
EXPECT_EQ(archer1_power1,archer2_power1);
EXPECT_EQ(archer1_max_health,archer2_max_health);

}
TEST(User_Factory_Test, Test3){
EXPECT_EQ(is_empty_custom, true);

}
TEST(Squad_Test, Test4){
EXPECT_EQ(squad0_distance_of_attack, -1);
EXPECT_EQ(squad0_distance_of_walk, -1);
EXPECT_EQ(squad0_is_empty1, true);
EXPECT_EQ(squad0_is_empty2, true);
EXPECT_EQ(squad0_x, 5);
EXPECT_EQ(squad0_y, 5);

EXPECT_EQ(squad1_distance_of_attack, 2);
EXPECT_EQ(squad1_distance_of_walk, 1);
EXPECT_EQ(squad1_x1, 0);
EXPECT_EQ(squad1_y1, 0);
EXPECT_EQ(squad1_x2, 1);
EXPECT_EQ(squad1_y2, 0);
EXPECT_EQ(squad1_x3, 1);
EXPECT_EQ(squad1_y3, 0);
}


TEST(Object_Factory_Test, Test5){
EXPECT_EQ(squad2_is_empty1, false);
EXPECT_EQ(squad2_is_empty2, true);


EXPECT_EQ(squad1_distance_of_attack, squad3_distance_of_attack);
EXPECT_EQ(squad1_distance_of_walk, squad3_distance_of_walk);
EXPECT_EQ(squad1_x1, squad3_x1);
EXPECT_EQ(squad1_y1, squad3_y1);
EXPECT_EQ(squad1_x2, squad3_x2);
EXPECT_EQ(squad1_y2, squad3_y2);
EXPECT_EQ(squad1_x3, squad3_x3);
EXPECT_EQ(squad1_y3, squad3_y3);
}
*/


