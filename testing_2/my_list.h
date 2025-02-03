#pragma once
#include "ListNode.h"
#include <stdexcept>

class List
{
public:
	List()
		: m_head(new ListNode(static_cast<int>(0))), m_size(0),
		m_tail(new ListNode(0, m_head))
	{}

	virtual ~List();
	bool Empty() const;
	unsigned long Size() const;
	void PushFront(int value);
	void PushBack(int value);
	int PopFront();
	int PopBack();
	void Clear();

private:
	ListNode* extractPrev(ListNode* node);

private:
	ListNode* m_head;
	ListNode* m_tail;
	unsigned long m_size;
};