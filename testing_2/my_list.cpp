#include "my_list.h"

List::~List()
{
	Clear();
	delete m_head;
	delete m_tail;
}

bool List::Empty() const { return m_size == 0; }

unsigned long List::Size() const { return m_size; }

void List::PushFront(int value)
{
	new ListNode(value, m_head, m_head->next);
	++m_size;
}

void List::PushBack(int value)
{
	new ListNode(value, m_tail->prev, m_tail);
	++m_size;
}

int List::PopFront()
{
	if (Empty()) throw std::runtime_error("list is empty");
	auto node = extractPrev(m_head->next->next);
	int ret = node->value;
	delete node;
	return ret;
}

int List::PopBack()
{
	if (Empty()) throw std::runtime_error("list is empty");
	auto node = extractPrev(m_tail);
	int ret = node->value;
	delete node;
	return ret;
}

void List::Clear()
{
	auto current = m_head->next;
	while (current != m_tail)
	{
		current = current->next;
		delete extractPrev(current);
	}
}

ListNode* List::extractPrev(ListNode* node)
{
	auto target = node->prev;
	target->prev->next = target->next;
	target->next->prev = target->prev;
	--m_size;
	return target;
}