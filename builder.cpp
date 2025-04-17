#include <iostream>
#include <string>
using namespace std;
// Builder Pattern Example in C++
class Burger {
    public:
        string bun;
        string patty;
        string sauce;
        bool cheese;
    
        void showBurger() {
            cout << "Burger with " << bun << ", " << patty 
                 << ", " << (cheese ? "cheese" : "no cheese") 
                 << ", and " << sauce << " sauce." << endl;
        }
    };
class BurgerBuilder {
        public:
            virtual BurgerBuilder* setBun(string) = 0;
            virtual BurgerBuilder* setPatty(string) = 0;
            virtual BurgerBuilder* setSauce(string) = 0;
            virtual BurgerBuilder* addCheese(bool) = 0;
            virtual Burger build() = 0;
        };
        class VegBurgerBuilder : public BurgerBuilder {
            private:
                Burger burger;
            
            public:
                BurgerBuilder* setBun(string b) override {
                    burger.bun = b;
                    return this;
                }
            
                BurgerBuilder* setPatty(string p) override {
                    burger.patty = p;
                    return this;
                }
            
                BurgerBuilder* setSauce(string s) override {
                    burger.sauce = s;
                    return this;
                }
            
                BurgerBuilder* addCheese(bool c) override {
                    burger.cheese = c;
                    return this;
                }
            
                Burger build() override {
                    return burger;
                }
            };
class Chef {
    public:
        Burger makeVegBurger(BurgerBuilder* builder) {
            return builder
                ->setBun("Whole Wheat Bun")
                ->setPatty("Veg Patty")
                ->addCheese(true)
                ->setSauce("Tomato")
                ->build();
        }
};
int main() {
    Chef chef;
    VegBurgerBuilder builder;
    
    Burger myBurger = chef.makeVegBurger(&builder);
    myBurger.showBurger();
                
return 0;
}
                