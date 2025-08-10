class Solution {
public:
    bool reorderedPowerOf2(int N) {
        array<int, 10> countN = count(N);

        int num = 1;

        for (int i = 0; i < 31; i++) {
            if (countN == count(num)) {
                return true;
            }
            num = num << 1;
        }

        return false;
    }

    array<int, 10> count(int N) {
        array<int, 10> arr = {0};

        while (N > 0) {
            arr[N % 10]++;
            N /= 10;
        }

        return arr;
    }
};