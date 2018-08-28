#pragma once

#include "Global.h"


enum class CONDITION_TYPE 
{
		EXIST_IN_R_OF_X_POSITION  // Ư�� ��ġ X�� �ݰ� R �ȿ� ����
	,   CLOSE_IN_R_X		  // ������Ʈ X�� �ݰ� R�ȿ� ����.	
	,	UNDER_LIFE_X_PERCENT  // ������� X�ۼ�Ʈ ����.
	,	OVER_LIFE_X_PERCENT   // ������� X�ۼ�Ʈ �̻�.
	,	HAVE_ITEM_X_N		  // ������ X�� N�� ����
	,	EQUIP_X				  // X�� ���
	,	DEATH				  // ����
	,	KILL_X				  // X�� ����
	,	OVER_LEVEL_X		  // ������ X�̻�
	,	UNDER_LEVEL_X		  // ������ X����
	,	GET_MESSAGE_X		  // �޽��� X�� ����.
	,	FLAG_X_VALUE_EQUAL_N  // �÷��� X ���� N�̴�.
	,	FLAG_X_VALUE_OVER_N   // �÷��� X ���� N���� ũ��.
	,	FLAG_X_VALUE_UNDER_N  // �÷��� X ���� N���� �۴�.
	,	FLAG_X_IS_TRUE		  // �÷��� X�� ���̴�.
	,	FLAG_X_IS_FALSE		  // �÷��� X�� �����̴�.
};

enum class REACTION_TYPE
{
	KILL_X						// X�� ���δ�.
	, EXPUP_X_N					// X���� N��ŭ ����ġ�� �ش�. 
	, LEVEL_X_SET_N				// X�� ������ N���� �����Ѵ�.
	, FLAG_X_VALUE_SET_N			// �÷��� X�� ���� N���� �����Ѵ�. . 
	, FLAG_X_VALUE_INCREASE_N	// �÷��� X�� ���� N��ŭ ���� . 
	, FLAG_X_VALUE_DECREASE_N	// �÷��� X�� ���� N��ŭ ���� . 
	, FLAG_X_SET_TRUE			// �÷��� X�� ���� ������ ����. 
	, FLAG_X_SET_FALSE			// �÷��� X�� ���� �������� ���� . 
	, SEND_MESSAGE_X				// �޽��� X�� ���� 
	, GIVE_ITEM_X_N				// ������ X�� N��ŭ �ش�. 
};

enum class NODE_TYPE 
{
	 OPERATOR
	,OPERAND 
};

struct ACTOR_INFO
{
	enum class ACTOR_TYPE
	{
		  EMPTY
		, PC				//�÷��̾�
		, COMMON_OBJECT		//�Ϲ����� ������Ʈ(����, ������ ��)
		, UNIQUE_OBJECT		//����ũ   ������Ʈ(���丮�� �����ι� ��)
	};

	enum class OBJECT_TYPE
	{
			NPC
		,	ITEM
		,	EQUIPMENT
		,	OBJECT
		,	FLAG	
	};

	using EMPTY_INFO			= nullptr_t;
	using PC_INFO				= int64_t;										// �÷��̾�� ���� ������ �ʿ������... �׳� int�� ����
	using COMMON_OBJECT_INFO	= std::tuple<OBJECT_TYPE, int, int>;			// �Ϲ� ������Ʈ�� Type, Kind �� ���еȴ�.
	using UNIQUE_OBJECT_INFO	= std::tuple<OBJECT_TYPE, std::wstring>;		// ����ũ ������Ʈ�� �̸����� ���еȴ�. 
	using INFO_TYPE				= std::variant<EMPTY_INFO, PC_INFO, COMMON_OBJECT_INFO, UNIQUE_OBJECT_INFO>;
	


private:
	ACTOR_TYPE	m_ActorType = ACTOR_TYPE::PC;
	INFO_TYPE	m_ActorInfo;

	ACTOR_INFO(ACTOR_TYPE actorType, INFO_TYPE actorInfo)
		: m_ActorType(actorType)
		, m_ActorInfo(std::move(actorInfo))
	{}

public:
	ACTOR_TYPE GetActorType() const { return m_ActorType; }
	INFO_TYPE  GetActorInfo() const { return m_ActorInfo; }


public:
	static ACTOR_INFO CreateActor_EMPTY()
	{
		return ACTOR_INFO(ACTOR_TYPE::EMPTY, nullptr);
	}

	static ACTOR_INFO CreateActor_PC()
	{
		return ACTOR_INFO(ACTOR_TYPE::PC, 0i64);
	}

	static ACTOR_INFO CreateActor_CommonNPC(OBJECT_TYPE objectType, int type, int kind)
	{
		return ACTOR_INFO(ACTOR_TYPE::COMMON_OBJECT, std::move(std::make_tuple(objectType, type, kind)));
	}

	static ACTOR_INFO CreateActor_UniqueNPC(OBJECT_TYPE objectType, std::wstring name)
	{
		return ACTOR_INFO(ACTOR_TYPE::UNIQUE_OBJECT, std::move(std::make_tuple(objectType, std::move(name))));
	}
};

struct REACTION_INFO
{
	REACTION_TYPE	m_Type;					//���� Ÿ��.
	ACTOR_INFO		m_Target;				//���� ���
	ACTOR_INFO		m_Reward;				//���� ��󿡰� �� ���� ����
	int64_t			m_RewardValue = 0;		//���� ���� Value��.

	REACTION_INFO(REACTION_TYPE reactionType, ACTOR_INFO targetInfo, ACTOR_INFO rewardInfo, int64_t rewardValue)
		: m_Type(reactionType)
		, m_Target(std::move(targetInfo))
		, m_Reward(std::move(rewardInfo))
		, m_RewardValue(rewardValue)
	{}
};

class ConditionNode;






