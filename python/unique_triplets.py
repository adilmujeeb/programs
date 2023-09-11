# Given an integer array nums, return all the UNIQUE triplets that sums zero
# Please note that the solution set must not contain duplicate triplets.
# e.g. Triplets [-1, -1, 2] and [2, -1, -1] are same because same elements 
# are being used within the list.

def sum_to_zero(nums):
    main_list=[]
    sub_list=[]
    duplicate_list=[]
    sub1_list=[]
    for i in range(0,len(nums)-2):
        #sum = nums[i]
        for j in range(i+1,len(nums)-1):
            for k in range(j+1,len(nums)):
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    sub_list.append(nums[i])
                    sub_list.append(nums[j])
                    sub_list.append(nums[k])
                    sub_list.sort()
                    if sub_list not in sub1_list:
                        sub1_list.append(sub_list)
                    sub_list = []
    return sub1_list
nums = [-1,0,1,2,-1,-4]
nums = [0,1,1]
nums = [-1,0,1,2,-1,-1,-1,-1,2,2,-4]
print(sum_to_zero(nums))
