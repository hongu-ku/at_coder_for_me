# %%
# バブルソート O(n^2)
# 順番に隣り合う要素を比べて行って小さい要素の方が大きいときに入れ替える
from random import randint


def bubble_sort(arr):
    change = True
    while change:
        change = False
        for i in range(len(arr) - 1):
            if arr[i] > arr[i+1]:
                arr[i], arr[i+1] = arr[i+1], arr[i]
                change = True
    return arr

# マージソート
# 分割して結合するときに並び替える
# 速い。安定。メモリめっちゃ食う.


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left = arr[:mid]
    right = arr[mid:]

    left = merge_sort(left)
    right = merge_sort(right)

    return list(merge(left, right))


def merge(left, right):
    sorted_list = []
    left_index = 0
    right_index = 0

    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            sorted_list.append(left[left_index])
            left_index += 1
        else:
            sorted_list.append(right[right_index])
            right_index += 1

    if left:
        sorted_list.extend(left[left_index:])
    if right:
        sorted_list.extend(right[right_index:])

    return sorted_list

# ヒープソート
# ヒープを構築して、一番上のノードと一番下のノードを入れ替え、1-(N-1)でノードを再構築する


def heapsort(aList):
    list_size = len(aList) - 1
    for i in range(list_size // 2, -1, -1):
        shift_down(aList, i, list_size)

    for i in range(list_size, 0, -1):
        if aList[0] > aList[i]:
            temp = aList[0]
            aList[0] = aList[i]
            aList[i] = temp
            shift_down(aList, 0, i - 1)
    return aList
# end def heapsort


def shift_down(aList, root, bottom):
    left = root * 2 + 1
    right = root * 2 + 2

    if left <= bottom and aList[left] > aList[root]:
        max_child = left
    else:
        max_child = root

    if right <= bottom and aList[right] > aList[max_child]:
        max_child = right

    if max_child != root:
        aList[root], aList[max_child] = aList[max_child], aList[root]
        shift_down(aList, max_child, bottom)
# end def sift_down


# %%
l = [randint(0, 999) for i in range(7)]
print('Unsorted')
print(l)

print('Sorted')
print(heapsort(l))

# %%
