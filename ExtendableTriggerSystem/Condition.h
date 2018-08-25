#pragma once

#include "Global.h"


const int CONDITION_VALUE_STRING_LENGTH = 64;	//����� ����� ���� �� ����..
const int CONDITION_VALUE_STRING_LENGTH_NULL = CONDITION_VALUE_STRING_LENGTH + 1;

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


struct CONDITION_ACTOR
{
	enum class ACTOR_TYPE
	{
		  PC				//�÷��̾�
		, COMMON_NPC		//�Ϲ����� NPC (����)
		, UNIQUE_NPC		//����ũ NPC(���丮�� �����ι� ��)
	};
	using COMMON_NPC_TYPE = std::tuple<int, int>;
	using ACTOR_NAME_TYPE = std::array<wchar_t, CONDITION_VALUE_STRING_LENGTH_NULL>;
	using ACTOR_INFO = std::variant<int, COMMON_NPC_TYPE, ACTOR_NAME_TYPE>;
	//�÷��̾��� ��쿡�� ���� ������ ������ �ʿ䰡����. 
	//�Ϲ����� NPC�� ��쿡�� Type �з��� int, Kind �з��� int 2���� int���� �޴´�.
	//����ũ NPC�� ��쿡�� �̸����� �����Ѵ�. �̸��� �ִ� 64���� �����Ѵ�. 


private:
	ACTOR_TYPE m_ActorType = ACTOR_TYPE::PC;
	ACTOR_INFO m_ActorInfo;

	CONDITION_ACTOR(ACTOR_TYPE actorType, ACTOR_INFO actorInfo)
		: m_ActorType(actorType)
		, m_ActorInfo(std::move(actorInfo))
	{}

public:
	ACTOR_TYPE GetActorType() const { return m_ActorType; }
	ACTOR_INFO GetActorInfo() const { return m_ActorInfo; }


public:
	static CONDITION_ACTOR CreateActor_PC()
	{
		return CONDITION_ACTOR(ACTOR_TYPE::PC, 0);
	}

	static CONDITION_ACTOR Create_CommonNPC(int type, int kind)
	{
		return CONDITION_ACTOR(ACTOR_TYPE::COMMON_NPC, std::make_tuple(type, kind));
	}

	static CONDITION_ACTOR Create_UniqueNPC(ACTOR_NAME_TYPE name)
	{
		return CONDITION_ACTOR(ACTOR_TYPE::UNIQUE_NPC, std::move(name));
	}
};
