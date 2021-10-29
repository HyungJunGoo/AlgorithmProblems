# https://programmers.co.kr/learn/courses/30/lessons/77486?language=python3
# 다단계 칫솔 판매
from collections import defaultdict
from math import floor


def solution(enroll, referral, seller, amount):
    name_income = defaultdict(int)
    name_referral = defaultdict()
    for name, _referral in zip(enroll, referral):
        name_referral[name] = _referral

    for seller_name, amount in zip(seller, amount):
        amount *= 100
        name_income[seller_name] += amount * 0.9
        amount *= 0.1
        while not (
            seller_name == "-" or name_referral[seller_name] == "-" or amount < 1
        ):
            seller_name = name_referral[seller_name]
            fee = floor(amount * 0.1)
            amount -= fee
            name_income[seller_name] += amount
            amount = fee
    return [int(name_income[name]) for name in enroll]


enroll = ["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"]
referral = ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"]
seller = ["young", "john", "tod", "emily", "mary"]
amount = [12, 4, 2, 5, 10]
result = [360, 958, 108, 0, 450, 18, 180, 1080]

print(solution(enroll, referral, seller, amount))
