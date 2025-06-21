class Solution {
public:
    int sumofsquares(int x)
    {
        int sum = 0;
        while (x)
        {
            int tmp = x % 10;
            sum += tmp * tmp;
            x /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow = sumofsquares(n);
        int fast = sumofsquares(slow);
        while (slow != fast)
        {
            slow = sumofsquares(slow);

            fast = sumofsquares(sumofsquares(fast));
        }
        return slow == 1;
    }
};

