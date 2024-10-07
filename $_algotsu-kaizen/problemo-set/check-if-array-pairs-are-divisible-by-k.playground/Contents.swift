
class Solution {

    func canArrange(_ arr: [Int], _ k: Int) -> Bool {
        guard k > 1 else {
            return true
        }

        let mods = arr.map { ((($0 % k) + k) % k, 0b1) }
        let freq = [Int: Int](mods, uniquingKeysWith: +)

        if let f = freq[0], f % 2 != 0 {
            return false
        }

        return (1...k/2).allSatisfy { freq[$0] == freq[k - $0] }
    }
}


let solution = Solution()


//Input: arr = [1,2,3,4,5,6], k = 7
//Output: true
print(
    solution.canArrange([1,2,3,4,5,6], 7),
    true
)

//Input: arr = [1,2,3,4,5,10,6,7,8,9], k = 5
//Output: true
print(
    solution.canArrange([1,2,3,4,5,10,6,7,8,9], 5),
    true
)


//Input: arr = [1,2,3,4,5,6], k = 10
//Output: false
print(
    solution.canArrange([1,2,3,4,5,6], 10),
    false
)
