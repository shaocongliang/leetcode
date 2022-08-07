func findDuplicates(nums []int) []int {
	length := len(nums)
	for i := 0; i < length; i++ {
		nums[nums[i]%length] = nums[nums[i]%length] + length
	}

	var res []int
	for i := 0; i < length; i++ {
		if nums[i] > length*2 {
			if i == 0 {
				res = append(res, length)
			} else {
				res = append(res, i)
			}
		}
	}
	return res
}