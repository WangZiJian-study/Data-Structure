#include <iostream>
using namespace std;
#include "ReservationSystem.h"

int main() {

ReservationSystem R;

    R.showAllFlights();
	//添加三个航班 
    R.addFlight(338, 4, 3);
    R.addFlight(412, 8, 3);
    R.addFlight(168, 6, 2);
    //显示所有航班 
    R.showAllFlights();
	//添加已有航班--失败 
    R.addFlight(338, 8, 6);
    R.showAllFlights();
    
    R.showFlight(338);
    int rowRes1[4] = {3, 3, 1, 1};
    char colRes1[4] = {'A', 'B', 'B', 'C'};
    // 预定338航班座位: 3A, 3B, 1B, 1C
    int Num1 = R.makeReservation(338, 4, rowRes1, colRes1);
    if (Num1 != -1)
    cout << "Your reservation code is " << Num1 << endl;

    cout << endl;


    R.showFlight(338);
    int rowRes2[2] = {2, 4};
    char colRes2[2] = {'A', 'C'};
    int Num2 = R.makeReservation(338, 2, rowRes2, colRes2);
    if (Num2 != -1)
    cout << "Your reservation code is " << Num2 << endl;

    cout << endl;

    R.showFlight(338);
    int rowRes3[2] = {2, 3};
    char colRes3[2] = {'B', 'A'};//3A已满 
    int code3 = R.makeReservation(338, 2, rowRes3, colRes3);
    if (code3 != -1)
    cout << "Your reservation code is " << code3 << endl;

    cout << endl;

    R.showFlight(338);
    int rowRes4[7] = {1, 2, 2, 3, 4, 3, 1};
    char colRes4[7] = {'A', 'B', 'C', 'C', 'A', 'B', 'B'};//3B, 1B已满 
    int code4 = R.makeReservation(338, 7, rowRes4, colRes4);
    if (code4 != -1)
    cout << "Your reservation code is " << code4 << endl;

    cout << endl;

    R.showFlight(338);
    R.showAllFlights();
    R.showReservation(100);//无 

    R.showReservation(Num1);
    R.cancelReservation(300);//无 
    R.cancelReservation(Num2);

    R.showFlight(338);
    R.showAllFlights();
    R.cancelFlight(412);
    R.showFlight(412);
    R.showAllFlights();
    R.cancelFlight(674);
    R.showAllFlights();

    // buradan sonra bir s?k?nt? var
    R.cancelFlight(338);
    R.showReservation(Num1);
    R.showAllFlights();

    return 0;
}
