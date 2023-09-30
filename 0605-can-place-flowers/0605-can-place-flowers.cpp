class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if(n==0) return true;

        for(int i=0;i<size;i++)
        {
            if(flowerbed[i]==0) {

                bool canPlant = (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0);
                if(canPlant) {
                    flowerbed[i] = 1; 
                    n--; 
                }
            }
            if (n == 0) return true;
        }

        return false;
    }

};