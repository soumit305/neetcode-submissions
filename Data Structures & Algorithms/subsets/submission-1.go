func subsets(nums []int) [][]int {
	var ans [][]int
	var curr []int
	generateSubsets(0, &curr, nums, &ans)
	return ans
}

func generateSubsets(idx int, curr *[]int, nums []int, ans *[][]int) {
	if idx == len(nums) {
		tmp := make([]int, len(*curr))
		copy(tmp, *curr)
		*ans = append(*ans, tmp)
		return
	}
	*curr = append(*curr, nums[idx])
	generateSubsets(idx+1, curr, nums, ans)
	*curr = (*curr)[:len(*curr)-1]
	generateSubsets(idx+1, curr, nums, ans)
}
