class KthLargest {
    priority_queue<int, vector<int>, greater<int>> heap;
    int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        for (auto e : nums)
        {
            heap.push(e);
            if (heap.size() > k)
            {
                heap.pop();
            }
        }
        _k = k;
    }

    int add(int val) {
        heap.push(val);
        if (heap.size() > _k) heap.pop();
        return heap.top();
    }
};