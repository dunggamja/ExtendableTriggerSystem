#include "Trigger.h"
#include "Reaction/ReactionHelper.h"

Trigger::Trigger(ConditionNode::UniquePtr conditionNode, std::vector<REACTION_INFO> reactionInfos, bool isOneShot, float repeatTime)
	: m_ConditionNode(std::move(conditionNode))
	, m_VecReactionInfos(std::move(reactionInfos))
	, m_IsOneShot(isOneShot)
	, m_RepeatTime(repeatTime)
	, m_AccumTime(0.f)
	, m_NumOfDoReactions(0)
{
}

bool Trigger::CheckCondition() const
{
	if (m_ConditionNode) return m_ConditionNode->IsConditionTrue();

	return true;
}

void Trigger::DoReactions()
{
	//게임월드를 건드릴수 밖에 없다. 일단은 패스.

	++m_NumOfDoReactions;
	m_AccumTime = 0.f;
}

void Trigger::ClearActivateInfo()
{
	m_AccumTime = 0.f;
	m_NumOfDoReactions = 0;
}
