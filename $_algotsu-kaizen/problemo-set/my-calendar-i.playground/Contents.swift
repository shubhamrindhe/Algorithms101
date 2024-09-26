private class Node {

    let start: Int
    let end: Int
    var left: Node?
    var right: Node?

    init(start: Int, end: Int) {
        self.start = start
        self.end = end
    }

    func insert(start: Int, end: Int) -> Bool {
        if start >= self.end {
            if let right {
                return right.insert(start: start, end: end)
            }

            right = Node(start: start, end: end)
            return true
        } else if end <= self.start {
            if let left {
                return left.insert(start: start, end: end)
            }

            left = Node(start: start, end: end)
            return true
        } else {
            return false
        }
    }
}

class MyCalendar {

    private var root: Node?

    init() {

    }

    func book(_ start: Int, _ end: Int) -> Bool {
        guard let root else {
            root = Node(start: start, end: end)
            return true
        }

        return root.insert(start: start, end: end)
    }
}
