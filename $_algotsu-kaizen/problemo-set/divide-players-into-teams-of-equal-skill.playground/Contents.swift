
class Solution {

    func dividePlayers(_ skill: [Int]) -> Int {
        var result = 0
        let list = skill.sorted()
        var i = 0, j = list.count - 1
        let score = list.first! + list.last!

        while i < j {
            guard list[i] + list[j] == score else {
                return -1
            }

            result += list[i] * list[j]

            i += 1
            j -= 1
        }

        return result
    }
}

let solution = Solution()

//Input: skill = [3,2,5,1,3,4]
//Output: 22
print(
    solution.dividePlayers([3,2,5,1,3,4]),
    true
)

//Input: skill = [3,4]
//Output: 12
print(
    solution.dividePlayers([3,4]),
    true
)

//Input: skill = [1,1,2,3]
//Output: -1
print(
    solution.dividePlayers([1,1,2,3]),
    false
)
