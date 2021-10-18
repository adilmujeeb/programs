''' Problem statement:
 * Given an unsorted array X[] consisting of n integers, write a program
 * to find the length of the longest consecutive sequence of integers in the array.
 * The consecutive numbers can be in any order.
 * Input: X[] = [40, 4, 50, 1, 2, 13, 9, 3, 29], Output: 4
 * Explanation: The longest consecutive sequence is 1,2,3 and 4.
'''
def linearsearch(x, item):
	for i in range(len(x)):
		#print("{0} - {1}".format(i, x[i]))
		if x[i] == item:
			return 1
	return 0

def find_long_seq(x):
	longest_seq = 0
	
	for i in range(len(x)):
		#print("{0} - {1}".format(i, x[i]))
		cur_item = x[i]
		cur_len = 1
		while(linearsearch(x, cur_item+1)):
			cur_item += 1
			cur_len += 1
		if cur_len > longest_seq:
			longest_seq = cur_len
	return longest_seq

def main():
	x = [40, 4, 50, 1, 2, 13, 9, 3, 29]
	print(x)
	print(find_long_seq(x))
	

if __name__ == '__main__':
	main()
