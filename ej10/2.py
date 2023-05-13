def lineal_ds():
    print("stack, queue, list")

output = lineal_ds()
output is None

any([True, False, False])
any([False,False, False])
str()
str(15)

def print_str(strName):
    print(strname)

print_str("python")

def multyply(fltA, fltB):
    return fltA *fltB
multiply(4, 5)  

round (multiply(4.4, 5.3))


from datetime import timedelta,datetime

def contest_duration(hours=5):
    now=datetime.now()
    arrival = now + timedelts(hours=hours)
    return arrival.strftime("contest duration until:%A %H:%M")

contest_duration()
contest_duration(1)
contest_duration(hours=1)


face datatime import timedelta, datetime

def contest_duration (name, hours=5):
     now=datetime.now()
     arrival = now + timedelta(hours_hours)
     return arrival.strftime(f"contest {name}'s  duration until: %A %H:%M")
contest_duration("EDAI")
contes_duaration("CPCFI", hours=0.45)


def vars_args(*args):
    print(args)
vars_args()
vars_args("stack", "queue","list")
vars_agrs_args(5)

defvariable_length(**kwargs):
    print(f"{len(kwargs}data structures and their operations:")
    for title, name in kwargs.items():
        print(f"\t{title}-> {name}")
variable_length(stack="pop, push", queue="enqueue, dequeue", list="add, delete")


def variable_length(**kwargs):
    print(f"\t{len (kwarangs)} data structers and their operations:")
    for title, name inkwargs. items():
        print(f"{title}-> {name}")
variable_length(stack="pop, push", queue="enqueue, dequeuue", list="add,delete")

cont=0
def increment():
    cont=5
increment()
print(cont)


cont=0
def increment():
    global cont=5
increment()
print(cont)

xyz=lambda x,y,y: x * y * z
print(xyz(2, 3, 4))
print(xyz(3, 6, 9))

print((lambdax:))