#pragma once

#include <queue>

#include "GOAPAction.h"
#include "GOAPGoal.h"

enum class EExecutionState
{
	SUCCESS,
	RUNNING,
	ABORT,
	NOTFOUND,
	IDLE
};

class GOAPPlanner
{
	private:
	EExecutionState m_executionState = EExecutionState::IDLE;

	bool CheckPreconditions(std::unordered_map<std::string, bool> preconditions, std::unordered_map<std::string, bool> currentWorldState);

	public:
	GOAPPlanner() {};

	//Methods
	std::queue<GOAPAction*> FindPlan(GOAPGoal* goal, std::vector<GOAPAction*> actions, std::unordered_map<std::string, bool> currentWorldState);
};