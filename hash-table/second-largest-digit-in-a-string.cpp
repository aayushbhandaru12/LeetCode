class Solution {
public:
    int secondHighest(string s) {
        int largest = -1, second = -1;

        for (char c : s) {
            if (isdigit(c)) {
                int digit = c - '0';

                if (digit > largest) {
                    second = largest;
                    largest = digit;
                } 
                else if (digit < largest && digit > second) {
                    second = digit;
                }
            }
        }

        return second;
    }
};