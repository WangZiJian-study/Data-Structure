#include "List.h"
 
void Person::ListInitiate(Flight **head)
{
 int count=0;
    *head = (Flight *)malloc(sizeof(Flight));
 (*head)->PersonHead=(Ticket *)malloc(sizeof(Ticket));
 (*head)->PersonHead->next=NULL;
    (*head)->next=NULL;
 for(int i=0;i<50;i++)
 {
  (*head)->Seat[i]=0;
 }
}
 
bool Person::Check(int *Seat,int Ch)
{
 int i;
 for(int i=0;i<50;i++)
 {
  if(Ch==i&&Seat[i]!=1)return 1;
 }
 return 0;
}
 
Flight* Index(Flight *head,char *Id)
{
 Flight *p=head->next;
 
 while(p)
 {
  if(strcmp(p->FlightId,Id)==0)
  {
   return p;
  }
  p=p->next;
 }
 
 return NULL;
}
/*******************************预定******************************/
void Person::Insert(Flight *head)
{
 int count=0;
 int Ch;
 Flight *s=head;
 
 if(s->next==NULL)
 {
  cout<<"暂无航班！"<<endl;
  return ;
 }
 
 cout<<"航班列表："<<endl;
 s=s->next;
 while(s!=NULL)
 {
  puts(s->FlightId);
  count++;
  if(count%5==0)
   cout<<"\n";
  s=s->next;
 }
 count=0;
 char FID[10];
 cout<<"输入航班ID：";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
  cout<<"输入ID有误"<<endl;
  return;
 }
 cout<<endl;
 cout<<"有以下座位可供选择："<<endl;
 for(int i=0;i<50;i++)
 {
  if(s->Seat[i]!=1)
  {
   cout<<i<<"号"<<"\t";
   count++;
   if(count%5==0)
    cout<<"\n";
  }
 }
 cout<<endl;
 cout<<"输入座位号：\n";
 cin>>Ch;
 getchar();
 if(!Check(head->Seat,Ch))
 {
  cout<<"This Seat have been booked or it is non-existent";
  return ;
 }
 s->Seat[Ch]=1;
 char name[20];
 cout<<endl;
 cout<<"Input your Name:";
 gets(name);
 Ticket *p=s->PersonHead,*q;
 
 while(p->next!=NULL)
 { 
  if(strcmp(p->next->Name,name)>0)
   break;
  p=p->next;
 }
 
 q=(Ticket *)malloc(sizeof(Ticket));
 q->next=p->next;
 p->next=q;
 strcpy(q->Name,name);
 q->SeatId=Ch;
}
 
/*******************************取消预定******************************/
int Person::Delete(Flight *head)
{
 char name[20],FID[10];
 cout<<"Input your Name:";
 gets(name);
 getchar();
 
 Flight *s;
 cout<<"Input the Flight ID:";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
  cout<<"输入ID有误"<<endl;
  return 0;
 }
 
 
 Ticket *p=s->PersonHead->next,*pre=s->PersonHead;
 int flag=0;
 while(p!=NULL)
 {
  if(strcmp(p->Name,name)==0){
   flag=1;
   break; 
  }
  pre=p;
  p=p->next;
 }
 if(flag==1){
  pre->next=p->next;
  s->Seat[p->SeatId]=0;
  free(p);
  cout<<"你的机票已经取消成功";
 }
 else 
 {
  cout<<"您还没订票\n";
  return 0; 
 }
 return 1;
 
}
 
/*******************************显示信息******************************/
void Person::show(Flight *head)
{
 Flight *s;
 char FID[10];
 cout<<"Input The Flight ID:";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
  cout<<"输入ID有误"<<endl;
  return;
 }
 Ticket *p=s->PersonHead->next;
 if(p==NULL)
 {
  cout<<"还没乘客订票"<<endl;
  return;
 }
 while(p!=NULL)
 {
  cout<<"乘客: "<<p->Name<<"   座位号:" <<p->SeatId;
  p=p->next;
 }
}
 
/*******************************查询相关信息******************************/
void Person::Search(Flight *head)
{
 char name[20];
 cout<<"Input Your Name:";
 gets(name);
 
 Flight *s;
 char FID[10];
 cout<<"Input The Flight ID:";
 gets(FID);
 s=Index(head,FID);
 if(s==NULL)
 {
  cout<<"输入ID有误"<<endl;
  return;
 }
 
 
 Ticket *p=s->PersonHead->next;
 int flag=0;
 while(p!=NULL)
 {
  if(strcmp(p->Name,name)==0){
   flag=1;
   break; 
  }
  p=p->next;
 }
 if(flag==1){
  cout<<name<<"  已订机票"<<endl;
 }
 else 
 {
  cout<<name<<"  未订机票"<<endl;
 }
}
 
/*******************************增加航班**********************************/
void Person::AddFlght(Flight *head)
{
 char FlightID[10];
 Flight *p=head,*q;
 
 cout<<"  输入航班ID：";
 gets(FlightID);
 
 while(p->next)
 {
  p=p->next;
 }
 
 ListInitiate(&q);
 p->next=q;
 strcpy(q->FlightId,FlightID);
 cout<<"——航班已添加成功！";
}
 
/**********************************删除航班*******************************************/
void Person::DeleteFlght(Flight *head)
{
 char FlightID[10];
 int flag=0;
 Flight *p=head->next,*q=head;
 
 int count=0;
 Flight *s=head;
 
 if(s->next==NULL)
 {
  cout<<"  暂无航班！"<<endl;
  return ;
 }
 
 cout<<"  航班列表："<<endl;
 s=s->next;
 while(s!=NULL)
 {
  cout<<s->FlightId<<endl;
  count++;
  if(count%5==0)
   cout<<"\n";
  s=s->next;
 }
 cout<<"  输入航班ID：";
 gets(FlightID);
 while(p)
 {
  if(strcmp(p->FlightId,FlightID)==0)
  {
   flag=1;break;
  }
  q=p;
  p=p->next;
 }
 if(flag==0)
 {
  cout<<"  该航班ID不存在！";
  return ;
 }
 q->next=q->next->next;
 free(p);
 cout<<"  航班已删除！\n";
}
