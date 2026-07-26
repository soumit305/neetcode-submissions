class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l1 = s1.size();
        int l2 = s2.size();

        if (l1>l2) return false;

        vector<int> freq1(26,0);
        vector<int> freq2(26,0);

        for (int i = 0; i < l1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (freq1[i] == freq2[i]) matches++;
        }

       if (matches == 26) return true;

        // Slide the window across s2
        int l = 0;
        for (int r = l1; r < l2; r++) {
            // 1. Add the incoming character on the right
            int r_idx = s2[r] - 'a';
            freq2[r_idx]++;
            if (freq2[r_idx] == freq1[r_idx]) {
                matches++;
            } else if (freq2[r_idx] == freq1[r_idx] + 1) {
                matches--; // It was matching before, but now we overshot
            }

            // 2. Remove the outgoing character on the left
            int l_idx = s2[l] - 'a';
            freq2[l_idx]--;
            if (freq2[l_idx] == freq1[l_idx]) {
                matches++;
            } else if (freq2[l_idx] == freq1[l_idx] - 1) {
                matches--; // It was matching before, but now we fell short
            }
            l++;

            // 3. Check if all 26 frequencies match
            if (matches == 26) return true;
        }

        return false;
    }
};
