#include "list.h"
 
int menu()
{
	int option;
	cout<<endl<<endl;
	cout<<"���˵�"<<endl;
	cout<<"  1.Booking the ticket of flighting"<<endl;
	cout<<"  2.Cancel the flighting"<<endl;
	cout<<"  3.Display the information "<<endl;
	cout<<"  4.Search"<<endl;
	cout<<"  5.Add a Flight"<<endl;
	cout<<"  6.Delete a Flight"<<endl;
	cout<<"  0.Exit"<<endl<<endl;
	cout<<"Please input your option:";
	cin>>option;
	getchar();
	cout<<endl;
	if(option>=0&&option<=6)
	 	return option;
	else 
	  	return -1;
}
 
int main()
{ 
 
  	cout<<"------------------------->�������ϵͳ<<<<-----------------------------"<<endl;
 	cout<<"                      ��ӭ��ʹ�øú���ϵͳ"<<endl;
   	Flight *head;
  	Person P;
	P.ListInitiate(&head);
 	switch(menu( ))
  	{
 		 case 1:P.Insert(head);break;   //Ԥ��
 		 case 2:P.Delete(head);break;   //ȡ��
 		 case 3:P.show(head);break;     //��ʾ
  		case 4:P.Search(head);break;     //��ѯ
 		 case 5:P.AddFlght(head);break;  //��Ӻ���
 		 case 6:P.DeleteFlght(head);break; //ɾ������
  		case 0:exit(0);
 		 default:cout<<"Choice error!\n";
  	}
    return 0;
}
