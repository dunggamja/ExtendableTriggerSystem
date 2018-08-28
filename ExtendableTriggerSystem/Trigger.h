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
	ConditionNode::UniquePtr		m_ConditionNode;		//Ʈ������ �ߵ�����.
	std::vector<REACTION_INFO>		m_VecReactionInfos;		//����


	bool		m_IsOneShot		= false;	//Ʈ������ �ߵ��� 1���� �Ǵ���, ������ �ߵ� �������� üũ�Ѵ�.
	float		m_RepeatTime	= 0.f;		//�ٽ� �ߵ��ϴµ� �ɸ��� �ð� (sec)
	float		m_AccumTime		= 0.f;		//���� �ð�.
	int64_t		m_NumOfDoReactions = 0;		//�ߵ� Ƚ��.

public:
	Trigger(ConditionNode::UniquePtr conditionNode, std::vector<REACTION_INFO> reactionInfos, bool isOneshot, float repeatTime);

public:
	bool	IsExpired() const				{ return m_IsOneShot && m_NumOfDoReactions; } 
	bool	IsOneShot() const				{ return m_IsOneShot; }
	void	AccumulateTime(float time)		{ m_AccumTime += time; }
	bool	CheckCondition() const;		//���� üũ.
	void	DoReactions();				//����


	void	ClearActivateInfo();
};