import Darwin
import CoreGraphics

class Solution {

    private enum Direction {
        case N
        case E
        case W
        case S

        var left: Direction {
            switch self {
            case .N:
                return .W
            case .E:
                return .N
            case .W:
                return .S
            case .S:
                return .E
            }
        }

        var right: Direction {
            switch self {
            case .N:
                return .E
            case .E:
                return .S
            case .W:
                return .N
            case .S:
                return .W
            }
        }

        var step: (Int, Int) {
            switch self {
            case .N:
                return (0, 1)
            case .E:
                return (1, 0)
            case .W:
                return (-1, 0)
            case .S:
                return (0, -1)
            }
        }
    }

    private static let turnLeft = -0b10
    private static let turnRight = -0b01

    func robotSim(_ commands: [Int], _ obstacles: [[Int]]) -> Int {
        let hashSet = obstacles.reduce(into: Set<String>()) { $0.insert("\($1.first!).\($1.last!)") }
        var position = (0, 0)
        var dir: Direction = .N
        var maxDistance = 0x0

        for command in commands {
            switch command {
            case Self.turnLeft:
                dir = dir.left
            case Self.turnRight:
                dir = dir.right
            default:
                for _ in 0 ..< command {
                    let step = dir.step
                    let next = (position.0 + step.0, position.1 + step.1)
                    if hashSet.contains("\(next.0).\(next.1)") {
                        break
                    }
                    position = next
                }
                maxDistance = max(maxDistance, position.0 * position.0 + position.1 * position.1)
            }
        }

        return maxDistance
    }
}

let solution = Solution()

// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]
// Output: 65
print(
    solution.robotSim([4,-1,4,-2,4], [[2,4]]),
    65
)

// Input: commands = [4,-1,3], obstacles = []
// Output: 25
print(
    solution.robotSim([4,-1,3], []),
    25
)

// Input: commands = [6,-1,-1,6], obstacles = []
// Output: 36
print(
    solution.robotSim([6,-1,-1,6], []),
    36
)
