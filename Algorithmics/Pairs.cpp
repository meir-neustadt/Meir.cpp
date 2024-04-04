#include <iostream>
#include <vector>


std::pair<int, int> hasPairWithSum(const std::vector<int>& arr, int target) {
    int n = arr.size();
    // Not a pair
    if (n<2) return {-2, 0};
    
    // Binary search to find a potential candidate
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
                std::cout<<arr[mid]<<complementor<<std::endl;
                if (arr[mid] == complementor){
                    std::cout<<secondNumber<<std::endl;
                    return std::make_pair(mid, secondNumber);
                } else if (arr[mid] < complementor) {
                    left2 = mid + 1;
                    //std::cout<<right2<<mid<<std::endl;
                } else {
                    right2 = mid - 1;
                    //std::cout<<left2<<mid<<std::endl;
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
    // If no potential candidate is found, return false
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
