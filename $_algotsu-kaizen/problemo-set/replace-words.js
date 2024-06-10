/**
 * 648. Replace Words
 * https://leetcode.com/problems/replace-words/description
 */

class Trie {

    constructor() {
        this.links = new Array(26)
        this.data = null
    }

    insert(key, data) {
        let node = this

        for (const char of key) {
            const idx = char.charCodeAt(0) - 97
            if (!node.links[idx]) node.links[idx] = new Trie()
            node = node.links[idx]
        }

        node.data = data;
    }

    seek(key, options = {}) {
        let node = this
        const { firstWhere } = options || {}

        for (const char of key) {
            const idx = char.charCodeAt(0) - 97

            if (!node.links[idx]) {
                return null
            }

            node = node.links[idx]

            if (Boolean(firstWhere) && firstWhere?.(node)) {
                return node
            }
        }

        return node
    }

    search(key, options = {}) {
        let node = this.seek(key, options)
        return node?.data
    }
}

/**
 * @param {string[]} dictionary
 * @param {string} sentence
 * @return {string}
 */
const replaceWords = function (dictionary, sentence) {
    const trie = new Trie();

    for (let i = 0; i < dictionary.length; ++i) trie.insert(dictionary[i], i)

    let processedSentence = sentence
        .split(' ')
        .map(word => {
            const idx = trie.search(word, {
                firstWhere: (node) => {
                    return node.data !== null
                }
            })
            return idx != null ? dictionary[idx] : word
        })
        .join(' ');

    return processedSentence
}

const replaceWords_DUMB = function (dictionary, sentence) {
    let currentWord = ''
    let skipFlag = false
    let wordMap = new Map()
    let wordSet = new Set(dictionary)
    dictionary.forEach((e) => { wordMap.set(e, e.length) })

    let processedSentence = ''

    for (let i = 0; i < sentence.length; ++i) {
        let char = sentence.charAt(i)

        if (char == ' ') {
            skipFlag = false
            currentWord = currentWord = ''
        } else if (!skipFlag) {
            currentWord = currentWord.concat(char)
        }

        if (skipFlag) continue

        if (wordSet.has(currentWord)) skipFlag = true
        processedSentence = processedSentence.concat(char)
    }

    return processedSentence
}

export { replaceWords }

const trie = new Trie()

// let list = ['ab', 'abc']
// for (let i = 0; i < list.length; ++i) {
//     trie.insert(list[i], 11)
// }

// console.log(trie);
// for (let i = 0; i < list.length; ++i) {
//     console.log('$#-search', trie.search(list[i], {
//         firstWhere: (node) => {
//             console.log('000', node.data);
//             return Boolean(node.data)
//         }
//     }));
// }

console.log("$#", replaceWords(["ab"], "ab abc"))

// console.log("$#", replaceWords(["cat", "bat", "rat"], "the cattle was rattled by the battery"));
// console.log("$#", "the cat was rat by the bat");

// console.log("$#", replaceWords(["a", "b", "c"], "aadsfasf absbs bbab cadsfafs"));
// console.log("$#", "a a b c");
