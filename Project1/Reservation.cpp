#include <iostream>
#include <iomanip>
using namespace std;
#include "Reservation.h"

// ���캯�� 
Reservation::Reservation() {
    totalResNo = 0;
    reservedRowsArr = NULL;
    reservedColsArr = NULL;
    flightNoArr = NULL;
    passangerNoArr = NULL;
}
// ��������
Reservation::~Reservation() {
    delete[] flightNoArr;

    delete[] passangerNoArr ;


    for ( int i = 0; i < ( sizeof(reservedRowsArr) / sizeof(int)); i++) {
        delete reservedRowsArr[i];
    }

    delete[] reservedRowsArr;


    for ( int i = 0; i < ( sizeof(reservedColsArr) / sizeof(int)); i++) {
        delete reservedColsArr[i];
    }
    delete[] reservedColsArr;

}

// functions
// Ԥ����λ 
int Reservation::addRes( const int flightNo, const int passangerNo, const int *seatRow, const char *seatCol, const int rno, const int sno){
        // ����Ԥ�������䶯̬���鱣�溽��ţ�Ԥ������ 
		if ( totalResNo == 0) {

            flightNoArr = new int[1];
            passangerNoArr = new int[1];
            reservedRowsArr = new int*[1];
            reservedColsArr = new int*[1];

            passangerNoArr[totalResNo] = passangerNo;
            flightNoArr[totalResNo] = flightNo;
            reservedRowsArr[totalResNo] = new int[passangerNo];
            reservedColsArr[totalResNo] = new int[passangerNo];


            for ( int i = 0; i < passangerNo; i++) {
                reservedRowsArr[totalResNo][i] = seatRow[i];
            }

            for ( int i = 0; i < passangerNo; i++) {
                reservedColsArr[totalResNo][i] = letterToInt(seatCol[i]);
            }

            totalResNo++;
            return totalResNo;
        }
        // ����ʱ���鸴������Ԥ������չһ����λ�����µ�Ԥ�������ͷž����� 
        else {
            int reservedSeatCount = 0;
            bool isReserved = false;
            // reserve

            for ( int i = 0; i < passangerNo; i++) {

                if ( seatIsReserved( flightNo, seatRow[i], letterToInt(seatCol[i]))) {

                    cout << seatRow[i] << seatCol[i] << " ";
                    reservedSeatCount++;
                    isReserved = true;
                }
            }

            if ( isReserved) {
                if ( reservedSeatCount == 1) {
                    cout << "is not available." << endl;
                    return -1;
                }
                else {
                    cout << "are not available." << endl;
                    return -1;
                }

            }
            else {
                int* tempFlightNoArr = flightNoArr;
                int* tempPassangerNoArr = passangerNoArr;
                int** tempRows = reservedRowsArr;
                int** tempCols = reservedColsArr;

                tempFlightNoArr = new int [totalResNo+1];
                tempPassangerNoArr = new int [totalResNo+1];
                tempRows = new int*[totalResNo+1];
                tempCols = new int*[totalResNo+1];


                for ( int i = 0; i < totalResNo; i++) {
                    tempFlightNoArr[i] = flightNoArr[i];
                    tempPassangerNoArr[i] = passangerNoArr[i];
                    tempRows[i] = new int[passangerNoArr[i]];
                    tempCols[i] = new int[passangerNoArr[i]];

                    for ( int j = 0; j < passangerNoArr[i]; j++) {

                        tempRows[i][j] = reservedRowsArr[i][j];
                        tempCols[i][j] = reservedColsArr[i][j];
                    }
                }


            for (int i = 0 ; i < totalResNo ; i++)
            {
                delete[] reservedRowsArr[i];
                delete[] reservedColsArr[i];
            }
            delete []reservedRowsArr;
            delete []reservedColsArr;
            delete []flightNoArr;
            delete []passangerNoArr;

            tempFlightNoArr[totalResNo] = flightNo;
            flightNoArr = tempFlightNoArr;

            tempPassangerNoArr[totalResNo] = passangerNo;
            passangerNoArr = tempPassangerNoArr;

            tempRows[totalResNo] = new int[passangerNo];
            tempCols[totalResNo] = new int[passangerNo];

            for ( int i = 0; i < passangerNo; i++) {
                tempRows[totalResNo][i] = seatRow[i];
                tempCols[totalResNo][i] = letterToInt(seatCol[i]);
            }

            reservedRowsArr = tempRows;
            reservedColsArr = tempCols;

            totalResNo++;
            return totalResNo;
        }
    }
}

