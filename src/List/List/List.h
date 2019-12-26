#pragma once
#include<iostream>
using namespace std;
template<class TKey, class TData>
class TList
{
public:
	struct TNode
	{
		TKey key;
		TData *pData;
		TNode *pNext;
	};
public: // private
		TNode *pFirst;
		TNode *pPrev;
		TNode *pNext;
		TNode *pCur;
public:
	TList();
	TList(const TList<TKey, TData>&);
	TList(const TNode&); ///
	~TList();
	TNode* Search(TKey);
	void InsertStart(TKey, TData*);
	void InsertEnd(TKey, TData*);
	void InsertBefore(TKey, TKey, TData*);
	void InsertAfter(TKey, TKey, TData*);
	void Delete(TKey);
	void Reset();
	bool IsEnded()const;
	void Next();
	friend ostream& operator <<(ostream& o, TList<TKey, TData> &list)
	{
		if (list.pFirst == nullptr)
		{
			throw "Empty list";
		}
		TNode* tmp0 = list.pCur;
		TNode* tmp1 = list.pPrev;
		TNode* tmp2 = list.pNext;
		list.Reset();
		while (list.pCur != nullptr)
		{
			o << list.pCur->key << " " << *list.pCur->pData << endl;
			list.Next();
		}
		list.pCur = tmp0;
		list.pPrev = tmp1;
		list.pNext = tmp2;
		return o;
	}
};

