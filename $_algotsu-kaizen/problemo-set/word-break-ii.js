/**
 * 140. Word Break II
 * https://leetcode.com/problems/word-break-ii/description/
 */

var wordBreak = function (s, wordDict) {
    let output = []

    if (wordDict.includes(s)) {
        output.push(s)
    }

    for (let i = 0; i < s.length; ++i) {
        let subs = s.substring(0, i)

        if (wordDict.includes(subs)) {
            let words = wordBreak(s.substring(i), wordDict)

            if (words.length == 1) {
                output.push([subs, ...words].join(' '))
            } else if (words.length > 1) {
                words.forEach((word) => { output.push([subs, word].join(' ')) })
            }
        }
    }

    return output
};

export { wordBreak };

console.log(wordBreak("catsanddog", ["cat", "cats", "and", "sand", "dog"]))
console.log(wordBreak(
    "pineapplepenapple",
    ["apple", "pen", "applepen", "pine", "pineapple"]
))
