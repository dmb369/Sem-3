#Decimal To Binary Conversion

# Function to convert Decimal To Binary Number System
def dec_to_binary(n):

    bin_num = None

    # Complete this function to return binary equivalent output of the given number 'n' in 8-bit format

    if (n==0):
        return '00000000'

    else:
        bin_num = dec_to_binary(n // 2)  
        rem = n % 2
        return bin_num + str(rem) 


# Main function
if __name__ == '__main__':
    
    # take the T (test_cases) input
    test_cases = int(input())

    # Write the code here to take the n value
    for case in range(1,test_cases+1):
        # take the n input values
        n = int(input())
        

        # Once you have the n value, call the dec_to_binary function to find the binary equivalent of 'n' in 8-bit format
        bin_num = str(int(dec_to_binary(n))).zfill(8)
        print(bin_num)
    
