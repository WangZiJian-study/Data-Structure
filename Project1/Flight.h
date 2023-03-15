#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

using namespace std;

class Flight {
public:
    // constructor
    Flight( const int fno, const int rno, const int sno);

    // destructor
    ~Flight();

	// set & get functions
	void setFlightNo( const int fno );
	void setRowNo( const int rno);
	void setSeatNo( const int sno);

	int getFlightNo();
	int getRowNo();
	int getSeatNo();
	int getAllSeatNo();
	int getAvailableSeatNo();
	int getTotalResNo();

	// reservation functions
	void increaseResNoBy( const int no);
	void decreaseResNoBy( const int no);
	void setResDefault();


private:
    //properties
    int flightNo;
    int rowNo;
    int seatNo;
    int totalResNo;
};

#endif // FLIGHT_H
