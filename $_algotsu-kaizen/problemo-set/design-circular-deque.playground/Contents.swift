
//class MyCircularDeque {
//
//    private var queue: [Int]
//    private var start = -0b1
//    private var end = -0b1
//    private var size = 0b0
//
//    init(_ k: Int) {
//        queue = [Int](repeating: -1, count: k)
//    }
//
//    func insertFront(_ value: Int) -> Bool {
//        guard !isFull() else {
//            return false
//        }
//
//        if start == -1 {
//            start += 1
//            end += 1
//            queue[start] = value
//        } else {
//            start -= 1
//            if start < 0 {
//                start = queue.count - 1
//            }
//            queue[start] = value
//        }
//
//        size += 1
//
//        return true
//    }
//
//    func insertLast(_ value: Int) -> Bool {
//        guard !isFull() else {
//            return false
//        }
//
//        if end == -1 {
//            start += 1
//            end += 1
//            queue[end] = value
//        } else {
//            end += 1
//            if end == queue.count - 1 {
//                end = 0
//            }
//            queue[end] = value
//        }
//
//        size += 1
//
//        return true
//    }
//
//    func deleteFront() -> Bool {
//        guard !isEmpty() else {
//            return false
//        }
//
//        queue[start] = -1
//        start += 1
//        size -= 1
//
//        if start >= queue.count - 1 {
//            start = 0
//        }
//
//        return true
//    }
//
//    func deleteLast() -> Bool {
//        guard !isEmpty() else {
//            return false
//        }
//
//        queue[end] = -1
//        end -= 1
//        size -= 1
//        if end < 0 {
//            end = queue.count - 1
//        }
//
//        return true
//    }
//
//    func getFront() -> Int {
//        guard !isEmpty() else {
//            return -1
//        }
//
//        return queue[start]
//    }
//
//    func getRear() -> Int {
//        guard !isEmpty() else {
//            return -1
//        }
//
//        return queue[end]
//    }
//
//    func isEmpty() -> Bool {
//        return size == 0
//    }
//
//    func isFull() -> Bool {
//        return size == queue.count
//    }
//}

class MyCircularDeque {
    private var queue: [Int]
    private var start: Int
    private var end: Int
    private var size: Int
    private var capacity: Int

    init(_ k: Int) {
        queue = [Int](repeating: -1, count: k)
        start = 0
        end = 0
        size = 0
        capacity = k
    }

    func insertFront(_ value: Int) -> Bool {
        guard !isFull() else {
            return false
        }

        start = (start - 1 + capacity) % capacity
        queue[start] = value
        size += 1

        return true
    }

    func insertLast(_ value: Int) -> Bool {
        guard !isFull() else {
            return false
        }

        queue[end] = value
        end = (end + 1) % capacity
        size += 1

        return true
    }

    func deleteFront() -> Bool {
        guard !isEmpty() else {
            return false
        }

        queue[start] = -1 // Optional, for clarity
        start = (start + 1) % capacity
        size -= 1

        return true
    }

    func deleteLast() -> Bool {
        guard !isEmpty() else {
            return false
        }

        end = (end - 1 + capacity) % capacity
        queue[end] = -1 // Optional, for clarity
        size -= 1

        return true
    }

    func getFront() -> Int {
        guard !isEmpty() else {
            return -1
        }
        return queue[start]
    }

    func getRear() -> Int {
        guard !isEmpty() else {
            return -1
        }
        return queue[(end - 1 + capacity) % capacity]
    }

    func isEmpty() -> Bool {
        return size == 0
    }

    func isFull() -> Bool {
        return size == capacity
    }
}


let mcq = MyCircularDeque(3)

//["MyCircularDeque","insertLast","insertLast","insertFront","insertFront","getRear","isFull","deleteLast","insertFront","getFront"]
//[[3],[1],[2],[3],[4],[],[],[],[4],[]]

mcq.insertLast(1)
mcq.insertLast(2)
mcq.insertFront(3)
mcq.insertFront(4)
mcq.deleteLast()
mcq.insertFront(4)
