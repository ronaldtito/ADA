def partition(nums, low, high):  
    pivot = nums[(low + high) // 2]
    i = low - 1
    j = high + 1
    while True:
        i += 1
        while nums[i] < pivot:
            i += 1
        j -= 1
        while nums[j] > pivot:
            j -= 1
        if i >= j:
            return j
        nums[i], nums[j] = nums[j], nums[i]

def quickselect(nums, k):
    low, high = 0, len(nums) - 1
    while True:
        pivot_index = partition(nums, low, high)
        if pivot_index < k:
            low = pivot_index + 1
        elif pivot_index > k:
            high = pivot_index - 1
        else:
            return nums[pivot_index]

def find_median(nums):
    if len(nums) % 2 == 1:
        return quickselect(nums, len(nums) // 2)
    else:
        return 0.5 * (quickselect(nums, len(nums) // 2 - 1) + quickselect(nums, len(nums) // 2))
