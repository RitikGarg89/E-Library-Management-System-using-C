#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_CUSTOMERS 100
#define PRICE_PER_MONTH 50
#define DAILY_LATE_FEE 2

// Structure to store book information
typedef struct
{
    char title[100];
    char author[100];
    int pages;
} Book;

// Structure to store customer information
typedef struct
{
    char customerName[100];
    char email[100];
    char phone[15];
    char bookTitle[100];
    char bookAuthor[100];
    char issueDate[15];
    char returnDate[15];
    int isIssued;
} Customer;

// Global arrays to store books and customers
Book library[MAX_BOOKS];
Customer customers[MAX_CUSTOMERS];
int bookCount = 0;     // Counter for the number of books in the library
int customerCount = 0; // Counter for the number of customers

// Function declarations
void addBook();
void displayBooks();
void searchByAuthor();
void issueBook();
void returnBook();
void searchCustomerDetails();
int isLeapYear(int year);
int daysInMonth(int year, int month);
int totalDaysFromStart(int day, int month, int year);
int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2);

// Function to add a book to the library
void addBook()
{
    char yn;
    for (;;)
    {
        printf("Do you Want To Add Book (Y/N): ");
        scanf(" %c", &yn);
        if (yn == 'Y' || yn == 'y')
        {
            if (bookCount >= MAX_BOOKS)
            {
                printf("Library is full!\n");
                return;
            }
            printf("\n##########################################\n");
            printf("\nEnter book title: ");
            scanf(" %[^\n]%*c", library[bookCount].title);
            printf("Enter author: ");
            scanf(" %[^\n]%*c", library[bookCount].author);
            printf("Enter number of pages: ");
            scanf("%d", &library[bookCount].pages);
            bookCount++;
            printf("Book added successfully!\n");
            printf("\n##########################################\n");
        }
        else
        {
            break;
        }
    }
}

// Function to display all books in the library
void displayBooks()
{
    if (bookCount == 0)
    {
        printf("No books in the library.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++)
    {
        printf("\n##########################################\n");
        printf("\tBook %d\n", i + 1);
        printf("\tTitle: %s\n", library[i].title);
        printf("\tAuthor: %s\n", library[i].author);
        printf("\tPages: %d\n", library[i].pages);
        printf("\n");
        printf("\n##########################################\n");
    }
}

// Function to search books by a specific author
void searchByAuthor()
{
    char author[100];
    printf("Enter author name to search: ");
    scanf(" %[^\n]%*c", author);
    int found = 0;
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(library[i].author, author) == 0)
        {
            printf("\n##########################################\n");
            printf("\tTitle: %s\n", library[i].title);
            printf("\tAuthor: %s\n", library[i].author);
            printf("\tPages: %d\n", library[i].pages);
            printf("\n##########################################\n");
            printf("\n");
            found = 1;
        }
    }
    if (!found)
    {
        printf("No books found by this author.\n");
    }
}

// Function to issue a book to a customer
void issueBook()
{
    if (customerCount >= MAX_CUSTOMERS)
    {
        printf("Cannot issue more books. Customer limit reached.\n");
        return;
    }
    printf("\n##########################################\n");

    printf("Enter customer name: ");
    scanf(" %[^\n]%*c", customers[customerCount].customerName);
    printf("Enter email: ");
    scanf(" %[^\n]%*c", customers[customerCount].email);
    printf("Enter phone number: ");
    scanf(" %[^\n]%*c", customers[customerCount].phone);
    printf("Enter book title: ");
    scanf(" %[^\n]%*c", customers[customerCount].bookTitle);
    printf("Enter book author: ");
    scanf(" %[^\n]%*c", customers[customerCount].bookAuthor);
    printf("Enter issue date (dd/mm/yyyy): ");
    scanf(" %[^\n]%*c", customers[customerCount].issueDate);
    customers[customerCount].isIssued = 1;
    customerCount++;
    printf("\nBook issued successfully!\n");
    printf("\n##########################################\n");
}

