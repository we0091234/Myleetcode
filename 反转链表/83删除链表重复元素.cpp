#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int val):val(val),next(nullptr){}
};

ListNode *initNode(vector<int> &array)
{
    ListNode *pHead = new ListNode(0);
    auto pTail = pHead;
    for(int i = 0; i<array.size(); i++)
    {
        pTail->next=new ListNode(array[i]);
        pTail=pTail->next;
    }
    return pHead->next;
}
void showNode(ListNode *head)
{
    while(head)
    {
        if(head->next)
            cout<<head->val<<"->";
        else
         cout<<head->val<<endl;
         head=head->next;
    }
}
  ListNode* deleteDuplicates(ListNode* head) //I
  {
    ListNode *pHead = new ListNode(0);
    pHead->next=head;
    auto p = head;
    auto q = head->next;
    int tmp;
    int flag=0;
    while(q)
    {  
       tmp = p->val;
       while(q&&q->val==tmp )
       {
           p->next=q->next;
           q=q->next;
       }
       if(!q)
       break;
       p=q;
       q=q->next;
    }
    return  pHead->next;

    }

      ListNode* deleteDuplicates2(ListNode* head) //II
      {
        //   auto pHead= new ListNode(101);
        //   pHead->next =head;
        //   auto p = pHead;
        //   auto q = p->next;
        //   while(q)
        //   {
        //       int val = p->val;
        //       int  cnt = 0;
        //       while(q&&q->val==val)
        //       {
        //              cnt++
                     
        //       }
        //       if(!q)
        //       break;
        //       p =q;
        //       q=q->next;
        //   }
        map<int,int> mymap;
        auto p = head;
    while(p)
    {
        mymap[p->val]++;
        p=p->next;
    }
    for(map<int,int>::iterator it = mymap.begin();it!=mymap.end();)
    {
        if (it->second >1)
        mymap.erase(it++);
        else
        it++;
    }

    auto pHead=new ListNode(0);
    pHead->next =head;
     p = pHead;
    map<int,int >::iterator it;
    int flag = 0;
    while(head)
    {
        flag = 0;
      it = mymap.find(head->val);
      if(it==mymap.end())
      {
          flag = 1;
          p->next=head->next;
          head=head->next;
      }
       
       if(!flag)
       {
           p=p->next;
       head=head->next;
       }
    }
    return  pHead->next;

      }
    


ListNode *reverseNode(ListNode *left,ListNode *right) //作用是将一段[2，4) 将节点left到right之间的链表反转，比如[1,2,3,4,5]如果left=1,right=3  反转就变为[2,1,3,4,5] right是闭区间
{
    if(left==NULL)
    return left;
    auto pre =left;
    auto cur=pre->next;
    while(cur!=right)
    {
        auto tmp =cur->next;
        cur->next =pre;
        pre=cur;
        cur=tmp;
    }
    // left->next =NULL;
    return pre;
}





int main(int argc,char **argv)
{
    vector<int>  array{-50,-50,-49,-48,-47,-47,-47,-46,-45,-43,-42,-41,-40,-40,-40,-40,-40,-40,-39,-38,-38,-38,-38,-37,-36,-35,-34,-34,-34,-33,-32,-31,-30,-28,-27,-26,-26,-26,-25,-25,-24,-24,-24,-22,-22,-21,-21,-21,-21,-21,-20,-19,-18,-18,-18,-17,-17,-17,-17,-17,-16,-16,-15,-14,-14,-14,-13,-13,-12,-12,-10,-10,-9,-8,-8,-7,-7,-6,-5,-4,-4,-4,-3,-1,1,2,2,3,4,5,6,6,7,8,8,9,9,10,10,10,11,11,12,12,13,13,13,14,14,14,15,16,17,17,18,20,21,22,22,22,23,23,25,26,28,29,29,29,30,31,31,32,33,34,34,34,36,36,37,37,38,38,38,39,40,40,40,41,42,42,43,43,44,44,45,45,45,46,47,47,47,47,48,49,49,49,50};
    auto head= initNode(array);
    showNode(head);
    head=deleteDuplicates2(head);
     showNode(head);
}