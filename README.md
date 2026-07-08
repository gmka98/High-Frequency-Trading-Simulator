# High-Frequency Order Book & Backtester in C++

## 📌 Project Overview
A lightweight, high-performance Limit Order Book (LOB) and backtesting engine written in modern C++. It supports Order insertion, cancellation, and execution matching using an efficient price-time priority algorithm.

## 🚀 Features
- **Limit Order Book:** Fast insertion and matching engine ($O(1)$ or $O(\log N)$ complexity).
- **Backtester:** Simulates trading strategies using historical CSV market data.
- **Performance Metrics:** Track PnL (Profit and Loss), Sharpe Ratio, and execution time.

## 🛠️ Architecture & Tech Stack
- **Language:** C++17 or C++20
- **Data Structures:** `std::map` for price levels, `std::list` for FIFO queue at each price point.
- **Build System:** CMake (Free and industry standard)

## 📊 Sample Output & Performance
[Insère ici un screenshot de la console qui montre les trades exécutés et le PnL final]
