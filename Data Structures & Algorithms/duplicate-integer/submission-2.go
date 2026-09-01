func hasDuplicate(nums []int) bool {
    freq := make(map[int]int)
    for i := 0; i < len(nums); i++ {
        _, exists := freq[nums[i]]
        if exists {
            return true
        }     
        freq[nums[i]] = 1;
    }
    return false;
}
