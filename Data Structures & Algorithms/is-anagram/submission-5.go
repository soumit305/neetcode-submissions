func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}
	var length = len(s)
	var hash [26]int
	for idx := 0; idx < length; idx++ {
		hash[s[idx]-'a']++
	}
	for idx := 0; idx < length; idx++ {
		if hash[t[idx]-'a'] == 0 {
			return false;
		}
		hash[t[idx]-'a']--
	}
	return true
}
