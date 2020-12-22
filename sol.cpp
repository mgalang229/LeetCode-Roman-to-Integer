class Solution {
public:
    int romanToInt(string s) {
        //create pairs of characters (roman numerals) to corresponding value
        pair<char, int> p[7] = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        //create 'prev' variable to save previous number
        int d = 0;
        int prev = -1;
        /* there are three conditions for each loop:
         * first condition, check if 'prev' variable is reset.
         * second condition, check if 'prev' variable has a value and check if
         * the current value is less or equal than the previous value, if true, then 
         * add the corresponding value and save it in the 'prev' variable.
         * third condition: if the current value is greater than the previous,
         * then, subtract the previous value from 'd' and get the sum of 'd',
         * and the difference of the current value from the previous value.
         * Lastly, reset 'prev' to negative one.
         * */
        for (int i = 0; i < (int) s.size(); i++) {
            for (int j = 0; j < 7; j++) {
                if (s[i] == p[j].first && prev == -1) {
                    d += p[j].second;
                    prev = p[j].second;
                } else if (s[i] == p[j].first && p[j].second <= prev) {
                    d += p[j].second;
                    prev = p[j].second;
                } else if (s[i] == p[j].first && p[j].second > prev) {
                    d -= prev;
                    d += (p[j].second - prev);
                    prev = -1;
                }
            }
        }
        return d;
    }
};
