
class SegmentTree():

    def __init__(self, array):
        n = len(array) - 1

        n |= n >> 1
        n |= n >> 2
        n |= n >> 4
        n |= n >> 8
        n |= n >> 16

        n += 1

        self.arr_len = n

        tree = [set() for _ in range(4 * array)]
        # build binary tree
        for i in range(n-2, -1, -1):
            for tup in range(i*2 + 1, i*2 + 3):
                tree[i].add(tup)

        self.tree = tree

    def get_sum(self, l, r):
        # get leaf with value 'l'
        l += self.arr_len - 1
        # get leaf with value 'r'
        r += self.arr_len - 2
        letters = set()
        sum = 0

        while (l <= r):

            if ((l % 2) == 0):
                # it means l is a right child
                sum += len(self.tree[l])

                # move l to right by 1, so it becomes a left child and find its parent
                l = (l + 1 - 1) // 2
            else:
                # when l is a left child, when just find its parent
                l = (l - 1) // 2

            if ((r % 2) == 1):
                # it means r is a left chid
                sum += len(self.tree[r])

                # move r to left by 1, so it becomes a right child and find its parent
                r = (r - 1 - 2) // 2
            else:
                # when r is a right child
                r = (r - 2) // 2

        return sum

    def update(self, i, value):

        node = self.arr_len - 1 + i


        self.tree[node] = set(value)

        while node > 0:
            # find parent node
            node = (node - 1) // 2

            left_child = node * 2 + 1
            right_child = node * 2 + 2

            self.tree[node] = self.tree[left_child].union(self.tree[right_child])


if __name__ == "__main__":

    val = "dfcbbcfeeedbaea"
    array = [set() for _ in len(val)]
    for i, v in enumerate(array):
        v.add(val[i])

    seg = SegmentTree(array)

    print(len(seg.tree), seg.tree)
    

    print(seg.get_sum(2, 6))
    # 24

    seg.update(5, 11)

    print(seg.tree)
    

    print(seg.get_sum(2, 6))
    # 31

