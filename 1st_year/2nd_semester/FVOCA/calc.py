variables_map = {}

stack = []

#Instructions
PUSH=1
ADD=2
MULT=3
SUB=4
TRUE=5
FALSE=6
EQ=7
LE=8
AND=9
NEG=10
FETCH=11
STORE=12
NOOP=13
BRANCH=14
LOOP=15

p = [(PUSH, 1, None), (PUSH, 2, None), (ADD, None, None)]

st = (p, [], dict())

def interpreter(s):
    c = fst(s)
    i = c[0]

    match i:
        case "PUSH":
            stack.insert(0, c[1])
        case "ADD":
            result = stack[0] + stack[1]
            stack.insert(0, result)
            return result
        case "MULT":
            result = stack[0] * stack[1]
            stack.insert(0, result)
            return result
        case "SUB":
            result = stack[1] - stack[0]
            stack.insert(0, result)
            return result
        case "TRUE":
            stack.insert(0, True)
        case "FALSE":
            stack.insert(0, False)
        case "EQ":
            if stack[0] == stack[1]:
                stack.insert(0, True)
                return True
            else:
                stack.insert(0, False)
                return False
        case "LE":
            if stack[0] < stack[1] or stack[0] == stack[1]:
                stack.insert(0, True)
                return True
            else:
                stack.insert(0, False)
        case "AND":
            if stack[0] and stack[1] or not stack[0] and not stack[1]:
                stack.insert(0, True)
                return True
            else:
                stack.insert(0, False)
                return False
        case "NEG":
            result = stack[0] * -1
            return result
        case "FETCH":
            result = variables_map['c[1]']
            stack.insert(0, result)
            return result
        case "STORE":
            variables_map['c[1]'] = c[2]
        case "NOOP":
            pass
        case "BRANCH":
            pass
        case "LOOP":
            pass






# # def push(x):
# #     return variables_map["x"]


# def push(x,e,s):
#     return (None,x+e,s)

# def add(x, y):
#     a  = push(x)
#     b = push(y)
#     variables_map["result"] = a + b
#     return variables_map["result"]

# def sub(x, y):
#     a  = push(x)
#     b = push(y)
#     variables_map["result"] = a - b
#     return variables_map["result"]

# def multi(x, y):
#     a  = push(x)
#     b = push(y)
#     variables_map["result"] = a * b
#     return variables_map["result"]

# def eq(x, y):
#     if x == y:
#         return True
    
# def leq(x, y):
#     if x != y:
#         return True

# def noop():
#     pass