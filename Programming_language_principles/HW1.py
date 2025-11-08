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