#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>

using namespace std;

class Reservation {
public:
    // constructors
    Reservation();
    ~Reservation();

    // functions
    int addRes( const int flightNo, const int passangerNo, const int *seatRow, const char *seatCol, const int rno, const int sno);
    void cancelRes( int resCode);
    void showRes( const int resCode);
    void cancelAllResFor( const int flightNo);

    bool flightHasRes( const int flightNo);
    bool seatIsReserved( const int flightNo, const int row, const int col);
    int getFlightNo( const int resCode);
    int getPassangerNo( const int resCode);

private:
    //properties
    int totalResNo;
    int* flightNoArr;
    int* passangerNoArr;
    int** reservedRowsArr;
    int** reservedColsArr;

    int letterToInt( const char character);
    char intToLetter( const int number);
};

#endif // RESERVATION_H
