func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	var ans []string
	var curr string
	generateLetterCombinations(0,&curr,&ans,digits)
	return ans
}

func generateLetterCombinations(idx int, curr *string, ans *[]string, digits string){
	mpp := map[int]string{
    	2:     "abc",
    	3:     "def",
		4:     "ghi",
		5:     "jkl",
		6:     "mno",
		7:     "pqrs",
		8:     "tuv",
		9:     "wxyz",
	}
	if idx == len(digits) {
		temp := *curr
		*ans = append(*ans,temp)
		return 
	}
	str := mpp[int(digits[idx]-'0')]
	for _, char := range str {
		*curr += string(char)
		generateLetterCombinations(idx+1,curr,ans,digits)
		*curr = (*curr)[:len(*curr)-1]
	}
}