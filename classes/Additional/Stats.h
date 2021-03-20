#pragma once
#include <string>
#include <map>
#include <vector>

class Stats
{
private:
	int amount_of_games_ = 0;
	int victories_ = 0;
	std::string name_;
	int money_ = 0;
	std::vector<int> bought_units_ids_;
	std::vector<int> avaliable_units_ids_;

public:
	const std::string PATH_TO_PLAYER_DATA = "./data/player_data.txt";

	void SetName(std::string new_name);
	std::string GetName();
	void SetMoney(int new_money);
	int GetMoney();
	void SetAvaliableUnitsTypesIds(std::vector<int> new_avaliable_units_ids);
	std::vector<int> GetAvaliableUnitsTypesIds();
	void AddVictory();
	void AddLose();
	void SetAmountOfPlayedGames(int new_amount);
	void SetAmountOfVictoriesGames(int new_amount);
	int GetAmountOfPlayedGames();
	int GetAmountOfVictoriesGames();
	
	std::string ToString();
	

	// false = not loaded
	bool LoadLastPlayer();
	// false = not found
	bool FindPlayerByName();
	
	void CreateNewPlayer(std::string name, int money, std::vector<int> avaliable_units_ids);
};


