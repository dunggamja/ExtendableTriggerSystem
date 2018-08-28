#pragma once
#include "Global.h"
#include "TriggerHeader.h"
#include "ConditionNode.h"

class ConditionOperator : public ConditionNode
{
public:
	enum class OPERATOR_TYPE
	{
		AND, OR
	};

private:
	OPERATOR_TYPE	m_OperatorType;
	std::list<ConditionNode::UniquePtr> m_listChildNodes;

public:
	ConditionOperator(OPERATOR_TYPE operatorType) : ConditionNode(NODE_TYPE::OPERATOR), m_OperatorType(operatorType) {}
	ConditionOperator(OPERATOR_TYPE operatorType, std::initializer_list<ConditionNode::UniquePtr> listNode)
		: ConditionNode(NODE_TYPE::OPERATOR)
		, m_OperatorType(operatorType)
		, m_listChildNodes(std::move(listNode))
	{}

	void AddChildNode(ConditionNode::UniquePtr childNode)
	{
		m_listChildNodes.emplace_back(childNode);
	}


	virtual bool IsConditionTrue() const override
	{
		
		if (OPERATOR_TYPE::AND == m_OperatorType)
		{
			return std::all_of(m_listChildNodes.cbegin(), m_listChildNodes.cend()
				, [&](const ConditionNode::UniquePtr& node)->bool
			{
				return (node) && node->IsConditionTrue();
			});
		}
		else if(OPERATOR_TYPE::OR == m_OperatorType)
		{
			return std::any_of(m_listChildNodes.cbegin(), m_listChildNodes.cend()
				, [&](const ConditionNode::UniquePtr& node)->bool
			{
				return (node) && node->IsConditionTrue();
			});
		}

		return false;
	}
};

