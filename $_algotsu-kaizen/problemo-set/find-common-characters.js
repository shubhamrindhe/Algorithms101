/**
 * 1002. Find Common Characters
 * https://leetcode.com/problems/find-common-characters/description
 */

/**
 * @param {string[]} words
 * @return {string[]}
 */
var commonChars = function (words) {
    let commonCharList = []
    let chars_arr = words.map( (word) => { return word.split('') } )

    let first = chars_arr[0] || []

    for (let i = 0; i < first.length; ++i) {
        let char_ = first[i]
        let flag = true
        for (let j = 1; j < chars_arr.length; ++j) {
            if (chars_arr[j].includes(char_)) {
                let idx = chars_arr[j].indexOf(char_)
                chars_arr[j][idx] = null
                continue
            }  else {
                flag = false  
            } 
        }
        
        if (flag) commonCharList.push(char_)
    }

    return commonCharList
};

export { commonChars }

console.log("$#", commonChars(["bella", "label", "roller"]));
console.log("$#", commonChars(["cool", "lock", "cook"]));
