#include <iostream>
#include <vector>

/*The purpose of the function: given a list of numbers sorted in ascending order
when each number is greater than the sum of all the numbers preceding it,
Find if there is a pair of numbers that add up to a given number, and if so - return
the index of the two numbers.
The premise of the function: since each number multiplies the previous number
by more than 2, the pair must not be adjacent. The larger number must be 
between half and the whole of the given number. We will do a binary search
for the big number and then we will check if its complement to the given number
also exists in the list.*/

std::pair<int, int> hasPairWithSum(const std::vector<int>& arr, int target) {
    int n = arr.size();
    // Not a pair
    if (n<2) return {-2, 0};
    
    // Binary search to find the potential candidate
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] >= target / 2 && arr[mid] <= target) {
            int complementor = target - arr[mid];
            int secondNumber = mid;
            // Binary search to find a potential candidate
            int left2 = 0, right2 = mid - 1;
            while (left2 <= right2){
                mid = left2 + (right2 - left2) / 2;
                if (arr[mid] == complementor){
                    return std::make_pair(mid, secondNumber);
                } else if (arr[mid] < complementor) {
                    left2 = mid + 1;
                } else {
                    right2 = mid - 1;
                }
            } return {-1, 0};
        } else if (arr[mid] < target / 2) {
            // If the potential candidate is smaller, search in the right half
            left = mid + 1;
        } else {
            // If the potential candidate is greater, search in the left half
            right = mid - 1;
        }
    }
    // If no potential candidate is found, return -1
    return {-1, 0};
}

int main() {
    // Example array sorted in ascending order
    std::vector<int> arr = {1, 3, 9, 20, 40, 83, 153};
    int target = 84; // Example target sum
    auto pair = hasPairWithSum(arr, target);
    if (pair.first != -1) {
        std::cout << "Pair found with sum " << target << ": " << pair.first << ", " << pair.second << std::endl;
    } else {
        std::cout << "No pair found with sum " << target << std::endl;
    }
    return 0;
}