template<class TKey, class TData>
TList<TKey, TData >::TList()
{
	pFirst = nullptr;
	pPrev = nullptr;
	pCur = nullptr;
	pNext = nullptr;
}
template<class TKey, class TData>
TList<TKey, TData>::TList(const TList<TKey, TData>& list)
{
	if (list.pFirst == nullptr)
		throw "empty list";
	//
	pFirst = new TNode;
	pFirst->key = list.pFirst->key;
	pFirst->pData = new TData(*list.pFirst->pData);
	pFirst->pNext = list.pFirst->pNext;
	//
	TNode* node = list.pFirst->pNext;
	TNode* copy = pFirst;
	while (node != nullptr)
	{
		TNode* tmp = new TNode;
		tmp->key = node->key;
		tmp->pData = new TData;
		*tmp->pData = *node->pData;
		copy->pNext = tmp;
		copy = tmp;
		node = node->pNext;
	}
	Reset();
}
template<class TKey, class TData>
TList<TKey, TData>::TList(const TList<TKey, TData>::TNode& node)
{
	if(node == nullptr)
		throw"empty node";
	pFirst = new TNode;
	pFirst->key = node.key;
	pFirst->pData = new TData;
	*pFirst->pData = *node.pData;
	TNode* _node = node.pNext;
	TNode* copy = pFirst;
	while (_node != nullptr)
	{
		TNode* tmp = new TNode;
		tmp->key = _node->key;
		tmp->pData = new TData;
		*tmp->pData = *_node->pData; 
		copy->pNext = tmp;
		copy = tmp;
		_node = _node.pNext;
	}
	Reset();
}
template<class TKey, class TData>
TList<TKey, TData>::~TList()
{
	while (!IsEnded())
	{
		Next();
		delete[] pPrev;
	}
	delete[] pCur;
}
template<class TKey, class TData>
void TList<TKey, TData>::Reset()
{
	pPrev = nullptr;
	pCur = pFirst;
	if (pFirst != nullptr)
		pNext = pCur->pNext;
	else
		pNext = nullptr;
}
template<class TKey, class TData>
bool TList<TKey, TData>::IsEnded() const
{
	return(pCur == nullptr);
}
template<class TKey, class TData>
void TList<TKey, TData>::Next()
{
	if (IsEnded())
		throw"cant complete Next";
	pPrev = pCur;
	pCur = pNext;
	if (pNext != nullptr)
		pNext = pNext->pNext;
}
template<class TKey, class TData>
typename TList<TKey, TData>::TNode* TList<TKey, TData>::Search(TKey key)
{
	if (pFirst == nullptr)
		return 0;
	TNode* tmp0 = pCur;
	TNode* tmp1 = pPrev;
	TNode* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
	{
		pCur = tmp0;
		pPrev = tmp1;
		pNext = tmp2;
		return 0;
	}
	TNode* tmp = pCur;
	pCur = tmp0;
	pPrev = tmp1;
	pNext = tmp2;
	return tmp;
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertStart(TKey key, TData* data)
{
	if (pFirst == nullptr)
	{
		TNode* tmp = new TNode;
		tmp->key = key;
		tmp->pData = new TData;
		if (data != nullptr)
			*tmp->pData = *data;
		else
			tmp->pData = nullptr;
		tmp->pNext = nullptr;
		pFirst = tmp;
		pCur = pFirst;
		return;
	}
	TNode* tmp = new TNode;
	tmp->key = key;
	tmp->pData = new TData;
	if (data != nullptr)
		*tmp->pData = *data;
	else
		tmp->pData = nullptr;
	tmp->pNext = pFirst;
	pFirst = tmp;
	if (pCur == pFirst->pNext)
		pPrev = pFirst;
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertEnd(TKey key, TData* data)
{
	if (pFirst == nullptr)
	{
		TNode* tmp = new TNode;
		tmp->key = key;
		tmp->pData = new TData;
		*tmp->pData = *data;
		tmp->pNext = nullptr;
		pFirst = tmp;
		pCur = pFirst;
		return;
	}
	TNode* tmp0 = pCur;
	TNode* tmp1 = pPrev;
	TNode* tmp2 = pNext;
	while (!IsEnded())
		Next();
	////
	TNode* tmp = new TNode;
	tmp->key = key;
	tmp->pData = new TData;
	*tmp->pData = *data;
	////
	pPrev->pNext = tmp;
	tmp->pNext = nullptr;
	if (tmp0 == pPrev)
	{
		pNext = pPrev->pNext;
		pCur = tmp0;
		pPrev = tmp1;
	}
	if (tmp0 == nullptr)
	{
		pPrev = pPrev->pNext;
		pCur = tmp0;
		pNext = tmp2;
	}
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertBefore(TKey key, TKey newkey, TData* data)
{
	if (pFirst == nullptr)
	{
		////
		TNode* tmp = new TNode;
		tmp->key = newkey;
		tmp->pData = new TData;
		*tmp->pData = *data;
		tmp->pNext = nullptr;
		////
		pFirst = tmp;
		pCur = pFirst;
		return;
	}
	TNode* tmp0 = pCur;
	TNode* tmp1 = pPrev;
	TNode* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "key is not found";
	////
	TNode* tmp = new TNode;
	tmp->key = newkey;
	tmp->pData = new TData;
	*tmp->pData = *data;
	tmp->pNext = pCur;
	/////
	pPrev->pNext = tmp;
	if (pCur == tmp0)
	{
		pPrev = pPrev->pNext;
		pNext = tmp2;
	}
	else if (pPrev == tmp0)
	{
		pNext = pPrev->pNext;
		pCur = tmp0;
		pPrev = tmp1;
	}
	else
	{
		pCur = tmp0;
		pPrev = tmp1;
		pNext = tmp2;
	}
}
template<class TKey, class TData>
void TList<TKey, TData>::InsertAfter(TKey key, TKey newkey, TData* data)
{
	if (pFirst == nullptr)
	{
		///
		TNode* tmp = new TNode;
		tmp->key = newkey;
		tmp->pData = new TData;
		*tmp->pData = *data;
		tmp->pNext = nullptr;
		////
		pFirst = tmp;
		pCur = pFirst;
		return;
	}
	TNode* tmp0 = pCur;
	TNode* tmp1 = pPrev;
	TNode* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "key is not found";
	/////
	TNode* tmp = new TNode;
	tmp->key = newkey;
	tmp->pData = new TData;
	*tmp->pData = *data;
	tmp->pNext = pNext;
	pCur->pNext = tmp;
	/////
	if (pCur == tmp0)
	{
		pNext = pCur->pNext;
		pPrev = tmp1;
	}
	else if (pNext == tmp0)
	{
		pPrev = pCur->pNext;
		pCur = tmp0;
		pNext = tmp2;
	}
	else
	{
		pCur = tmp0;
		pPrev = tmp1;
		pNext = tmp2;
	}
}
template<class TKey, class TData>
void TList<TKey, TData>::Delete(TKey key) //simplify
{
	if (pFirst == nullptr)
		throw "cant delete element from empty list";
	TNode* tmp0 = pCur;
	TNode* tmp1 = pPrev;
	TNode* tmp2 = pNext;
	Reset();
	while (!IsEnded() && (pCur->key != key))
		Next();
	if (pCur == nullptr)
		throw "key is not found";
	if (pCur == pFirst)
	{
		if (tmp0 == pFirst)
		{
			delete pFirst;
			pFirst = pNext;
			pCur = pFirst;
			if (pNext != nullptr)
			pNext = pCur->pNext;
		}
		else
		{
			delete pFirst;
			pFirst = pNext;
			pCur = tmp0;
			pPrev = tmp1;
			pNext = tmp2;
		}
	}
	else
		if (pCur == tmp0)
		{
			pPrev->pNext = pNext;
			delete pCur;
			pCur = tmp2;
			pPrev = tmp1;
			if (tmp2 != 0)
				pNext = tmp2->pNext;
			else
				pNext = tmp2;
		}
		else
			if (pPrev == tmp0)
			{
				pPrev->pNext = pNext;
				delete pCur;
				pCur = tmp0;
				pPrev = tmp1;
				pNext = pNext;
			}
			else
				if (pNext == tmp0)
				{
					pPrev->pNext = pNext;
					delete pCur;
					pCur = tmp0;
					pNext = tmp2;
				}
				else
				{
					delete pCur;
					pCur = tmp0;
					pPrev = tmp1;
					pNext = tmp2;
				}
}