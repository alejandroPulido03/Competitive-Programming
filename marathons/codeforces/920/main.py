t = int(input())
for _ in range(t):
    nums = []
    for _ in range(4):
        nums.append([])
        a, b = map(int, input().split())
        nums[-1].append(a)
        nums[-1].append(b)
    if (nums[0][0] != nums[1][0]):
        print(pow(abs(nums[0][0] - nums[1][0]), 2))
    else:
        print(pow(abs(nums[0][1] - nums[1][1]), 2))
