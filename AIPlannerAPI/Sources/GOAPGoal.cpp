#include <iostream>

#include "GOAPGoal.h"

GOAPGoal::GOAPGoal(std::string name, std::unordered_map<std::string, bool> desiredWorldState)
{
	m_name = name;
}

void GOAPGoal::AddPrecondition(std::string key, bool value)
{
	m_desiredWorldState.insert({ key, value });
}

void GOAPGoal::RemovePrecondition(std::string key)
{
	m_desiredWorldState.erase(key);
}

void GOAPGoal::PrintPreconditions()
{
	std::cout << "Preconditions: " << std::endl;

	for (auto it = m_desiredWorldState.begin(); it != m_desiredWorldState.end(); it++) {
		std::cout << (it->first) << " " << (it->second) << std::endl;
	}

	std::cout << "\n";
}