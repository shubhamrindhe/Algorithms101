/**
 * 1190. Reverse Substrings Between Each Pair of Parentheses
 * https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/description/
 */

/**
 * @param {string} s
 * @return {string}
 */
const stackception = (s) => {
    // # BEATS ~ 81.48%
    let stack_stack = []
    let currentStack = null
    let output_str = ''

    for (let char of s) {
        if (char == '(') {
            currentStack = []
            stack_stack.push(currentStack)
            continue
        } else if (char == ')') {
            let last_stack = stack_stack.pop()
            currentStack = stack_stack[stack_stack.length - 1]

            if (currentStack) {
                stack_stack[stack_stack.length - 1] = currentStack.concat(last_stack.reverse())
                currentStack = stack_stack[stack_stack.length - 1]
            } else {
                output_str += last_stack.reverse().join('')
            }

            continue
        }

        if (currentStack) {
            currentStack.push(char)
        } else {
            output_str += char
        }
    }

    return output_str
}

/**
 * @param {string} s
 * @return {string}
 */
const wormhole_traversal = (s) => {
    // # BEATS ~ 33.33%
    let output = []
    const portals = new Map()
    let stack = []

    for (let IDX = 0; IDX < s.length; ++IDX) {
        const char = s.charAt(IDX)
        if (char == '(') {
            stack.push(IDX)
        } else if (char == ')') {
            const XDI = stack.pop()
            portals.set(IDX, XDI)
            portals.set(XDI, IDX)
        }
    }

    let index = 0, direction = 1
    while (index < s.length) {
        const char = s.charAt(index)
        if (char == '(' || char == ')') {
            index = portals.get(index)
            direction = -direction
        } else {
            output.push(char)
        }
        index += direction
    }

    return output.join('')
}

/**
 * @param {string} s
 * @return {string}
 */
var reverseParentheses = function (s) {
    // # BEATS ~ 81.48%
    // return stackception(s)

    // # BEATS ~ 33.33%
    return wormhole_traversal(s)
};

export { reverseParentheses }

// Input: s = "(abcd)"
// Output: "dcba"
console.log("$#",
    reverseParentheses("(abcd)"),
    "dcba",
);

// Input: s = "(u(love)i)"
// Output: "iloveu"
console.log("$#",
    reverseParentheses("(u(love)i)"),
    "iloveu",
);

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
console.log("$#",
    reverseParentheses("(ed(et(oc))el)"),
    "leetcode",
);

// ++

// "vdgzyj()"
console.log("$#",
    reverseParentheses("vdgzyj()"),
    "vdgzyj",
);

// "a(bcdefghijkl(mno)p)q"
console.log("$#",
    reverseParentheses("a(bcdefghijkl(mno)p)q"),
    "a(bcdefghijkl(mno)p)q",
);

// "sxmdll(q)eki(x)"
console.log("$#",
    reverseParentheses("sxmdll(q)eki(x)"),
    "sxmdll(q)eki(x)",
);

// "yhqqvjhjchlahdn(())"
console.log("$#",
    reverseParentheses("yhqqvjhjchlahdn(())"),
    "yhqqvjhjchlahdn(())",
);

// "(ed(et(oc))el)"
console.log("$#",
    reverseParentheses("(ed(et(oc))el)"),
    "(ed(et(oc))el)",
);

// "(mno(pqr(stu)vwx)yz)"
console.log("$#",
    reverseParentheses("(mno(pqr(stu)vwx)yz)"),
    "(mno(pqr(stu)vwx)yz)",
);

// "(abc(def(ghi(jkl)mno)pqr)stu(vwx)yz)"
console.log("$#",
    reverseParentheses("(abc(def(ghi(jkl)mno)pqr)stu(vwx)yz)"),
    "(abc(def(ghi(jkl)mno)pqr)stu(vwx)yz)",
);
