// Author: Sean Davis

#include <string.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "flight.h"
#include "utilities.h"

using namespace std;

void Flight::addPassenger() const
{
  if(!plane->addPassenger(flightNum))
    cout << "We are sorry but Flight #" << flightNum << " is full.\n";
  
}  // addPassenger()

void Flight::removePassenger() const
{
  cout << "Passengers on Flight #" << flightNum << endl;
  plane->removePassenger();
} //

void Flight::addFlight()
{
  cout << "\nFlight number to add: ";
  cin >> flightNum;
  cin.ignore(TEN, '\n');
  cout << "Origin: ";
  cin.getline(origin, MAX_CITY_LENGTH);
  cout << "Destination: ";
  cin.getline(destination, MAX_CITY_LENGTH);
  plane = new Plane();
  plane->addPlane();
} //

void Flight::removeFlight()
{
  plane->removePlane();
} //

Flight::~Flight()
{
  ofstream outf ("flights2.csv", ios::out | ios::app);
  outf << flightNum << "," << origin << "," << destination << ",";
  plane->writePlane(outf, flightNum);
  outf.close();
  delete plane;
}  // freeFlight()


int Flight::getFlightNumber() const
{
  return flightNum;
}  // getFlightNumber()


void Flight::printFlightInfo() const
{
  cout << left << setw(FLIGHT_NUM_SPACE) << flightNum << ' ' 
    << setw(MAX_CITY_LENGTH) << origin << ' '  << destination << endl;
}  // printFlightInfo()


void Flight::readFlight( ifstream &inf)
{ 
  inf >> flightNum;
  inf.ignore(TEN, ',');
  inf.getline(origin, MAX_CITY_LENGTH, ',');
  inf.getline(destination, MAX_CITY_LENGTH, ',');
  plane = new Plane(inf, flightNum);
}  // readFlight()


