/**
 * 726. Number of Atoms
 * https://leetcode.com/problems/number-of-atoms/description/
 */

/**
 * @param {string} formula
 * @return {string}
 */
var countOfAtoms = function (formula) {
    // # Runtime Beats ~ 89.74%
    // # Memory Beats ~ 97.44%
    let stack = [new Map()], element = '', count = '', paranthesisDepth = 0

    const addMaps = (...maps) => {
        const keys = maps.reduce((a, map) => { return a.concat([...map.keys()]) }, [])
        const keySet = new Set(keys)
        const map = new Map()
        for (const key of keySet) {
            map.set(key, maps.reduce((a, map) => {
                return a + (map.get(key) || 0)
            }, 0))
        }
        return map
    }

    const scaleMap = (map, factor) => {
        for (const key of map.keys()) map.set(key, map.get(key) * factor)
        return map
    }

    const squash = () => {
        const top = stack[stack.length - 1]
        const multiplier = Boolean(count) ? parseInt(count) : 1

        if (top == ')') {
            stack.pop()
            let frquencyMaps = []

            let popedValue = null
            do {
                popedValue = stack.pop()
                if (popedValue instanceof Map) frquencyMaps.push(popedValue)
            } while (popedValue != '(')

            if (multiplier > 1) {
                for (const frquencyMap of frquencyMaps)
                    scaleMap(frquencyMap, multiplier)
            }

            let mergedMap = addMaps(...frquencyMaps)
            stack.push(mergedMap)
        } else if (top instanceof Map && Boolean(element)) {
            let freq = top.get(element)
            if (Boolean(freq)) {
                top.set(element, freq + multiplier)
            } else {
                top.set(element, multiplier)
            }
        }
    }

    for (const char of formula) {
        if (char == '(') {
            const top = stack[stack.length - 1]
            squash()
            count = ''
            element = ''
            paranthesisDepth++
            stack.push(char)
            stack.push(new Map())
        } else if (char == ')') {
            squash()
            count = ''
            element = ''
            count = ''
            paranthesisDepth--
            stack.push(char)
        } else if (char >= '0' && char <= '9') {
            count += char
        } else if (char >= 'a' && char <= 'z') {
            element += char
        } else if (char >= 'A' && char <= 'Z') {
            squash()
            count = ''
            element = char
        } else {
            console.error("something is wrong", char);
        }
    }

    squash()
    let squashedMap = addMaps(...stack)

    return [...squashedMap.keys()].sort().reduce((_, element) => {
        let frquency = squashedMap.get(element)
        return _ + `${element}${(frquency > 1 ? frquency : '')}`
    }, '')
};

export { countOfAtoms }

// Input: formula = "H2O"
// Output: "H2O"
console.log("$#",
    countOfAtoms("H2O"),
    "H2O",
);

// Input: formula = "Mg(OH)2"
// Output: "H2MgO2"
console.log("$#",
    countOfAtoms("Mg(OH)2"),
    "H2MgO2",
);

// Input: formula = "K4(ON(SO3)2)2"
// Output: "K4N2O14S4"
console.log("$#",
    countOfAtoms("K4(ON(SO3)2)2"),
    "K4N2O14S4",
);


// formula =
// "H11He49NO35B7N46Li20"
// Use Testcase
// Output
// "B7H11He49Li20N46O35"
// Expected
// "B7H11He49Li20N47O35"

console.log("$#",
    countOfAtoms("H11He49NO35B7N46Li20"),
    "B7H11He49Li20N47O35",
);

// const addMaps = (...maps) => {
//     let keys = maps.reduce((a, v)=> { return a.concat([...v.keys()]) }, [])
//     let keySet = new Set(keys)

//     const map = new Map()

//     for (const key of keySet) {
//         map.set(
//             key,
//             maps.reduce((a, map)=> { return a + map.get(key) || 0 }, 0)
//         )
//     }

//     return map
// }

// console.log(addMaps(new Map([['a', 10], ['b', 69]]), new Map([['b', 10], ['a', 1]])))