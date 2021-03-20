#include "Stats.h"

/*
int amount_of_played_games_ = 0;
int amount_of_victories_ = 0;
std::string name_;
int money_;
std::vector<int> bought_units_ids_;
std::vector<int> avaliable_units_ids_;
const static std::string PATH_TO_PLAYER_DATA = "./data/player_data.txt";
*/

void Stats::SetName(std::string new_name)
{
	name_ = new_name;
}
std::string Stats::GetName()
{
	return name_;
}
void Stats::SetMoney(int new_money)
{
	money_ = new_money;
}
int Stats::GetMoney()
{
	return money_;
}
void Stats::SetAvaliableUnitsTypesIds(std::vector<int> new_avaliable_units_ids)
{
	avaliable_units_ids_ = new_avaliable_units_ids;
}
std::vector<int> Stats::GetAvaliableUnitsTypesIds()
{
	return avaliable_units_ids_; 
}
void Stats::AddVictory()
{
	++victories_;
	++amount_of_games_;
}
void Stats::AddLose()
{
	++amount_of_games_;
}
void Stats::SetAmountOfPlayedGames(int new_amount)
{
	amount_of_games_ = new_amount;
}
void Stats::SetAmountOfVictoriesGames(int new_amount)
{
	victories_ = new_amount;
}
int Stats::GetAmountOfPlayedGames()
{
	return amount_of_games_;
}
int Stats::GetAmountOfVictoriesGames()
{
	return victories_;
}


std::string Stats::ToString()
{
	std::string result =  "_NEW_PLAYER_:" + name_ + ";" + std::to_string(amount_of_games_) + ";" + std::to_string(victories_) + ";" + std::to_string(money_) + ";";
	
	for (auto it : avaliable_units_ids_)
		result += it + "|";
       	result += ";";	

	return result;
}


// false = not loaded
bool Stats::LoadLastPlayer()
{
	return false;
}
// false = not found
bool Stats::FindPlayerByName()
{
	return false;
}

void Stats::CreateNewPlayer(std::string name, int money, std::vector<int> avaliable_units_ids)
{
	name_ = name;
	money_ = money;
	avaliable_units_ids_ = avaliable_units_ids;
}

