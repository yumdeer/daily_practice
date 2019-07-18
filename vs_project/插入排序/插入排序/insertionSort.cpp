#include<iostream>
#include<list>
#define ListNodePosi(T) ListNode<T>*

template<typename T>
void List<T>::insertionSort(ListNodePosi(T)p,int n)
{
	for(int r=0;r<n;r++)
	{
		insertA(search(p->data,r,p),p->data);
		p=p->succ;remove(p->pred);
	}
}

template<typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p,int n)
{
	ListNodePosi(T)max=p;
	for(ListNodePosi(T)cur=p;1<n;n--)
	if(!lt((cur=cur->succ)->data,max->data))
		max=cur;
	return max;
}

template<typename T>
void List<T>::insertionSort(ListNodePosi(T)p,int n)
{
	ListNodePosi(T) head=p->pred;	ListNodePosi(T) tail=p;
	for(int i=0;i<n;i++) tail=tail->succ;
	while(1<n)
	{
	ListNodePosi(T) max=selectMax(head->succ,n);
	insertB(tail,remove(max));
	tail=tail->pred;n--;
	}
}