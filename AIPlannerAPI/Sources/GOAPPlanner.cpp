#include "GOAPPlanner.h"

std::queue<GOAPAction*> GOAPPlanner::FindPlan(GOAPGoal* goal, std::vector<GOAPAction*> actions, std::unordered_map<std::string, bool> currentWorldState)
{
	std::unordered_map<std::string, bool> tempWorldState = currentWorldState;
	std::vector<GOAPAction*> tempActions = actions;
	std::queue<GOAPAction*> plan = std::queue<GOAPAction*>();

	m_executionState = EExecutionState::RUNNING;


	//while (m_executionState == EExecutionState::RUNNING)
	//{
	//	tempActions = actions;

	//	for (int i = 0; i < tempActions.size(); i++)
	//	{
	//		if (!CheckPreconditions(tempActions[i]->GetPreconditions(), tempWorldState))
	//			continue;

	//		plan.push(tempActions[i]);


	//		//tempActions[i]->GetPreconditions();
	//	}
	//}

	return plan;
}

bool GOAPPlanner::CheckPreconditions(std::unordered_map<std::string, bool> preconditions, std::unordered_map<std::string, bool> currentWorldState)
{
	if(preconditions.empty())
		return true;

	for (std::unordered_map<std::string, bool>::iterator it = preconditions.begin(); it != preconditions.end(); it++) 
	{
		if (currentWorldState.at((*it).first) != (*it).second)
			return false;
	}

	return true;
}