// Function to return a book from a customer
void returnBook()
{
    char customerName[100], phone[15], bookTitle[100], bookAuthor[100], returnDate[15];
    printf("\n##########################################\n");
    printf("Enter customer name: ");
    scanf(" %[^\n]%*c", customerName);
    printf("Enter phone number: ");
    scanf(" %[^\n]%*c", phone);
    printf("Enter book title: ");
    scanf(" %[^\n]%*c", bookTitle);
    printf("Enter book author: ");
    scanf(" %[^\n]%*c", bookAuthor);
    printf("Enter return date (dd/mm/yyyy): ");
    scanf(" %[^\n]%*c", returnDate);

    for (int i = 0; i < customerCount; i++)
    {
        if (customers[i].isIssued && strcmp(customers[i].customerName, customerName) == 0 &&
            strcmp(customers[i].phone, phone) == 0 &&
            strcmp(customers[i].bookTitle, bookTitle) == 0 &&
            strcmp(customers[i].bookAuthor, bookAuthor) == 0)
        {
            customers[i].isIssued = 0;
            strcpy(customers[i].returnDate, returnDate);

            // Calculate date difference
            int day1, month1, year1, day2, month2, year2;
            sscanf(customers[i].issueDate, "%d/%d/%d", &day1, &month1, &year1);
            sscanf(returnDate, "%d/%d/%d", &day2, &month2, &year2);

            int totalDays1 = totalDaysFromStart(day1, month1, year1);
            int totalDays2 = totalDaysFromStart(day2, month2, year2);
            int diff = totalDays2 - totalDays1;

            // Calculate late fee if returned after a month
            int lateDays = diff - 30;
            printf("Rent fee: Rs. %d\n", PRICE_PER_MONTH);
            if (lateDays > 0)
            {
                int lateFee = lateDays * DAILY_LATE_FEE;
                printf("Late fee: Rs. %d\n", lateFee);
                printf("Total Amount You have to Pay: Rs. %d\n", lateFee + PRICE_PER_MONTH);
            }

            printf("Book returned successfully!\n");
            return;
            printf("\n##########################################\n");
        }
    }
    printf("No such issued book found for the given customer details.\n");
}

// Function to search details of a specific customer
void searchCustomerDetails()
{
    char customerName[100];
    printf("Enter customer name to search: ");
    scanf(" %[^\n]%*c", customerName);
    int found = 0;
    for (int i = 0; i < customerCount; i++)
    {
        if (strcmp(customers[i].customerName, customerName) == 0)
        {
            printf("Customer Name: %s\n", customers[i].customerName);
            printf("Email: %s\n", customers[i].email);
            printf("Phone: %s\n", customers[i].phone);
            printf("Book Title: %s\n", customers[i].bookTitle);
            printf("Book Author: %s\n", customers[i].bookAuthor);
            printf("Issue Date: %s\n", customers[i].issueDate);
            printf("Return Date: %s\n", customers[i].returnDate);
            printf("Is Issued: %s\n", customers[i].isIssued ? "Yes" : "No");
            printf("\n");
            found = 1;
        }
    }
    if (!found)
    {
        printf("No customer found with the given name.\n");
    }
}

// Function to check if a year is a leap year
int isLeapYear(int year)
{
    if (year % 4 == 0)
    {
        return 1;
    }
    return 0;
}

// Function to get the number of days in a month
int daysInMonth(int year, int month)
{
    int daysInMonthArray[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    return daysInMonthArray[month - 1];
}

// Function to calculate the total number of days from a fixed date (1/1/0000) to the given date
int totalDaysFromStart(int day, int month, int year)
{
    int totalDays = 0;

    // Count days for complete years
    for (int i = 0; i < year; i++)
    {
        totalDays += isLeapYear(i) ? 366 : 365;
    }

    // Count days for complete months in the given year
    for (int i = 1; i < month; i++)
    {
        totalDays += daysInMonth(year, i);
    }

    // Add the days in the current month
    totalDays += day;

    return totalDays;
}

int main()
{
    int day1, month1, year1, day2, month2, year2;
    int choice;
    do
    {
        printf("\n\n##########################################\
        tE-library Management System\t##########################################\n");
        printf("PRESS>>>1. Add Book Information\n");
        printf("PRESS>>>2. Display All Books Information\n");
        printf("PRESS>>>3. Search by Author\n");
        printf("PRESS>>>4. Customer Issuing Book\n");
        printf("PRESS>>>5. Customer Returning Book\n");
        printf("PRESS>>>6. Search Customer Details\n");
        printf("PRESS>>>7. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addBook();
            break;
        case 2:
            displayBooks();
            break;
        case 3:
            searchByAuthor();
            break;
        case 4:
            issueBook();
            break;
        case 5:
            returnBook();
            break;
        case 6:
            searchCustomerDetails();
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 7);

    return 0;
}
