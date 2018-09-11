#include <iostream>
#include <iomanip>
#include <vector>

/*
 * Given a list of expenses for each student (in cents), return the minimum
 * amount of money (also in cents) that needs to change hands in order to 
 * equalize payments among the students.
 */
int get_exchange_amount (const std::vector<int>& expenses) 
{
    int i;
    int total_in_cents = 0; 
    int num_students = expenses.size();

    /* Calculate the total expenses in cents */
    for (i = 0; i < num_students; ++i)
        total_in_cents += expenses[i];

    int avg = total_in_cents / num_students;
    int rem = total_in_cents % num_students;
    int exchange_amount = 0;
    int j = rem; 
    int target;

    /* For each student whose expenses are higher than average, calculate
     * how much they will need to offload onto someone else in order to
     * arrive at an equalized amount */
    for (i = 0; i < num_students; ++i) {
        if (expenses[i] > avg) {
            target = j ? (avg + 1) : avg;
            exchange_amount += (expenses[i] - target);
            if (j) --j;
        }
    }

    return exchange_amount;
}

int main () 
{
    int i;
    int amount_in_cents;
    int num_students;
    float amount_in_dollars;
    
    std::vector<int> expenses; 
    std::vector<int> exchange_amounts;

    std::cin >> num_students;

    /* Keep calculating exchange amounts for trips until the number of students
     * given for a trip is 0 */
    while (num_students) {
        i = 0;
        
        /* Store the expenses for each student on the trip in the expenses vector */
        while (i++ < num_students) {
            std::cin >> amount_in_dollars;
            amount_in_cents = amount_in_dollars * 100;
            
            expenses.push_back(amount_in_cents);
        }

        exchange_amounts.push_back(get_exchange_amount(expenses));

        expenses.clear();
        std::cin >> num_students;
    }

    /* Print the amount of money that needs to change hands for each trip */
    std::cout << std::setprecision(2) << std::fixed;

    for (i = 0; i < exchange_amounts.size(); ++i) {
        amount_in_dollars = exchange_amounts[i] / 100.00;
        std::cout << "$" << amount_in_dollars << std::endl;
    }

    return 0;
}
