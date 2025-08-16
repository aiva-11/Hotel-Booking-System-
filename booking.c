#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "booking.h"

#define FILE_NAME "records.txt"

void bookRoom() {
    struct Customer c;
    FILE *fp = fopen(FILE_NAME, "a");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Customer ID: ");
    scanf("%d", &c.id);
    printf("Enter Name: ");
    scanf(" %[^\n]", c.name);
    printf("Enter Room No: ");
    scanf("%d", &c.room_no);
    printf("Enter No. of Days: ");
    scanf("%d", &c.days);

    float rate = 1000.0;  // Example rate per day
    c.cost = calculatePayment(c.days, rate);

    fprintf(fp, "%d,%s,%d,%d,%.2f\n", c.id, c.name, c.room_no, c.days, c.cost);
    fclose(fp);

    printf("Booking Successful! Total Cost = %.2f\n", c.cost);
}

void viewBookings() {
    struct Customer c;
    FILE *fp = fopen(FILE_NAME, "r");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    printf("\n--- Current Bookings ---\n");
    while (fscanf(fp, "%d,%49[^,],%d,%d,%f\n", &c.id, c.name, &c.room_no, &c.days, &c.cost) == 5) {
        printf("ID: %d | Name: %s | Room: %d | Days: %d | Cost: %.2f\n",
               c.id, c.name, c.room_no, c.days, c.cost);
    }
    fclose(fp);
}

void cancelBooking(int id) {
    struct Customer c;
    FILE *fp = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    int found = 0;
    while (fscanf(fp, "%d,%49[^,],%d,%d,%f\n", &c.id, c.name, &c.room_no, &c.days, &c.cost) == 5) {
        if (c.id != id) {
            fprintf(temp, "%d,%s,%d,%d,%.2f\n", c.id, c.name, c.room_no, c.days, c.cost);
        } else {
            found = 1;
        }
    }

    fclose(fp);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found)
        printf("Booking with ID %d canceled!\n", id);
    else
        printf("Booking ID not found!\n");
}

float calculatePayment(int days, float rate) {
    return days * rate;
}
