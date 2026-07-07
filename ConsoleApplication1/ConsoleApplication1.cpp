// ConsoleApplication1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include <list>
#include <memory>
#include <map>
#include <algorithm> 

enum class OrderSide {
    BUY,
    SELL
};

struct Order {
    int id;
    double price;
    int quantity;
    OrderSide side;


    Order(int _id, double _price, int _quantity, OrderSide _side)
        : id(_id), price(_price), quantity(_quantity), side(_side) { }

};

struct PriceLevel {
    double price;

    PriceLevel() = default;

    PriceLevel(double _price) 
        : price(_price) { }
    
    std::list<std::shared_ptr<Order>> orders;
    
    void addOrder(std::shared_ptr<Order> newOrder) {
        orders.push_back(newOrder);
    }

};

struct OrderBook {
    std::map<double, PriceLevel> asks;
    std::map<double, PriceLevel, std::greater<double>> bids;

    void addOrder(std::shared_ptr<Order> order) {

        if (order->side == OrderSide::BUY) {
            bids[order->price].addOrder(order);
        }

        else {
            asks[order->price].addOrder(order);
        }
        matchOrder();
    }

    void matchOrder(){
        while(!bids.empty() && !asks.empty()){
            auto bestbidIt = bids.begin();
            auto bestAskIt = asks.begin();

            if (bestbidIt->first >= bestAskIt->first) {
                auto& buyOrder = bestbidIt->second.orders.front();
                auto& sellOrder = bestAskIt->second.orders.front();

                int tradeQuantity = std::min(buyOrder->quantity, sellOrder->quantity);

                //3 On reduit les volumes restantes
				buyOrder->quantity -= tradeQuantity;
                sellOrder->quantity -= tradeQuantity;

                std::cout << "-> TRADE EXECUTE ! Quantity:" << tradeQuantity << " Price:" << bestAskIt->first << std::endl;
            }
            if (buyOrder->quantity == 0) {
                bestbidIt->second.orders.pop_front();
            };
            if (sellOrder->quantity == 0) {
                bestAskIt->second.orders.pop_front();
            };
            if (bestbidIt->second.orders.empty()) {
                bids.erase(bestbidIt);
            }
            if (bestaskIt->second.orders.empty()) {
                asks.erase(bestAskIt);
            }
            ;
           
        
        }
    
    }
};

int main() {

    OrderBook book;

	// Ajouter un ordre d'achat
    auto buyOrder = std::make_shared<Order>(1, 98.25, 5, OrderSide::BUY);
    book.addOrder(buyOrder);
    std::cout << "Buy order:" << book.bids[98.25].orders.size() << buyOrder->price << std::endl;

	// Ajouter un ordre de vente
    auto sellOrder = std::make_shared<Order>(2, 98.25, 5, OrderSide::SELL);
    book.addOrder(sellOrder);
    std::cout << "Sell order: " << sellOrder->price << std::endl;

    auto buyOrder = std::make_shared<Order>(4, 99.25, 10, OrderSide::BUY);


    return 0;
};

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln