''' Problem statement:
 * Given an unsorted array X[] consisting of n integers, write a program
 * to find the length of the longest consecutive sequence of integers in the array.
 * The consecutive numbers can be in any order.
 * Input: X[] = [40, 4, 50, 1, 2, 13, 9, 3, 29], Output: 4
 * Explanation: The longest consecutive sequence is 1,2,3 and 4.
 * UPDATE: change the ouput instead of returning the length, also return the list.
'''
def linearsearch(x, item):
	for i in range(len(x)):
		#print("{0} - {1}".format(i, x[i]))
		if x[i] == item:
			return 1
	return 0

def find_long_seq(x):
	longest_seq = 0
	longest_seq_list = []	
	longest_seq_list_tmp = []
	for i in range(len(x)):
		#print("{0} - {1}".format(i, x[i]))
		cur_item = x[i]
		longest_seq_list_tmp = []
		longest_seq_list_tmp.append(cur_item)
		cur_len = 1
		while(linearsearch(x, cur_item+1)):
			longest_seq_list_tmp.append(cur_item+1)
			cur_item += 1
			cur_len += 1
		if cur_len > longest_seq:
			longest_seq = cur_len
			longest_seq_list = longest_seq_list_tmp
	#return longest_seq
	return longest_seq_list

def main():
	x = [40, 4, 50, 1, 2, 13, 9, 3, 29]
	print("Original list =", x)
	res = find_long_seq(x)
	print("Longest sequence list: {0}, length: {1}".format(res, len(res)))
	

if __name__ == '__main__':
	main()
