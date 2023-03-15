#include <iostream>
#include <malloc.h>
#include <string.h>
 
using namespace std;
typedef struct TK{
     char Name[20];
  int SeatId;
     struct TK *next;
}Ticket;
 
 
typedef struct FLY
{
 char FlightId[10];
 int Seat[50];
 Ticket *PersonHead;
 struct FLY *next;
}Flight;
 
 
class Person{
public:
 void ListInitiate(Flight **head);
 bool Check(int *Seat,int Ch);
 void Insert(Flight *head);
 int Delete(Flight *head);
 void show(Flight *head);
 void Search(Flight *head);
 void AddFlght(Flight *head);
 void DeleteFlght(Flight *head);
};
