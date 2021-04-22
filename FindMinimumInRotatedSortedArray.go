func findMin(nums []int) int {
    n := len(nums)
    // rotated
    if nums[0] > nums[n-1] {
        for i := 0; i < n-1; i++ {
            if nums[i] > nums[i+1] {
                return nums[i+1];
            }
        }
    }
    return nums[0];
}
