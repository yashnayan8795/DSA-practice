class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        if (isValidTriangle(a, b, c)) {
            if (a == b && b == c) {
                return "equilateral";
            } else if (a == b || b == c || a == c) {
                return "isosceles";
            } else {
                return "scalene";
            }
        } else {
            return "none";
        }
    }

    bool isValidTriangle(int side1, int side2, int side3) {
    if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1) {
        return true;
    } else {
        return false;
    }
}
};