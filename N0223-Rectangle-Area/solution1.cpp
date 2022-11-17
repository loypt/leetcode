class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H){
        int x = min(G, C) > max(E, A) ? (min(G, C) - max(E, A)) : 0;
        int y = min(D, H) > max(B, F) ? (min(D, H) - max(B, F)) : 0;
        return (D - B) * (C - A) + (G - E) * (H - F) - x * y;
    }
};
