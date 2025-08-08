/* 
LeetCode: 901. Online Stock Span  
Link: https://leetcode.com/problems/online-stock-span/

Problem:  
Design an algorithm that collects daily stock prices and returns the **span** of that stock’s price for the current day.  
The span is the number of consecutive days (including today) the price has been **less than or equal to** today’s price.

## Brute Force Approach:
- For each `price`, scan backward to count how many previous prices were ≤ current.
- Time Complexity: O(n²)
- Space Complexity: O(n)

## Optimal Approach: Monotonic Stack
- Use a stack to maintain pairs of `{price, index}`.
- For each new price:
    - Pop all smaller or equal prices from the stack.
    - The span is the difference between current index and top of stack (previous greater).
    - Push current `{price, index}` onto the stack.

### Key Insight:
- The stack keeps previous prices in decreasing order.
- Time Complexity: O(n) overall (amortized, since each element is pushed and popped at most once)
- Space Complexity: O(n)
*/

#include <stack>
using namespace std;

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int index;

    StockSpanner() {
        index = -1; 
    }

    int next(int price) {
        index += 1;

        // Remove all prices from the stack that are less than or equal to current price
        while(!st.empty() && st.top().first <= price){
            st.pop();
        }

        // If stack is empty, span is entire range till now
        int span = index - (st.empty() ? -1 : st.top().second);

        st.push({price, index});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
