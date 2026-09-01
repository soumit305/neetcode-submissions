func combinationSum(nums []int, target int) [][]int {
    var ans [][]int
	var curr []int
	generateCombinationSums(0,0,&curr,&ans,nums,target)
	return ans
}

func generateCombinationSums(idx int, sum int, curr *[]int, ans *[][]int, nums []int, target int){
	if idx == len(nums){
		if sum == target {
			tmp := make([]int, len(*curr))
			copy(tmp,*curr)
			*ans = append(*ans,tmp)
		}
		return
	}
	if sum + nums[idx] <= target {
		*curr = append(*curr, nums[idx])
		generateCombinationSums(idx,sum + nums[idx],curr,ans,nums,target)
		*curr = (*curr)[:len(*curr)-1]
	} 
	generateCombinationSums(idx+1,sum,curr,ans,nums,target)
}
