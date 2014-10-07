class Solution:
    # @return a tuple, (index1, index2)
    def twoSum(self, num, target):
        #建立索引值映射
        indexMap = {}
        for i, number in enumerate(num):
            if number not in indexMap:
                indexMap[number] = []
            indexMap[number].append(i)

        #排序
        sortnum = sorted(num)

        beg = 0
        end = len(num) - 1
        while beg < end:
            s = sortnum[beg] + sortnum[end]
            if s == target:
                i1 = 0
                i2 = 0

                i1 = indexMap[sortnum[beg]][0] + 1
                if sortnum[beg] == sortnum[end]:
                    i2 = indexMap[sortnum[end]][1] + 1
                else:
                    i2 = indexMap[sortnum[end]][0] + 1

                if i1 < i2:
                    return (i1, i2)
                else:
                    return (i2, i1)
            elif s < target:
                beg += 1
            else:
                end -= 1

        return ()
