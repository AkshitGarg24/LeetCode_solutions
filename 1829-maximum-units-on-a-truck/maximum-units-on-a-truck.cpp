class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }

    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), cmp);

        int totalUnits = 0;
        int remainingTruckSize = truckSize;

        for (const auto& boxType : boxTypes) {
            int numberOfBoxes = boxType[0];
            int unitsPerBox = boxType[1];

            if (remainingTruckSize >= numberOfBoxes) {
                totalUnits += numberOfBoxes * unitsPerBox;
                remainingTruckSize -= numberOfBoxes;
            } else {
                totalUnits += remainingTruckSize * unitsPerBox;
                break;
            }
        }

        return totalUnits;
    }
};