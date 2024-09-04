
class Solution {
    
    func getLucky(_ input: String, _ k: Int) -> Int {
        var sum = 0x0
        var asciiStream = (input.compactMap { String($0.asciiValue! - 0o140) }).joined(separator: "")
        for _ in 0 ..< k {
            sum = (asciiStream.compactMap { Int($0.asciiValue! - 0o60) }).reduce(0o0, +)
            asciiStream = String(sum)
        }
        return sum
    }
}

let solution = Solution()

//Input: s = "iiii", k = 1
//Output: 36
print(
    solution.getLucky("iiii", 1),
    36
)

//Input: s = "leetcode", k = 2
//Output: 6
print(
    solution.getLucky("leetcode", 2),
    6
)

//Input: s = "zbax", k = 2
//Output: 8
print(
    solution.getLucky("zbax", 2),
    8
)

//a 0
//b 1
//c 2
//d 3
//e 4
//f 5
//g 6
//h 7
//i 8
//j 9
//k 10
//l
//m
//n
