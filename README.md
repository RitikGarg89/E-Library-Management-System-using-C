# 📚 E-library Management System (C-Based)

> A robust, console-driven Library Management System built using C. Designed for efficient book inventory management, customer circulation, and automated late fee calculations.

## 🚀 Features

### 📖 Book Management
- **Add Books**: Easily register new books with titles, authors, and page counts.
- **Inventory Display**: View a complete list of all books currently in the library.
- **Author Search**: Quickly find books by searching for a specific author.

### 💳 Customer & Circulation
- **Book Issuing**: Register customer details (Name, Email, Phone) and link them to issued books with precise dates.
- **Return & Billing**: 
  - Automated calculation of rent duration.
  - **Base Rent**: Rs. 50 (per month).
  - **Late Fees**: Rs. 2 per day for returns after the 30-day grace period.
- **Customer Directory**: Search for customer records and view their current issuance status.

### 📅 Advanced Date Logic
The system features a custom-built date engine:
- Leap year detection.
- Calculation of total days from a fixed epoch to determine precise date differences.

## 🛠️ Technical Details
- **Language**: C
- **Data Structures**: `struct`, `typedef`, and fixed-size arrays.
- **Constants**:
  - `MAX_BOOKS`: 100
  - `MAX_CUSTOMERS`: 100
  - `PRICE_PER_MONTH`: Rs. 50
  - `DAILY_LATE_FEE`: Rs. 2

## 💻 How to Run

### 1. Compile
Use a standard C compiler like `gcc`:
```bash
gcc library_system.c -o library_system
```

### 2. Execute
```bash
./library_system
```

## 📜 Usage Instructions
1. Navigate the menu using numeric inputs (1-7).
2. For dates, use the `dd/mm/yyyy` format to ensure correct fee calculation.
3. The system supports up to 100 books and 100 customer records in its current configuration.

---
*Efficient management for your digital bookshelf.*
