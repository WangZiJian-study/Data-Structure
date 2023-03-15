#include <iostream>
using namespace std;
#include "Flight.h"

// constructors
Flight::Flight( const int fno, const int rno, const int sno) {
    flightNo = fno;
    rowNo = rno;
    seatNo = sno;
    totalResNo = 0;
}//航班类 

// destructor
Flight::~Flight() {

}

// functions
void Flight::setFlightNo( const int fno) {
    if ( fno > 0)
        flightNo = fno;
    else {
        cout << "invalid flight number" << endl;
    }
}
void Flight::setRowNo( const int rno) {
    if ( rno > 0)
       rowNo = rno;
    else {
        cout << "invalid row number" << endl;
    }
}
void Flight::setSeatNo( const int sno) {
    if ( sno > 0)
        seatNo = sno;
    else {
        cout << "invalid seat number" << endl;
    }
}

int Flight::getFlightNo() {
    return flightNo;
}
int Flight::getRowNo() {
    return rowNo;
}
int Flight::getSeatNo() {
    return seatNo;
}
int Flight::getAllSeatNo () {
    return rowNo * seatNo;
}
int Flight::getAvailableSeatNo() {
    return ( rowNo * seatNo ) - totalResNo;//可用座位数 
}
int Flight::getTotalResNo() {
    return totalResNo;//总座位数 
}

void Flight::increaseResNoBy( const int no){
    totalResNo = totalResNo + no;//增加总预定数 
}

void Flight::decreaseResNoBy( const int no){
    totalResNo = totalResNo - no;//减少总预定数 
}

void Flight::setResDefault() {
    totalResNo = 0;//重置 
}
