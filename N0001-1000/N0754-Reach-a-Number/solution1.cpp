class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = (-1 + sqrt(1 + 8.0 * target)) / 2;
        int d = target - n * (n + 1) / 2;
        if (!d) return n;
        d -= ++n;
        return (d & 1 ? n + 1 + n % 2 : n);
    }   
};
