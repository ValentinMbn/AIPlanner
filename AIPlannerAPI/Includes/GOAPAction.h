#pragma once

#include <unordered_map>
#include <string>

class GOAPAction
{
	protected:
	std::string m_name;
    std::unordered_map<std::string, bool> m_preconditions;
	std::unordered_map<std::string, bool> m_effects;

	float m_cost = 0.0f;

	public:
	//Constructor
	GOAPAction() {};

	//Getters
	float GetCost() { return m_cost; }
	std::string GetName() { return m_name; }
	std::unordered_map<std::string, bool> GetPreconditions() { return m_preconditions; }
	std::unordered_map<std::string, bool> GetEffects() { return m_effects; }

	//Setters
	void SetCost(float newCost) { m_cost = newCost; }

	//Methods
	void AddPrecondition(std::string key, bool value);
	void AddEffect(std::string key, bool value);

	virtual void Execute() = 0;

	//Debug
	void PrintPreconditions();
	void PrintEffects();
};