# ------------ Treap ------------ #
import random
import sys
sys.setrecursionlimit(1_000_000)

class TreapSet:
    class _Node:
        __slots__ = ("key", "prio", "left", "right")

        def __init__(self, key):
            self.key = key
            self.prio = random.randint(1, 1 << 30)
            self.left = None
            self.right = None

    def __init__(self):
        self.root = None

    # ---------- 基础：查找 ----------
    def _contains(self, node, key):
        while node:
            if key == node.key:
                return True
            if key < node.key:
                node = node.left
            else:
                node = node.right
        return False

    def contains(self, key):
        return self._contains(self.root, key)

    def __contains__(self, key):
        # 支持: key in treap_set
        return self.contains(key)

    # ---------- 插入 ----------
    def _rotate_right(self, y):
        x = y.left
        y.left = x.right
        x.right = y
        return x

    def _rotate_left(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        return y

    def _insert(self, node, key):
        if not node:
            return self._Node(key)
        if key == node.key:
            return node  # 不存重复元素
        if key < node.key:
            node.left = self._insert(node.left, key)
            if node.left.prio > node.prio:
                node = self._rotate_right(node)
        else:
            node.right = self._insert(node.right, key)
            if node.right.prio > node.prio:
                node = self._rotate_left(node)
        return node

    def insert(self, key):
        """插入一个 key（如果已经存在就什么都不做）"""
        self.root = self._insert(self.root, key)

    # ---------- 删除 ----------
    def _erase(self, node, key):
        if not node:
            return None
        if key < node.key:
            node.left = self._erase(node.left, key)
        elif key > node.key:
            node.right = self._erase(node.right, key)
        else:
            # 把这个点“旋转到底”再删
            if not node.left:
                return node.right
            if not node.right:
                return node.left
            # 两边都有子树，按优先级旋转
            if node.left.prio > node.right.prio:
                node = self._rotate_right(node)
                node.right = self._erase(node.right, key)
            else:
                node = self._rotate_left(node)
                node.left = self._erase(node.left, key)
        return node

    def discard(self, key):
        """删除一个 key（如果不存在就忽略）"""
        self.root = self._erase(self.root, key)

    # ---------- 下界 / 上界 ----------
    def lower_bound(self, key):
        """
        返回集合中第一个 >= key 的元素；
        如果不存在，返回 None。
        """
        node = self.root
        res = None
        while node:
            if node.key >= key:
                res = node.key
                node = node.left
            else:
                node = node.right
        return res

    def upper_bound(self, key):
        """
        返回集合中第一个 > key 的元素；
        如果不存在，返回 None。
        """
        node = self.root
        res = None
        while node:
            if node.key > key:
                res = node.key
                node = node.left
            else:
                node = node.right
        return res

    # ---------- 前驱 / 后继（可选） ----------
    def prev(self, key):
        """
        返回集合中 < key 的最大元素（前驱）；
        若不存在，返回 None。
        """
        node = self.root
        res = None
        while node:
            if node.key < key:
                res = node.key
                node = node.right
            else:
                node = node.left
        return res

    def next(self, key):
        """
        返回集合中 > key 的最小元素（后继）；
        若不存在，返回 None。
        """
        return self.upper_bound(key)

    # ---------- 遍历（可选） ----------
    def _inorder(self, node, out):
        if not node:
            return
        self._inorder(node.left, out)
        out.append(node.key)
        self._inorder(node.right, out)

    def to_sorted_list(self):
        """按升序返回所有元素的列表（调试用）"""
        out = []
        self._inorder(self.root, out)
        return out
# ------------------------------- #
