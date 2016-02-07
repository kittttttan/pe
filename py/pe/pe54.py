#!/usr/bin/env python

from sys import argv

value = { '2':2,'3':3,'4':4,'5':5,'6':6,'7':7,'8':8,'9':9,
        'T':10,'J':11,'Q':12,'K':13,'A':14 }

# tuple(reversed(sorted(value.values())))
all_kinds = (14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2)
all_suits = ['D', 'C', 'S', 'H'] # list('DCSH')

def make_hand(cards):
    hand = {}
    for card in cards:
        hand.setdefault(value[card[0]], {})[card[1]] = 1
        hand.setdefault(card[1], {})[value[card[0]]] = 1
    return hand

def get(hash, arr):
    return ((i, hash.get(i, {})) for i in arr)

def rank(hand):
    # Royal flush
    get_hand_suits = get(hand, all_suits)
    for suit, kinds in get_hand_suits:
        if ('T','J','Q','K','A') in kinds:
            return (9,)

    # Straight flush
    for suit, kinds in get_hand_suits:
        kinds = sorted(kind for kind in kinds.keys())
        if len(kinds) == 5 and kinds[4] - kinds[0] == 4:
            return (8, kinds[0])

    # Four of a kind
    get_hand_kinds = get(hand, all_kinds)
    for kind, suits in get_hand_kinds:
        if len(suits.keys()) == 4:
            return (7, kind)

    # Full house
    for kind, suits in get_hand_kinds:
        if len(suits.keys()) == 3:
            for kind2, suits2 in get_hand_kinds:
                if len(suits2.keys()) == 2:
                    return (6, kind, kind2)

    # Flush
    for suit, kinds in get_hand_suits:
        if len(kinds.keys()) == 5:
            return (5,)

    # Straight
    kinds = sorted(kind for kind in all_kinds if kind in hand)
    if len(kinds) == 5 and kinds[4] - kinds[0] == 4:
        return (4, kinds[0])

    # Three of a kind
    for kind, suits in get(hand, all_kinds):
        if len(suits.keys()) == 3:
            return (3, kind)

    # Two pairs
    for kind, suits in get(hand, all_kinds):
        if len(suits.keys()) == 2:
            for kind2, suits2 in get(hand, all_kinds):
                if kind != kind2 and len(suits2.keys()) == 2:
                    return (2, kind, kind2)

    # One pair
    for kind, suits in get(hand, all_kinds):
        if len(suits.keys()) == 2:
            return (1, kind)

    for kind in all_kinds:
        if kind in hand:
            return (0, kind)

    return 0

def pe54(fname="../res/pe54.txt"):
    """
    How many hands did player one win in the game of poker?
    """
    count = 0
    for hand in open(fname):
        hands = hand.split(' ')
        p1, p2 = make_hand(hands[0:5]), make_hand(hands[5:10])
        v1, v2 = rank(p1), rank(p2)
        if v1 > v2:
            count += 1
    return count

def main():
    argc = len(argv)
    if argc > 1:
        fname = argv[1]
    else:
        fname = "../res/pe54.txt"

    try:
        print(pe54(fname))
    except FileNotFoundError:
        print("""file not found: %s

  python pe54.py [filepath]""" % fname)

if __name__ == "__main__":
    main()
