#include <iostream>
using namespace std;
#include "Flight.h"

// constructors
Flight::Flight( const int fno, const int rno, const int sno) {
    flightNo = fno;
    rowNo = rno;
    seatNo = sno;
    totalResNo = 0;
}//������ 

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
    return ( rowNo * seatNo ) - totalResNo;//������λ�� 
}
int Flight::getTotalResNo() {
    return totalResNo;//����λ�� 
}

void Flight::increaseResNoBy( const int no){
    totalResNo = totalResNo + no;//������Ԥ���� 
}

void Flight::decreaseResNoBy( const int no){
    totalResNo = totalResNo - no;//������Ԥ���� 
}

void Flight::setResDefault() {
    totalResNo = 0;//���� 
}
