// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    // asks the input from the users
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    // prints the output by calling the function half() which is user defined
    printf("$%.2f \n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // the 100.0f indicates that it is a float value
    // converting tax from a percentage value to a cash (numerical) value and calling it tax_amt
    float tax_amt = bill * tax / 100.0f;

    // tip = tip + 0.0 converts tip from integer to a floating point value which is called typecasting
    // it can also be done by tip = tip * 1.0
    // converting tip from a percentage value to a cash (numerical) value and calling it tip_amt
    // here tip amount is calculated post-tax amount not pre-tax
    tip = tip + 0.0;
    float tip_amt = (bill + tax_amt) * tip / 100.0f;

    // half_amt stores the half of the total bill amount which each person should pay
    float half_amt = (bill + tax_amt + tip_amt) / 2.0f;

    // returning the amount owed by each person
    return half_amt;
}
