
def check_start_time(time):
    flag = 0;
    #print("Input: ", time)
    time_val, am_pm = time.split()
#    print("Time_val and ap_pm val = ", time_val, am_pm)
    hour, minute = time_val.split(':')
    hour = int(hour)
    minute = int(minute)
#    print("Hour and min val = ", hour, min)
    if (hour >12 or hour < 0):
        print("Error in hour value")
        flag = -1
    if (minute > 59 or minute < 0):
        print("Error in minute value")
        flag = -1
    if am_pm not in ('am','pm','AM','PM'):
        print("Incorrect AM/PM value")
        flag = -1

    if flag == 0:
        return (hour, minute, am_pm)
    else:
        return (-1, -1, -1)

def check_time_interval(time):
    flag = 0
    hour, minute = time.split(':')
    hour = int(hour)
    minute = int(minute)
#    print("Hour and min val = ", hour, min)
    if (hour < 0):
        print("Error in hour value")
        flag = -1
    if (minute > 59 or minute < 0):
        print("Error in min value")
        flag = -1
    if flag == 0:
        return (hour, minute)
    else:
        return (-1, -1)
    
def cal_end_time(hr_s, min_s, ap_s, day, hr_i, min_i):
#    print("Arguments:", hr_s, min_s, ap_s, day, hr_i, min_i)
    weekdays = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']

    #weekday = {'sunday':1, 'monday': 2, 'tuesday': 3, 'wednesday': 4, 'thursday': 5, 'friday': 6, 'saturday': 7}

    # list out keys and values separately
    #key_list = list(weekday.keys())
    #val_list = list(weekday.values())
    
    hr_remain = 0
    hr_cycle = 0 
    ap_f = ap_s
    am_pm_cycle = 0
    num_of_days = 0
    cur_idx = 0
    final_idx = 0
    add_str = ''

    if day == None:
        final_day = ''
    else:
        final_day = day
        cur_idx = weekdays.index(day)

    final_min_val = min_s + min_i
    if (final_min_val >= 60):
        hr_remain = int(final_min_val / 60)
        final_min_val = int(final_min_val % 60)
     
    #no of 12 hours cycle in interval
    if hr_i > 0:
        hr_i += hr_remain
        hr_remain = 0
        hr_cycle = hr_i / 12
        hr_remain = hr_i % 12

    if(hr_s + hr_remain) > 12:
        hr_final_val = (hr_s + hr_remain) % 12
        hr_cycle += ((hr_s + hr_remain) / 12) 
    elif (hr_s + hr_remain) == 12:
        hr_final_val = hr_s + hr_remain
        hr_cycle += 1    
    else:
        hr_final_val = hr_s + hr_remain

    num_of_days += int(hr_cycle / 2)

    am_pm_cycle += int(hr_cycle % 2)

    if am_pm_cycle:
        if ap_s.lower() == 'am':
            ap_f = 'PM'
        else:
            ap_f = 'AM'
            num_of_days += 1        
    
    out = str(hr_final_val).zfill(2) + ':' + str(final_min_val).zfill(2) + ' ' + ap_f
    if(num_of_days):
        if num_of_days == 1:
            final_idx = cur_idx + 1
            if(final_day):
                #position = val_list.index(final_idx)
                final_idx = (final_idx + 1) % 7
                #final_day = ', ' + key_list[position]
                final_day = ', ' + weekdays[final_idx - 1]
            add_str = final_day + ' (next day)'
            
        else:
            #final_idx = cur_idx + (num_of_days % 7)
            final_idx = (cur_idx + 1 + int(num_of_days)) % 7

            #if final_idx > 7 : 
            #    final_idx = final_idx % 7
            #if(final_idx):
            if(final_day):
                #position = val_list.index(final_idx)
                final_day = ', ' + weekdays[final_idx - 1]
                #final_day = ', ' + key_list[position]
            add_str = final_day + ' (' + str(num_of_days) + ' days later)'
        
    else:
        if(final_day):
            add_str = ', ' + final_day
    out += add_str
    return out   

def add_time(start_time, time_interval, day = None):
    weekdays = ['Sunday', 'Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday', 'Saturday']

    if day != None and day.capitalize().strip() not in weekdays:
       print("Error in day")
       return
    hr_s, min_s, ap_s = check_start_time(start_time)
    hr_i, min_i = check_time_interval(time_interval)

    if day != None:
       day = day.capitalize().strip()

    res = cal_end_time(hr_s, min_s, ap_s, day, hr_i, min_i)    
    print(res)
    return

input_flag = True
while (input_flag): 
    t = input("Enter time:")
    #check_start_time(t)
    d = input("Enter duration:")
    dd = input("Enter day:")
    if dd == 'None':
        dd = None
    add_time(t, d, dd)
    yes_no = input("Want to continue:")
    if (yes_no.lower() == 'n'):
        input_flag = False
