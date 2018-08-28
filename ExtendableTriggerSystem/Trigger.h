#pragma once

#include "Global.h"
#include "Condition/Node/ConditionNode.h"


class Trigger
{
public:
	enum TRIGGER_CHECK_TYPE
	{

	};

private:
	ConditionNode::UniquePtr		m_ConditionNode;		//트리거의 발동조건.
	std::vector<REACTION_INFO>		m_VecReactionInfos;		//반응


	bool		m_IsOneShot		= false;	//트리거의 발동이 1번만 되는지, 여러번 발동 가능한지 체크한다.
	float		m_RepeatTime	= 0.f;		//다시 발동하는데 걸리는 시간 (sec)
	float		m_AccumTime		= 0.f;		//누적 시간.
	int64_t		m_NumOfDoReactions = 0;		//발동 횟수.

public:
	Trigger(ConditionNode::UniquePtr conditionNode, std::vector<REACTION_INFO> reactionInfos, bool isOneshot, float repeatTime);

public:
	bool	IsExpired() const				{ return m_IsOneShot && m_NumOfDoReactions; } 
	bool	IsOneShot() const				{ return m_IsOneShot; }
	void	AccumulateTime(float time)		{ m_AccumTime += time; }
	bool	CheckCondition() const;		//조건 체크.
	void	DoReactions();				//반응


	void	ClearActivateInfo();
};