// ȡ��Ԥ�� 
void Reservation::cancelRes( int resCode) {
    // �Ƚ�ƥ��Ԥ�� 
    if ( resCode <= 0 || resCode > totalResNo) {
        cout << "No reservations are found under Num " << resCode << endl;
        cout << endl;
        return;
    }
    else {
        resCode--;
        cout << "Reservation for the seats ";
        for ( int i = 0; i < passangerNoArr[resCode]; i++) {
             cout << reservedRowsArr[resCode][i] << intToLetter(reservedColsArr[resCode][i]) << " ";
        }
        cout << "is canceled in Flight " << flightNoArr[resCode] << endl;


        flightNoArr[resCode] = 0;
        passangerNoArr[resCode] = 0;

        delete reservedRowsArr[resCode];
        delete reservedColsArr[resCode];

        reservedRowsArr[resCode] = NULL;
        reservedColsArr[resCode] = NULL;

        totalResNo--;
    }
}

// ����resCode��ȡԤ����Ϣ 
void Reservation::showRes( const int resCode) {

    if ( resCode <= 0 || resCode > totalResNo) {
        cout << "No reservations under Num " << resCode << endl;
        cout << endl;
        return;
    }
    else {
            if ( passangerNoArr[resCode-1] == 0){
                cout << "No reservations under Num " << resCode << endl;
                cout << endl;
                return;
            }
            else {
                cout << "Reservations under Num " << resCode << " in Flight " << flightNoArr[resCode-1] << ": ";

                for ( int i = 0; i < passangerNoArr[resCode-1]; i++) {
                    cout << reservedRowsArr[resCode-1][i] << intToLetter(reservedColsArr[resCode-1][i]) << " ";
                }
                cout << "\n" << endl;
            }
    }
}
// ȡ�������ΪflightNo��Ԥ�� 
void Reservation::cancelAllResFor( const int flightNo) {
    if ( totalResNo <= 0) {
        cout << "There are no reservations to cancel" << endl;
    }
    else {
        for ( int i = 0; i < totalResNo; i++) {
            if ( flightNoArr[i] == flightNo){
                flightNoArr[i] = 0;
                passangerNoArr[i] = 0;

                delete reservedRowsArr[i];
                delete reservedColsArr[i];

                reservedRowsArr[i] = NULL;
                reservedColsArr[i] = NULL;
            }
        }
    }
}
// ȡ��Ԥ����¼ 
bool Reservation::flightHasRes( const int flightNo) {
    if ( totalResNo == 0) {
        return false;
    }

    for ( int i = 0; i < totalResNo; i++){
        if ( flightNoArr[i] == flightNo) {
            return true;
        }
    }

    return false;
}

// �ж��Ƿ�Ԥ�� 
bool Reservation::seatIsReserved( const int flightNo , const int row, const int col) {

    if ( totalResNo == 0 ) {
        return false;
    }
    else {

        for( int i = 0 ; i < totalResNo; i++) {
            for ( int j = 0 ; j < passangerNoArr[i]; j++) {
                if ( reservedRowsArr[i][j] == row && reservedColsArr[i][j] == col ){
                    return true;
                }
            }
        }
    }
    return false;
}

// ����Ԥ����ŵĺ���� 
int Reservation::getFlightNo( const int resCode) {
    if ( resCode > 0 && resCode <= totalResNo) {
        return flightNoArr[resCode-1];
    }
    return -1;
}

// ����Ԥ����ŵĳ˿��� 
int Reservation::getPassangerNo( const int resCode) {
    if ( resCode > 0 && resCode <= totalResNo) {
        return passangerNoArr[resCode-1];
    }
    return -1;
}

// ��ĸ����ת�� 
int Reservation::letterToInt( const char character) {
    return (int) ( character - 'A' );
}

char Reservation::intToLetter( const int number ) {
    if ( number >= 0 && number <= 25 )
    {
        return "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[number];
    }
    return '-';
}

