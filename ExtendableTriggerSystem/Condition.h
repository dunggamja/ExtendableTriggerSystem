#pragma once

#include "Global.h"


const int CONDITION_VALUE_STRING_LENGTH = 64;	//컨디션 밸류용 글자 수 제한..
const int CONDITION_VALUE_STRING_LENGTH_NULL = CONDITION_VALUE_STRING_LENGTH + 1;

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


struct CONDITION_ACTOR
{
	enum class ACTOR_TYPE
	{
		  PC				//플레이어
		, COMMON_NPC		//일반적인 NPC (몬스터)
		, UNIQUE_NPC		//유니크 NPC(스토리상 등장인물 등)
	};
	using COMMON_NPC_TYPE = std::tuple<int, int>;
	using ACTOR_NAME_TYPE = std::array<wchar_t, CONDITION_VALUE_STRING_LENGTH_NULL>;
	using ACTOR_INFO = std::variant<int, COMMON_NPC_TYPE, ACTOR_NAME_TYPE>;
	//플레이어의 경우에는 딱히 정보를 지정할 필요가없다. 
	//일반적인 NPC의 경우에는 Type 분류용 int, Kind 분류용 int 2개의 int값을 받는다.
	//유니크 NPC의 경우에는 이름으로 구분한다. 이름은 최대 64까지 지원한다. 


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
