func twoSum(nums []int, target int) []int {
    mpp := make(map[int]int)
	for idx := 0; idx < len(nums); idx++ {
		val, exists := mpp[target - nums[idx]]
		if exists {
			return []int{val,idx}
		}
		mpp[nums[idx]] = idx
	}
	return []int{-1,-1}
}
