#include <iostream>
#include <string>

class BankAccount{
private:
    int balance;

public:
    BankAccount() : balance(0) {
        std::cout << "Bank Constructor called" << std::endl;
    }
    BankAccount(int b) : balance(b) {
        std::cout << "Bank Constructor called" << std::endl;
    }
    ~BankAccount(){
        std::cout << "Bank Destructor called" << std::endl;
    }

    virtual std::string getAccountType() const{
        return "Bank Account";
    };
    friend void printBalance(const BankAccount&);
    int getBalance(){return balance;}
    void setBalance(int new_balance){
        balance = new_balance;
    }
};

class SavingsAccount : public BankAccount{
private:
    double interestRate;
public:
    SavingsAccount() : BankAccount(), interestRate(0){
        std::cout << "Savings constructor called" << std::endl;
    }
    SavingsAccount(int b, double ir) : BankAccount(b), interestRate(ir) {
        std::cout << "Savings constructor called" << std::endl;
    }
    ~SavingsAccount() {
        std::cout << "Savings destructor called" << std::endl;
    }
    std::string getAccountType() const override{
        return "Savings Account";
    }

    void applyInterest(){
        setBalance(getBalance() + getBalance() * interestRate);
    }
};

void printBalance(const BankAccount& b){
    std::cout << "Account balance: " << b.balance << std::endl;
}

int main(){
    {
        SavingsAccount s = SavingsAccount(50, 0.2);
        printBalance(s);
        s.applyInterest();
        printBalance(s);
    }

    return 0;
}