#ifndef BOOKING_H
#define BOOKING_H

struct Customer {
    int id;
    char name[50];
    int room_no;
    int days;
    float cost;
};

void bookRoom();
void viewBookings();
void cancelBooking(int id);
float calculatePayment(int days, float rate);

#endif
