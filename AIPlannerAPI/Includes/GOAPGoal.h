#pragma once

#include <unordered_map>

class GOAPGoal
{
	private:
	std::string m_name = "Default Goal";
	std::unordered_map<std::string, bool> m_desiredWorldState;

	public:
	//Constructor
	GOAPGoal(std::string name = "NoName", std::unordered_map<std::string, bool> desiredWorldState = std::unordered_map<std::string, bool>());

	//Getters
	std::string GetName() { return m_name; }

	//Setters
	void SetName(std::string name) { m_name = name ;}

	void AddPrecondition(std::string key, bool value);
	void RemovePrecondition(std::string key);

	//Debug
	void PrintPreconditions();
};
