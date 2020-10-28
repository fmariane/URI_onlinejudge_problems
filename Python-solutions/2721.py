from itertools import cycle

snowballs = input()

reindeers = ["Dasher", "Dancer", "Prancer", "Vixen",
             "Comet", "Cupid", "Donner", "Blitzen",  "Rudolph"]


def parseNumSnowballs(entrada):
    total = 0
    entrada = entrada.split(" ")
    for i in entrada:
        total += int(i)

    return total


def pickReindeer(reindeers, num_snowballs):
    reindeers = cycle(reindeers)

    for r in reindeers:
        num_snowballs -= 1

        if(num_snowballs == 0):
            return r


num_snowballs = parseNumSnowballs(snowballs)
winner = pickReindeer(reindeers, num_snowballs)

print(winner)
