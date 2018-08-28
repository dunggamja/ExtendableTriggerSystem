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

	//�ᱹ ����� üũ�� ���ؼ��� ���� ���忡 ���� ������ �ʿ��ϴ�. 
	//���� �ڵ�� �� ���Ӹ��� �ٸ� �� �ۿ� ���� ��. �ϴ� �Ѿ��.
	virtual bool IsConditionTrue() const override { return false; }
};
