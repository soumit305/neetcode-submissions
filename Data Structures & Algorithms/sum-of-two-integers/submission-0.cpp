class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // 1. Calculate sum bits without carrying (XOR)
            int sumWithoutCarry = a ^ b;
            // 2. Calculate carry bits (AND), cast to unsigned to avoid negative shift overflow
            int carry = (unsigned int)(a & b) << 1;
            // 3. Update a and b for the next iteration
            a = sumWithoutCarry;
            b = carry;
        }
        return a;
    }
};
