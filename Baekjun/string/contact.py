# (100+1+ | 01)+

def solution(signal):
    answer = True
    while len(signal) > 0:
        # print(f"signal : {signal}")
        n_signal = update_signal(signal)
        if n_signal == signal:
            answer = False
            break
        signal = n_signal
    return answer

def update_signal(signal):
    if signal[0:2] == '01':
        signal = signal[2:]
        # print(f"updated_signal : {signal}")
        return signal
    else:
        return check_type_one(signal)
        
        
def check_type_one(signal):
    # print("check type one")
    if signal[0] == '0': return signal
    check = False
    for i,c in enumerate(signal):
        if i == 0: continue
        if c != '0' and i >= 2:
            #ok
            signal = signal[i:]
            # print(f"ok case : {signal}")
            check = True
            break
        elif c != '0' and i<2: 
            # print("err1")
            return signal
    if signal[0] != '1' or check == False: 
        # print("err2")
        return signal
    for i,c in enumerate(signal):
        if c != '1':
            signal = signal[i:]
            break
        if i == 1 and signal[i:4] == "100":
            signal = signal[i:]
            break
        if i == len(signal)-1 and c == '1':
            signal = signal[i+1:]
    # print(f"updated_signal : {signal}")
    return signal
def main():
    N = input()
    answer = []
    for i in range(int(N)):
        signal = input()
        if solution(signal) == True: answer.append("YES")
        else: answer.append("NO")
    for a in answer:
        print(a)
    return

if __name__ == "__main__":
    main()