#! /usr/bin/python

class Solution:
    def findLadders(self, start, end, dict):
        wordlen = len(start)

        self.result = []
        self.resultLen = 21922222222222222222
        self.path = []
        #letter dicts
        letters = [set() for i in range(0, wordlen)]
        for word in dict:
            for i, c in enumerate(word):
                letters[i].add(c)

        for i, c in enumerate(start):
            letters[i].add(c)

        for i, c in enumerate(end):
            letters[i].add(c)

        print letters

        word = [c for c in start]
        self.path.append(start)

        for i in range(0, wordlen):
            self.findladderHelper(letters, i, word, start, end, dict)

        print "##########################"
        print self.result

    def findladderHelper(self, letters, i, word, start, end, dict):
        wordlen = len(start)
        if "".join(word) == end:
            if 0 < len(word) < self.resultLen:
                self.result.append(self.path)
                self.resultLen = len(word)

        if len(letters) <= i:
            return

        oldc = word[i]
        for c in letters[i]:
            word[i] = c
            w = "".join(word)

            if w == end:
                print "##################"
                self.path.append(w)
                print self.path

                if 0 < len(w) < self.resultLen:
                    self.path.append(w)
                #    print self.path
                    self.result.append(self.path)
                    self.resultLen = len(w)
                    self.path.pop()
                    word[i] = oldc
                    return

            if w not in dict:
                word[i] = oldc
                continue

            if w in self.path:
                word[i] = oldc
                continue

            self.path.append("".join(word))
            for j in range(0, wordlen):
                self.findladderHelper(letters, j, word, start, end, dict)
            self.path.pop()
            word[i] = oldc


start = "hit"
end = "cog"
dict = ["hot", "dot", "dog", "lot", "log"]

s = Solution()
s.findLadders(start, end, dict)



