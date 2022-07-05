#include "GOAPAction.h"

#include <iostream>

void GOAPAction::AddPrecondition(std::string key, bool value)
{
	m_preconditions.insert({ key, value });
}

void GOAPAction::AddEffect(std::string key, bool value)
{
	m_effects.insert({ key, value });
}

void GOAPAction::PrintPreconditions()
{
	std::cout << "Preconditions: " << std::endl;

	for (auto it = m_preconditions.begin(); it != m_preconditions.end(); it++) 
		std::cout << (it->first) << " " << (it->second)  << std::endl;

	std::cout << "\n";
}

void GOAPAction::PrintEffects()
{
	std::cout << "Effects: " << std::endl;

	for (auto it = m_effects.begin(); it != m_effects.end(); it++)
		std::cout << (it->first) << " " << (it->second) << std::endl;

	std::cout << "\n";
}