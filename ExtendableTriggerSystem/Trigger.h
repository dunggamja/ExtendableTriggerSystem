#pragma once

#include "Global.h"



class Trigger
{
public: 


private:
	bool	isOneShot		= false;	//Ʈ������ �ߵ��� 1���� �Ǵ���, ������ �ߵ� �������� üũ�Ѵ�.
	int		repeatTimeSec	= 0;		//�ٽ� �ߵ��ϴµ� �ɸ��� �ð� (�ʴ���)

	//Ʈ������ ��. 
	//Condition
	//Condition operator
	//

public:
	bool CheckCondition() const;
	
};