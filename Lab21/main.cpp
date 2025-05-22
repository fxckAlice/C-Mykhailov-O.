#include <iostream>
using namespace std;
class FlightBooking {
public:
	FlightBooking(int id, int capacity, int reserved);
	FlightBooking();
	void printStatus();
	bool reserveSeats(int number_ob_seats);
	bool cancelReservations(int number_ob_seats);
	int getId() {
		return id;
	}
private:
	int id;
	int capacity;
	int reserved;
};
FlightBooking::FlightBooking()
{
	id = 0;
	capacity = 0;
	reserved = 0;
}
FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
	this->id=id;
	this->capacity=capacity;
	if (reserved < 0) {
		this->reserved = 0;
	}
	else {
		this->reserved=reserved;
	}
}
bool FlightBooking::reserveSeats(int number_of_seats)
{
	int max_reservable = capacity * 1.05;
	if (reserved + number_of_seats <= max_reservable) {
		reserved += number_of_seats;
		return true;
	}
	return false;
}
bool FlightBooking::cancelReservations(int number_of_seats)
{
	if (number_of_seats > reserved) {
		return false;
	}
	reserved -= number_of_seats;
	return true;
}
void FlightBooking::printStatus()
{
	double percentage = (double)reserved / capacity * 100;
	cout << "Flight " << id << " : " << reserved << "/" << capacity
	     << " (" << (int)(percentage + 0.5) << "%) seats reserved" << endl;
}
int findFlight(FlightBooking bookings[], int size, int id) {
	for (int i = 0; i < size; ++i) {
		if (bookings[i].getId() == id)
			return i;
	}
	return -1;
}

void printAllFlights(FlightBooking bookings[], int size) {
	bool found  = false;
	for (int i = 0; i < size; ++i) {
		if (bookings[i].getId() != 0) {
			bookings[i].printStatus();
			found = true;
		}
	}
	if (!found )
		cout << "No flights in the system" << endl;
}
int main() {
	FlightBooking bookings[10];
	string command = "";

	while (true) {
		printAllFlights(bookings, 10);
		cout << "What would you like to do?: ";
		getline(cin, command);

		if (command == "quit")
			break;

		if (command.find("create") == 0) {
			int id, capacity;
			size_t pos = command.find(' ', 7);
			id = stoi(command.substr(7, pos - 7));
			capacity = stoi(command.substr(pos + 1));

			if (findFlight(bookings, 10, id) != -1) {
				cout << "Cannot perform this operation: flight already exists" << endl;
				continue;
			}

			bool created = false;
			for (int i = 0; i < 10; ++i) {
				if (bookings[i].getId() == 0) {
					bookings[i] = FlightBooking(id, capacity, 0);
					created = true;
					break;
				}
			}
			if (!created) {
				cout << "Cannot perform this operation: no space for new flights" << endl;
			}
		}
		else if (command.find("delete") == 0) {
			int id = stoi(command.substr(7));
			int idx = findFlight(bookings, 10, id);
			if (idx != -1) {
				bookings[idx] = FlightBooking();
			} else {
				cout << "Cannot perform this operation: flight not found" << endl;
			}
		}
		else if (command.find("add") == 0) {
			int id, n;
			size_t pos = command.find(' ', 4);
			id = stoi(command.substr(4, pos - 4));
			n = stoi(command.substr(pos + 1));

			int idx = findFlight(bookings, 10, id);
			if (idx != -1) {
				if (!bookings[idx].reserveSeats(n)) {
					cout << "Cannot perform this operation" << endl;
				}
			} else {
				cout << "Cannot perform this operation: flight not found" << endl;
			}
		}
		else if (command.find("cancel") == 0) {
			int id, n;
			size_t pos = command.find(' ', 7);
			id = stoi(command.substr(7, pos - 7));
			n = stoi(command.substr(pos + 1));

			int idx = findFlight(bookings, 10, id);
			if (idx != -1) {
				if (!bookings[idx].cancelReservations(n)) {
					cout << "Cannot perform this operation" << endl;
				}
			} else {
				cout << "Cannot perform this operation: flight not found" << endl;
			}
		}
		else {
			cout << "Unknown command" << endl;
		}
	}

	return 0;
}