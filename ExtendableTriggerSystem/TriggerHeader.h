#pragma once

#include "Global.h"


enum class CONDITION_TYPE 
{
		EXIST_IN_R_OF_X_POSITION  // 특정 위치 X의 반경 R 안에 존재
	,   CLOSE_IN_R_X		  // 오브젝트 X의 반경 R안에 근접.	
	,	UNDER_LIFE_X_PERCENT  // 생명력이 X퍼센트 이하.
	,	OVER_LIFE_X_PERCENT   // 생명력이 X퍼센트 이상.
	,	HAVE_ITEM_X_N		  // 아이템 X를 N개 소지
	,	EQUIP_X				  // X를 장비
	,	DEATH				  // 죽음
	,	KILL_X				  // X를 죽임
	,	OVER_LEVEL_X		  // 레벨이 X이상
	,	UNDER_LEVEL_X		  // 레벨이 X이하
	,	GET_MESSAGE_X		  // 메시지 X를 받음.
	,	FLAG_X_VALUE_EQUAL_N  // 플래그 X 값이 N이다.
	,	FLAG_X_VALUE_OVER_N   // 플래그 X 값이 N보다 크다.
	,	FLAG_X_VALUE_UNDER_N  // 플래그 X 값이 N보다 작다.
	,	FLAG_X_IS_TRUE		  // 플래그 X가 참이다.
	,	FLAG_X_IS_FALSE		  // 플래그 X가 거짓이다.
};

enum class REACTION_TYPE
{
	KILL_X						// X를 죽인다.
	, EXPUP_X_N					// X에게 N만큼 경험치를 준다. 
	, LEVEL_X_SET_N				// X의 레벨을 N으로 설정한다.
	, FLAG_X_VALUE_SET_N			// 플래그 X의 값을 N으로 설정한다. . 
	, FLAG_X_VALUE_INCREASE_N	// 플래그 X의 값을 N만큼 증가 . 
	, FLAG_X_VALUE_DECREASE_N	// 플래그 X의 값을 N만큼 감소 . 
	, FLAG_X_SET_TRUE			// 플래그 X의 값을 참으로 설정. 
	, FLAG_X_SET_FALSE			// 플래그 X의 값을 거짓으로 설정 . 
	, SEND_MESSAGE_X				// 메시지 X를 전송 
	, GIVE_ITEM_X_N				// 아이템 X를 N만큼 준다. 
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
		, PC				//플레이어
		, COMMON_OBJECT		//일반적인 오브젝트(몬스터, 아이템 등)
		, UNIQUE_OBJECT		//유니크   오브젝트(스토리상 등장인물 등)
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
	using PC_INFO				= int64_t;										// 플레이어는 딱히 정보가 필요없지만... 그냥 int로 구분
	using COMMON_OBJECT_INFO	= std::tuple<OBJECT_TYPE, int, int>;			// 일반 오브젝트는 Type, Kind 로 구분된다.
	using UNIQUE_OBJECT_INFO	= std::tuple<OBJECT_TYPE, std::wstring>;		// 유니크 오브젝트는 이름으로 구분된다. 
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
	REACTION_TYPE	m_Type;					//반응 타입.
	ACTOR_INFO		m_Target;				//반응 대상
	ACTOR_INFO		m_Reward;				//반응 대상에게 줄 보상 정보
	int64_t			m_RewardValue = 0;		//보상 관련 Value값.

	REACTION_INFO(REACTION_TYPE reactionType, ACTOR_INFO targetInfo, ACTOR_INFO rewardInfo, int64_t rewardValue)
		: m_Type(reactionType)
		, m_Target(std::move(targetInfo))
		, m_Reward(std::move(rewardInfo))
		, m_RewardValue(rewardValue)
	{}
};

class ConditionNode;






