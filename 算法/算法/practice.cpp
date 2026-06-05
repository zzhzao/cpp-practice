class MedianFinder {
public:
    priority_queue<int> left; // ?¸ù¶Ñ 
    priority_queue<int, vector<int>, greater<int>> right; // ?¸ù¶Ñ 
    MedianFinder() {

    }

    void addNum(int num) {
        if (left.size() == right.size())
        {
            if (left.empty() || num < left.top())
            {
                left.push(num);
            }
            else
            {
                right.push(num);
                left.push(right.top());
                right.pop();
            }
        }
        else
        {
            if (num < left.top())
            {
                left.push(num);
                right.push(left.top());
                left.pop();
            }
            else
            {
                right.push(num);
            }
        }
    }

    double findMedian() {
        if (left.size() == right.size()) return (left.top() + right.top()) / 2.0;
        else return left.top();
    }
};
