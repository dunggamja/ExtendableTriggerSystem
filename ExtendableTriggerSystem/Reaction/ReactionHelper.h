#pragma once
#include "Global.h"
#include "TriggerHeader.h"

class ReactionHelper
{
public:
	//보상을 위해서는 게임 월드에 대한 접근이 필요하다. 
	//이쪽 코드는 각 게임마다 다를 수 밖에 없을 것. 일단 넘어가자.
	template <typename T>
	static void ReactionFunc() {}
};