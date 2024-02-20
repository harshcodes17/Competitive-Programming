/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.find(needle)==-1){
            return -1;
        }
        else{
            return haystack.find(needle);
        }
    }
};
// @lc code=end

