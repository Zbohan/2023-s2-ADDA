#include "EfficientTruckloads.h"

int EfficientTruckloads::numTrucks(int numCrates, int loadSize) {
    if(numCrates <= loadSize) {
        return 1;
    }
    if(memo.find(numCrates) != memo.end()) {
        return memo[numCrates];
    }

    int left = numCrates / 2;
    int right = numCrates - left;
    int result = numTrucks(left, loadSize) + numTrucks(right, loadSize);
    memo[numCrates] = result;
    return result;
}
