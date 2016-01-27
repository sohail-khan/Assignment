// Copyright eeGeo Ltd (2012-2014), All Rights Reserved

#pragma once

#include "Types.h"

namespace Eegeo
{
	template <typename T>
	class ListItem
	{
	public:
		ListItem			( T* pItem ) : m_pItem(pItem), m_prev(NULL), m_next(NULL)
		{
		}
		
		T*			GetItem	()		{ return m_pItem; }
		
		ListItem*	GetPrev	()		{ return m_prev; }
		ListItem*	GetNext	()		{ return m_next; }
		
		void		SetPrev	( ListItem* pPrev )		{ m_prev = pPrev; }
		void		SetNext	( ListItem* pNext )		{ m_next = pNext; }
		
		
	private:
		
		T*			m_pItem;
		
		ListItem*	m_prev;
		ListItem*	m_next;
	};
	
	
	template <typename T>
	class List
	{
	public:
		List				();
		
		T*		GetHead		()				{ return m_head; }
		T*		GetTail		()				{ return m_tail; }
		u32		GetLength	()				{ return m_length; }
		
		void	AddToHead	( T* item );
		void	AddToTail	( T* item );
		
		void	InsertBefore( T* item, T* listItem );
		void	InsertAfter	( T* item, T* listItem );
		
		T*		RemoveHead	();
		T*		RemoveTail	();
		T*		Remove		(T* item);
		
	private:
		T*		m_head;
		T*		m_tail;
		u32		m_length;
	};
	
	template <typename T>
	List<T>::List() : m_head(NULL), m_tail(NULL), m_length(0)
	{
	}
	
	template <typename T>
	void List<T>::AddToHead	( T* item )
	{
		item->SetPrev(NULL);
		item->SetNext(m_head);
		
		if(m_head)
		{
			m_head->SetPrev(item);
		}
		else
		{
			m_tail	= item;
		}
		
		m_head	= item;
		m_length++;
	}
	
	template <typename T>
	void List<T>::AddToTail	( T* item )
	{
		item->SetPrev(m_tail);
		item->SetNext(NULL);
		
		if(m_tail)
		{
			m_tail->SetNext(item);
		}
		else
		{
			m_head	= item;
		}
		
		m_tail	= item;
		m_length++;
	}
	
	template <typename T>
	void List<T>::InsertBefore( T* item, T* listItem )
	{
		item->SetPrev(listItem->GetPrev());
		item->SetNext(listItem);
		
		if(listItem->GetPrev())
		{
			listItem->GetPrev()->SetNext(item);
		}
		
		listItem->SetPrev(item);
		
		if(m_head == listItem)
		{
			m_head = item;
		}
		
		m_length++;
	}
	
	template <typename T>
	void List<T>::InsertAfter	( T* item, T* listItem )
	{
		item->SetPrev(listItem);
		item->SetNext(listItem->GetNext());
		
		if(listItem->GetNext())
		{
			listItem->GetNext()->SetPrev(item);
		}
		
		listItem->SetNext(item);
		
		if(m_tail == listItem)
		{
			m_tail = item;
		}
		
		m_length++;
	}
	
	template <typename T>
	T* List<T>::RemoveHead	()
	{
		T*	head = m_head;
		
		if(m_head)
		{
			if(m_head->GetNext())
			{
				m_head->GetNext()->SetPrev(NULL);
			}
			
			if(m_head == m_tail)
			{
				m_tail = NULL;
			}
			
			m_head	= m_head->GetNext();
			
			head->SetPrev(NULL);
			head->SetNext(NULL);
			
			m_length--;
		}
		
		return head;
	}
	
	template <typename T>
	T* List<T>::RemoveTail	()
	{
		T*	tail = m_tail;
		
		if(m_tail)
		{
			if(m_tail->GetPrev())
			{
				m_tail->GetPrev()->SetNext(NULL);
			}
			
			if(m_head == m_tail)
			{
				m_head = NULL;
			}
			
			m_tail	= m_tail->GetPrev();
			
			tail->SetPrev(NULL);
			tail->SetNext(NULL);
			
			m_length--;
		}
		
		return tail;
	}
	
	template <typename T>
	T* List<T>::Remove(T* item)
	{
		if(m_head == item)
		{
			return RemoveHead();
		}
		else if(m_tail == item)
		{
			return RemoveTail();
		}
		else
		{
			if(item->GetPrev())
			{
				item->GetPrev()->SetNext(item->GetNext());
			}
			
			if(item->GetNext())
			{
				item->GetNext()->SetPrev(item->GetPrev());
			}
			
			item->SetPrev(NULL);
			item->SetNext(NULL);
			
			m_length--;
			
			return item;
		}
	}
}
