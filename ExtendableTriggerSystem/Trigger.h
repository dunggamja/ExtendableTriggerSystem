#pragma once

#include "Global.h"



class Trigger
{
public: 


private:
	bool	isOneShot		= false;	//트리거의 발동이 1번만 되는지, 여러번 발동 가능한지 체크한다.
	int		repeatTimeSec	= 0;		//다시 발동하는데 걸리는 시간 (초단위)

	//트리거의 평가. 
	//Condition
	//Condition operator
	//

public:
	bool CheckCondition() const;
	
};