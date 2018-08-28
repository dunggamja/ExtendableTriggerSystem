#pragma once
#include "Global.h"
#include "TriggerHeader.h"
#include "ConditionNode.h"

class ConditionOperand : public ConditionNode
{
private:
	CONDITION_TYPE	m_ConditionType;
	ACTOR_INFO		m_SubjectActor;
	ACTOR_INFO		m_TargetActor;
	int64_t			m_TargetValue = 0i64;

public:

	ConditionOperand(CONDITION_TYPE conditionType, ACTOR_INFO subjectActor, ACTOR_INFO targetActor, int64_t targetValue)
		: ConditionNode(NODE_TYPE::OPERAND)
		, m_ConditionType(conditionType)
		, m_SubjectActor(std::move(subjectActor))
		, m_TargetActor(std::move(targetActor))
		, m_TargetValue(targetValue)
	{}

	//결국 컨디션 체크를 위해서는 게임 월드에 대한 접근이 필요하다. 
	//이쪽 코드는 각 게임마다 다를 수 밖에 없을 것. 일단 넘어가자.
	virtual bool IsConditionTrue() const override { return false; }
};
