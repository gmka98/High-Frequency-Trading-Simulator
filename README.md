# 📈 C++ Order Book & Matching Engine

A lightweight, high-performance financial order matching engine written in **Modern C++**. 

This project simulates the core matching mechanism of a financial exchange (e.g., Stock Exchange, Crypto Exchange). It receives buy and sell orders, maintains an Order Book, and automatically executes trades when conditions match.

---

## 🛠️ Features

- **Order Types:**
  - **LIMIT**: Buy/Sell at a specified price or better.
  - **MARKET**: Buy/Sell immediately at the best available market price.
- **Matching Logic:**
  - **Price-Time Priority** matching algorithm.
  - **Partial Fills**: Tracks remaining order quantities in the book.
- **Architecture & Data Structures:**
  - `std::map`: Automatically sorts price levels (bids in descending order, asks in ascending order).
  - `std::list`: FIFO queue for orders at the same price level.
  - `std::shared_ptr`: Safe and efficient dynamic memory allocation.
- **Reporting:** Real-time execution logs via a `TickerTape` data structure.

---

## 🏗️ Project Architecture

```text
├── Order.h          # Data structures for Order, PriceLevel, and Enums (OrderSide, OrderType)
├── OrderBook.h      # Declarations for OrderBook class and TradeReport struct
├── OrderBook.cpp    # Matching logic and Bids/Asks map management
└── main.cpp         # Entry point for testing and market scenario simulation
