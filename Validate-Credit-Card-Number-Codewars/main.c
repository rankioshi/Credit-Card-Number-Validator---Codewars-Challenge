#include <stdio.h>

// Function to check if a credit card number is valid using the Luhn Algorithm
int isCreditCardValid(long long int creditCardNumber) {
    int sum = 0;
    int doubleDigit = 0;
    int digit;

    while (creditCardNumber > 0) {
        digit = creditCardNumber % 10;

        
        if (doubleDigit) {
            digit *= 2;

            
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;

        
        doubleDigit = !doubleDigit;

        creditCardNumber /= 10;
    }

    
    return (sum % 10 == 0);
}

int main() {
    long long int cardNumber;

    
    printf("Enter the credit card number: ");
    scanf("%lld", &cardNumber);

    
    if (isCreditCardValid(cardNumber)) {
        printf("The credit card number %lld is valid.\n", cardNumber);
    } else {
        printf("The credit card number %lld is not valid.\n", cardNumber);
    }

    return 0;
}
