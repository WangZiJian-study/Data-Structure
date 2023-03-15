#ifndef RESERVATIONSYSTEM_H
#define RESERVATIONSYSTEM_H

#include <string>
#include "Flight.h"
#include "Reservation.h"

using namespace std;

class ReservationSystem {
public:
    // constructor
    ReservationSystem();
    // destructor
    ~ReservationSystem();

    // functions
	void addFlight( const int flightNo, const int rowNo, const int seatNo );
	void cancelFlight( const int flightNo );
    void showAllFlights();
    void showFlight( const int flightNo );

	int makeReservation( const int flightNo, const int numPassengers, const int *seatRow, const char *seatCol );
	void cancelReservation( const int resCode );
	void showReservation( const int resCode );

private:
    // variables
    Flight** flightsArr;
    Reservation res;
    int totalResNo;
    int totalFlightNo;

    // function
    void showDetailedInformation( const int flightNo);
    char intToLetter( const int number);
};

#endif // RESERVATIONSYSTEM_H
