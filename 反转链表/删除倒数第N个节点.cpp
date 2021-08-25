#include <iostream> 
#include <cstdlib>
#include <vector>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



void initLinkList(ListNode *&l1,vector<int>&array) 
{
    l1 = (ListNode*)malloc(sizeof(ListNode));
    l1 ->val=array[0];
    l1->next=NULL;
    ListNode *pTail = l1;
    for(int i = 1; i<array.size(); i++)
    {
        ListNode *pNew = (ListNode*)malloc(sizeof(ListNode));
        pNew ->val=array[i];
        pNew->next=NULL;
        pTail->next = pNew;
        pTail=pNew;
    }

}

void show(ListNode* l1)
{
    while (l1) 
    {
        cout<<l1->val<<" ";
        l1=l1->next;
    }
    cout<<endl;
}

int getLength(ListNode* head)
{
    int length=0;
    auto p=head;
    while(p)
    {
        length++;
        p=p->next;
    }
    return length;
}

ListNode* deleteNode(ListNode* head,int N)
{

    int length=0;
    auto p1=head;
    while(p1)
    {
        length++;
        p1=p1->next;
    }

   ListNode* pHead = new ListNode(0);
   pHead->next=head;
   auto p = pHead;
   auto q=p->next;
//    int length=getLength(head);
   int M = length-N+1;
   for(int i = 1; i<M;i++)
   {
      q=q->next;
      p=p->next;
   }

   p->next=q->next;
   delete q;
   return pHead->next;


}
int main(int argc, char** argv)
{
    vector<int > array1={1,2,3,4,5};
    vector<int> array2={9,9,9,9};
    ListNode *l1 =NULL;
    initLinkList(l1,array1);
    show(l1);
    cout<<getLength(l1)<<endl;
    // l1=linkListReverse(l1);
    l1=deleteNode(l1,5);
     show(l1);
    return 0;
}