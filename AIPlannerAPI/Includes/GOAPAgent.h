#pragma once

#include <unordered_map>
#include <queue>

#include "GOAPAction.h"
#include "GOAPGoal.h"
#include "GOAPPlanner.h"

class GOAPAgent
{
	private:
	std::unordered_map<std::string, bool> m_currentWorldState;
	std::vector<GOAPAction*>	m_actions;
	std::vector<GOAPGoal*>	m_goals;
	GOAPPlanner m_planner;
	std::queue<GOAPAction*> m_plan;

	public:
	//Constructor
	GOAPAgent() {};

	//Getters
	GOAPGoal* GetGoal(std::string goalName);

	//Methods
	void AddGoal(std::string goalToAdd, std::unordered_map<std::string, bool> desiredWorldState = std::unordered_map<std::string, bool>());
	void AddGoal(GOAPGoal* goal);

	void RemoveGoal(std::string goalToRemove);
	void RemoveGoal(GOAPGoal* goalToRemove);

	void AddState(std::string stateToAdd, bool value);
	void RemoveState(std::string stateToRemove);

	void AddAction(GOAPAction* action);
	void RemoveAction(std::string actionToRemove);

	void SearchPlan();
	void ExecutePlan();


	//Debug
	void PrintGoals();
	void PrintActions();
};