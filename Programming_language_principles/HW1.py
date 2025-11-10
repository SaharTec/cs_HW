#task1
def print_next_date(date):

    d = int(date / 1000000)
    m = int(((date / 10000)- day * 100))
    y = int(date % 10000)
    print (d, m, y)

    def num_of_days_in_mounth(m):
        if(m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12):
            day_in_m = 31
        elif (m == 4 or m == 6 or m == 9 or m == 11):
            day_in_m = 30
        elif (m == 2):
            if(is_leap_year(y) == True ):
                day_in_m = 29
            else:
                day_in_m = 28    


    def is_leap_year (year):
        if((year % 4 == 0 and year % 100 != 0) or year & 400 == 0):
            return True


print(print_next_date(28102025))


def arange_digits(num):
    """bulding 2 string that represent odd and even numbers"""
    evenstr = ""
    oddStr= ""
    """casting the input number into string"""
    number = str(num)
    """go trow the number string and sort for even and odd number to the correct string"""
    for n in number:
        digit = int(n)
        if(digit % 2 == 0):
            evenstr += n
        else:
            oddStr += n
    """build a sorted string whene even numbers are first"""        
    new_num = evenstr + oddStr
    """casting the string into int"""
    return int(new_num)
print(arange_digits(1234567))

#task3
"""check if a given number in range is prime or not"""
def is_prime(num):
    for n in range(2, num + 1):
        if( num % n == 0):
            return False
        return True
""""if the number is prime it will print it"""
def print_prime_numbers(min, max):
    for n in range(min,max+1):
        if(is_prime(n) == True):
            print(n)

#print_prime_numbers(100, 200)

#task4
def print_figure(size):
    for space in range(1, ((size +1)//2)+1):
        if(space == (size+1)// 2):
            print("*")
        else:
            print(end="  ")
    
    if( size >= 3 and size <= 13):
        for n in range(1, size +1):
            for i in range(1, n+1):
                print("*" , i, end= "")
            print(" *")
print_figure(3)