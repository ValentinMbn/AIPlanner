#include <iostream>

#include "GOAPAgent.h"

GOAPGoal* GOAPAgent::GetGoal(std::string goalName)
{
	for (std::vector<GOAPGoal*>::iterator it = m_goals.begin(); it != m_goals.end(); ++it)
	{
		if ((*it)->GetName() == goalName)
			return (*it);
	}

	return nullptr;
}

void GOAPAgent::AddGoal(std::string goalToAdd, std::unordered_map<std::string, bool> desiredWorldState)
{
	m_goals.push_back(new GOAPGoal(goalToAdd, desiredWorldState));
}

void GOAPAgent::AddGoal(GOAPGoal* goal)
{
	m_goals.push_back(goal);
}

void GOAPAgent::RemoveGoal(std::string goalToRemove)
{
	GOAPGoal* goalTodelete = nullptr;

	for (std::vector<GOAPGoal*>::iterator it = m_goals.begin(); it != m_goals.end(); ++it)
	{
		if ((*it)->GetName() == goalToRemove)
		{
			goalTodelete = (*it);
			m_goals.erase(it);
			break;
		}
	}

	if(goalTodelete)
		delete goalTodelete;
}

void GOAPAgent::RemoveGoal(GOAPGoal* goalToRemove)
{
	RemoveGoal(goalToRemove->GetName());
}

void GOAPAgent::AddState(std::string stateToAdd, bool value)
{
	m_currentWorldState.insert({ stateToAdd, value});
}

void GOAPAgent::RemoveState(std::string stateToRemove)
{
	m_currentWorldState.erase(stateToRemove);
}

void GOAPAgent::AddAction(GOAPAction* action)
{
	m_actions.push_back(action);
}

void GOAPAgent::RemoveAction(std::string actionToRemove)
{
	
}

void GOAPAgent::SearchPlan()
{
	m_plan = m_planner.FindPlan(m_goals.front(), m_actions, m_currentWorldState);

	ExecutePlan();
}

void GOAPAgent::ExecutePlan()
{
	while (!m_plan.empty())
	{
		m_plan.front()->Execute();
		m_plan.pop();
	}
}

void GOAPAgent::PrintGoals()
{
	std::cout << "Goals: " << std::endl;

	for (std::vector<GOAPGoal*>::iterator it = m_goals.begin(); it != m_goals.end(); ++it)
	{
		std::cout << (*it)->GetName() << std::endl;
		(*it)->PrintPreconditions();
	}

	std::cout << "\n";
}

void GOAPAgent::PrintActions()
{
	std::cout << "Actions: " << std::endl;

	for (std::vector<GOAPAction*>::iterator it = m_actions.begin(); it != m_actions.end(); ++it)
	{
		std::cout << (*it)->GetName() << std::endl;
		(*it)->PrintPreconditions();
		(*it)->PrintEffects();
	}

	std::cout << "\n";
}