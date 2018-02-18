#include<stdio.h>
#include<stdbool.h>

long power(int n)
{
  long result = 1;

  if(n != 0) 
  {
    do
    {
      result *= 10;
    } while(--n > 0);
  }

  return result;
}

// works for maximum of two digits
int sum_of_digits(int n)
{
  return n / 10 + n % 10;
}

bool is_valid(long long card_number)
{
  bool valid = true;
  // sum of every other digit
  int sum = 0;
  for(int i = 0; i < 16; i++)
  {
    int digit = card_number / power(i) % 10;    
    if((i + 1) % 2 == 1) sum += digit;
     else sum += sum_of_digits(digit * 2);   
  }
  
  valid = sum % 10 == 0;
  return valid;
}

bool checkCardsDigitsWith(long long card_number, int digits, int shouldBe)
{
  return card_number / power(digits) == shouldBe;
}

char* getCardCompany(long long card_number)
{
  // check if American Express card
  if(checkCardsDigitsWith(card_number, 13, 37) || checkCardsDigitsWith(card_number, 13, 34)) return "AMEX";
  // check if Master Card
  else if(checkCardsDigitsWith(card_number, 14, 51) || checkCardsDigitsWith(card_number, 14, 52) || checkCardsDigitsWith(card_number, 14, 53) || checkCardsDigitsWith(card_number, 14, 54) ||
  	checkCardsDigitsWith(card_number, 14, 55)) return "MASTERCARD";
  else if(checkCardsDigitsWith(card_number, 12, 4) || checkCardsDigitsWith(card_number, 15, 4)) return "VISA";
  else return "INVALID";
}

int main()
{
  long long card_number;

  scanf("%lld", &card_number);
  
  if(is_valid(card_number))
    printf("%s\n", getCardCompany(card_number));
  else
    printf("INVALID\n");
}
