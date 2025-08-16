#include <stdio.h>
#include "booking.h"

int main() {
    int choice, id;

    while (1) {
        printf("\n--- Hotel Booking System ---\n");
        printf("1. Book Room\n");
        printf("2. View Bookings\n");
        printf("3. Cancel Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                bookRoom();
                break;
            case 2:
                viewBookings();
                break;
            case 3:
                printf("Enter Customer ID to cancel: ");
                scanf("%d", &id);
                cancelBooking(id);
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
