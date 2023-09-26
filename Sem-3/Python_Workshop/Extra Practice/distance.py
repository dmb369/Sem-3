#Calculate the distance
 
# Import any required module/s
import math


# Function to calculate Euclidean distance between two points
def compute_distance(a, b, c, d):
    e=c-a
    f=d-b
    g=e**2
    h=f**2
    distance=math.sqrt(g+h)
    k=round(distance,2)
    print(f"Distance: {k:.2f}")

# Main function
if __name__ == '__main__':
    
    # Take the T (test_cases) input
    test_cases = int(input())

    # Write the code here to take the x1, y1, x2 and y2 values
    for i in (0, test_cases):
        x1, y1, x2, y2=map(int,input().split())
        # Once you have all 4 values, call the compute_distance function to find Euclidean distance
        compute_distance(x1, y1, x2, y2)

