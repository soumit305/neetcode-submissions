func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	var ans [][]int
	var curr []int
	generateCombinationSum(0,0,&curr,&ans,candidates,target)
	return ans
}

func generateCombinationSum(idx int, sum int, curr *[]int, ans *[][]int, candidates []int, target int){
	if sum == target {
		tmp := make([]int, len(*curr))
		copy(tmp, *curr)
		*ans = append(*ans,tmp)
		return
	}
	if idx == len(candidates) || sum > target {
		return
	}

	*curr = append(*curr,candidates[idx])
	generateCombinationSum(idx+1,sum + candidates[idx],curr,ans,candidates,target)
	*curr = (*curr)[:len(*curr)-1]

	for idx+1 < len(candidates) && candidates[idx] == candidates[idx+1] {
		idx++
	}
	generateCombinationSum(idx+1,sum,curr,ans,candidates,target)
}