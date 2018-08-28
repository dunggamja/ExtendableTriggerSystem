#pragma once
#include "Global.h"
#include "TriggerHeader.h"


class ConditionNode 
{
public:
	using UniquePtr = std::unique_ptr<ConditionNode>;

private:
	NODE_TYPE m_NodeType;
public:
	ConditionNode(NODE_TYPE nodeType) : m_NodeType(nodeType) {}
	virtual ~ConditionNode() = default;

	NODE_TYPE	GetNodeType() const { return m_NodeType; }
	virtual bool IsConditionTrue() const = 0;
};
